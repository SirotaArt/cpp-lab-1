#include <iostream>
#include <fstream>

using namespace std;


class Matriz
{
public:

    int** a;
    int w, l;

    Matriz() //Дефолтная 2*2 с нулями
    {
        w = l = 2;
        a = new int*[w];

        for (int i = 0; i < l; i++) 
        {
            a[i] = new int [l];
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < l; j++)
            {
                 a[i][j] = 0;
            }
        }
    }  

    Matriz(int sh, int le)  //Можно задать любую sh*le с нулями
    {
        w = le;
        l = sh;
        a = new int* [w];

        for (int i = 0; i < w; i++)
        {
            a[i] = new int[l];
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < l; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    void SetNew() //Устанавливаем свою матрицу (изменяем существующую) с заполнением
    {
        
        int n, m;
        cin >> n;
        cin >> m;

        for (int i = 0; i < w; i++)
        {
            delete a[i];
        }
        w = n;
        l = m;
        a = new int* [w];

        for (int i = 0; i < w; i++)
        {
            a[i] = new int[l];
        }

        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < l; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void SetFile(string namefile) //Устанавливаем свою матрицу (изменяем существующую) считыванием файла
    {
        string path = namefile;
        ifstream fin;
        fin.open(path);
        int ch;
        int Count = 0;

        if (!fin.is_open())
        {
            cout << "Ошибка открытия файла" << "\n";
        }

        else
        {
            cout << "Файл открыт" << "\n";

            while (fin >> ch)
            {
                Count++;
            }
            cout << "Закрыт" << "\n";
            fin.close();
        }

        ifstream fin2;
        fin2.open(path);
        if (!fin2.is_open())
        {
            cout << "Ошибка открытия файла" << "\n";
        }

        else
        {
            cout << "Файл открыт" << "\n";
            int* mass = new int[Count];

            for (int i = 0; i < Count; i++)
            {
                fin2 >> mass[i];
            }

            int n, m;
            n = mass[0];
            m = mass[1];

            for (int i = 0; i < w; i++)
            {
                delete a[i];
            }
            w = n;
            l = m;
            a = new int* [w];

            for (int i = 0; i < w; i++)
            {
                a[i] = new int[l];
            }

            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    a[i][j] = mass[i * 3 + j + 2];
                }
            }

            delete[] mass;
            cout << "Закрыт" << "\n";
            fin2.close();
        }
        
    }

    void PrintFile(string namefile)
    {
        string path = namefile;
        ofstream fout;
        fout.open(path);

        if (!fout.is_open())
        {
            cout << "Ошибка записи файла" << "\n";
        }

        else
        {
            for (int i = 0; i < w; i++)
            {
                for (int j = 0; j < l; j++)
                {
                    fout << a[i][j] << " ";
                }
                fout << "\n";
            }
            cout << "Записано" << "\n";
        }

    }

    void printf()
    {
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < l; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
   
    Matriz operator* (const Matriz& D) const
    {
        Matriz A(w, D.l);
        for (int i = 0; i < D.l; i++)
        {
            for (int j = 0; j < w; j++)
            {
                A.a[i][j] = 0;
                for (int k = 0; k < D.w; k++)
                {
                    A.a[i][j] += a[i][k] * D.a[k][j];
                }
            }
        }
        return A;

    }

    Matriz operator+ (const Matriz& D) const
    {
        if (w != D.w || l != D.l)
        {
            cout << "Сложение матриц невозможно!";
        }
        else
        { 
            Matriz A(l, w);
            for (int i = 0; i < w; i++)
                for (int j = 0; j < l; j++)
                    A.a[i][j] = a[i][j] + D.a[i][j];
            return A;
        }
    }

    Matriz operator- (const Matriz& D) const
    {
        if (w != D.w || l != D.l)
        {
            cout << "Вычитание матриц невозможно!";
        }
        else
        {
            Matriz A(l, w);
            for (int i = 0; i < w; i++)
                for (int j = 0; j < l; j++)
                    A.a[i][j] = a[i][j] - D.a[i][j];
            return A;
        }
    }

    bool operator== (const Matriz& D) const
    {
        if (w != D.w || l != D.l)
        {
            return false;
        }
        else
        {
            int f = 1;
            for (int i = 0; i < w; i++)
                for (int j = 0; j < l; j++)
                    if (a[i][j] != D.a[i][j])
                    {
                        f = 0;
                    }
            if (f == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }

    bool operator!= (const Matriz& D) const
    {
        if (w != D.w || l != D.l)
        {
            return true;
        }
        else
        {
            int f = 1;
            for (int i = 0; i < w; i++)
                for (int j = 0; j < l; j++)
                    if (a[i][j] != D.a[i][j])
                    {
                        f = 0;
                    }
            if (f == 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }

    void FirstStr(int c, float k)
    {
        for (int i = 0; i < l; i++)
        {
            a[c-1][i] = a[c-1][i] * k;
        }
    }

    void FirstSb(int c, float k)
    {
        for (int i = 0; i < w; i++)
        {
            a[i][c - 1] = a[i][c - 1] * k;
        }
    }

    void SecStr(int c, int k)
    {
        int t;
        for (int i = 0; i < l; i++)
        {
            t = a[c - 1][i];
            a[c - 1][i] = a[k - 1][i];
            a[k - 1][i] = t;
        }
    }

    void SecSb(int c, int k)
    {
        int t;
        for (int i = 0; i < w; i++)
        {
            t = a[i][c - 1];
            a[i][c - 1] = a[i][k - 1];
            a[i][k - 1] = t;
        }
    }

    void ThStr(int c, int k, int g)
    {
        for (int i = 0; i < l; i++)
        {
            a[c - 1][i] = a[c - 1][i] + a[k - 1][i] * g;
        }
    }

    void ThSb(int c, int k, int g)
    {
        for (int i = 0; i < w; i++)
        {
            a[i][c - 1] = a[i][c - 1] + a[i][k - 1] * g;
        }
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    Matriz Two;
    Matriz One;
    Matriz Thr;

    One.SetNew();
    One.printf();

    One.ThSb(2, 3, 2);
    One.printf();
    system("pause");

}

