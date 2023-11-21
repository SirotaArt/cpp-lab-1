#include <iostream>
#include <string>
using namespace std;

int main()
{
    unsigned int n=0;
    unsigned int l=0;
    unsigned int k=0;
    string Petr = "";
    string Mauua = "";
    cin >> n;

    if (n % 4 ==1   || n % 4 == 2)
    {
        cout << "NO"<<endl;
    }
 
    else 
    {
        if (n % 4 == 0)
        {
            for (unsigned int i = 1; i <= n; i++)
            {
                if (i % 4 == 1 || i % 4 == 0)
                {
                    l += 1;
                    Petr += to_string(i)+ " ";
                }
                else 
                {
                    k += 1;
                    Mauua += to_string(i) + " ";
                }
            }
        }

        else 
        {
            for (unsigned int i = 1; i <= n; i++)
            {
                if (i % 4 == 0 || i % 4 == 3)
                {
                    l += 1;
                    Petr += to_string(i) + " ";
                }
                else
                {
                    k += 1;
                    Mauua += to_string(i) + " ";
                }
            }
        }

        cout << "YES"<< endl;
        cout << l << endl << Petr << endl << k << endl << Mauua;
    }
    system("pause");
}