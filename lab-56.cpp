#include <iostream>
using namespace std;


class Zoo
{
private:
    string Name;
    string Country;
    string Species;
    string Time;
    int Sale;
    int Count;

public:

    Zoo()
    {
        Name = "Про100Z00";
        Country = "Russia";
        Species = "млекопитающиеся, рептилоиды";
        Time = "10:00 - 19:00";
        Sale = 300;
        Count = 123
    }

    Zoo(string ZooName, string ZooCountry, string ZooSpecies, string ZooTime,  int ZooSale, int ZooCount)
    {
        Name = ZooName;
        Country = ZooCountry;
        Species = ZooSpecies;
        Time = ZooTime;
        Sale = ZooSale;
        Count = ZooCount;
    }

    void SetAll(string ZooName, string ZooCountry, string ZooSpecies, string ZooTime, int ZooSale, int ZooCount)
    {
        Name = ZooName;
        Country = ZooCountry;
        Species = ZooSpecies;
        Time = ZooTime;
        Sale = ZooSale;
        Count = ZooCount;
    }

    void SetName(string ZooName)
    {
        Name = ZooName;
    }

    void SetCountry(string ZooCountry)
    {
        Country = ZooCountry;
    }

    void SetSpecies(string ZooSpecies)
    {
        Species = ZooSpecies;
    }

    void SetTime(string ZooTime)
    {
        Time = ZooTime;
    }

    void SetSale(int ZooSale)
    {
        Sale = ZooSale;
    }
    void SetCount(int ZooCount)
    {
        Count = ZooCount;
    }

    void print()
    {
        cout << "Название: " << Name << endl;
        cout << "Страна: " << Country << endl;
        cout << "Виды животины: " << Species << endl;
        cout << "Время работы: " << Time << endl;
        cout << "Стоимость билета: " << Sale << endl;
        cout << endl;
    }

    ~Zoo()
    {
        cout << "Класс отработал" << endl;
    }
};




int main()
{
    setlocale(LC_ALL, "Russian");
    

}