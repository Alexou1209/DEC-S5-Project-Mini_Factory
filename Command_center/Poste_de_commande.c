//*************************************************************************
// Fichier : Poste_de_commande.c
//
// Programme qui gère la communication CAN entre l'interface usagé et le reste
// des équipements (usine, bras, balance, véhicule)
//
// @author Malbrouck Harold Jonathan
//
// **********************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <fcntl.h>

#define CAN_INTERFACE "can0"
#define CAN_ID 0x034
#define CAN_ID_BALANCE 0x031
#define CAN_ID_ARRET_URGENCE 0x001

/* ---- Fonctions d'erreur ---- */
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

/* ---- Configuration du socket CAN ---- */
int setup_can_socket(const char *interface, int apply_filters) {
    int can_socket;
    struct ifreq ifr;
    struct sockaddr_can addr;

    // Création du socket CAN
    if ((can_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        error("Erreur lors de la création du socket CAN");
    }

    // Configuration de l'interface CAN
    strcpy(ifr.ifr_name, interface);
    if (ioctl(can_socket, SIOCGIFINDEX, &ifr) < 0) {
        error("Erreur lors de la configuration de l'interface CAN");
    }

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    // Liaison du socket à l'interface CAN
    if (bind(can_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		     error("Erreur lors du bind du socket CAN");
    }

    

    return can_socket;
}

/* ---- Envoi d'un message CAN ---- */
void send_can_message(int can_socket, struct can_frame *frame) {
    if (write(can_socket, frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        error("Erreur lors de l'envoi CAN");
    }

    printf("Message CAN envoyé -> ID: 0x%03X, Data: ", frame->can_id);
    for (int i = 0; i < frame->can_dlc; i++) {
        printf("%02X ", frame->data[i]);
    }
    printf("\n");
}

/* ---- Réception d'un message CAN ---- */
int receive_can_message(int can_socket, struct can_frame *frame) {
    int nbytes = read(can_socket, frame, sizeof(struct can_frame));
    if (nbytes < 0) {
        error("Erreur lors de la réception CAN");
    }
    return nbytes;
}
/* ---- Affichage d'un message CAN ---- */
void print_can_message(const char *label, struct can_frame *frame) {
    printf("%s -> ID: 0x%03X, Data: ", label, frame->can_id);
    for (int i = 0; i < frame->can_dlc; i++) {
        printf("%02X ", frame->data[i]);
    }
    printf("\n");
}

/* ---- Processus fils : Réception CAN et transfert au père ---- */
void child_process(int pipe_fd, const char *interface) {
    close(pipe_fd); // Ferme l'extrémité inutilisée du pipe (écriture)

    // Configuration du socket CAN avec filtres
    int can_socket = setup_can_socket(interface, 1);

    struct can_frame frame;
    printf("Fils : En attente de messages CAN...\n");

    //while (1) {
        // Réception d'un message CAN
        receive_can_message(can_socket, &frame);

        // Affichage du message reçu
        print_can_message("Fils : Message CAN reçu", &frame);
        
        // Transfert du message au processus père via le pipe
        if (write(pipe_fd, &frame, sizeof(struct can_frame)) < 0) {
            error("Erreur lors de l'écriture dans le pipe");
        }
    //}

    close(can_socket);
    close(pipe_fd); // Ferme le pipe après usage
}

/* ---- Processus père : Envoi CAN et lecture des messages du fils ---- */
void parent_process(int pipe_fd, const char *interface) {   

	close(pipe_fd); // Ferme l'extrémité inutilisée du pipe (lecture)

    // Configuration du socket CAN
    int can_socket = setup_can_socket(interface, 0);
    int nbytes;
    struct can_frame frame;
    frame.can_id = CAN_ID;
    frame.can_dlc = 3;

    printf("Père : Prêt à envoyer des messages CAN\n");

        static char user_input;
while(1){
        scanf(" %c", &user_input);

	if(user_input == 's'){ // Commande de démarrage
		frame.data[0] = 0x40;
		frame.data[1] = 0x60;
		frame.data[2] = 0x80;
	}
       
	if (user_input == 'q') { //commande d'arret
        frame.data[0] = 0x41;
		frame.data[1] = 0x60;
	    frame.data[2] = 0x80;	
	}
        
	if(user_input == 'a'){ // commande d'arret d'urgence
		frame.can_id = CAN_ID_ARRET_URGENCE; 
		frame.data[0] = 0x041;
		frame.data[1] = 0x060; 
		frame.data[2] = 0x080;
	}

            // Envoi du message CAN
            send_can_message(can_socket, &frame);
        

        // Lecture des messages du fils via le pipe
        struct can_frame received_frame;
        if(read(pipe_fd, &received_frame, sizeof(struct can_frame)) > 0) {
            //print_can_message("Père : Message reçu du fils", &received_frame);
			    
     	    printf("DATA: %08X ", fram.can_id);   // Affiche l'ID du message CAN en hexadécimal
 	
			for (int i = 0; i < frame.can_dlc ; i++){
			printf("%02X ", frame.data[i]);  // Affiche chaque octet de données en hexadécimal
			}
			printf("\n");
			fflush(stdout);
        }
}

    close(can_socket);
    close(pipe_fd); // Ferme le pipe après usage
}


/* ---- Fonction principale ---- */
int main() {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        error("Erreur lors de la création du pipe");
    }

    pid_t pid = fork();
    if (pid < 0) {
        error("Erreur lors de la création du processus fils");
    }

    if (pid == 0) {
        // Processus fils
        child_process(pipe_fd[1], CAN_INTERFACE);
    } else {
        // Processus père
        parent_process(pipe_fd[0], CAN_INTERFACE);
    }

    return 0;
}

