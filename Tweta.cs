using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tamagotchi
{
    class Tweta : Tamagotchi
    {
        public void Fly()
        {
            petEnergy = -2;
            petHealth = +1;
            petHunger = +3;
            petTiredness = +5;
        }

    }
}
