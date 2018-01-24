using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tamagotchi
{
    class Wufa : Tamagotchi
    {
        // Property pet's Happiness
        public int myHappiness = 100;
        public int petHappiness
        {
            get { return myHappiness; }
            set { myHappiness = SetHappiness(value); }
        }

        //setting the pet Happiness
        private int SetHappiness(int Temp)
        {
            if (myHappiness < 5)
            {
                myHappiness = 0;
            }
            else if (myHappiness > 100)
            {
                myHappiness = 100;
            }
            else
            {
                myHappiness += Temp;
            }
            return myHappiness;
        }
        //This overrides the play function in the tamagotchi class
        public override void play()
        {
            petEnergy = 4;
            petHealth = 7;
            petHunger = -1;
            petTiredness = +3;
            petHappiness = +7;
        }


    }
}
