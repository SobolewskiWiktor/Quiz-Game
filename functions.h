#ifndef know_functions
#define know_functions

#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <typeinfo>

#include "classes.h"

using namespace std;

int used[10];
int x = 0;

Question Active("Question", "Good", "One", "Two", "Three", "Four", "Number", "Type");

int get_question()
{
    string line;
    while (true)
    {
        int id_in_int = 0;
        ifstream from_question_file("questions.txt");
        if (!from_question_file)
        {
            system("cls");
            cout << "[ERROR] - Brak pliku z pytaniami !" << endl;
            Sleep(900);
        }
        srand((unsigned)time(NULL));
        int random = (rand() % 10);

        do
        {
            getline(from_question_file, line);
            string question = " ";
            string answer_one_correct = " ";
            string answer_two = " ";
            string answer_three = " ";
            string answer_four = " ";
            string id = " ";
            int length = line.length();
            int spacer = 0;
            for (int i = 0; i < length; i++)
            {
                if (line[i] == ';')
                {
                    spacer++;
                    continue;
                }
                if (spacer == 6)
                {
                    id = id + line[i];
                }
            }
            if (id != " ")
            {
                id_in_int = stoi(id);
            }
            int exist = 1;
            for (int i = 0; i < 10; i++)
            {
                if (used[i] == id_in_int)
                {
                    exist = 0;
                }
            }
            if (id_in_int == random && exist == 1)
            {
                length = line.length();
                spacer = 0;
                for (int i = 0; i < length; i++)
                {
                    if (line[i] == ';')
                    {
                        spacer++;
                        continue;
                    }
                    if (spacer == 0)
                    {
                        question = question + line[i];
                    }
                    if (spacer == 1)
                    {
                        answer_one_correct = answer_one_correct + line[i];
                    }
                    if (spacer == 2)
                    {
                        answer_two = answer_two + line[i];
                    }
                    if (spacer == 3)
                    {
                        answer_three = answer_three + line[i];
                    }
                    if (spacer == 4)
                    {
                        answer_four = answer_four + line[i];
                    }
                }
                Active.set_question(question);
                Active.set_good_answer(answer_one_correct);
                Active.set_answer_two(answer_two);
                Active.set_answer_three(answer_three);
                Active.set_answer_four(answer_four);
                used[x] = id_in_int;
                x++;
                return 0;
            }
        } while (!from_question_file.eof());
        from_question_file.close();
    }
}
void game()
{
    x = 0;
    int odpowiedz;
    int numer_pytania = 1;
    int kwota = 500;
    int kwota_gwarantowana = 0;
    int correct = 0;
    while (true)
    {
        srand((unsigned)time(NULL));
        int answer_version = (rand() % 4);
        system("cls");
        if (numer_pytania == 2)
        {
            kwota = 1000;
        }
        if (numer_pytania == 3)
        {
            kwota = 2000;
            kwota_gwarantowana = 1000;
        }
        if (numer_pytania == 4)
        {
            kwota = 5000;
        }
        if (numer_pytania == 5)
        {
            kwota = 10000;
        }
        if (numer_pytania == 6)
        {
            kwota = 20000;
        }
        if (numer_pytania == 7)
        {
            kwota = 40000;
        }
        if (numer_pytania == 8)
        {
            kwota = 75000;
            kwota_gwarantowana = 40000;
        }
        if (numer_pytania == 9)
        {
            kwota = 125000;
        }
        if (numer_pytania == 10)
        {
            kwota = 250000;
        }
        if (numer_pytania == 11)
        {
            kwota = 500000;
        }
        if (numer_pytania == 12)
        {
            kwota = 1000000;
        }
        get_question();
        cout << "Pytanie Nr: " << numer_pytania << endl;
        cout << "Walczysz o: " << kwota << " Gwarantowane: " << kwota_gwarantowana << endl;
        cout << "===================" << endl;
        cout << endl;
        cout << Active.get_question() << endl;
        if (answer_version == 0)
        {
            cout << "1: " << Active.get_good_answer() << " 2:" << Active.get_answer_two() << endl;
            cout << "3: " << Active.get_answer_three() << " 4:" << Active.get_answer_four() << endl;
            correct = 1;
        }
        if (answer_version == 1)
        {
            cout << "1: " << Active.get_answer_four() << " 2:" << Active.get_answer_two() << endl;
            cout << "3: " << Active.get_answer_three() << " 4:" << Active.get_good_answer() << endl;
            correct = 4;
        }
        if (answer_version == 2)
        {
            cout << "1: " << Active.get_answer_four() << " 2:" << Active.get_answer_two() << endl;
            cout << "3: " << Active.get_good_answer() << " 4:" << Active.get_answer_three() << endl;
            correct = 3;
        }
        if (answer_version == 3)
        {
            cout << "1: " << Active.get_answer_four() << " 2:" << Active.get_good_answer() << endl;
            cout << "3: " << Active.get_answer_two() << " 4:" << Active.get_answer_three() << endl;
            correct = 2;
        }
        cout << "Odpowiedz: ";
        cin >> odpowiedz;
        if (odpowiedz != correct)
        {
            system("cls");
            cout << "GAME OVER" << endl;
            if (kwota_gwarantowana == 0)
            {
                cout << "BRAK WYGRANEJ" << endl;
            }
            else
            {
                cout << "Wygrywasz: " << kwota_gwarantowana << endl;
            }
            Sleep(1600);
            break;
        }
        if (numer_pytania == 12)
        {
            system("cls");
            cout << "    GAME OVER   " << endl;
            cout << "WYGRYWASZ MILION" << endl;
            cout << endl;
            Sleep(1600);
            break;
        }
        numer_pytania++;
    }
}
void add_question()
{
    int ID_to_add;
    int getted_int_id;
    ifstream from_file("questions.txt");
    if (!from_file)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        while (true)
        {
            srand((unsigned)time(NULL));
            int ID_Generate = rand();
            int spacer = 0;
            int exist = 0;
            string Getted_ID;
            string line = " ";
            while (!from_file.eof())
            {
                getline(from_file, line);
                int length = line.length();
                int spacer = 0;

                for (int i = 0; i < length; i++)
                {
                    if (line[i] == ';')
                    {
                        spacer++;
                        continue;
                    }
                    if (spacer == 6)
                    {
                        Getted_ID = Getted_ID + line[i];
                    }
                }
                getted_int_id = stoi(Getted_ID);
                if (getted_int_id == ID_Generate)
                {
                    exist = 1;
                }
                spacer = 0;
                Getted_ID = " ";
            }
            from_file.close();
            if (exist == 0)
            {
                ID_to_add = ID_Generate;
                break;
            }
        }
    }
    string question = " ";
    string good_answer = " ";
    string answer_two = " ";
    string answer_three = " ";
    string answer_four = " ";
    string type = " ";
    cout << "Pytanie: ";
    cin >> question;
    cout << "Poprawna Odpowiedz: ";
    cin >> good_answer;
    cout << "Odpowiedz nr2: ";
    cin >> answer_two;
    cout << "Odpowiedz nr3: ";
    cin >> answer_three;
    cout << "Odpowiedz nr4: ";
    cin >> answer_four;
    cout << "Dziedzina: ";
    cin >> type;
    ofstream to_file("questions.txt", ios::app);
    to_file << endl
            << question << ";" << good_answer << ";" << answer_two << ";" << answer_three << ";" << answer_four << ";" << type << ";" << ID_to_add;
}
#endif
