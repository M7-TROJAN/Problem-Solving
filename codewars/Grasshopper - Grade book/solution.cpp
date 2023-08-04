char getGrade(int a, int b, int c)
{
    int average = (a + b + c) / 3 ;

    if(average >= 90) return 'A';
    if(average >= 80) return 'B';
    if(average >= 70) return 'C';
    if(average >= 60) return 'D';
    return 'F';
}

// ............................................................................

char getGrade(int a, int b, int c) {
    int avg = (a + b + c) / 3;
    switch(avg)
    {
        case 90 ... 100: return 'A';
        case 80 ... 89: return 'B';
        case 70 ... 79: return 'C';
        case 60 ... 69: return 'D';
        default: return 'F';
    }
}

// That is the case range extension of the GNU C compiler and not standard C or C++. Might cause problem in different compiler
// Remember that this is just an extension and not a part of the language.
// https://gcc.gnu.org/onlinedocs/gcc-4.1.2/gcc/Case-Ranges.html

// Good try to show your ability to dive deeply but I'd suggest not to show anything like this in real interview,
// unless you explicitly declare that this code is not portable and it's very bad idea to use this syntax in production

