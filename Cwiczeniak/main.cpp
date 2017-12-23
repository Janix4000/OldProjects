#include <iostream>
#include <windows.h>

using namespace std;

int Ilosc, Czas, Przerwon=2500;

int main()
{
    cout << "Czas przerwy w sekundach: ";
    cin >> Czas;
    for(;;)
    {
    cout <<"Ile: ";
    cin >> Ilosc;

    system("cls"); Sleep(2500);

    for(int i=0; i<Ilosc; i++)
    {
        cout << i+1 << "\a" << endl;
        Sleep(Przerwon); system("cls");
    }
    for(int i=0; i<3; i++)  { cout << "\a"; Sleep(200); }
    Przerwon+=50;
    system("cls"); Sleep(Czas*1000);
    }

    return 0;
}
