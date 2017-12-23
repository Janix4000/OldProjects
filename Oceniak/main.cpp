#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int rodz, n, maximum, x, c=0, s, ods=1, nrL, Lnr, wIlosc, wWybor, wDecyz, wY, wStrona;
int N[101];
float up[100];
float pp[101];
fstream plik;
string decyz, linia, nazwa;
string oc[101], Naz[101];

int main()
{
while(c<3)
	{c=0;
while(c<1){c=0;
	//MENU
	cout<<"---------- MENU ----------"<<endl<<endl
	<<"Dzien dobry, jak dzisiaj liczymy?"<<endl
	<<"1. Po kolei"<<endl
	<<"2. Nie po kolei"<<endl
	<<"3. Jednego ucznia"<<endl
	<<"4. Wczytaj"<<endl
	<<"5. Wyjscie"<<endl;
	rodz=getch();
	system("cls");
    	//WYKRYWANIE BLEDU
	switch(rodz)
	{
    	case '1':
    	case '2':
    	case '3':
    	case '4':
    	case '5':
        	c=1;
    	break;
    	//
    	default:
        	{system("cls"); cout<<"Bledna komenda"<<"\a"<<endl;}
    	break;
	}}
	c=0;
	//MAX PUNKTOW
	if((rodz!='4')&&(rodz!='5'))
	{cout<<"Max punktow ze sprawdzianu: ";
	if(!(cin >> maximum))
    	{cerr<<"To nie jest liczba!"; Sleep(2500); exit(0);}
	system("cls");}
	//WYJSCIE
	if(rodz=='5')
    	{exit(0);}
	//OPERACJA DLA WIELU UCZNIOW
	else if((rodz=='1')||(rodz=='2'))
    	{cout<<"Ilu uczniow: ";
    	if(!(cin >> n))
    	{cerr<<"To nie jest liczba!"; Sleep(2500); exit(0);}
     	system("cls");
    	//PO KOLEJI
     	if (rodz=='1')
      	{for(int i=0; i<n; i++)
       	{cout<<"Uczen nr."<<i+1<<" otrzymal punktow: ";
       	if(!(cin >> up[i]))
       	{cerr<<"To nie jest liczba!"; Sleep(2500); exit(0);}}}
    	//NIE POKOLEJI
     	else if (rodz=='2')
      	{for(int i=0; i<n; i++)
       	{cout<<"Numer ucznia: ";
       	if(!(cin >> x))
       	{cerr<<"To nie jest liczba!"; Sleep(2500); exit(0);}
        	cout<<"Punktow otrzymal: "; cin>>up[x-1];}}}
	//DLA JEDNEGO UCZNIA
	else if(rodz=='3')
     	{cout<<"Uczen otrzymal: ";
     	if(!(cin >> up[0]))
     	{cerr<<"To nie jest liczba!"; Sleep(2500); exit(0);} n=1;;}


	//WCZYTYWANIE
	else if(rodz=='4')
    	{plik.open("Save.txt", ios::in);
    	if(plik.good()==false)
        	{system("cls"); cout<<"Brak pliku";
         	getchar(); exit(0);}
nrL=0;
while(!plik.eof())
{
	getline(plik,linia); Naz[nrL]=linia;
	getline(plik,linia); N[nrL]=atoi(linia.c_str());
	for(int i=0; i<=N[nrL]; i++)
    	{getline(plik,linia);}
	nrL++;
}
plik.close(); plik.clear();
int j=0; Lnr=0; nrL--; wY=0;
while(c<2)
{
	while(c<1)
	{
    	Lnr=Lnr+9;
    	if(Lnr<=nrL){wIlosc=9; c=1;}
    	else if(Lnr>nrL+8){j=0; Lnr=0; c=0; }
    	else if(Lnr>nrL){wIlosc=nrL%9; Lnr=nrL; c=1;}
	}
	c=0; int i=0;
	wStrona=nrL/9; if(nrL%9>0){wStrona++;}
	wY++; if(wY>wStrona){wY=1;}
	cout<<"-------- STRONA "<<wY<<"/"<<wStrona<<" --------"<<endl<<endl;
	for(; j<Lnr; j++)
    	{i++; cout<<i<<". "<<Naz[j]<<endl;}
	if(Lnr!=nrL){cout<<endl<<"0. Nastepna strona"<<endl;}
	else if(nrL>9){cout<<endl<<"0. Powrot do pierwszej strony"<<endl;}
	while(c<1)
	{
    	wWybor=getch();
    	switch(wWybor)
       	{case '1': {wDecyz=Lnr-wIlosc; c=2;} break;
        	case '2': {if(wIlosc<2){c=0;} else {wDecyz=Lnr-(wIlosc-1); c=2;}} break;
        	case '3': {if(wIlosc<3){c=0;} else {wDecyz=Lnr-(wIlosc-2); c=2;}} break;
        	case '4': {if(wIlosc<4){c=0;} else {wDecyz=Lnr-(wIlosc-3); c=2;}} break;
        	case '5': {if(wIlosc<5){c=0;} else {wDecyz=Lnr-(wIlosc-4); c=2;}} break;
        	case '6': {if(wIlosc<6){c=0;} else {wDecyz=Lnr-(wIlosc-5); c=2;}} break;
        	case '7': {if(wIlosc<7){c=0;} else {wDecyz=Lnr-(wIlosc-6); c=2;}} break;
        	case '8': {if(wIlosc<8){c=0;} else {wDecyz=Lnr-(wIlosc-7); c=2;}} break;
        	case '9': {if(wIlosc<9){c=0;} else {wDecyz=Lnr-(wIlosc-8); c=2;}} break;
        	case '0': {if(nrL<=9) {c=0;} else {c=1;}}}
	}
	system("cls");
if(c<2){c=0;}
}
c=0;
plik.open("Save.txt", ios::in);
for(int i=0; i<wDecyz; i++)
	{for(int z=0; z<N[i]+3; z++)
    	{getline(plik,linia);}}
getline(plik,linia); getline(plik,linia);
n=N[wDecyz];
getline(plik,linia); maximum=atoi(linia.c_str());
for(int i=0; i<n; i++)
	{getline(plik,linia); up[i]=atof(linia.c_str());}
plik.close(); plik.clear();}
	//OBLICZANIE PROCENTU UCZNIA
while(c<2){ c=0;
	for(int i=0; i<n; i++)
  	{pp[i]=up[i];pp[i]/=maximum; pp[i]*=100;}
	//SREDNIA
	pp[n]=0; s=n;
	for(int i=0; i<n; i++)
    	{if((up[i]<0)||(up[i]>maximum))
        	{s--;}
     	else
        	{pp[n]+=pp[i];}}
	pp[n]/=s;
	//OCENIANIE
	for(int i=0;i<=n;i++)
     	{if 	(pp[i]<0){oc[i]="BLD";}
      	else if(pp[i]<30){oc[i]="1  ";}
      	else if(pp[i]<41){oc[i]="1+ ";}
      	else if(pp[i]<46){oc[i]="2  ";}
      	else if(pp[i]<49){oc[i]="2+ ";}
      	else if(pp[i]<51){oc[i]="3- ";}
      	else if(pp[i]<65){oc[i]="3  ";}
      	else if(pp[i]<71){oc[i]="3+ ";}
      	else if(pp[i]<75){oc[i]="4- ";}
      	else if(pp[i]<81){oc[i]="4  ";}
      	else if(pp[i]<86){oc[i]="4+ ";}
      	else if(pp[i]<91){oc[i]="5- ";}
      	else if(pp[i]<96){oc[i]="5  ";}
      	else if(pp[i]<100){oc[i]="5+ ";}
      	else if(pp[i]==100){oc[i]="6  ";}
      	else if(up[i]==1001){oc[i]="NOB";}
      	else {oc[i]="BLD";}}
	system("cls");
while(c<1){
	//WYPISANIE OCEN WIELU UCZNIOW
	if((rodz=='1')||(rodz=='2')||(rodz=='4'))
 	{for(int i=0; i<n; i++)
  	{cout<<"Uczen nr."<<i+1<<" dostal: "<<oc[i];
       	if(oc[i]!="NOB"){cout<<"	"<<up[i]<<"/"<<maximum;}
       	if((oc[i]!="NOB")&&(oc[i]!="BLD")){cout<<"	"<<pp[i]<<"%";}
       	cout<<endl;
       	if(ods==0){cout<<endl;}}
 	cout<<endl<<endl<<"Srednia tej klasy: "<<oc[n]<<"	"<<pp[n]<<"%"<<endl;}
 	//WYPISANIE OCENY JEDNEGO
	else if(rodz=='3')
 	{cout<<"Uczen dostal: "<<oc[0]<<"	"<<up[0]<<"/"<<maximum<<"	"<<pp[0]<<"%"<<endl;}
 	//KOMENDY
	cin>>decyz;
    	//POPRAWA
	if((decyz=="popraw")&&(rodz!='3'))
 	{c=1;
  	cout<<"Numer ucznia: ";cin>>x;
  	cout<<"Punktow otrzymal: ";cin>>up[x-1];
  	system("cls");}
    	//RESET
	else if(decyz=="reset")
 	{system("cls");c=2;}
    	//EXIT
	else if(decyz=="exit")
 	{c=3;}
	else if((decyz=="odstep")&&(rodz!='3'))
 	{ods=0; system("cls");}
	else if((decyz=="blisko")&&(rodz!='3'))
 	{ods=1; system("cls");}
	else if((decyz=="zapisz")||(decyz=="save"))
    	{cout<<"Nazwa: ";
     	cin>>nazwa;
     	plik.open("Save.txt",ios::out | ios::app);
     	plik<<nazwa<<endl;
     	plik<<n<<endl;
     	plik<<maximum<<endl;
     	for(int i=0; i<n; i++)
        	{plik<<up[i]<<endl;}
     	plik.close(); plik.clear();
     	system("cls");}
	else{system("cls");cout<<"Bledna komenda"<<"\a"<<endl;}
	}}}
	//KONIEC PROGRAMU
	return 0;
}
