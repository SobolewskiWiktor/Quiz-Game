#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdio>

#include "functions.h"
#include "classes.h"


using namespace std; 

int main()
{
     while (true)
     {
        system("cls");
     int wybor = 0; 
     cout<<"  _== MENU ==_  "<<endl;
     cout<<endl;
     cout<<"1. GRAJ" <<endl;
     cout<<"2. Dodaj pytanie"<<endl;
     cout<<"3. Wyjdz"<<endl;
     cin >> wybor;
     switch (wybor)
     {
      case 1:
      {
        system("cls");
        game(); 
        break;
      }
      case 2:
      {
        system("cls");
        add_question();
        break;
      }
      case 3:
      {
        system("cls");
        cout<<"Dziekujemy za gre <3 Do zobaczenia !"<<endl;
        Sleep(1000);
        return 0; 
        break;
      }
     
     default:
     {
        system("cls");
        cout<<"[ERROR] - Wybierz poprawna opcje"<<endl;
        Sleep(900);
     }
     }
     }
     
         return 0; 
}
