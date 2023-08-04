int seats_in_theater(int total_col, int total_row, int col, int row)
{

    // the column behind me
    col -= 1;

    int result_col = total_col - col;
    int result_row = total_row - row;

    return result_col * result_row;
}

// ........................................................................

int seats_in_theater(int total_col, int total_row, int col, int row)
{
    return (total_col - (col - 1)) * (total_row - row);
}
