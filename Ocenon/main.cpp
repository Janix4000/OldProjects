#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int rodz, maximum, n;
float srednia;
float *up, *pp;
string* oc;

void Menu(int &Tryb);
void Wpis(int &wpis);
void fWpis(float &wpis);
void PoKol(int Ile, float *TabPunkt);
void nPoKol(int Ile, float *TabPunkt);
bool SzuKopie(int* Zapisani, int Ile, int Wpisana);
void Nieobecni(int* Zapisani, int IleZapis, float* up, int Ile);
void Wczytywanie();
float Procent(float* Tab, int Numer, int Naj);
void Srednia(float* Procent, int Ile, int maximum);
string Ocena(float* Procent, int Ile);
void Wypis(string* Ocena, float* Punkty, float* Procent, int Ile, int maximum);
void Komendy (int &c, int Ile, float* up);

int main()
{
    int c=0;
    while(c<2)
    {
        c=0;
        Menu(rodz);
        if(rodz!= '4' && rodz!= '5')
        {
            cout << "Maksymalna ilosc punktow: ";
            Wpis(maximum);
            system("cls");
        }

        switch(rodz)
        {
        case '1':
        case '2':
        {
            cout << "Ilosc uczniow: ";
            Wpis(n);
            system("cls");
            up = new float [n];
            pp = new float [n+1];
            oc = new string [n+1];
            if(rodz== '1') PoKol(n, up);
            if(rodz== '2') nPoKol(n, up);
        }
        break;
        case '3':
        {
            up = new float [1];
            pp = new float [2];
            oc = new string [2];
            cout << "Punktow otrzymal: ";
            fWpis(up[0]);
            n=1;
            system("cls");
        }
        case '4':
            Wczytywanie();
            break;
        case '5':
            exit(0);
            break;

        }

        for(int i=0; i<n; i++) pp[i]=Procent(up, i, maximum);

        while(c<1)
        {
            Srednia(pp, n, maximum);
            for(int i=0; i<=n; i++) oc[i]=Ocena(pp, i);
            for(int i=0; i<n; i++) Wypis(oc, up, pp, i, maximum);
            cout << endl << endl << "Srednia tej klasy: " << oc[n] << "	  " << pp[n] << "%" << endl;
            Komendy(c, n, up);
        }

        delete [] up;
        delete [] pp;
        delete [] oc;

    }
    return 0;
}

void Menu(int &Tryb)
{
    int c=0;
    while(c<1)
    {
        cout<<"---------- MENU ----------"<<endl<<endl
            <<"Dzien dobry, jak dzisiaj liczymy?"<<endl
            <<"1. Po kolei"<<endl
            <<"2. Nie po kolei"<<endl
            <<"3. Jednego ucznia"<<endl
            <<"4. Wczytaj"<<endl
            <<"5. Wyjscie"<<endl;

        Tryb = getch();
        system("cls");

        switch(Tryb)
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
            c=1;
            break;
        default:
            ;
        }
    }
}

void Wpis(int &wpis)
{
    if(!(cin >> wpis))
    {
        cerr<<"To nie jest liczba!";
        Sleep(1000);
        exit(0);
    }
}

void fWpis(float &wpis)
{
    if(!(cin >> wpis))
    {
        cerr<<"To nie jest liczba!";
        Sleep(1000);
        exit(0);
    }
}

void PoKol(int Ile, float *TabPunkt)
{
    for(int i=0; i<Ile; i++)
    {
        cout << "Uczen nr." << i+1<<" otrzymal punktow: ";
        fWpis(TabPunkt[i]);
        system("cls");
    }
}

void nPoKol(int Ile, float *TabPunkt)
{
    int x, c=0;
    int* Zapisani;
    Zapisani= new int [Ile];

    for(int i=0; i<Ile; i++)
    {
        c=0;
        while(c<1)
        {
            cout << "Numer ucznia: ";
            Wpis(x);
            if( (x>Ile&&x!=1001)||x<1||SzuKopie(Zapisani, i, x-1)==true)
            {
                system("cls");
            }
            else c=1;
        }
        if(x==1001)
        {
            Nieobecni(Zapisani, i, TabPunkt, Ile);
            i=Ile;
            system("cls");
        }
        else
        {
            cout << "Punktow otrzymal: ";
            fWpis(TabPunkt[x-1]);
            Zapisani[i]= x-1;
            system("cls");
        }
    }
    delete [] Zapisani;
}

