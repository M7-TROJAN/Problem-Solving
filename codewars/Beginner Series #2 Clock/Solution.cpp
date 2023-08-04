int past(int h, int m, int s)
{
    int timeInMilliseconds = (h * 3600000) + (m * 60000) + (s * 1000);
    return timeInMilliseconds;
}

int past(int h, int m, int s)
{
    // 1second == 1000ms
    // 1minute == 60s == 60000ms
    // 1h == 60m === 3600s == 3600000ms

    return (h * 3600000) + (m * 60000) + (s * 1000);
}