int rental_car_cost(int d)
{
    return d >= 7 ? d * 40 - 50 : d >= 3 ? d * 40 - 20 : d * 40;
}