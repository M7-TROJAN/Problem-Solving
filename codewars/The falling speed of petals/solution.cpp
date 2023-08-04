double SakuraFall(double petalSpeed)
{
    const int distance = 5 * 80; // Distance in centimeters

    if (petalSpeed <= 0) return 0;

    double time = distance / petalSpeed; // Time in seconds
    return time;
}

/*
-- How did I solve the problem!?

    * by Using the formula for time distance speed
    - speed = distance ÷ time.
    - distance = speed × time.
    - time = distance ÷ speed.
*/

double SakuraFall(double Speed)
{
    return Speed <= 0 ? 0 : 400 / Speed;
}