bool SzuKopie(int* Zapisani, int Ile, int Wpisana)
{
    bool Prawda=false;

    for(int i=0; i<Ile; i++)
    {
        if(Zapisani[i]==Wpisana)
        {
            i=Ile;
            Prawda=true;
        }
        else if(i==Ile-1) Prawda =false;
    }
    return Prawda;
}

void Nieobecni(int* Zapisani, int IleZapis, float* up, int Ile)
{
    for(int i=0; i<Ile; i++)
    {
        if(SzuKopie(Zapisani, IleZapis, i)==false) up[i]=1001;
    }
}

void Wczytywanie()
{
    int nrL=0, wWybor, wIlosc, wDecyz, wStrona;
    int N[100];
    fstream plik;
    string linia;
    string Nazwa[100];

    plik.open("Save.txt", ios::in);
    if(plik.good()==false)
    {
        cout << "Brak pliku odczytu.";
        getchar();
        exit(0);
    }

    while(!plik.eof())
    {
        getline(plik,linia);
        Nazwa[nrL]=linia;
        getline(plik,linia);
        N[nrL]=atoi( linia.c_str() );

        for(int i=0; i<=N[nrL]; i++)
        {
            getline(plik,linia);
        }
        nrL++;
    }
    plik.close();
    plik.clear();
    nrL--;

    int j=0, Lnr=0, wY=0, c=0;

    while(c<2)
    {
        while(c<1)
        {
            Lnr=Lnr+9;
            if(Lnr<=nrL)
            {
                wIlosc=9;
                c=1;
            }
            else if(Lnr>nrL+8)
            {
                j=0;
                Lnr=0;
                c=0;
            }
            else if(Lnr>nrL)
            {
                wIlosc=nrL%9;
                Lnr=nrL;
                c=1;
            }
        }
        c=0;
        int i=0;
        wStrona=nrL/9;
        if(nrL%9>0) wStrona++;
        wY++;
        if(wY>wStrona) wY=1;
        cout << "-------- STRONA " << wY << "/" << wStrona << " --------" << endl << endl;
        for(; j<Lnr; j++)
        {
            i++;
            cout<<i<<". "<<Nazwa[j]<<endl;
        }

        if(Lnr!=nrL)
        {
            cout<<endl<<"0. Nastepna strona"<<endl;
        }
        else if(nrL>9)
        {
            cout<<endl<<"0. Powrot do pierwszej strony"<<endl;
        }
        while(c<1)
        {
            wWybor= getch();
            switch(wWybor)
            {
            case '1':
            {
                wDecyz=Lnr-wIlosc;
                c=2;
            }
            break;
            case '2':
            {
                if(wIlosc<2)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-1);
                    c=2;
                }
            }
            break;
            case '3':
            {
                if(wIlosc<3)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-2);
                    c=2;
                }
            }
            break;
            case '4':
            {
                if(wIlosc<4)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-3);
                    c=2;
                }
            }
            break;
            case '5':
            {
                if(wIlosc<5)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-4);
                    c=2;
                }
            }
            break;
            case '6':
            {
                if(wIlosc<6)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-5);
                    c=2;
                }
            }
            break;
            case '7':
            {
                if(wIlosc<7)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-6);
                    c=2;
                }
            }
            break;
            case '8':
            {
                if(wIlosc<8)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-7);
                    c=2;
                }
            }
            break;
            case '9':
            {
                if(wIlosc<9)
                {
                    c=0;
                }
                else
                {
                    wDecyz=Lnr-(wIlosc-8);
                    c=2;
                }
            }
            break;
            case '0':
            {
                if(nrL<=9)
                {
                    c=0;
                }
                else
                {
                    c=1;
                }
            }
            }
        }
        system("cls");
        if(c<2) c=0;
    }
    c=0;
    plik.open("Save.txt", ios::in);
    for(int i=0; i<wDecyz; i++)
    {
        for(int z=0; z<N[i]+3; z++)
        {
            getline(plik,linia);
        }
    }
    getline(plik,linia);
    getline(plik,linia);
    n=N[wDecyz];
    getline(plik,linia);
    maximum=atoi(linia.c_str());
    up = new float [n];
    pp = new float [n+1];
    oc = new string [n+1];
    for(int i=0; i<n; i++)
    {
        getline(plik,linia);
        up[i]=atof(linia.c_str());
    }
    plik.close();
    plik.clear();
}

