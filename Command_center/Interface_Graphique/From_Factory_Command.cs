//*************************************************************************************
// Auteur : Malbrouck Harold Jonathan
//
// Description : Interface usager qui permet de gérer l'usine :
//                    - le démarrage
//                    - l'arrêt d'urgence
//                    - Visualisation du parcours du véhicule
//                    - Voir la couleur du block
//                    - Voir le poid du block
//************************************************************************************


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using Renci.SshNet;
using System.Net.NetworkInformation;
using AForge.Video;
using AForge.Video.DirectShow;
using System.Security.AccessControl;
using System.Text.RegularExpressions;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using TimerForms = System.Windows.Forms.Timer; // Alias pour System.Windows.Forms.Timer


namespace Projet_final_Poste_de_commande
{
    public partial class frm_factory_API : Form
    {
        #region Declaration Variables
        private SerialPort _SerialPort; // Port série pour la communication avec le moteur
        private SshClient _Client_Poste_de_commande; // Client SSH pour le poste de commande
        private SshClient _Client_Poste_de_pesage; // Client SSH pour le poste de pesage
        private FilterInfoCollection _Fic; // Collection de filtres pour les caméras
        private VideoCaptureDevice _Vcd1; // Dispositif de capture vidéo pour la caméra 1
        private VideoCaptureDevice _Vcd2; // Dispositif de capture vidéo pour la caméra 2
        private ShellStream _ShellStream_Poste_de_commande; // Flux de shell pour le poste de commande
        private ShellStream _ShellStream_Poste_de_pesage; // Flux de shell pour le poste de pesage
        private bool bEtatConnecter = false; // État de la connexion
        private bool bEmergency = false; // État d'urgence
        private bool bEtatMarche = false; // État de marche
        private static string dataRx; // Données reçues du port série
        private float fWeight = 2; // Poids initial
        private CancellationTokenSource _Cts; // Token pour annuler les tâches
        private List<string> cameraNames; // Liste des noms de caméras
        private Bitmap _MyImage; // Image pour la caméra
        private Random rnd = new Random(); // Générateur de nombres aléatoires

        // Déclaration des variables pour accumuler les lignes de texte reçues pour chaque flux
        private StringBuilder commandBuffer = new StringBuilder();
        private StringBuilder pesageBuffer = new StringBuilder();
        // Déclaration d'un Timer pour gérer la mise à jour périodique des zones de texte
        private System.Threading.Timer updateTimer ;

        // Constantes pour les codes CAN
        private const string CAN_EMERGENCY_STOP = "0x001";
        private const string CAN_WEIGHT = "0x031";
        private const string CAN_VEHICLE_POSITION = "0x032";
        private const string CAN_FACTORY_MESSAGE = "0x034";
        #endregion

        #region INITIALISATION
        public frm_factory_API()
        {
            this.FormBorderStyle = FormBorderStyle.FixedSingle; // Empêche le redimensionnement de la fenêtre
            this.MaximizeBox = this.MinimizeBox = false; // Désactive les boutons de maximisation et minimisation
            this.TopMost = true; // La fenêtre sera toujours au-dessus des autres fenêtres
            InitializeComponent(); // Initialise les composants de la fenêtre
            formInitialisation(); // Appelle la méthode d'initialisation du formulaire
        }

        private void formInitialisation()
        {
            ListingSerialPort(); // Liste des ports disponibles  
            gb_Ctrl_Usine.Enabled = false; // Désactive le groupe de contrôle de l'usine
            gb_Vehicule.Enabled = false; // Désactive le groupe de contrôle du véhicule
            btn_Emergency.BackColor = Color.Red; // Définit la couleur du bouton d'urgence
            rTB_PosteCommande.ReadOnly = true; // Rend la zone de texte en lecture seule
            rTB_PostePesage.ReadOnly = true; // Rend la zone de texte en lecture seule
            CamInitianilisation(); // Initialise les caméras
            pB_parcour.SizeMode = PictureBoxSizeMode.StretchImage; // Définit le mode d'affichage de l'image
            pB_parcour.Image = Properties.Resources.BALANCE; // Définit l'image par défaut
        }

        protected override void WndProc(ref Message m)
        {
            const int WM_NCLBUTTONDOWN = 0xA1; // Message Windows pour le clic dans la zone non-client
            const int HTCAPTION = 0x2; // Indicateur pour la barre de titre

            // Bloquer le déplacement si le clic provient de la barre de titre
            if (m.Msg == WM_NCLBUTTONDOWN && m.WParam.ToInt32() == HTCAPTION)
            {
                return; // Ne pas transmettre ce message à la base (empêche le déplacement)
            } 
            
            base.WndProc(ref m); // Appel à la méthode de base pour gérer les autres messages
        }

