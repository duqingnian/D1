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
    public partial class frmSplashScreen : Form
    {
        public frmSplashScreen()
        {
            InitializeComponent();
            //This sets the timer with a 2 second interval.
            this.Controls.Add(pictureBox1);
            timSplash = new System.Windows.Forms.Timer();
            timSplash.Interval = 2000;
            imgChange();
        }

        private void frmSplashScreen_Load(object sender, EventArgs e)
        {

        }
        public void imgChange()
        {
            //This if statement will change images when the form is loading
            timSplash.Tick += (sender, args) =>
            {
                if (pictureBox1.ImageLocation == @"E:\Tamagotchi\Tamagotchi\bin\Debug\Adventure Image.png")
                {
                    pictureBox1.ImageLocation = @"E:\Tamagotchi\Tamagotchi\bin\Debug\SplashScreenImage.jpg";
                }
                else if (pictureBox1.ImageLocation == @"E:\Tamagotchi\Tamagotchi\bin\Debug\SplashScreenImage.jpg")
                {
                    pictureBox1.ImageLocation = @"E:\Tamagotchi(original)\Tamogotchi\Tamogotchi\Resources\SplashScreenImage.jpg";
                }

                else if (pictureBox1.ImageLocation == @"E:\Tamagotchi(original)\Tamogotchi\Tamogotchi\Resources\SplashScreenImage.jpg")
                {
                    pictureBox1.ImageLocation = @"E:\Tamagotchi\Tamagotchi\bin\Debug\creatureBac.jpg";
                }
            };
            timSplash.Start();
            pictureBox1.ImageLocation = @"E:\Tamagotchi\Tamagotchi\bin\Debug\Adventure Image.png";
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
