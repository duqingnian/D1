using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Tamagotchi
{
    public partial class frmStart : Form
    {
        public frmStart()
        {
            // Close the frmSplashscreen in 8 seconds
            Thread t = new Thread(new ThreadStart(startForm));
            t.Start();
            Thread.Sleep(8000);
            InitializeComponent();
            t.Abort();
        }
        // run the splashScreen form
        public void startForm()
        {
           
            Application.Run(new frmSplashScreen());
        }
        private void btnStart_Click(object sender, EventArgs e)
        {
            // Call the creature form Panel
            frmCreaturePanel StaToCreature = new frmCreaturePanel();
            StaToCreature.Show();
            this.Hide();
        }

        private void frmStart_Load(object sender, EventArgs e)
        {

        }
    }
}
