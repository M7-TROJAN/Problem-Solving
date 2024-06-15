using System;

namespace TrianglePattern
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter the number of rows: ");
            if (int.TryParse(Console.ReadLine(), out int rows))
            {
                PrintTriangle(rows);
            }
            else
            {
                Console.WriteLine("Invalid input. Please enter a valid number.");
            }

            Console.ReadKey();
        }

        static void PrintTriangle(int rows)
        {
            for (int i = 0; i < rows; i++)
            {
                // Print leading spaces
                PrintCharacters(' ', rows - i - 1);

                // Print asterisks
                PrintCharacters('*', 2 * i + 1);

                // Move to the next line
                Console.WriteLine();
            }
        }

        static void PrintCharacters(char character, int count)
        {
            for (int i = 0; i < count; i++)
            {
                Console.Write(character);
            }
        }
    }
}
