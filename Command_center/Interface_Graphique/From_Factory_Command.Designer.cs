namespace Projet_final_Poste_de_commande
{
  partial class frm_factory_API
  {
    /// <summary>
    /// Variable nécessaire au concepteur.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Nettoyage des ressources utilisées.
    /// </summary>
    /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Code généré par le Concepteur Windows Form

    /// <summary>
    /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
    /// le contenu de cette méthode avec l'éditeur de code.
    /// </summary>
    private void InitializeComponent()
    {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(frm_factory_API));
            this.gb_Connexion = new System.Windows.Forms.GroupBox();
            this.btn_ConnectandDeconnect = new System.Windows.Forms.Button();
            this.cb_Port = new System.Windows.Forms.ComboBox();
            this.lbl_Port = new System.Windows.Forms.Label();
            this.gb_Ctrl_Usine = new System.Windows.Forms.GroupBox();
            this.btn_Stop = new System.Windows.Forms.Button();
            this.lbl_etat = new System.Windows.Forms.Label();
            this.lbl_Machine = new System.Windows.Forms.Label();
            this.btn_Start = new System.Windows.Forms.Button();
            this.btn_Emergency = new System.Windows.Forms.Button();
            this.gb_Vehicule = new System.Windows.Forms.GroupBox();
            this.rB_kg = new System.Windows.Forms.RadioButton();
            this.rB_Lbs = new System.Windows.Forms.RadioButton();
            this.lbl_currentUnit = new System.Windows.Forms.Label();
            this.lbl_currentWeight = new System.Windows.Forms.Label();
            this.lbl_currentcolor = new System.Windows.Forms.Label();
            this.lbl_unit = new System.Windows.Forms.Label();
            this.lbl_Poids = new System.Windows.Forms.Label();
            this.lbl_BlocColor = new System.Windows.Forms.Label();
            this.gb_View = new System.Windows.Forms.GroupBox();
            this.pB_parcour = new System.Windows.Forms.PictureBox();
            this.cB_Cam1 = new System.Windows.Forms.ComboBox();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.gB_BbBdebug = new System.Windows.Forms.GroupBox();
            this.rTB_PostePesage = new System.Windows.Forms.RichTextBox();
            this.rTB_PosteCommande = new System.Windows.Forms.RichTextBox();
            this.LiveCAM_gB = new System.Windows.Forms.GroupBox();
            this.cB_Cam2 = new System.Windows.Forms.ComboBox();
            this.CAMLIVE2_pB = new System.Windows.Forms.PictureBox();
            this.CAMLIVE1_pB = new System.Windows.Forms.PictureBox();
            this.gb_Connexion.SuspendLayout();
            this.gb_Ctrl_Usine.SuspendLayout();
            this.gb_Vehicule.SuspendLayout();
            this.gb_View.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pB_parcour)).BeginInit();
            this.gB_BbBdebug.SuspendLayout();
            this.LiveCAM_gB.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.CAMLIVE2_pB)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.CAMLIVE1_pB)).BeginInit();
            this.SuspendLayout();
            // 
            // gb_Connexion
            // 
            this.gb_Connexion.BackColor = System.Drawing.Color.WhiteSmoke;
            this.gb_Connexion.Controls.Add(this.btn_ConnectandDeconnect);
            this.gb_Connexion.Controls.Add(this.cb_Port);
            this.gb_Connexion.Controls.Add(this.lbl_Port);
            this.gb_Connexion.Font = new System.Drawing.Font("Stencil", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gb_Connexion.Location = new System.Drawing.Point(14, 15);
            this.gb_Connexion.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_Connexion.Name = "gb_Connexion";
            this.gb_Connexion.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_Connexion.Size = new System.Drawing.Size(403, 291);
            this.gb_Connexion.TabIndex = 0;
            this.gb_Connexion.TabStop = false;
            this.gb_Connexion.Text = "Connexion Serie";
            // 
            // btn_ConnectandDeconnect
            // 
            this.btn_ConnectandDeconnect.BackColor = System.Drawing.Color.WhiteSmoke;
            this.btn_ConnectandDeconnect.Location = new System.Drawing.Point(33, 159);
            this.btn_ConnectandDeconnect.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_ConnectandDeconnect.Name = "btn_ConnectandDeconnect";
            this.btn_ConnectandDeconnect.Size = new System.Drawing.Size(332, 72);
            this.btn_ConnectandDeconnect.TabIndex = 3;
            this.btn_ConnectandDeconnect.Text = "Connecter";
            this.btn_ConnectandDeconnect.UseVisualStyleBackColor = false;
            this.btn_ConnectandDeconnect.Click += new System.EventHandler(this.btn_ConnectandDeconnect_Click);
            // 
            // cb_Port
            // 
            this.cb_Port.BackColor = System.Drawing.Color.WhiteSmoke;
            this.cb_Port.Font = new System.Drawing.Font("Constantia", 13.8F);
            this.cb_Port.FormattingEnabled = true;
            this.cb_Port.Location = new System.Drawing.Point(182, 68);
            this.cb_Port.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.cb_Port.Name = "cb_Port";
            this.cb_Port.Size = new System.Drawing.Size(177, 43);
            this.cb_Port.TabIndex = 1;
            this.cb_Port.Text = "Sélectionner";
            // 
            // lbl_Port
            // 
            this.lbl_Port.AutoSize = true;
            this.lbl_Port.Font = new System.Drawing.Font("Constantia", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Port.Location = new System.Drawing.Point(60, 75);
            this.lbl_Port.Name = "lbl_Port";
            this.lbl_Port.Size = new System.Drawing.Size(66, 35);
            this.lbl_Port.TabIndex = 0;
            this.lbl_Port.Text = "Port";
            // 
            // gb_Ctrl_Usine
            // 
            this.gb_Ctrl_Usine.BackColor = System.Drawing.Color.WhiteSmoke;
            this.gb_Ctrl_Usine.Controls.Add(this.btn_Stop);
            this.gb_Ctrl_Usine.Controls.Add(this.lbl_etat);
            this.gb_Ctrl_Usine.Controls.Add(this.lbl_Machine);
            this.gb_Ctrl_Usine.Controls.Add(this.btn_Start);
            this.gb_Ctrl_Usine.Controls.Add(this.btn_Emergency);
            this.gb_Ctrl_Usine.Font = new System.Drawing.Font("Stencil", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gb_Ctrl_Usine.Location = new System.Drawing.Point(453, 15);
            this.gb_Ctrl_Usine.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_Ctrl_Usine.Name = "gb_Ctrl_Usine";
            this.gb_Ctrl_Usine.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_Ctrl_Usine.Size = new System.Drawing.Size(262, 291);
            this.gb_Ctrl_Usine.TabIndex = 1;
            this.gb_Ctrl_Usine.TabStop = false;
            this.gb_Ctrl_Usine.Text = "Contrôle de l\'Usine";
            // 
            // btn_Stop
            // 
            this.btn_Stop.BackColor = System.Drawing.Color.WhiteSmoke;
            this.btn_Stop.Font = new System.Drawing.Font("Stencil", 9F);
            this.btn_Stop.Location = new System.Drawing.Point(130, 112);
            this.btn_Stop.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_Stop.Name = "btn_Stop";
            this.btn_Stop.Size = new System.Drawing.Size(132, 81);
            this.btn_Stop.TabIndex = 4;
            this.btn_Stop.Text = "Arret";
            this.btn_Stop.UseVisualStyleBackColor = false;
            this.btn_Stop.Click += new System.EventHandler(this.btn_Stop_Click);
            // 
            // lbl_etat
            // 
            this.lbl_etat.AutoSize = true;
            this.lbl_etat.Font = new System.Drawing.Font("Constantia", 12F);
            this.lbl_etat.Location = new System.Drawing.Point(21, 242);
            this.lbl_etat.Name = "lbl_etat";
            this.lbl_etat.Size = new System.Drawing.Size(0, 29);
            this.lbl_etat.TabIndex = 3;
            // 
            // lbl_Machine
            // 
            this.lbl_Machine.AutoSize = true;
            this.lbl_Machine.Font = new System.Drawing.Font("Constantia", 13.8F);
            this.lbl_Machine.Location = new System.Drawing.Point(25, 201);
            this.lbl_Machine.Name = "lbl_Machine";
            this.lbl_Machine.Size = new System.Drawing.Size(212, 35);
            this.lbl_Machine.TabIndex = 2;
            this.lbl_Machine.Text = "Machine à états :";
            // 
            // btn_Start
            // 
            this.btn_Start.BackColor = System.Drawing.Color.WhiteSmoke;
            this.btn_Start.Font = new System.Drawing.Font("Stencil", 9F);
            this.btn_Start.Location = new System.Drawing.Point(3, 112);
            this.btn_Start.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_Start.Name = "btn_Start";
            this.btn_Start.Size = new System.Drawing.Size(120, 81);
            this.btn_Start.TabIndex = 1;
            this.btn_Start.Text = "Démarrer";
            this.btn_Start.UseVisualStyleBackColor = false;
            this.btn_Start.Click += new System.EventHandler(this.btn_Start_Click);
            // 
            // btn_Emergency
            // 
            this.btn_Emergency.BackColor = System.Drawing.Color.WhiteSmoke;
            this.btn_Emergency.Location = new System.Drawing.Point(3, 31);
            this.btn_Emergency.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btn_Emergency.Name = "btn_Emergency";
            this.btn_Emergency.Size = new System.Drawing.Size(255, 81);
            this.btn_Emergency.TabIndex = 0;
            this.btn_Emergency.Text = "Arrêt d\'urgence";
            this.btn_Emergency.UseVisualStyleBackColor = false;
            this.btn_Emergency.Click += new System.EventHandler(this.btn_Emergency_Click);
            // 
            // gb_Vehicule
            // 
            this.gb_Vehicule.BackColor = System.Drawing.Color.WhiteSmoke;
            this.gb_Vehicule.Controls.Add(this.rB_kg);
            this.gb_Vehicule.Controls.Add(this.rB_Lbs);
            this.gb_Vehicule.Controls.Add(this.lbl_currentUnit);
            this.gb_Vehicule.Controls.Add(this.lbl_currentWeight);
            this.gb_Vehicule.Controls.Add(this.lbl_currentcolor);
            this.gb_Vehicule.Controls.Add(this.lbl_unit);
            this.gb_Vehicule.Controls.Add(this.lbl_Poids);
            this.gb_Vehicule.Controls.Add(this.lbl_BlocColor);
            this.gb_Vehicule.Font = new System.Drawing.Font("Stencil", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gb_Vehicule.Location = new System.Drawing.Point(732, 15);
            this.gb_Vehicule.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_Vehicule.Name = "gb_Vehicule";
            this.gb_Vehicule.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_Vehicule.Size = new System.Drawing.Size(252, 291);
            this.gb_Vehicule.TabIndex = 2;
            this.gb_Vehicule.TabStop = false;
            this.gb_Vehicule.Text = "Chargement du Véhicule";
            // 
            // rB_kg
            // 
            this.rB_kg.AutoSize = true;
            this.rB_kg.Font = new System.Drawing.Font("Constantia", 12F);
            this.rB_kg.Location = new System.Drawing.Point(144, 242);
            this.rB_kg.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.rB_kg.Name = "rB_kg";
            this.rB_kg.Size = new System.Drawing.Size(66, 33);
            this.rB_kg.TabIndex = 10;
            this.rB_kg.TabStop = true;
            this.rB_kg.Text = "Kg";
            this.rB_kg.UseVisualStyleBackColor = true;
            this.rB_kg.CheckedChanged += new System.EventHandler(this.rB_kg_CheckedChanged);
            // 
            // rB_Lbs
            // 
            this.rB_Lbs.AutoSize = true;
            this.rB_Lbs.Font = new System.Drawing.Font("Constantia", 12F);
            this.rB_Lbs.Location = new System.Drawing.Point(42, 244);
            this.rB_Lbs.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.rB_Lbs.Name = "rB_Lbs";
            this.rB_Lbs.Size = new System.Drawing.Size(74, 33);
            this.rB_Lbs.TabIndex = 9;
            this.rB_Lbs.TabStop = true;
            this.rB_Lbs.Text = "Lbs";
            this.rB_Lbs.UseVisualStyleBackColor = true;
            this.rB_Lbs.CheckedChanged += new System.EventHandler(this.rB_Lbs_CheckedChanged);
            // 
            // lbl_currentUnit
            // 
            this.lbl_currentUnit.AutoSize = true;
            this.lbl_currentUnit.Font = new System.Drawing.Font("Constantia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_currentUnit.Location = new System.Drawing.Point(162, 141);
            this.lbl_currentUnit.Name = "lbl_currentUnit";
            this.lbl_currentUnit.Size = new System.Drawing.Size(38, 29);
            this.lbl_currentUnit.TabIndex = 8;
            this.lbl_currentUnit.Text = "kg";
            // 
            // lbl_currentWeight
            // 
            this.lbl_currentWeight.AutoSize = true;
            this.lbl_currentWeight.Font = new System.Drawing.Font("Constantia", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_currentWeight.Location = new System.Drawing.Point(102, 136);
            this.lbl_currentWeight.Name = "lbl_currentWeight";
            this.lbl_currentWeight.Size = new System.Drawing.Size(0, 35);
            this.lbl_currentWeight.TabIndex = 7;
            // 
            // lbl_currentcolor
            // 
            this.lbl_currentcolor.AutoSize = true;
            this.lbl_currentcolor.Font = new System.Drawing.Font("Constantia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_currentcolor.Location = new System.Drawing.Point(37, 100);
            this.lbl_currentcolor.Name = "lbl_currentcolor";
            this.lbl_currentcolor.Size = new System.Drawing.Size(0, 29);
            this.lbl_currentcolor.TabIndex = 6;
            // 
            // lbl_unit
            // 
            this.lbl_unit.AutoSize = true;
            this.lbl_unit.Font = new System.Drawing.Font("Constantia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_unit.Location = new System.Drawing.Point(88, 201);
            this.lbl_unit.Name = "lbl_unit";
            this.lbl_unit.Size = new System.Drawing.Size(83, 29);
            this.lbl_unit.TabIndex = 5;
            this.lbl_unit.Text = "Unité :";
            // 
            // lbl_Poids
            // 
            this.lbl_Poids.AutoSize = true;
            this.lbl_Poids.Font = new System.Drawing.Font("Constantia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_Poids.Location = new System.Drawing.Point(20, 143);
            this.lbl_Poids.Name = "lbl_Poids";
            this.lbl_Poids.Size = new System.Drawing.Size(82, 29);
            this.lbl_Poids.TabIndex = 4;
            this.lbl_Poids.Text = "Poids :";
            // 
            // lbl_BlocColor
            // 
            this.lbl_BlocColor.AutoSize = true;
            this.lbl_BlocColor.Font = new System.Drawing.Font("Constantia", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_BlocColor.Location = new System.Drawing.Point(20, 65);
            this.lbl_BlocColor.Name = "lbl_BlocColor";
            this.lbl_BlocColor.Size = new System.Drawing.Size(192, 29);
            this.lbl_BlocColor.TabIndex = 3;
            this.lbl_BlocColor.Text = "Couleur du Bloc :";
            // 
            // gb_View
            // 
            this.gb_View.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.gb_View.BackColor = System.Drawing.Color.WhiteSmoke;
            this.gb_View.Controls.Add(this.pB_parcour);
            this.gb_View.Font = new System.Drawing.Font("Stencil", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.gb_View.Location = new System.Drawing.Point(14, 314);
            this.gb_View.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_View.Name = "gb_View";
            this.gb_View.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gb_View.Size = new System.Drawing.Size(971, 675);
            this.gb_View.TabIndex = 2;
            this.gb_View.TabStop = false;
            this.gb_View.Text = "Usine - Véhicule et Parcours";
            // 
            // pB_parcour
            // 
            this.pB_parcour.BackColor = System.Drawing.Color.WhiteSmoke;
            this.pB_parcour.InitialImage = null;
            this.pB_parcour.Location = new System.Drawing.Point(7, 35);
            this.pB_parcour.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.pB_parcour.Name = "pB_parcour";
            this.pB_parcour.Size = new System.Drawing.Size(957, 632);
            this.pB_parcour.TabIndex = 3;
            this.pB_parcour.TabStop = false;
            // 
            // cB_Cam1
            // 
            this.cB_Cam1.Font = new System.Drawing.Font("Constantia", 13.8F);
            this.cB_Cam1.FormattingEnabled = true;
            this.cB_Cam1.Location = new System.Drawing.Point(6, 35);
            this.cB_Cam1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.cB_Cam1.Name = "cB_Cam1";
            this.cB_Cam1.Size = new System.Drawing.Size(316, 43);
            this.cB_Cam1.TabIndex = 2;
            this.cB_Cam1.Text = "Sélectionner la LiveCam1";
            this.cB_Cam1.SelectedIndexChanged += new System.EventHandler(this.cB_Cam1_SelectedIndexChanged);
            // 
            // gB_BbBdebug
            // 
            this.gB_BbBdebug.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.gB_BbBdebug.Controls.Add(this.rTB_PostePesage);
            this.gB_BbBdebug.Controls.Add(this.rTB_PosteCommande);
            this.gB_BbBdebug.Font = new System.Drawing.Font("Stencil", 10.8F);
            this.gB_BbBdebug.Location = new System.Drawing.Point(14, 996);
            this.gB_BbBdebug.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gB_BbBdebug.Name = "gB_BbBdebug";
            this.gB_BbBdebug.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.gB_BbBdebug.Size = new System.Drawing.Size(971, 280);
            this.gB_BbBdebug.TabIndex = 4;
            this.gB_BbBdebug.TabStop = false;
            this.gB_BbBdebug.Text = "BbB Debug Interface";
            // 
            // rTB_PostePesage
            // 
            this.rTB_PostePesage.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rTB_PostePesage.Location = new System.Drawing.Point(10, 156);
            this.rTB_PostePesage.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.rTB_PostePesage.Name = "rTB_PostePesage";
            this.rTB_PostePesage.Size = new System.Drawing.Size(947, 116);
            this.rTB_PostePesage.TabIndex = 5;
            this.rTB_PostePesage.Text = "";
            // 
            // rTB_PosteCommande
            // 
            this.rTB_PosteCommande.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.rTB_PosteCommande.Location = new System.Drawing.Point(10, 35);
            this.rTB_PosteCommande.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.rTB_PosteCommande.Name = "rTB_PosteCommande";
            this.rTB_PosteCommande.Size = new System.Drawing.Size(947, 108);
            this.rTB_PosteCommande.TabIndex = 4;
            this.rTB_PosteCommande.Text = "";
            // 
            // LiveCAM_gB
            // 
            this.LiveCAM_gB.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.LiveCAM_gB.BackColor = System.Drawing.Color.Transparent;
            this.LiveCAM_gB.Controls.Add(this.cB_Cam2);
            this.LiveCAM_gB.Controls.Add(this.CAMLIVE2_pB);
            this.LiveCAM_gB.Controls.Add(this.cB_Cam1);
            this.LiveCAM_gB.Controls.Add(this.CAMLIVE1_pB);
            this.LiveCAM_gB.Font = new System.Drawing.Font("Stencil", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LiveCAM_gB.ForeColor = System.Drawing.Color.Red;
            this.LiveCAM_gB.Location = new System.Drawing.Point(991, 15);
            this.LiveCAM_gB.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.LiveCAM_gB.Name = "LiveCAM_gB";
            this.LiveCAM_gB.Padding = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.LiveCAM_gB.Size = new System.Drawing.Size(1136, 1264);
            this.LiveCAM_gB.TabIndex = 5;
            this.LiveCAM_gB.TabStop = false;
            this.LiveCAM_gB.Text = "LIVECAM - Véhicule et USINE";
            // 
            // cB_Cam2
            // 
            this.cB_Cam2.Font = new System.Drawing.Font("Constantia", 13.8F);
            this.cB_Cam2.FormattingEnabled = true;
            this.cB_Cam2.Location = new System.Drawing.Point(6, 641);
            this.cB_Cam2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.cB_Cam2.Name = "cB_Cam2";
            this.cB_Cam2.Size = new System.Drawing.Size(316, 43);
            this.cB_Cam2.TabIndex = 5;
            this.cB_Cam2.Text = "Sélectionner la LiveCam2";
            this.cB_Cam2.SelectedIndexChanged += new System.EventHandler(this.cB_Cam2_SelectedIndexChanged);
            // 
            // CAMLIVE2_pB
            // 
            this.CAMLIVE2_pB.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.CAMLIVE2_pB.BackColor = System.Drawing.Color.WhiteSmoke;
            this.CAMLIVE2_pB.Location = new System.Drawing.Point(6, 641);
            this.CAMLIVE2_pB.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.CAMLIVE2_pB.Name = "CAMLIVE2_pB";
            this.CAMLIVE2_pB.Size = new System.Drawing.Size(1123, 615);
            this.CAMLIVE2_pB.TabIndex = 4;
            this.CAMLIVE2_pB.TabStop = false;
            // 
            // CAMLIVE1_pB
            // 
            this.CAMLIVE1_pB.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.CAMLIVE1_pB.BackColor = System.Drawing.Color.WhiteSmoke;
            this.CAMLIVE1_pB.Location = new System.Drawing.Point(6, 35);
            this.CAMLIVE1_pB.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.CAMLIVE1_pB.Name = "CAMLIVE1_pB";
            this.CAMLIVE1_pB.Size = new System.Drawing.Size(1123, 598);
            this.CAMLIVE1_pB.TabIndex = 3;
            this.CAMLIVE1_pB.TabStop = false;
            // 
            // frm_factory_API
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.BackgroundImage = global::Projet_final_Poste_de_commande.Properties.Resources._3R;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(2140, 1291);
            this.Controls.Add(this.LiveCAM_gB);
            this.Controls.Add(this.gB_BbBdebug);
            this.Controls.Add(this.gb_View);
            this.Controls.Add(this.gb_Vehicule);
            this.Controls.Add(this.gb_Ctrl_Usine);
            this.Controls.Add(this.gb_Connexion);
            this.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "frm_factory_API";
            this.Text = "Poste de Commamde";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.frm_factory_API_FormClosed);
            this.gb_Connexion.ResumeLayout(false);
            this.gb_Connexion.PerformLayout();
            this.gb_Ctrl_Usine.ResumeLayout(false);
            this.gb_Ctrl_Usine.PerformLayout();
            this.gb_Vehicule.ResumeLayout(false);
            this.gb_Vehicule.PerformLayout();
            this.gb_View.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pB_parcour)).EndInit();
            this.gB_BbBdebug.ResumeLayout(false);
            this.LiveCAM_gB.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.CAMLIVE2_pB)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.CAMLIVE1_pB)).EndInit();
            this.ResumeLayout(false);

    }

    #endregion

    private System.Windows.Forms.GroupBox gb_Connexion;
    private System.Windows.Forms.GroupBox gb_Ctrl_Usine;
    private System.Windows.Forms.GroupBox gb_Vehicule;
    private System.Windows.Forms.GroupBox gb_View;
    private System.Windows.Forms.Label lbl_Port;
    private System.Windows.Forms.ComboBox cb_Port;
    private System.Windows.Forms.Button btn_ConnectandDeconnect;
    private System.ComponentModel.BackgroundWorker backgroundWorker1;
    private System.Windows.Forms.Button btn_Start;
    private System.Windows.Forms.Button btn_Emergency;
    private System.Windows.Forms.Label lbl_etat;
    private System.Windows.Forms.Label lbl_Machine;
    private System.Windows.Forms.Label lbl_currentWeight;
    private System.Windows.Forms.Label lbl_currentcolor;
    private System.Windows.Forms.Label lbl_unit;
    private System.Windows.Forms.Label lbl_Poids;
    private System.Windows.Forms.Label lbl_BlocColor;
    private System.Windows.Forms.Label lbl_currentUnit;
    private System.Windows.Forms.RadioButton rB_Lbs;
    private System.Windows.Forms.RadioButton rB_kg;
    private System.Windows.Forms.ComboBox cB_Cam1;
    private System.Windows.Forms.PictureBox pB_parcour;
    private System.Windows.Forms.GroupBox gB_BbBdebug;
    private System.Windows.Forms.RichTextBox rTB_PosteCommande;
    private System.Windows.Forms.PictureBox CAMLIVE1_pB;
    private System.Windows.Forms.PictureBox CAMLIVE2_pB;
    private System.Windows.Forms.ComboBox cB_Cam2;
    private System.Windows.Forms.RichTextBox rTB_PostePesage;
    private System.Windows.Forms.Button btn_Stop;
        private System.Windows.Forms.GroupBox LiveCAM_gB;
    }
}

