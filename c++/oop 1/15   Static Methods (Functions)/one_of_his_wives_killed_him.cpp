#include <iostream>
using namespace std;

// Woman class representing different women with their information
class woman {
private:
    string _Name;
    int _Age;
    string _CarModel;

public:
    // Constant static member representing the husband's name
    const static string _HusbandName;

    // Static member indicating whether the husband is alive or not
    static bool ISHusbandAlive;

    // Constructor to initialize woman's information
    woman() {
        _Name = "Unknown";
        _Age = 0;
        _CarModel = "Unknown";
    }

    // Setter for woman's name
    void setWomanName(string name) {
        _Name = name;
    }

    // Getter for woman's name
    string getWomanName() {
        return _Name;
    }

    // Setter for woman's age
    void setWomanAge(int age) {
        _Age = age;
    }

    // Getter for woman's age
    int getWomanAge() {
        return _Age;
    }

    // Setter for woman's car model
    void setCarModel(string Model) {
        _CarModel = Model;
    }

    // Getter for woman's car model
    string getCarModel() {
        return _CarModel;
    }

    // Static method to get the husband's name
    static string getHusbandName() {
        return _HusbandName;
    }

    // Print woman's information
    void print() {
        cout << "\nWoman Info:\n";
        cout << "=========\n";
        cout << "Name: " << _Name << endl;
        cout << "Age: " << _Age << endl;
        cout << "Car Model: " << _CarModel << endl;
        cout << "Husband Name: " << _HusbandName << endl;
        cout << "Is The Husband Alive?: " << (ISHusbandAlive ? "Yes alhamdalalah" : "No, one of his wives killed him") << endl;
    }

    // Property to allow direct access to woman's name as if it were a regular variable
    _declspec(property(get = getWomanName, put = setWomanName)) string Name;

    // Property to allow direct access to woman's age as if it were a regular variable
    _declspec(property(get = getWomanAge, put = setWomanAge)) int Age;

    // Property to allow direct access to woman's car model as if it were a regular variable
    _declspec(property(get = getCarModel, put = setCarModel)) string CarModel;
};

// Static member initialization outside the class
const string woman::_HusbandName = "Mahmoud Mattar";

// Initialize the static member to true (Husband is alive) initially
bool woman::ISHusbandAlive = true;

int main() {
    // Create four instances of the woman class
    woman woman1, woman2, woman3, woman4;

    // Set information for woman1 and display her details
    woman1.setWomanName("Rahma");
    woman1.setWomanAge(22);
    woman1.setCarModel("Kia");
    woman1.print();

    // Set information for woman2 using properties and display her details
    woman2.Name = "Asmaa";
    woman2.Age = 25;
    woman2.CarModel = "BMW";
    cout << "\nWoman Info:\n";
    cout << "=========\n";
    cout << "Name: " << woman2.Name << endl;
    cout << "Age: " << woman2.Age << endl;
    cout << "Car Model: " << woman2.CarModel << endl;
    cout << "Husband Name: " << woman2._HusbandName << endl;
    cout << "Is The Husband Alive?: " << (woman::ISHusbandAlive ? "Yes alhamdalalah" : "No, one of his wives killed him") << endl;

    // Set information for woman3 and display her details
    woman3.setWomanName("Bassma");
    woman3.setWomanAge(27);
    woman3.setCarModel("Mercedes");
    cout << "\nWoman Info:\n";
    cout << "=========\n";
    cout << "Name: " << woman3.Name << endl;
    cout << "Age: " << woman3.Age << endl;
    cout << "Car Model: " << woman3.CarModel << endl;
    cout << "Husband Name: " << woman3._HusbandName << endl;
    cout << "Is The Husband Alive?: " << (woman::ISHusbandAlive ? "Yes alhamdalalah" : "No, one of his wives killed him") << endl;

    // Set information for woman4 and display her details
    woman4.setWomanName("Khulood");
    woman4.setWomanAge(25);
    woman4.setCarModel("BMW");
    woman4.print();

    // Changing the static member 'ISHusbandAlive' to false (Husband is no longer alive).
    woman::ISHusbandAlive = false;

    // Displaying the information again after the change.
    woman1.print();
    woman2.print();
    woman3.print();
    woman4.print();
}

/*
Explanation:

1- In the given code, we have a class woman representing different women with their information, including name, age, car model,
and a static member representing the husband's name and another static member indicating whether the husband is alive or not.

2- The woman class has several member functions for setting and getting information, as well as a print() method to display the woman's information.

3- The static members _HusbandName and ISHusbandAlive are declared as const static string and static bool, respectively.
The const keyword indicates that _HusbandName is constant and cannot be modified, while static means these members are shared among all instances of the woman class.

4- In the main() function, we create four instances of the woman class, named woman1, woman2, woman3, and woman4.

5- We set the information for each woman using the setter methods (setWomanName(), setWomanAge(), and setCarModel()),
and then call the print() method to display their information, including the husband's name and whether the husband is alive.

6- We can access the static members (_HusbandName and ISHusbandAlive) directly through the class name (woman::), as demonstrated in the print() method.
Alternatively, we can access static members through any instance of the class (woman2._HusbandName)
or directly using the class name without an instance (woman::ISHusbandAlive).

7- After setting the ISHusbandAlive static member to false, it reflects in all instances of the woman class,
and the print() method shows that the husband is no longer alive for all instances.

8- The code uses properties to allow direct access to member variables (Name, Age, CarModel)
as if they were regular variables, making the code more concise and readable.

Overall, the example demonstrates the usage of static members in a class, how they are shared among instances,
and how they can be accessed directly through the class name or through an instance of the class.
The use of properties simplifies the code by providing easy access to member variables.
*/