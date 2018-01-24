using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tamagotchi
{
    public partial class frmWufa : Form
    {
        // instantiation of wufa 
        Wufa myWufa = new Wufa();
        int score = 0;
        public frmWufa()
        {       
            InitializeComponent();
            preventOverlap();
        }
        private void picBackground_Click(object sender, EventArgs e)
        {

        }

        private void timWufa_Tick(object sender, EventArgs e)
        {        
            myPetDecrease();
            Sethealth();
            SetEnergy();
            SetHunger();
            SetTiredness();
            SetHappiness();
            gameOver();
            imgSwitch();


            lblScore.Text = score.ToString();
            lblScore.Text = "Score: " + score.ToString();
        }
        public void preventOverlap()
        {
            //all the function that allow picture to overlap
            // picHealthControls();
            //  picEnergyControls();
            //picHungerControls();
            //picHappinessControls();
            //  picTirednessControls();
            //picBackground.Controls.Add(picWufa);
            picBackground.Controls.Add(picHappiness10);

        }
        //Allows all the health label to overlap the background image
        public void picHealthControls()
        {

            picBackground.Controls.Add(picHappiness10);
            picBackground.Controls.Add(picHealth9);
            picBackground.Controls.Add(picHealth8);
            picBackground.Controls.Add(picHealth7);
            picBackground.Controls.Add(picHealth6);
            picBackground.Controls.Add(picHealth5);
            picBackground.Controls.Add(picHealth4);
            picBackground.Controls.Add(picHealth3);
            picBackground.Controls.Add(picHealth2);
            picBackground.Controls.Add(picHealth1);
        }
        //Allows all the happiness label to overlap the background image
        public void picHappinessControls()
        {
            picBackground.Controls.Add(picHappiness10);
            picBackground.Controls.Add(picHappiness9);
            picBackground.Controls.Add(picHappiness8);
            picBackground.Controls.Add(picHappiness7);
            picBackground.Controls.Add(picHappiness6);
            picBackground.Controls.Add(picHappiness5);
            picBackground.Controls.Add(picHappiness4);
            picBackground.Controls.Add(picHappiness3);
            picBackground.Controls.Add(picHappiness2);
            picBackground.Controls.Add(picHappiness1);
        }
        //Allows all the energy label to overlap the background image
        public void picEnergyControls()
        {
            picBackground.Controls.Add(picEnergy10);
            picBackground.Controls.Add(picEnergy9);
            picBackground.Controls.Add(picEnergy8);
            picBackground.Controls.Add(picEnergy7);
            picBackground.Controls.Add(picEnergy6);
            picBackground.Controls.Add(picEnergy5);
            picBackground.Controls.Add(picEnergy4);
            picBackground.Controls.Add(picEnergy3);
            picBackground.Controls.Add(picEnergy2);
            picBackground.Controls.Add(picEnergy1);
        }
        //Allows all the hunger label to overlap the background image
        public void picHungerControls()
        {
            picBackground.Controls.Add(picHunger10);
            picBackground.Controls.Add(picHunger9);
            picBackground.Controls.Add(picHunger8);
            picBackground.Controls.Add(picHunger7);
            picBackground.Controls.Add(picHunger6);
            picBackground.Controls.Add(picHunger5);
            picBackground.Controls.Add(picHunger4);
            picBackground.Controls.Add(picHunger3);
            picBackground.Controls.Add(picHunger2);
            picBackground.Controls.Add(picHunger1);
        }
        //Allows all the tiredness label to overlap the background image
        public void picTirednessControls()
        {
            picBackground.Controls.Add(picTiredness10);
            picBackground.Controls.Add(picTiredness9);
            picBackground.Controls.Add(picTiredness8);
            picBackground.Controls.Add(picTiredness7);
            picBackground.Controls.Add(picTiredness6);
            picBackground.Controls.Add(picTiredness5);
            picBackground.Controls.Add(picTiredness4);
            picBackground.Controls.Add(picTiredness3);
            picBackground.Controls.Add(picTiredness2);
            picBackground.Controls.Add(picTiredness1);
        }
        //This function is responsible for hiding and showing the picHealth
        public void Sethealth()
        {

            if (myWufa.petHealth > 90 & myWufa.petHealth < 100)
            {
                lblHealth.Text = "Health: " + 10;
                picHealth10.Show();
                picHealth9.Show();
                picHealth8.Show();
                picHealth7.Show();
                picHealth6.Show();
                picHealth5.Show();
                picHealth4.Show();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
                picEnergy10.Hide();

            }
            if (myWufa.petHealth > 80 & myWufa.petHealth < 90)
            {
                lblHealth.Text = "Health: " + 9;
                picHealth10.Hide();
                picHealth9.Show();
                picHealth8.Show();
                picHealth7.Show();
                picHealth6.Show();
                picHealth5.Show();
                picHealth4.Show();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
            }
            if (myWufa.petHealth > 70 & myWufa.petHealth < 80)
            {
                lblHealth.Text = "Health: " + 8;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Show();
                picHealth7.Show();
                picHealth6.Show();
                picHealth5.Show();
                picHealth4.Show();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
            }
            if (myWufa.petHealth > 60 & myWufa.petHealth < 70)
            {
                lblHealth.Text = "Health: " + 7;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Show();
                picHealth6.Show();
                picHealth5.Show();
                picHealth4.Show();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
            }
            if (myWufa.petHealth > 50 & myWufa.petHealth < 60)
            {
                lblHealth.Text = "Health: " + 6;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Hide();
                picHealth6.Show();
                picHealth5.Show();
                picHealth4.Show();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
            }
            if (myWufa.petHealth > 40 & myWufa.petHealth < 50)
            {
                lblHealth.Text = "Health: " + 5;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Hide();
                picHealth6.Hide();
                picHealth5.Show();
                picHealth4.Show();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
            }
            if (myWufa.petHealth > 30 & myWufa.petHealth < 40)
            {
                lblHealth.Text = "Health: " + 4;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Hide();
                picHealth6.Hide();
                picHealth5.Hide();
                picHealth4.Show();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
            }

            if (myWufa.petHealth > 20 & myWufa.petHealth < 30)
            {
                lblHealth.Text = "Health: " + 3;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Hide();
                picHealth6.Hide();
                picHealth5.Hide();
                picHealth4.Hide();
                picHealth3.Show();
                picHealth2.Show();
                picHealth1.Show();
            }
            if (myWufa.petHealth > 10 & myWufa.petHealth < 20)
            {
                lblHealth.Text = "Health: " + 2;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Hide();
                picHealth6.Hide();
                picHealth5.Hide();
                picHealth4.Hide();
                picHealth3.Hide();
                picHealth2.Show();
                picHealth1.Show();
            }
            if (myWufa.petHealth > 1 & myWufa.petHealth < 10)
            {
                lblHealth.Text = "Health: " + 1;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Hide();
                picHealth6.Hide();
                picHealth5.Hide();
                picHealth4.Hide();
                picHealth3.Hide();
                picHealth2.Hide();
                picHealth1.Show();
            }
            if (myWufa.petHealth == 0)
            {
                lblHealth.Text = "Health: " + 0;
                picHealth10.Hide();
                picHealth9.Hide();
                picHealth8.Hide();
                picHealth7.Hide();
                picHealth6.Hide();
                picHealth5.Hide();
                picHealth4.Hide();
                picHealth3.Hide();
                picHealth2.Hide();
                picHealth1.Hide();
            }

        }

        //This function is responsible for hiding and showing the picHappiness
        public void SetHappiness()
        {

            if (myWufa.petHappiness > 90 & myWufa.petHappiness < 100)
            {
                lblHappiness.Text = "Happiness: " + 10;
                picHappiness10.Show();
                picHappiness9.Show();
                picHappiness8.Show();
                picHappiness7.Show();
                picHappiness6.Show();
                picHappiness5.Show();
                picHappiness4.Show();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
                picEnergy10.Hide();

            }
            if (myWufa.petHappiness > 80 & myWufa.petHappiness < 90)
            {
                lblHappiness.Text = "Happiness: " + 9;
                picHappiness10.Hide();
                picHappiness9.Show();
                picHappiness8.Show();
                picHappiness7.Show();
                picHappiness6.Show();
                picHappiness5.Show();
                picHappiness4.Show();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness > 70 & myWufa.petHappiness < 80)
            {
                lblHappiness.Text = "Happiness: " + 8;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Show();
                picHappiness7.Show();
                picHappiness6.Show();
                picHappiness5.Show();
                picHappiness4.Show();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness > 60 & myWufa.petHappiness < 70)
            {
                lblHappiness.Text = "Happiness: " + 7;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Show();
                picHappiness6.Show();
                picHappiness5.Show();
                picHappiness4.Show();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness > 50 & myWufa.petHappiness < 60)
            {
                lblHappiness.Text = "Happiness: " + 6;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Hide();
                picHappiness6.Show();
                picHappiness5.Show();
                picHappiness4.Show();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness > 40 & myWufa.petHappiness < 50)
            {
                lblHappiness.Text = "Happiness: " + 5;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Hide();
                picHappiness6.Hide();
                picHappiness5.Show();
                picHappiness4.Show();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness > 30 & myWufa.petHappiness < 40)
            {
                lblHappiness.Text = "Happiness: " + 4;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Hide();
                picHappiness6.Hide();
                picHappiness5.Hide();
                picHappiness4.Show();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
            }

            if (myWufa.petHappiness > 20 & myWufa.petHappiness < 30)
            {
                lblHappiness.Text = "Happiness: " + 3;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Hide();
                picHappiness6.Hide();
                picHappiness5.Hide();
                picHappiness4.Hide();
                picHappiness3.Show();
                picHappiness2.Show();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness > 10 & myWufa.petHappiness < 20)
            {
                lblHappiness.Text = "Happiness: " + 2;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Hide();
                picHappiness6.Hide();
                picHappiness5.Hide();
                picHappiness4.Hide();
                picHappiness3.Hide();
                picHappiness2.Show();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness > 1 & myWufa.petHappiness < 10)
            {
                lblHappiness.Text = "Happiness: " + 1;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Hide();
                picHappiness6.Hide();
                picHappiness5.Hide();
                picHappiness4.Hide();
                picHappiness3.Hide();
                picHappiness2.Hide();
                picHappiness1.Show();
            }
            if (myWufa.petHappiness == 0)
            {
                lblHappiness.Text = "Happiness: " + 0;
                picHappiness10.Hide();
                picHappiness9.Hide();
                picHappiness8.Hide();
                picHappiness7.Hide();
                picHappiness6.Hide();
                picHappiness5.Hide();
                picHappiness4.Hide();
                picHappiness3.Hide();
                picHappiness2.Hide();
                picHappiness1.Hide();
            }

        }

        //This function is responsible for hiding and showing the picEnergy
        public void SetEnergy()
        {

            if (myWufa.petEnergy > 90 & myWufa.petEnergy <= 100)
            {
                lblEnergy.Text = "Energy: " + 10;
                picEnergy10.Show();
                picEnergy9.Show();
                picEnergy8.Show();
                picEnergy7.Show();
                picEnergy6.Show();
                picEnergy5.Show();
                picEnergy4.Show();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();

            }
            if (myWufa.petEnergy > 80 & myWufa.petEnergy < 90)
            {
                lblEnergy.Text = "Energy: " + 9;
                picEnergy10.Hide();
                picEnergy9.Show();
                picEnergy8.Show();
                picEnergy7.Show();
                picEnergy6.Show();
                picEnergy5.Show();
                picEnergy4.Show();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy > 70 & myWufa.petEnergy < 80)
            {
                lblEnergy.Text = "Energy: " + 8;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Show();
                picEnergy7.Show();
                picEnergy6.Show();
                picEnergy5.Show();
                picEnergy4.Show();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy > 60 & myWufa.petEnergy < 70)
            {
                lblEnergy.Text = "Energy: " + 7;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Show();
                picEnergy6.Show();
                picEnergy5.Show();
                picEnergy4.Show();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy > 50 & myWufa.petEnergy < 60)
            {
                lblEnergy.Text = "Energy: " + 6;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Hide();
                picEnergy6.Show();
                picEnergy5.Show();
                picEnergy4.Show();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy > 40 & myWufa.petEnergy < 50)
            {
                lblEnergy.Text = "Energy: " + 5;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Hide();
                picEnergy6.Hide();
                picEnergy5.Show();
                picEnergy4.Show();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy > 30 & myWufa.petEnergy < 40)
            {
                lblEnergy.Text = "Energy: " + 4;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Hide();
                picEnergy6.Hide();
                picEnergy5.Hide();
                picEnergy4.Show();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();
            }

            if (myWufa.petEnergy > 20 & myWufa.petEnergy < 30)
            {
                lblEnergy.Text = "Energy: " + 3;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Hide();
                picEnergy6.Hide();
                picEnergy5.Hide();
                picEnergy4.Hide();
                picEnergy3.Show();
                picEnergy2.Show();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy > 10 & myWufa.petEnergy < 20)
            {
                lblEnergy.Text = "Energy: " + 2;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Hide();
                picEnergy6.Hide();
                picEnergy5.Hide();
                picEnergy4.Hide();
                picEnergy3.Hide();
                picEnergy2.Show();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy > 1 & myWufa.petEnergy < 10)
            {
                lblEnergy.Text = "Energy: " + 1;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Hide();
                picEnergy6.Hide();
                picEnergy5.Hide();
                picEnergy4.Hide();
                picEnergy3.Hide();
                picEnergy2.Hide();
                picEnergy1.Show();
            }
            if (myWufa.petEnergy == 0)
            {
                lblEnergy.Text = "Energy: " + 0;
                picEnergy10.Hide();
                picEnergy9.Hide();
                picEnergy8.Hide();
                picEnergy7.Hide();
                picEnergy6.Hide();
                picEnergy5.Hide();
                picEnergy4.Hide();
                picEnergy3.Hide();
                picEnergy2.Hide();
                picEnergy1.Hide();
            }
        }
        //This function is responsible for hiding and showing the picHunger
        public void SetHunger()
        {

            if (myWufa.petHunger > 90 & myWufa.petHunger < 100)
            {
                lblHunger.Text = "Hunger: " + 10;
                picHunger10.Show();
                picHunger9.Show();
                picHunger8.Show();
                picHunger7.Show();
                picHunger6.Show();
                picHunger5.Show();
                picHunger4.Show();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
                picHunger10.Hide();

            }
            if (myWufa.petHunger > 80 & myWufa.petHunger < 90)
            {
                lblHunger.Text = "Hunger: " + 9;
                picHunger10.Hide();
                picHunger9.Show();
                picHunger8.Show();
                picHunger7.Show();
                picHunger6.Show();
                picHunger5.Show();
                picHunger4.Show();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
            }
            if (myWufa.petHunger > 70 & myWufa.petHunger < 80)
            {
                lblHunger.Text = "Hunger: " + 8;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Show();
                picHunger7.Show();
                picHunger6.Show();
                picHunger5.Show();
                picHunger4.Show();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
            }
            if (myWufa.petHunger > 60 & myWufa.petHunger < 70)
            {
                lblHunger.Text = "Hunger: " + 7;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Show();
                picHunger6.Show();
                picHunger5.Show();
                picHunger4.Show();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
            }
            if (myWufa.petHunger > 50 & myWufa.petHunger < 60)
            {
                lblHunger.Text = "Hunger: " + 6;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Hide();
                picHunger6.Show();
                picHunger5.Show();
                picHunger4.Show();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
            }
            if (myWufa.petHunger > 40 & myWufa.petHunger < 50)
            {
                lblHunger.Text = "Hunger: " + 5;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Hide();
                picHunger6.Hide();
                picHunger5.Show();
                picHunger4.Show();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
            }
            if (myWufa.petHunger > 30 & myWufa.petHunger < 40)
            {
                lblHunger.Text = "Hunger: " + 4;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Hide();
                picHunger6.Hide();
                picHunger5.Hide();
                picHunger4.Show();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
            }

            if (myWufa.petHunger > 20 & myWufa.petHunger < 30)
            {
                lblHunger.Text = "Hunger: " + 3;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Hide();
                picHunger6.Hide();
                picHunger5.Hide();
                picHunger4.Hide();
                picHunger3.Show();
                picHunger2.Show();
                picHunger1.Show();
            }
            if (myWufa.petHunger > 10 & myWufa.petHunger < 20)
            {
                lblHunger.Text = "Hunger: " + 2;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Hide();
                picHunger6.Hide();
                picHunger5.Hide();
                picHunger4.Hide();
                picHunger3.Hide();
                picHunger2.Show();
                picHunger1.Show();
            }
            if (myWufa.petHunger > 1 & myWufa.petHunger < 10)
            {
                lblHunger.Text = "Hunger: " + 1;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Hide();
                picHunger6.Hide();
                picHunger5.Hide();
                picHunger4.Hide();
                picHunger3.Hide();
                picHunger2.Hide();
                picHunger1.Show();
            }
            if (myWufa.petHunger == 0)
            {
                lblHunger.Text = "Hunger: " + 0;
                picHunger10.Hide();
                picHunger9.Hide();
                picHunger8.Hide();
                picHunger7.Hide();
                picHunger6.Hide();
                picHunger5.Hide();
                picHunger4.Hide();
                picHunger3.Hide();
                picHunger2.Hide();
                picHunger1.Hide();
            }

        }

        //This function is responsible for hiding and showing the picTiredness
        public void SetTiredness()
        {

            if (myWufa.petTiredness > 90 & myWufa.petTiredness < 100)
            {
                lblTiredness.Text = "Tiredness: " + 10;
                picTiredness10.Show();
                picTiredness9.Show();
                picTiredness8.Show();
                picTiredness7.Show();
                picTiredness6.Show();
                picTiredness5.Show();
                picTiredness4.Show();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
                picEnergy10.Hide();

            }
            if (myWufa.petTiredness > 80 & myWufa.petTiredness < 90)
            {
                lblTiredness.Text = "Tiredness: " + 9;
                picTiredness10.Hide();
                picTiredness9.Show();
                picTiredness8.Show();
                picTiredness7.Show();
                picTiredness6.Show();
                picTiredness5.Show();
                picTiredness4.Show();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness > 70 & myWufa.petTiredness < 80)
            {
                lblTiredness.Text = "Tiredness: " + 8;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Show();
                picTiredness7.Show();
                picTiredness6.Show();
                picTiredness5.Show();
                picTiredness4.Show();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness > 60 & myWufa.petTiredness < 70)
            {
                lblTiredness.Text = "Tiredness: " + 7;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Show();
                picTiredness6.Show();
                picTiredness5.Show();
                picTiredness4.Show();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness > 50 & myWufa.petTiredness < 60)
            {
                lblTiredness.Text = "Tiredness: " + 6;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Hide();
                picTiredness6.Show();
                picTiredness5.Show();
                picTiredness4.Show();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness > 40 & myWufa.petTiredness < 50)
            {
                lblTiredness.Text = "Tiredness: " + 5;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Hide();
                picTiredness6.Hide();
                picTiredness5.Show();
                picTiredness4.Show();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness > 30 & myWufa.petTiredness < 40)
            {
                lblTiredness.Text = "Tiredness: " + 4;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Hide();
                picTiredness6.Hide();
                picTiredness5.Hide();
                picTiredness4.Show();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
            }

            if (myWufa.petTiredness > 20 & myWufa.petTiredness < 30)
            {
                lblTiredness.Text = "Tiredness: " + 3;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Hide();
                picTiredness6.Hide();
                picTiredness5.Hide();
                picTiredness4.Hide();
                picTiredness3.Show();
                picTiredness2.Show();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness > 10 & myWufa.petTiredness < 20)
            {
                lblTiredness.Text = "Tiredness: " + 2;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Hide();
                picTiredness6.Hide();
                picTiredness5.Hide();
                picTiredness4.Hide();
                picTiredness3.Hide();
                picTiredness2.Show();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness > 1 & myWufa.petTiredness < 10)
            {
                lblTiredness.Text = "Tiredness: " + 1;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Hide();
                picTiredness6.Hide();
                picTiredness5.Hide();
                picTiredness4.Hide();
                picTiredness3.Hide();
                picTiredness2.Hide();
                picTiredness1.Show();
            }
            if (myWufa.petTiredness == 0)
            {
                lblTiredness.Text = "Tiredness: " + 0;
                picTiredness10.Hide();
                picTiredness9.Hide();
                picTiredness8.Hide();
                picTiredness7.Hide();
                picTiredness6.Hide();
                picTiredness5.Hide();
                picTiredness4.Hide();
                picTiredness3.Hide();
                picTiredness2.Hide();
                picTiredness1.Hide();
            }

        }
        // This function is used to display a messagebox when the game is over
        public void gameOver()
        {
            if (myWufa.petEnergy == 0)
            {

                outputScore();
            }

            else if (myWufa.petHealth == 0)
            {
                outputScore();
            }
            else if (myWufa.petHunger == 0)
            {
                outputScore();
            }
            else if (myWufa.petHappiness == 0)
            {
                outputScore();
            }
            else if (myWufa.petTiredness == 0)
            {
                outputScore();
            }
        }
        public void outputScore()
        {
            timWufa.Stop();
            string output;

            output = string.Format("your score is: " + score.ToString());
            MessageBox.Show(output, "Game Over");


            globalClass.creatureCounter = globalClass.creatureCounter++;
        }
        //this is used to change the image 
        private void imgSwitch()
        {
            if (myWufa.petHealth > 70 && myWufa.petEnergy > 70)
            {
                picWufa.ImageLocation = @"C:\Users\saeed\Desktop\Tamagotchi\Tamagotchi\bin\Debug\Wufa Happy.png";
            }
            if (myWufa.petHealth > 40 && myWufa.petHealth <= 70)
            {
                picWufa.ImageLocation = @"C:\Users\saeed\Desktop\Tamagotchi\Tamagotchi\bin\Debug\WufaBored.png";
            }
            if (myWufa.petHealth <= 40 && myWufa.petEnergy <= 40)
            {
                picWufa.ImageLocation = @"C:\Users\saeed\Desktop\Tamagotchi\Tamagotchi\bin\Debug\WufaSad.png";
            }
        }
        private void myPetDecrease()
        {
            myWufa.petHunger = -1;
            myWufa.petHealth = -1;
            myWufa.petEnergy = -1;
            myWufa.petTiredness = -1;
            myWufa.petHappiness = -1;
        }
        private void btnStart_Click(object sender, EventArgs e)
        {
            //This will start the timer
            timWufa.Start();
        }
        private void btnPlay_Click(object sender, EventArgs e)
        {
            //this is calling the wufa play function
            myWufa.play();
        }

        private void btnFeed_Click(object sender, EventArgs e)
        {
            //This function will feed the wufa
            myWufa.feed();
            score = score + 1;
        }

        private void btnSleep_Click(object sender, EventArgs e)
        {
            //this function will let wufa go to sleep
            myWufa.sleep();
            score = score + 5;
        }

        private void BtnExit_Click(object sender, EventArgs e)
        {
            //closes the form
            this.Close();
        }
        private void frmWufa_Load(object sender, EventArgs e)
        {
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
