#include <iostream>
using namespace std;


class Human
{
private:
    string Name;
    string Gender;
    string Species;
    int Old;
    string Country;
    int IQ;

public:

    Human() 
    {
        Name = "Иван";
        Gender = "M";
        Species = "Human";
        Old = 30;
        Country = "Russia";
        IQ = 100;
    }

    Human(string PersonName, string PersonGender, string PersonSpecies, int PersonOld, string PersonCountry, int PersonIQ)
    {
        Name = PersonName;
        Gender = PersonGender;
        Species = PersonSpecies;
        Old = PersonOld;
        Country = PersonCountry;
        IQ = PersonIQ;
    }

    void SetAll(string PersonName, string PersonGender, string PersonSpecies, int PersonOld, string PersonCountry, int PersonIQ)
    {
        Name = PersonName;
        Gender = PersonGender;
        Species = PersonSpecies;
        Old = PersonOld;
        Country = PersonCountry;
        IQ = PersonIQ;
    }

    void SetName(string PersonName)
    {
        Name = PersonName;
    }

    void SetGender(string PersonGender)
    {
        Gender = PersonGender;
    }

    void SetSpecies(string PersonSpecies)
    {
        Species = PersonSpecies;
    }

    void SetOld(int PersonOld)
    {
        Old = PersonOld;
    }

    void SetCountry(string PersonCountry)
    {
        Country = PersonCountry;
    }

    void SetIQ(int PersonIQ)
    {
        IQ = PersonIQ;
    }

    void print()
    {
        cout << "ФИО: " << Name << endl;
        cout << "Пол: " << Gender << endl;
        cout << "Раса: " << Species << endl;
        cout << "Возраст: " << Old << endl;
        cout << "Страна: " << Country << endl;
        cout << "IQ: " << IQ << endl;
        cout << endl;
    }

    ~Human()
    {
        cout << "Класс отработал" << endl;
    }
};




int main()
{
    setlocale(LC_ALL, "Russian");
    Human Person1;
    Human Person2;
    Person1.SetAll("Артём", "М", "Human", 19, "Russia", 200);
    Person1.print();
    Person2.print();

}