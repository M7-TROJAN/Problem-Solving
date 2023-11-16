using System;

public class Sudoku
{
    private readonly int[,] board;
    private readonly Random random;

    public Sudoku()
    {
        // Initialize the Sudoku board and the Random object
        board = new int[9, 9];
        random = new Random();
        Initialize();
    }

    private void Initialize()
    {
        // Generate a random Sudoku board
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Generate a random number between 1 and 9
                int randomNumber = random.Next(1, 10);
                board[i, j] = randomNumber;
            }
        }
    }

    // Indexer for accessing and modifying Sudoku board values
    public int this[uint row, uint col]
    {
        get
        {
            if (row < 9 && col < 9)
                return board[row, col];
            else
                throw new ArgumentOutOfRangeException("Invalid matrix indices.");
        }
        set
        {
            // Check if the provided indices are within the valid range
            // Check if the value being set is between 1 and 9
            if (row < 9 && col < 9 && value >= 1 && value <= 9)
                board[row, col] = value;
            else
                throw new ArgumentOutOfRangeException("Invalid matrix indices or value.");
        }
    }


    // Print the Sudoku board
    public void PrintBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                Console.Write($"{board[i, j]} ");
            }
            Console.WriteLine();
        }
    }
}

class Program
{
    static void Main()
    {

        Sudoku sudoku = new Sudoku();

        sudoku.PrintBoard();


        Console.WriteLine($"\nValue at index 4, 4: {sudoku[4, 4]}");
    }
}
