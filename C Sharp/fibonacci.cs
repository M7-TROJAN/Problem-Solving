using System;

internal class Program
{
    static void Main(string[] args)
    {
        Console.Write("Enter the number of Fibonacci numbers to generate: ");

        // Read user input and parse it to get the counter value
        if (int.TryParse(Console.ReadLine(), out int counter) && counter > 0)
        {
            // Fibonacci [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
            for (int i = 0, prev = 0, current = 1; i < counter; ++i)
            {
                Console.Write(prev + " ");
                int newFib = prev + current;
                prev = current;
                current = newFib;
            }
        }
        else
        {
            Console.WriteLine("Please enter a valid positive integer.");
        }

        Console.ReadKey();
    }
}
