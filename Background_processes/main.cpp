#include<iostream>
#include<conio.h>
#include <fstream>
#include<stdlib.h>//konieczne do system tutaj
#include <string>
#include <time.h>

using namespace std;


//funkcja odpowiedzialna za wyswietlenie menu programu
int menu(int &opcja)
{
     cout<<" Wybierz opcje "<<endl;
     cout<<" <1> Atywacja wylacznika "<<endl;
     cout<<" <2> Dezaktywacja wylacznika "<<endl;
     cout<<" <3> Wyjscie " <<endl;


     cout<< " Podaj wybrana opcje: ";
     cin>> opcja;
     while(opcja<1 || opcja>3)
     {
          cout<<" Wybrales zla opcje, sprobuj jeszce raz! "<<endl;
          cin>>opcja;
     }

     cout<<endl;
     return opcja;
}

void czas(int &t)
{
     cout<<" Po jakim czasie (w min) komputer ma sie wylaczyc?"<<endl;
     cin>>t;
     while(t<1)
     {
          cout<<" Podales zla wartosc. Nalezy ustawic przynajmniej jedna minute. Sprobuj jescze raz :";
          cin>>t;
     }
     t=t*60;
}

void automaticSwitch()
{
    int opcja;
    int t;
    string komenda;

    do
    {
     system("cls"); //czyszczenie ekranu
     cout << "                    AUTOMATYCZNE WYLACZANIE KOMPUTERA                         "<<endl;
     menu(opcja);
     if(opcja==1)
        {
          czas(t);
          char czas[50];
          itoa(t,czas,10);
          komenda= "shutdown -s -t ";
          komenda += czas;
          system(komenda.c_str());
          cout<<" Nacisnij dowolny klawisz aby kontynuowac. "<<endl;
          //char a;
          //a = getch();
         }
     else
     if(opcja == 2)
     {
          system("shutdown -a");
          cout<<endl;
          cout<< " Nacisnij dowolny klawisz aby kontynuowac. "<<endl;
          //char a;
          //a = getch();
     }
     }
     while(opcja != 3);
     cout<< " Nacisnij dowolny klawisz aby kontynuowac. "<<endl;
     //wymus nacisniecie enter!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! zeby wrocic do menu glownego albo jakos inaczej wroc
}



int main()
{
    int select;
    int end = 1;

    do
    {
    cout<<" Wybierz co ma zrobic program "<<endl;
    cout<<" <1> Uruchomienie wiersza polecen "<<endl;
    cout<<" <2> Uruchomienie edytora rejestru "<<endl;
    cout<<" <3> uruchomienie eksploratora plikow " <<endl;
    cout<<" <4> Uruchomienie przegladarki Mozilla Firefox "<<endl;
    cout<<" <5> Uruchomienie Powershell'a "<<endl;
    cout<<" <6> Uruchomienie strony o Depeche Mode " <<endl;
    cout<<" <7> Automatyczne wylaczanie komputera " <<endl;
    cout<< " Podaj wybrana opcje: ";
    cin >>select;
    switch(select)
    {
                  case 1:
                       system("start cmd.exe");
                       cout << "WIERSZ POLECEN URUCHOMIONY";
                       break;
                  case 2:
                       system("start regedit.exe");
                       cout << "EDYTOR REJESTRU URUCHOMIONY";
                       break;
                  case 3:
                       system("start explorer.exe");
                       cout << "EKSPLORATOR PLIKOW URUCHOMIONY";
                       break;
                  case 4:
                       system("start firefox.exe");
                       cout << "PRZEGL¥DARKA MOZILLA FIREFOX URUCHOMIONA";
                       break;
                  case 5:
                       system("start powershell.exe");
                       cout << "POWERSHELL URUCHOMIONY";
                       break;
                  case 6:
                       system("start http://www.depechemode.com/");
                       cout << "STRONA DEPECHE MODE URUCHOMIONA";
                       break;
                  case 7:
                       automaticSwitch();
                       break;
                  default:
                       cout << "Nie ma takiej pozycji\n\n";
                       break;
    }  ;
    getch();
    system("cls");
    }while(end != 0);
}

