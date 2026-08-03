#include <iostream>
using namespace std;

class Temperature
{
private:
    float celsius;

public:
    Temperature(float c)
    {
        celsius = c;
    }

    void setTemp(float c)
    {
        celsius = c;
    }

    float toFahrenheit() const
    {
        return (celsius * 9 / 5) + 32;
    }

    float toKelvin() const
    {
        return celsius + 273.15;
    }

    friend bool areEqual(Temperature, Temperature);
};

bool areEqual(Temperature t1, Temperature t2)
{
    return t1.celsius == t2.celsius;
}

int main()
{
    Temperature t1(25);
    Temperature t2(25);

    cout << "Fahrenheit = "
         << t1.toFahrenheit() << endl;

    cout << "Kelvin = "
         << t1.toKelvin() << endl;

    if (areEqual(t1, t2))
        cout << "Both temperatures are equal\n";
    else
        cout << "Temperatures are not equal\n";

    t2.setTemp(30);

    if (areEqual(t1, t2))
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    return 0;
}
