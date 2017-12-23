#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int c=0, y;
long double wynik;
string znak;

int main()
{
    cout<<setprecision(2000);
    while(c<2)
    {
        c=0; cin>>wynik; cout<<endl;
        while(c<1)
        {
            cin>>znak; cout<<endl;
            if(znak=="reset")
                {c=1; system("cls");}
            else if(znak=="exit")
                {c=2;}
            else
            {
                cin>>y;
                if(znak=="+")
            {wynik+=y;}
                else if(znak=="-")
            {wynik-=y;}
                 else if(znak=="*")
            {wynik*=y;}
                 else if((znak=="/")||(znak==":"))
            {wynik/=y;}
            system("cls");
            cout<<wynik<<endl;
            }
        }
    }
    return 0;
}
