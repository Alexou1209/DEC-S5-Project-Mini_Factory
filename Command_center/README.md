Description de l'interface graphique

Section "Controle de l'usine" :
1) Boutons « arrêt d’urgence » et « démarrer » qui serviront à mettre le système en opération ou à l'arrêter ;
2) Moyens d'indiquer qu'un arrêt d'urgence est en cours ou que le système est en opération ou pas ;

Section "connexion série" :
1) Moyens de sélectionner le port de communication à utiliser et d'établir la connexion ; ( prendre note que le programme pour l'instant utilisation du SSH WIFI)
2) Indicateur du statut de la connexion qui servira à produire un signal d’alarme lorsque la communication sera rompue pendant plus de 30 secondes consécutives ;

Section "véhicule et parcours" :
1) Image qui représente la piste et les divers éléments du système ;
2) Indication approximative de la position du véhicule le long de la piste ;

Section "chargement du véhicule" :
1) Couleur du dernier bloc trié ou mention "inconnue" lorsqu'un tri est en cours
2) Sélecteur d'unités pour les mesures de poids et poids du dernier bloc trié en gramme ou en livres ;

Section "BBB debug interface"
1) permet d'afficher la communication et les message qui passe sur le CAN entre les BeagleBone Blues

Section "LIVECAM - Véhicule et USINE" :
  permet d'afficher en direct des liveCam selectionnées



Description Poste_de_commande

 1) Établit un lien de communication fiable et sécuritaire entre son ordinateur et son Beaglebone Blue ;
 2) Utilise un protocole qui permettra aux autres éléments du système de synchroniser leurs opérations ;
 3) Transmet les messages CAN qui s'adresseront aux autres éléments du système ;
 4) Émet des messages qui lui permettront d'indiquer si tous les éléments du système doivent être en arrêt ou en opération ;
 5) Reçoit et interpréte tous les messages CAN qui seront émis par les autres éléments du système.

