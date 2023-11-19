using System;

namespace Events
{
    class Program
    {
        static void Main(string[] args)
        {
            // Create an instance of the Stock class for Amazon
            Stock amazonStock = new Stock("Amazon");

            // Set the initial price of the stock
            amazonStock.Price = 100;

            // Subscribe to the OnPriceChanged event with the event handler Stock_OnPriceChanged
            amazonStock.OnPriceChanged += Stock_OnPriceChanged;

            // Simulate price changes
            amazonStock.ChangePriceBy(0.05m);
            amazonStock.ChangePriceBy(-0.02m);
            amazonStock.ChangePriceBy(0.00m);
            amazonStock.ChangePriceBy(0.07m);
            amazonStock.ChangePriceBy(0.03m);
            amazonStock.ChangePriceBy(-0.09m);
            amazonStock.ChangePriceBy(0.00m);
            amazonStock.ChangePriceBy(0.10m);

            Console.ReadKey();
        }

        // Event handler for the OnPriceChanged event
        private static void Stock_OnPriceChanged(Stock stock, decimal oldPrice)
        {
            string priceChangeDirection = DeterminePriceChangeDirection(stock.Price, oldPrice);

            // Display stock information and price change direction
            Console.WriteLine($"{stock.Name}: ${stock.Price} - {priceChangeDirection}");

            // Reset console color to default
            Console.ResetColor();
        }

        // Determines the direction of price change and sets the console color accordingly
        private static string DeterminePriceChangeDirection(decimal newPrice, decimal oldPrice)
        {
            if (newPrice > oldPrice)
            {
                Console.ForegroundColor = ConsoleColor.Green;
                return "UP";
            }
            else if (newPrice < oldPrice)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                return "Down";
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Gray;
                return "No Change";
            }
        }
    }

    // Delegate type for the Stock OnPriceChanged event
    public delegate void StockPriceChangeHandler(Stock stock, decimal oldPrice);

    // Stock class representing a stock with price-related functionality
    public class Stock
    {
        private string name;
        private decimal price;

        // Event for notifying subscribers about price changes
        public event StockPriceChangeHandler OnPriceChanged;

        // Constructor to initialize the Stock object with a name
        public Stock(string stockName)
        {
            this.name = stockName;
        }

        // Property to get the stock name
        public string Name => this.name;

        // Property for the stock price with event triggering on set
        public decimal Price
        {
            get => this.price;
            set
            {
                decimal oldPrice = this.price;
                this.price = value;

                // Notify subscribers about the price change
                OnPriceChanged?.Invoke(this, oldPrice);
            }
        }

        // Method to change the stock price by a given percentage
        public void ChangePriceBy(decimal percent)
        {
            // Calculate the new price
            decimal oldPrice = this.price;
            this.price += Math.Round(this.Price * percent, 2);

            // Check if there are subscribers before invoking the event
            // Notify subscribers about the price change
            OnPriceChanged?.Invoke(this, oldPrice);
        }
    }
}
