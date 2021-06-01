using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Proiect_3
{
    public partial class Form1 : Form
    {
        int n, m;
        double[] x = new double [12];
        double[] y = new double [12];
        double[] z = new double [12];
        double h;
        
        public Form1()
        {
            InitializeComponent();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
  
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            // calculam numarul de puncte si le afisam in tabelul interpolarii Newton II la caz discret
            m = (int)numericUpDown2.Value;
            dataGridView2.ColumnCount = m;
            double v = -9;
            for (int k = 0; k < m; k++)
            {
                z[k] = v + k * 2;
                dataGridView2[k, 0].Value = z[k];
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // calc tab interpolarii dupa formula 2 Newton 
            int i, j;
            double Pn = 0, q, t;
            double[] difFin = new double[12];
            dataGridView3.RowCount = m;
      
            difFin[0] = y[n - 1];

    

            for (i = 1; i < n; i++)
            {
               for (j = 0; j < n - i; j++)
                {
                    y[j] = y[j + 1] - y[j];
                }

                difFin[i] = y[n - 1 - i];
            }
            // DifIn
            dataGridView7.ColumnCount = n;
            for (i = 0; i < n; i++)
            {
                dataGridView7[i, 0].Value = difFin[i];
            }
            // Pn
            for (int k = 0; k < m; k++)
            {
                t = (z[k] - x[n - 1]) / h; 
              
                Pn = difFin[0];
                q = 1;
                for (i = 1; i < n; i++)
                {
                    
                    q = q * (t + i - 1) / i;
                  
                    Pn = Pn + q * difFin[i];

                }
                dataGridView3[0, k].Value = "z" + k.ToString();
                dataGridView3[1, k].Value = z[k].ToString();
                dataGridView3[2, k].Value = Pn.ToString();
            }
        }

        double g(double x)
        {
            // functia dup var meu
            return Math.Exp(x) * Math.Log(x);
        }

        private void numericUpDown4_ValueChanged(object sender, EventArgs e)
        {
            // calculam nr de noduri si le afisam in tabelul baza interpolarii la functia complexa
            n = (int)numericUpDown4.Value;
            // h = double.Parse(textBox3.Text);
            h = 0.2;
            x[0] = double.Parse(textBox4.Text);
            dataGridView6.RowCount = n;
            dataGridView6[0, 0].Value = "x0";
            dataGridView6[1, 0].Value = x[0];
            for (int i = 1; i < n; i++)
            {
                dataGridView6[0, i].Value = "x" + i.ToString();
                x[i] = x[i - 1] + h;
                dataGridView6[1, i].Value = x[i];
            }

            for (int i = 0; i < n; i++)
            {
                dataGridView6[2, i].Value = y[i] = g(x[i]);
            }
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            // calculam numarul de puncte si le afisam in tabelul interpolarii Newton II la functia complexa
            m = (int)numericUpDown3.Value;
            dataGridView5.ColumnCount = m;
            z[0] = 3; z[1] = 3.2; z[2] = 3.4; z[3] = 3.6;
            z[4] = 3.8; z[5] = 4; z[6] = 4.2; z[7] = 4.4;
            z[8] = 4.6; z[9] = 4.8;
            for (int k = 0; k < m; k++)
            {  
                dataGridView5[k, 0].Value = z[k];
            }
        }


        private void button2_Click(object sender, EventArgs e)
        {
            // calculam tabelul interpolarii dupa formula 2 Newton cu datele din tabelul baza interpolarii
            // de asemenea calculam conform functiei g* / delta
            int i, j;
            double Pn = 0, q, t, delta;
            double[] difFin = new double[12];
            dataGridView4.RowCount = m;
            // calculam diferente fin
            difFin[0] = y[n - 1];

            for (i = 1; i < n; i++)
            {
                for (j = 0; j < n - i; j++)
                {
                    y[j] = y[j + 1] - y[j];
                }

                difFin[i] = y[n - 1 - i];
            }
            // Calcul Pn
            for (int k = 0; k < m; k++)
            {
                t = (z[k] - x[n - 1]) / h;

                Pn = difFin[0];
                q = 1;
                for (i = 1; i < n; i++)
                {

                    q = q * (t + i - 1) / i;

                    Pn = Pn + q * difFin[i];

                }
                dataGridView4[0, k].Value = "z" + k.ToString();
                dataGridView4[1, k].Value = z[k].ToString();
                dataGridView4[2, k].Value = Pn.ToString();
                dataGridView4[3, k].Value = g(z[k]).ToString();
                delta = Math.Abs(g(z[k]) - Pn);
                dataGridView4[4, k].Value = delta.ToString("E2");
            }
    }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            // calculam nr de noduri si le afisam in tabelul baza interpolarii la caz discret
            n = (int)numericUpDown1.Value;
            h = double.Parse(textBox2.Text);
            x[0] = double.Parse(textBox1.Text);

            for (int i = 1; i < n; i++)
            {
                x[i] = x[i - 1] + h;

            }
            dataGridView1.RowCount = n;       
            for (int i = 0; i < n; i++)
            {
                dataGridView1[0, i].Value = "x" + i.ToString();
                dataGridView1[1, i].Value = x[i];
                y[i] = Math.Pow(x[i], 5) + 4 * Math.Pow(x[i], 4) + 3 * Math.Pow(x[i], 3)
                    + Math.Pow(x[i], 2) + 96 * x[i] + 65;         
      
                dataGridView1[2, i].Value = y[i];
            }
        }
    }
}
