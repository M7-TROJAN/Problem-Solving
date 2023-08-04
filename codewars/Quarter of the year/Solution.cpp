/*
Given a month as an integer from 1 to 12, return to which quarter of the year it belongs as an integer number.
For example: month 2 (February), is part of the first quarter; month 6 (June), is part of the second quarter;
and month 11 (November), is part of the fourth quarter.
Constraint:
    1 <= month <= 12
*/

int quarter_of(int month)
{
    // using mathematical logic
    return (month + 2) / 3;
    // ....................................................................

    // using ternary operator
    return month <= 3 ? 1 : month <=6 ? 2 : month <= 9 ? 3 : 4;
    // ....................................................................

    // using switch
    switch (month)
    {
    case 1:
    case 2:
    case 3:
        return 1;
    case 4:
    case 5:
    case 6:
        return 2;
    case 7:
    case 8:
    case 9:
        return 3;
    case 10:
    case 11:
    case 12:
        return 4;
    }
    // ....................................................................

    // using if condition
    if (month <= 3)
        return 1;
    else if (month <= 6)
        return 2;
    else if (month <= 9)
        return 3;
    else
        return 4;
}