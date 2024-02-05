#include <iostream>
using namespace std;


class Zoo
{
public:

    string Name;
    string Country;
    string Species;
    string Time;
    int Sale;
    int Count;

    Zoo()
    {
        Name = "Про100Z00";
        Country = "Russia";
        Species = "млекопитающиеся, рептилоиды";
        Time = "10:00 - 19:00";
        Sale = 300;
        Count = 123;
    }

    Zoo(const Zoo& obj)
    {
        Name = obj.Name;
        Country = obj.Country;
        Species = obj.Species;
        Time = obj.Time;
        Sale = obj.Sale;
        Count = obj.Count;
        cout << "Конструктор копирования вызван!" << "\n";
    }

    Zoo(string ZooName, string ZooCountry, string ZooSpecies, string ZooTime, int ZooSale, int ZooCount)
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
        cout << "Класс отработал" << "\n";
    }
};

void Osmotr(Zoo object, int n)
{
    string s = object.Time;
    int alltime = int(s[11] - '0') * 10 + int(s[12] - '0') + (int(s[8] - '0') * 10 + int(s[9] - '0')) * 60 - (int(s[3] - '0') * 10 + int(s[4] - '0') + (int(s[0] - '0') * 10 + int(s[1] - '0')) * 60);
    cout << alltime / n;
}

void Top(Zoo object[], int n)
{
    int* arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = (object[i].Sale) / (object[i].Count);
    }

    for (int j = 0; j < n; j++)  //Сортировка
    {
        int num_min = j;

        for (int i = j; i < n; i++)
        {
            if (arr[i] < arr[num_min])
            {
                num_min = i;
            }
        }

        int temp = arr[j];
        arr[j] = arr[num_min];
        arr[num_min] = temp;
        Zoo das = object[j];
        object[j] = object[num_min];
        object[num_min] = das;
    }

    for (int i = 0; i < n; i++)
    {
        cout << object[i].Name << " " << "\n";
    }

}

void Zoom(Zoo object[], int n, string x)
{
    for (int i = 0; i < n; i++)
    {
        if (object[i].Country == x)
        {
            cout << object[i].Name << "\n";
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Zoo One;
    Zoo Two;
    Zoo Tri;


    One.SetName("Птичий Двор");
    Two.SetName("Кормушка");
    Tri.SetSale(1000);
    Two.SetSale(500);
    Tri.SetCountry("USA");
    Tri.SetName("AmZoo");
   
    Zoo allClasses[3];
    allClasses[0] = One;
    allClasses[1] = Two;
    allClasses[2] = Tri;

    Osmotr(One, 5), cout << "\n";
    Top(allClasses, 3), cout << "\n";
    Zoom(allClasses, 3, "Russia"), cout << "\n";
    Zoo Koop(One);
    Koop.print();
    
    system("pause");
}