#include <iostream>
using namespace std;
/*
This function calculates the profit after taxes from selling new and used phones.
parameters:
- total_phones: the total number of phones (new and used)
- used_phones: the number of used phones
- price_of_new_phone: the selling price of a new phone
- VATS: the value-added tax rate as a percentage
return:
- the profit after taxes
*/
int pricing(int total_phones, int used_phones, int price_of_new_phone, int VATS)
{
    int count_of_new_phones, price_of_used_phone, profit_before_taxes, profit_after_taxes;

    count_of_new_phones = total_phones - used_phones;

    price_of_used_phone = price_of_new_phone - 200;

    profit_before_taxes = (count_of_new_phones * price_of_new_phone) + (used_phones * price_of_used_phone);

    profit_after_taxes = profit_before_taxes * (100 - VATS) / 100;

    return profit_after_taxes;


}
int main()
{
    cout << pricing(50, 10, 800, 20) << "\n"; // 30400
    return 0;
}