        private void ListingSerialPort()
        {
            try
            {
                string[] listeDesPorts = SerialPort.GetPortNames(); // Récupère la liste des ports série
                cb_Port.Items.Clear(); // Vide la liste des ports dans le combo box
                cb_Port.Items.AddRange(listeDesPorts); // Ajoute les ports disponibles au combo box
            }
            catch (Exception ex)
            {
                MessageBox.Show("Erreur lors de la récupération des ports : " + ex.Message); // Affiche un message d'erreur
            }
        }
        #endregion

        #region Connection
        private void btn_ConnectandDeconnect_Click(object sender, EventArgs e)
        {
            if (!bEtatConnecter) // Si non connecté
            {
                try
                {
                    //********************* SSH WIFI   modifier les addresses IP qui doivent du même sous reseaux ************************************
                    _Client_Poste_de_commande = new SshClient("172.20.10.8", "debian", "temppwd"); // poste de commande
                    _Client_Poste_de_pesage = new SshClient("172.20.10.5", "debian", "temppwd"); // poste pesage


                    //***********  À DÉCOMMENTER pour l'uilisation du PortSerie ************************

                    //if (cb_Port.SelectedItem == null) // Vérifie si un port a été sélectionné
                    //{
                    //    MessageBox.Show("Veuillez sélectionner un port série.", "Paramètres manquants");
                    //    return;
                    //}

                    //_SerialPort = new SerialPort(cb_Port.SelectedItem.ToString());
                    //_SerialPort.Handshake = Handshake.None;
                    // Gère les données reçues du port série
                    //_SerialPort.DataReceived += new SerialDataReceivedEventHandler(_SerialPort_DataReceive);

                    //if (!_SerialPort.IsOpen)
                    //{
                    //   Connect();
                    //}


                    Connect(); // Appelle la méthode de connexion
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Erreur lors de l'ouverture du port série : " + ex.Message, "Erreur");
                }
            }
            else
            {
                Deconnect(); // Appelle la méthode de déconnexion
            }
        }