float Procent(float* Tab, int Numer, int Naj)
{
    if(Tab[Numer]==1001) return 1001;
    else return (Tab[Numer]/Naj)*100;
}

void Srednia(float* Procent, int Ile, int maximum)
{
    int s=Ile;
    Procent[Ile]=0;
    for(int i=0; i<Ile; i++)
    {
        if(up[i]<0||up[i]>maximum) s--;
        else Procent[Ile]+= Procent[i];
    }
    Procent[Ile]/=s;
}

string Ocena(float* Procent, int Ile)
{
    string Ocenka;
    if     (Procent[Ile]<0)  Ocenka="BLD";
    else if(Procent[Ile]<30) Ocenka="1  ";
    else if(Procent[Ile]<41) Ocenka="1+ ";
    else if(Procent[Ile]<46) Ocenka="2  ";
    else if(Procent[Ile]<49) Ocenka="2+ ";
    else if(Procent[Ile]<51) Ocenka="3- ";
    else if(Procent[Ile]<65) Ocenka="3  ";
    else if(Procent[Ile]<71) Ocenka="3+ ";
    else if(Procent[Ile]<75) Ocenka="4- ";
    else if(Procent[Ile]<81) Ocenka="4  ";
    else if(Procent[Ile]<86) Ocenka="4+ ";
    else if(Procent[Ile]<91) Ocenka="5- ";
    else if(Procent[Ile]<96) Ocenka="5  ";
    else if(Procent[Ile]<100) Ocenka="5+ ";
    else if(Procent[Ile]==100) Ocenka="6  ";
    else if(Procent[Ile]==1001) Ocenka="NOB";
    else Ocenka="BLD";

    return Ocenka;
}

void Wypis(string* Ocena, float* Punkty, float* Procent, int Ile, int maximum)
{
    cout << "Uczen nr." << Ile+1 << " otrzymal: " << Ocena[Ile];
    if(Ocena[Ile]!="NOB") cout << "     " << Punkty[Ile] << "/" << maximum;
    if((Ocena[Ile]!="NOB")&&(Ocena[Ile]!="BLD")) cout << "     " << Procent[Ile] << "%";
    cout << endl;
}

void Komendy (int &c, int Ile, float* up)
{
    string komenda;
    int x, g=0;
    fstream plik;
    cin >> komenda;

    if (komenda=="popraw" && rodz!='3')
    {
        c=1;
        while(g<1)
        {
            cout<<"Numer ucznia: ";
            Wpis(x);
            if (x<=n && x>0) g=1;
            else g=0;
        }
        cout<<"Punktow otrzymal: ";
        cin >> up[x-1];
        system("cls");
        pp[x-1] = Procent(up, x-1, maximum);
        c=0;
    }
    else if(komenda=="reset")
    {
        system("cls");
        c=1;
    }
    else if(komenda=="exit") exit(0);
    else if(komenda=="zapisz" || komenda=="save")
    {
        string nazwa;
        cout << "Nazwa: ";
        cin >> nazwa;
        plik.open ("Save.txt",ios::out | ios::app);
        plik << nazwa << endl;
        plik << n << endl;
        plik << maximum << endl;
        for (int i=0; i<n; i++) plik << up[i] << endl;
        plik.close();
        plik.clear();
        system("cls"); c=0;
    }
    else
    {
        cout << "Bledna komenda!" << endl;
        getchar();
        getchar();
        system("cls");
    }
}
