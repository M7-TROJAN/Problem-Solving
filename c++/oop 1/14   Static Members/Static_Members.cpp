// Static Members

#include <iostream>
using namespace std;
class clsA
{
public:
    int var;
    static int counter;
    clsA()
    {
        counter++;
    }
    void Print()
    {
        cout << "\nvar = " << var << endl;
        cout << "counter = " << counter << endl;
    }
};

int clsA::counter = 0; // static variable initialisation outside the class
int main()
{

    clsA A1, A2, A3;
    A1.var = 10;
    A2.var = 20;
    A3.var = 30;
    A1.Print();
    A2.Print();
    A3.Print();

    A1.counter = 500;
    cout << "\nafter changing the static member counter in one object:\n";
    A1.Print();
    A2.Print();
    A3.Print();
}

/*
الستاتيك ميمبر بيتسمي برضو شيرد ميمبر 
الستاتيك فاريبل هو جلوبال فاريبل لكل الاوبجكت وهو بيكون علي مستوي الكلاس بمعني اخر الستاتيك داتا ميمبر بيقدرر اي اوبجكت يعدل عليه
واي تعديل بيحصل عليه التعديل ده بيحصل عند الكل 
زي الس متجوز اربع نسوان كل واجدة ليها بيت خاص بيها الي هي الميموري الوكيشن بس لو واحدة قتلت جوزها بيخسروه الكل 
*/