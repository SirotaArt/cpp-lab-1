#include <iostream>
#include <fstream>
using namespace std;


class Matrix
{
public:

    int** a;
    int height, width; // высота и ширина матрицы соотв.

    Matrix() //Дефолтная 2*2 с нулями
    {
        height = width = 2;
        a = new int*[height];

        for (int i = 0; i < width; i++) 
        {
            a[i] = new int [width];
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                 a[i][j] = 0;
            }
        }
    }  

    Matrix(int w, int h)  //Можно задать любую матрицу w*h с нулями
    {
        height = h;
        width = w;
        a = new int* [height];

        for (int i = 0; i < height; i++)
        {
            a[i] = new int[width];
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    void SetNew() //Устанавливаем свою матрицу (изменяем существующую) с заполнением через консоль
    {
        
        int w, h;
        cin >> w;
        cin >> h;

        for (int i = 0; i < height; i++)
        {
            delete a[i]; //удаляем прошлую матрицу
        }

        height = h;
        width = w;
        a = new int* [height];

        for (int i = 0; i < height; i++)
        {
            a[i] = new int[width];
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    void SetFile(string namefile) //Устанавливаем свою матрицу (изменяем существующую) считыванием из файла
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

            int w, h;
            w = mass[0];
            h = mass[1];

            for (int i = 0; i < height; i++)
            {
                delete a[i];
            }

            height = h;
            width = w;
            a = new int* [height];

            for (int i = 0; i < height; i++)
            {
                a[i] = new int[width];
            }

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    a[i][j] = mass[i * width + j + 2];
                }
            }

            delete[] mass;
            cout << "Закрыт" << "\n";
            fin2.close();
        }
        
    }

    void PrintFile(string namefile) //Запись матрицы в файл
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
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    fout << a[i][j] << " ";
                }

                fout << "\n";
            }

            cout << "Записано" << "\n";
        }

    }

    void printf() //Вывод в коносль
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                cout << a[i][j] << " ";
            }

            cout << "\n";
        }
    }
   
    Matrix operator* (const Matrix& D) const
    {
        if (D.height != width)
        {
            cout << "невозможно!";
        }
        else
        {
            Matrix NewArr(D.width, height);

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < D.width; j++)
                {
                    NewArr.a[i][j] = 0;

                    for (int k = 0; k < width; k++)
                    {
                        NewArr.a[i][j] += a[i][k] * D.a[k][j];
                    }
                }
            }
            return NewArr;
        }
    }

    Matrix operator+ (const Matrix& D) const
    {
        if (height != D.height || width != D.width)
        {
            cout << "Сложение матриц невозможно!";
        }

        else
        { 
            Matrix NewArr(width, height);

            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
                    NewArr.a[i][j] = a[i][j] + D.a[i][j];

            return NewArr;
        }
    }

    Matrix operator- (const Matrix& D) const
    {
        if (height != D.height || width != D.width)
        {
            cout << "Вычитание матриц невозможно!";
        }

        else
        {
            Matrix NewArr(width, height);

            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
                    NewArr.a[i][j] = a[i][j] - D.a[i][j];

            return NewArr;
        }
    }

    bool operator== (const Matrix& D) const  //Выводит '1' - true и '0' - false
    {
        if (height != D.height || width != D.width)
        {
            return false;
        }

        else
        {
            int f = 1;

            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
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

    bool operator!= (const Matrix& D) const //Выводит '1' - true и '0' - false
    {
        if (height != D.height || width != D.width)
        {
            return true;
        }

        else
        {
            int f = 1;

            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
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

    void FirstStr(int numStr, float k) //Умножение строки на число
    {
        for (int i = 0; i < width; i++)
        {
            a[numStr - 1][i] = a[numStr - 1][i] * k;
        }
    }

    void FirstSb(int numSb, float k) //Умножение столбца на число
    {
        for (int i = 0; i < height; i++)
        {
            a[i][numSb - 1] = a[i][numSb - 1] * k;
        }
    }

    void SecStr(int numStr1, int numStr2) //Переставновка двух строк
    {
        int t;

        for (int i = 0; i < width; i++)
        {
            t = a[numStr1 - 1][i];
            a[numStr1 - 1][i] = a[numStr2 - 1][i];
            a[numStr2 - 1][i] = t;
        }
    }

    void SecSb(int numSb1, int numSb2) //Переставновка двух столбцов
    {
        int t;

        for (int i = 0; i < height; i++)
        {
            t = a[i][numSb1 - 1];
            a[i][numSb1 - 1] = a[i][numSb2 - 1];
            a[i][numSb2 - 1] = t;
        }
    }

    void ThStr(int numStr1, int numStr2, float k) //Прибавление к одной строки другой, домноженной на число
    {
        for (int i = 0; i < width; i++)
        {
            a[numStr1 - 1][i] = a[numStr1 - 1][i] + a[numStr2 - 1][i] * k;
        }
    }

    void ThSb(int numSb1, int numSb2, int k)    //Прибавление к одному столбцу другого, домноженного на число
    {
        for (int i = 0; i < height; i++)
        {
            a[i][numSb1 - 1] = a[i][numSb1 - 1] + a[i][numSb2 - 1] * k;
        }
    }

    
};

double Det(int** a, int height, int width) //Функция по поиску определителя
{
    if (height!= width)
    {
        cout << "Невозможно!";
    }
    else 
    {
        if (height == 2)
        {
            return (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
        }

        else if (height == 1)
        {
            return a[0][0];
        }

        else if (height >= 3)
        {
            int** t;
            t = new int* [height - 1];

            for (int i = 0; i < height - 1; i++)
            {
                t[i] = new int[height - 1];
            }

            double det = 0;
            int x, y;

            for (int j = 0; j < height; j++)
            {
                x = 0;

                for (int k = 1; k < height; k++)
                {
                    y = 0;

                    for (int s = 0; s < height; s++)
                    {
                        if (s != j)
                        {
                            t[x][y] = a[k][s];
                            y++;
                        }
                    }

                    x++;
                }

                det += pow(-1, (double)j + 2) * a[0][j] * Det(t, height - 1, height - 1);
            }

            return det;
        }
    }
    
}


int main()
{
    setlocale(LC_ALL, "ru"); //русификатор для консоли

    Matrix A;
    Matrix B;
    Matrix C;

    //A.printf();
    //Matrix B(3, 5);
    //B.printf();

    //A.SetNew();
    //A.printf();

    //A.SetFile("myFile.txt");
    //A.printf();
    //A.PrintFile("NomyFile.txt");

    A.SetNew();
    //B.SetNew();
    //C = (A - B);
    //C.printf();
    //cout << (A != B);

    //A.FirstStr(1, 2);
    //A.FirstSb(1, 2);
    //A.SecStr(1, 2);
    //A.SecSb(1, 2);
    //A.ThStr(1, 2, 2);
    //A.ThSb(1, 2, 2);
    //A.printf();
    cout << Det(A.a, A.height, A.width);

   

    system("pause"); //чтобы консоль не пропадала
}

