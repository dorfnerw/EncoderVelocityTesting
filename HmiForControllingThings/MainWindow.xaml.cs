using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using TwinCAT;
using TwinCAT.Ads;
using TwinCAT.TypeSystem;
using TwinCAT.Ads.TypeSystem;
using System.Windows.Threading;

namespace HmiForControllingThings
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public AdsClient adsClient = new AdsClient();
        public AmsAddress amsAddress = new AmsAddress(new AmsNetId("169.254.214.231.1.1"), 350);
        dynamic symbols;
        bool Connected = false;

        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            IDynamicSymbolLoader loader;
            DynamicSymbolsCollection mainSymbols;
            try
            {
                adsClient.Connect(amsAddress);
                loader = (IDynamicSymbolLoader)SymbolLoaderFactory.Create(adsClient, SymbolLoaderSettings.DefaultDynamic);
                mainSymbols = (DynamicSymbolsCollection)loader.SymbolsDynamic;
                symbols = mainSymbols.First();
                Connected = true;
            }
            catch (Exception err)
            {
                MessageBox.Show("Error: Cannot connect to ADS client", "Error connecting to ADS client", MessageBoxButton.OK, MessageBoxImage.Error);
                Console.WriteLine(err.Message);
                Connected = false;
            }
        }

        private void DispatcherTimer_Tick(object sender, EventArgs e)
        {
            BadDataCounterBox.Text = symbols.BadDataCounter.ReadValue().ToString();
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            try
            {
                adsClient.Disconnect();
                adsClient.Dispose();
            }
            catch (Exception err)
            {
                Console.WriteLine(err.Message);
            }
        }

        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            BadDataCounterBox.Text = symbols.Started.WriteValue(true);
            if (Connected)
            {
                //  DispatcherTimer setup
                DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
                dispatcherTimer.Tick += new EventHandler(DispatcherTimer_Tick);
                dispatcherTimer.Interval = new TimeSpan(0, 0, 0, 0, 10);
                dispatcherTimer.Start();
            }
        }
    }
}

