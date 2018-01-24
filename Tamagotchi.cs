using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tamagotchi
{
    class Tamagotchi
    {

        // Property pet's name
        protected string myName;

        public string petName
        {
            get { return myName; }
            set { myName = (value); }
        }

        // property pets's color
        private string myColour;
        public string petColour
        {
            get { return myColour; }
            set { myColour = (value); }
        }

        // Property pet's Energy
        public int myEnergy;
        public int petEnergy
        {
            get { return myEnergy; }
            set { myEnergy = SetEnergy(value); }
        }

        //setting the pet energy
        private int SetEnergy(int Temp)
        {
            if (myEnergy < 5)
            {
                myEnergy = 0;
            }
            else if (myEnergy > 100)
            {
                myEnergy = 100;
            }
            else
            {
                myEnergy += Temp;
            }
            return myEnergy;
        }

        // Property pet's weight
        protected int myWeight;

        public int petWeight
        {
            get { return myWeight; }
            set { myWeight = SetWeight(value); }
        }
        //setting the pet Weight
        private int SetWeight(int Temp)
        {
            if (myWeight < 5)
            {
                myWeight = 0;
            }
            else if (myWeight > 100)
            {
                myWeight = 100;
            }
            else
            {
                myWeight += Temp;
            }
            return myWeight;
        }

        // Property pet's health
        private int myHealth;

        public int petHealth
        {
            get { return myHealth; }
            set { myHealth = SetHealth(value); }
        }

        //setting the pet energy
        private int SetHealth(int Temp)
        {
            if (myHealth < 5)
            {
                myHealth = 0;
            }
            else if (myHealth > 100)
            {
                myHealth = 100;
            }
            else
            {
                myHealth += Temp;
            }
            return myHealth;
        }


        // Property pet's tiredness
        private int myTiredness;

        public int petTiredness
        {
            get { return myTiredness; }
            set { myTiredness = SetTiredness(value); }
        }

        //setting the pet tiredness
        private int SetTiredness(int Temp)
        {
            if (myTiredness < 5)
            {
                myTiredness = 0;
            }
            else if (myTiredness > 100)
            {
                myTiredness = 100;
            }
            else
            {
                myTiredness += Temp;
            }
            return myTiredness;
        }


        // Property pet's hunger
        private int myHunger;

        public int petHunger
        {
            get { return myHunger; }
            set { myHunger = setHunger(value); }
        }
        //setting the pet tiredness
        private int setHunger(int Temp)
        {
            if (myHunger < 5)
            {
                myHunger = 0;
            }
            else if (myHunger > 100)
            {
                myHunger = 100;
            }
            else
            {
                myHunger += Temp;
            }
            return myHunger;
        }

        //Constructor Health
        public Tamagotchi()
        {
            myHealth = 100;
            myEnergy = 100;
            myHunger = 100;
            myTiredness = 100;
            myWeight = 100;

        }
        // this function will feed the Wufa pet
        public virtual void feed()
        {
            petEnergy = +7;
            petHealth = +10;
            petHunger = +9;
            petTiredness = -3;


        }
        // this function will sleep the Wufa pet
        public virtual void sleep()
        {
            petEnergy = +5;
            petHealth = -4;
            petHunger = +5;
            petTiredness = +10;
        }
        // this function will play the Wufa pet
        public virtual void play()
        {
            petEnergy = 4;
            petHealth = 7;
            petHunger = -1;
            petTiredness = +3;
        }

    }
}