        // Fonction de connexion
        private void Connect()
        {
            try
            {
                _Client_Poste_de_commande.Connect(); // Connecte au poste de commande
                _Client_Poste_de_pesage.Connect(); // Connecte au poste de pesage

                if (_Client_Poste_de_commande.IsConnected)
                {
                    MessageBox.Show("Connexion SSH Poste de commande réussie !", "Succès", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    var command = _Client_Poste_de_commande.RunCommand("ls");
                    rTB_PosteCommande.Text = command.Result; // Afficher le résultat
                }

                if (_Client_Poste_de_pesage.IsConnected)
                {
                    MessageBox.Show("Connexion SSH Poste de pesage réussie !", "Succès", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    var command = _Client_Poste_de_pesage.RunCommand("ls");
                    rTB_PostePesage.Text = command.Result; // Afficher le résultat
                }

                gb_Connexion.Text = "Connection OK";
                gb_Connexion.ForeColor = Color.Green;
                btn_ConnectandDeconnect.Text = "Deconnecter";
                lbl_Port.ForeColor = Color.Black;
                btn_ConnectandDeconnect.ForeColor = Color.Black;
                cb_Port.Enabled = false;
                bEtatConnecter = true;
                gb_Ctrl_Usine.Enabled = true;
                gb_Vehicule.Enabled = true;

                _ShellStream_Poste_de_commande = _Client_Poste_de_commande.CreateShellStream("CLI", 0, 0, 0, 0, 4096);
                _ShellStream_Poste_de_pesage = _Client_Poste_de_pesage.CreateShellStream("CLI", 0, 0, 0, 0, 4096);
                vDebuggerView();
                _ShellStream_Poste_de_commande.WriteLine("./Poste_de_commande");
                _ShellStream_Poste_de_commande.Flush();

                _ShellStream_Poste_de_pesage.WriteLine("cd BeagleboneLab/BrasBalance && ./BrasBalance");
                _ShellStream_Poste_de_pesage.Flush();
                StartListeningToCAN(); // Démarre l'écoute des données CAN
            }
            catch (Exception ex)
            {
                MessageBox.Show("Erreur lors de la connexion : " + ex.Message);
            }
        }

        // Fonction de déconnexion
        private void Deconnect()
        {
            try
            {
                btn_ConnectandDeconnect.Text = "Connecter"; // Met à jour le texte du bouton de connexion
                cb_Port.Enabled = true; // Réactive le combo box des ports
                bEtatConnecter = false; // Met à jour l'état de connexion
                gb_Ctrl_Usine.Enabled = false; // Désactive le groupe de contrôle de l'usine
                gb_Vehicule.Enabled = false; // Désactive le groupe de contrôle du véhicule

                // Dispose des flux de shell
                _ShellStream_Poste_de_commande.Dispose();
                _ShellStream_Poste_de_pesage.Dispose();
                _ShellStream_Poste_de_commande.Close();
                _ShellStream_Poste_de_pesage.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show("Erreur lors de la déconnexion : " + ex.Message); // Affiche un message d'erreur
            }
        }
        #endregion

        #region CONVERTION POIDS
        private void rB_Lbs_CheckedChanged(object sender, EventArgs e)
        {
            lbl_currentUnit.Text = "Lbs"; // Met à jour l'unité affichée
            lbl_currentWeight.Text = (Math.Round((fWeight * 2.20462262), 2)).ToString(); // Convertit et affiche le poids en livres
        }

        private void rB_kg_CheckedChanged(object sender, EventArgs e)
        {
            lbl_currentUnit.Text = "Kg"; // Met à jour l'unité affichée
            lbl_currentWeight.Text = (Math.Round((fWeight * 0.45359237), 2)).ToString(); // Convertit et affiche le poids en kilogrammes
        }
        #endregion

        #region BOUTON
        #region Emergency btn
        private void btn_Emergency_Click(object sender, EventArgs e)
        {
            // Vérifiez l'état de `bEmergency` pour démarrer ou arrêter le clignotement
            if (!bEmergency)
            {
                btn_Start.Enabled = false; // Désactive le bouton de démarrage
                bEmergency = true; // Met à jour l'état d'urgence
                _Cts = new CancellationTokenSource(); // Crée un token d'annulation
                SoftBlink(btn_Emergency, Color.FromArgb(30, 30, 30), Color.Red, 1000, false, _Cts.Token); // Démarre le clignotement
                lbl_etat.Text = "ARRET D'URGENCE"; // Met à jour l'état affiché
                _ShellStream_Poste_de_commande.Write("a\r"); // Envoie une commande d'arrêt d'urgence
                _ShellStream_Poste_de_commande.Flush();
                SoftBlink(lbl_etat, Color.FromArgb(30, 30, 30), Color.Red, 1000, false, _Cts.Token); // Démarre le clignotement de l'étiquette d'état
            }
            else
            {
                // Arrêter le clignotement
                _Cts.Cancel(); // Annule le clignotement
                bEmergency = false; // Met à jour l'état d'urgence
                btn_Emergency.ForeColor = Color.FromArgb(30, 30, 30); // Remet la couleur de départ
                lbl_etat.Text = "   EN ATTENTE  "; // Met à jour l'état affiché
                _ShellStream_Poste_de_commande.Write("s\r"); // Envoie une commande pour reprendre
                _ShellStream_Poste_de_commande.Flush();
                btn_Start.Enabled = true; // Réactive le bouton de démarrage
            }
        }

        private async void SoftBlink(Control ctrl, Color c1, Color c2, short CycleTime_ms, bool BkClr, CancellationToken cts)
        {
            var sw = new Stopwatch();
            sw.Start();
            short halfCycle = (short)Math.Round(CycleTime_ms * 0.5); // Calcule la moitié du cycle

            while (!cts.IsCancellationRequested) // Continue tant que le token n'est pas annulé
            {
                await Task.Delay(1); // Attend un milliseconde
                var n = sw.ElapsedMilliseconds % CycleTime_ms; // Calcule le temps écoulé dans le cycle
                var per = (double)Math.Abs(n - halfCycle) / halfCycle; // Calcule le pourcentage du cycle
                var red = (short)Math.Round((c2.R - c1.R) * per) + c1.R; // Calcule la composante rouge de la couleur
                var grn = (short)Math.Round((c2.G - c1.G) * per) + c1.G; // Calcule la composante verte de la couleur
                var blw = (short)Math.Round((c2.B - c1.B) * per) + c1.B; // Calcule la composante bleue de la couleur
                var clr = Color.FromArgb(red, grn, blw); // Crée la nouvelle couleur

                if (BkClr)
                    ctrl.BackColor = clr; // Change la couleur de fond si BkClr est vrai
                else
                    ctrl.ForeColor = clr; // Change la couleur de texte sinon
            }

            // Réinitialiser la couleur du contrôle après l'annulation
            ctrl.ForeColor = c1; // Remet la couleur de départ
            bEmergency = false; // Réinitialise l'état d'urgence
        }
        #endregion

        private void btn_Start_Click(object sender, EventArgs e)
        {
            if (!bEtatMarche) // Si l'état de marche est désactivé
            {
                lbl_etat.Text = "  EN FONCTION  "; // Met à jour l'état affiché
                bEtatMarche = true; // Met à jour l'état de marche
            }
            else
            {
                lbl_etat.Text = "   EN ATTENTE  "; // Met à jour l'état affiché
                bEtatMarche = false; // Met à jour l'état de marche
            }
            btn_Start.Text = "Demarrer"; // Met à jour le texte du bouton de démarrage
            _ShellStream_Poste_de_commande.Write("s\r"); // Envoie une commande pour démarrer
            _ShellStream_Poste_de_commande.Flush();
        }

        private void btn_Stop_Click(object sender, EventArgs e)
        {
            _ShellStream_Poste_de_commande.Write("q\r"); // Envoie une commande pour arrêter
            _ShellStream_Poste_de_commande.Flush();
        }
        #endregion

        #region LiveVideo
        private void CamInitianilisation()
        {
            _Fic = new FilterInfoCollection(FilterCategory.VideoInputDevice); // Récupère les dispositifs de capture vidéo
            cameraNames = new List<string>(); // Initialise la liste des noms de caméras
            int camIndex = 1;

            foreach (FilterInfo fi in _Fic)
            {
                cB_Cam1.Items.Add("CAM" + camIndex); // Ajoute les caméras au combo box 1
                cB_Cam2.Items.Add("CAM" + camIndex); // Ajoute les caméras au combo box 2
                cameraNames.Add(fi.MonikerString); // Ajoute le nom de la caméra à la liste
                camIndex++;
            }
        }

        private void FinalFrame_NewFrame_Cam1(object sender, NewFrameEventArgs eventArgs)
        {
            CAMLIVE1_pB.Image = (Bitmap)eventArgs.Frame.Clone(); // Affiche le cadre de la caméra 1
        }

        private void FinalFrame_NewFrame_Cam2(object sender, NewFrameEventArgs eventArgs)
        {
            CAMLIVE2_pB.Image = (Bitmap)eventArgs.Frame.Clone(); // Affiche le cadre de la caméra 2
        }

        private void cB_Cam1_SelectedIndexChanged(object sender, EventArgs e)
        {
            StopVideoCapture1(); // Arrête l'ancienne instance de capture si elle est en cours d'exécution

            _Vcd1 = new VideoCaptureDevice(cameraNames[cB_Cam1.SelectedIndex]); // Crée une nouvelle instance de capture vidéo pour la caméra 1
            _Vcd1.NewFrame += FinalFrame_NewFrame_Cam1; // Abonne l'événement de nouveau cadre
            _Vcd1.Start(); // Démarre la capture vidéo
        }

        private void cB_Cam2_SelectedIndexChanged(object sender, EventArgs e)
        {
            StopVideoCapture2(); // Arrête l'ancienne instance de capture si elle est en cours d'exécution

            _Vcd2 = new VideoCaptureDevice(cameraNames[cB_Cam2.SelectedIndex]); // Crée une nouvelle instance de capture vidéo pour la caméra 2
            _Vcd2.NewFrame += FinalFrame_NewFrame_Cam2; // Abonne l'événement de nouveau cadre
            _Vcd2.Start(); // Démarre la capture vidéo
        }

        private void StopVideoCapture1()
        {
            if (_Vcd1 != null && _Vcd1.IsRunning) // Vérifie si la caméra 1 est en cours d'exécution
            {
                _Vcd1.SignalToStop(); // Envoie un signal pour arrêter la capture
                _Vcd1.WaitForStop(); // Attend que la capture s'arrête
                _Vcd1.NewFrame -= FinalFrame_NewFrame_Cam1; // Se désabonne de l'événement de nouveau cadre
                _Vcd1 = null; // Libère la référence à la caméra 1
            }
        }

        private void StopVideoCapture2()
        {
            if (_Vcd2 != null && _Vcd2.IsRunning) // Vérifie si la caméra 2 est en cours d'exécution
            {
                _Vcd2.SignalToStop(); // Envoie un signal pour arrêter la capture
                _Vcd2.WaitForStop(); // Attend que la capture s'arrête
                _Vcd2.NewFrame -= FinalFrame_NewFrame_Cam2; // Se désabonne de l'événement de nouveau cadre
                _Vcd2 = null; // Libère la référence à la caméra 2
            }
        }


        private void frm_factory_API_FormClosed(object sender, FormClosedEventArgs e)
        {
            StopVideoCapture1(); // Arrête la capture vidéo de la caméra 1 lors de la fermeture du formulaire
            StopVideoCapture2(); // Arrête la capture vidéo de la caméra 2 lors de la fermeture du formulaire
        }
        #endregion

        #region BBB Debugger Interface


        private void vDebuggerView()
        {
            // Initialisation du Timer pour effectuer une mise à jour après un délai de 100 ms
            updateTimer = new System.Threading.Timer(UpdateTextBoxes, null, Timeout.Infinite, Timeout.Infinite);

            // Réception des réponses des commandes avec une attente de 3 secondes
            string reply_Commande = _ShellStream_Poste_de_commande.Expect(new Regex(@":.*>#"), new TimeSpan(0, 0, 3));
            string reply_Pesage = _ShellStream_Poste_de_pesage.Expect(new Regex(@":.*>#"), new TimeSpan(0, 0, 3));

            // Abonnement aux événements DataReceived pour chaque flux
            _ShellStream_Poste_de_commande.DataReceived += ShellStream_DataReceived;
            _ShellStream_Poste_de_pesage.DataReceived += ShellStream_DataReceived;

            // Initialisation des zones de texte pour indiquer que les serveurs sont connectés
            rTB_PosteCommande.Text = "server connected\n";
            rTB_PostePesage.Text = "server connected\n";

            // Défilement vers la fin des zones de texte
            rTB_PosteCommande.SelectionStart = rTB_PosteCommande.Text.Length;
            rTB_PostePesage.SelectionStart = rTB_PostePesage.Text.Length;

            // Défilement vers le bas dans les zones de texte
            rTB_PosteCommande.ScrollToCaret();
            rTB_PostePesage.ScrollToCaret();
        }

        // Méthode qui gère les événements de réception de données
        private void ShellStream_DataReceived(object sender, Renci.SshNet.Common.ShellDataEventArgs e)
        {
            try
            {
                // Vérifie si les données reçues sont valides
                if (e.Data == null || e.Data.Length == 0)
                    return; // Si les données sont nulles ou vides, on ne fait rien

                // Convertir les données binaires en chaîne de caractères UTF8
                var line = Encoding.UTF8.GetString(e.Data);

                // Filtrer et traiter les données avant de les afficher
                line = FilterData(line);

                // Si la ligne est vide après filtrage, on ne l'affiche pas
                if (string.IsNullOrEmpty(line))
                    return;

                // Identifier de quel flux provient la donnée (commande ou pesage) et accumuler les lignes dans le bon tampon
                if (sender == _ShellStream_Poste_de_commande)
                {
                    commandBuffer.AppendLine($"Poste de commande: {line}");
                }
                else if (sender == _ShellStream_Poste_de_pesage)
                {
                    pesageBuffer.AppendLine($"Poste de pesage: {line}");
                }

                // Déclenche la mise à jour des zones de texte après un délai de 100 ms
                updateTimer.Change(100, Timeout.Infinite);
            }
            catch (Exception ex)
            {
                // Gestion des erreurs : afficher un message si quelque chose va mal
                Console.WriteLine($"Erreur lors de la réception des données : {ex.Message}");
            }
        }

        // Cette méthode est appelée par le Timer pour mettre à jour les zones de texte
        private void UpdateTextBoxes(object state)
        {
            // Déléguer le travail à un thread de l'interface utilisateur pour mettre à jour les contrôles
            MethodInvoker methodInvokerDelegate = delegate ()
            {
                // Ajouter le contenu du tampon de commande à la zone de texte
                if (commandBuffer.Length > 0)
                {
                    rTB_PosteCommande.AppendText(commandBuffer.ToString());
                    commandBuffer.Clear(); // Réinitialiser le tampon après l'affichage
                }

                // Ajouter le contenu du tampon de pesage à la zone de texte
                if (pesageBuffer.Length > 0)
                {
                    rTB_PostePesage.AppendText(pesageBuffer.ToString());
                    pesageBuffer.Clear(); // Réinitialiser le tampon après l'affichage
                }

                // Mettre à jour la position du curseur et faire défiler vers le bas dans les deux zones de texte
                rTB_PosteCommande.SelectionStart = rTB_PosteCommande.Text.Length;
                rTB_PosteCommande.ScrollToCaret();

                rTB_PostePesage.SelectionStart = rTB_PostePesage.Text.Length;
                rTB_PostePesage.ScrollToCaret();
            };

            // Exécuter la mise à jour de l'interface utilisateur sur le thread principal
            Invoke(methodInvokerDelegate);
        }

        // Filtrage des données reçues pour éliminer des informations non souhaitées
        private string FilterData(string data)
        {
            // Exemple de filtrage pour ignorer les lignes contenant "ERREUR"
            if (data.Contains("ERREUR"))
                return string.Empty; // Si la ligne contient une erreur, on l'ignore

            // Nettoyer les retours chariots (\r\n) et autres caractères inutiles
            return data.Replace("\r\n", "\n");
        }


        #endregion

        #region Communication CAN
        private void StartListeningToCAN()
        {
            Task.Run(() =>
            {
                while (_ShellStream_Poste_de_commande != null)
                {
                    if (_ShellStream_Poste_de_commande.DataAvailable)
                    {
                        string output = _ShellStream_Poste_de_commande.ReadLine(); // Lit les données disponibles
                        if (output.StartsWith("DATA:")) // Vérifie si les données commencent par "DATA:"
                        {
                            string data = output.Substring(5).Trim(); // Extrait les données CAN
                            Invoke(new Action(() =>
                            {
                                rTB_PosteCommande.AppendText($"Données CAN reçues : {data}\n"); // Affiche les données CAN reçues
                            }));

                            ProcessCANData(data); // Traite les données CAN
                        }
                    }
                    Thread.Sleep(50); // Pause pour éviter une surcharge CPU
                }
            });
        }

        private void ProcessCANData(string data)
        {
            string[] bytes = data.Split(' '); // Sépare les données en fonction des espaces
            if (bytes.Length > 0) // Vérifie qu'il y a des données à traiter
            {
                // Vérifie le premier byte pour déterminer le type de message
                if (bytes[0] == CAN_EMERGENCY_STOP)
                {
                    btn_Emergency.PerformClick(); // Message prioritaire d'arrêt d'urgence
                }

                if (bytes[0] == CAN_WEIGHT) // Message provenant de la balance
                {
                    fWeight = Convert.ToInt32(bytes[1], 16); // Convertit la valeur du poids reçu de l'hexadécimal
                    lbl_currentWeight.Text = fWeight.ToString(); // Met à jour l'affichage du poids
                }

                if (bytes[0] == CAN_VEHICLE_POSITION) // Message provenant de la voiture
                {
                    switch (bytes[1]) // Affiche sa position
                    {
                        case "0x31":
                            pB_parcour.Image = Properties.Resources.USINE; // Met à jour l'image pour l'usine
                            break;
                        case "0x32":
                            pB_parcour.Image = Properties.Resources.CROISEMENT1; // Met à jour l'image pour le croisement 1
                            break;
                        case "0x33":
                            pB_parcour.Image = Properties.Resources.CURVE1; // Met à jour l'image pour la courbe 1
                            break;
                        case "0x34":
                            pB_parcour.Image = Properties.Resources.CURVE2; // Met à jour l'image pour la courbe 2
                            break;
                        case "0x35":
                            pB_parcour.Image = Properties.Resources.CROISEMENT2; // Met à jour l'image pour le croisement 2
                            break;
                        case "0x36":
                            pB_parcour.Image = Properties.Resources.BALANCE; // Met à jour l'image pour la balance
                            break;
                    }
                }

                if (bytes[0] == CAN_FACTORY_MESSAGE) // Message provenant de l'usine 
                {
                    if (bytes[1] == "0x041")
                    {
                        btn_Emergency.PerformClick(); // Message d'arrêt
                    }

                    switch (bytes[2])
                    {
                        case "0x60":
                            lbl_currentcolor.Text = "Non définie"; // Met à jour la couleur affichée
                            break;
                        case "0x61":
                            lbl_currentcolor.Text = "Noir"; // Met à jour la couleur affichée
                            break;
                        case "0x62":
                            lbl_currentcolor.Text = "Orange"; // Met à jour la couleur affichée
                            break;
                        case "0x63":
                            lbl_currentcolor.Text = "Métal"; // Met à jour la couleur affichée
                            break;
                    }
                }
            }
        }
        #endregion

    }
} 