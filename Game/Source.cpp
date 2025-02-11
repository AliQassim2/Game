﻿#include<iostream>
using namespace std;

void draw();
void replace(int, char);
bool checkAvailability(int);
bool checkWinner(char player);
void initializeCharacters();

char c1, c2, c3, c4, c5, c6, c7, c8, c9;
char currentPlayer = 'X';


int main0()
{
    while (true)
    {
        initializeCharacters();
        cout << "أهلاً بك في لعبة ال X-O  مجدداً" << endl << endl;
        draw();

        int input;
        int counter = 0;

        while (true)
        {
            cout << "دور " << currentPlayer << endl;
            cin >> input;

            while (!checkAvailability(input))
            {
                cout << "الرقم الذي أدخلته إما أنه غير صحيح، أو أنه محجوز" << endl;
                cout << "قم بإدخال رقماً آخراً" << endl;
                cin >> input;
            }


            if (counter % 2 == 0)
            {
                replace(input, currentPlayer);
                currentPlayer = 'O';
            }
            else
            {
                replace(input, currentPlayer);
                currentPlayer = 'X';
            }
            counter++;
            draw();


            if (checkWinner('X') || checkWinner('O'))
            {
                cout << "هل تريد إعادة اللعبة?" << endl;
                break;
            }
            else if (counter == 9)
            {
                cout << "تعادل" << endl;
                break;
            }

        }

        cout << "هل تود مواصلة اللعب؟" << endl;
        cout << "1- continue" << endl;
        cout << "2- exit" << endl;
        cin >> input;
        if (input == 1)
        {
            continue;
        }
        else
        {
            exit(0);
        }

    }

}

void initializeCharacters()
{
    c1 = '1';
    c2 = '2';
    c3 = '3';
    c4 = '4';
    c5 = '5';
    c6 = '6';
    c7 = '7';
    c8 = '8';
    c9 = '9';
}

// ترسم اللوحة
void draw() {
    cout << "\t" << c1 << "\t|\t" << c2 << "\t|\t" << c3 << endl;
    cout << "\t---------------------------------\n";
    cout << "\t" << c4 << "\t|\t" << c5 << "\t|\t" << c6 << endl;
    cout << "\t---------------------------------\n";
    cout << "\t" << c7 << "\t|\t" << c8 << "\t|\t" << c9 << endl;
    cout << endl;
}

// تقوم باستبدال الرقم المدخل بإما  x or o
void replace(int i, char c)
{

    switch (i)
    {
    case 1:
        c1 = c;
        break;
    case 2:
        c2 = c;
        break;
    case 3:
        c3 = c;
        break;
    case 4:
        c4 = c;
        break;
    case 5:
        c5 = c;
        break;
    case 6:
        c6 = c;
        break;
    case 7:
        c7 = c;
        break;
    case 8:
        c8 = c;
        break;
    case 9:
        c9 = c;
        break;

    }

}

// تقوم هذه الدالة بإرجاع 
// true: إن كان المدخل input صحيحاً
// false : إن كان المدخل خاطئاً
bool checkAvailability(int input)
{
    if (input < 1 || input > 9)
        return false;

    switch (input)
    {
    case 1:
        if (c1 == '1')
            return true;
        break;
    case 2:
        if (c2 == '2')
            return true;
        break;
    case 3:
        if (c3 == '3')
            return true;
        break;
    case 4:
        if (c4 == '4')
            return true;
        break;
    case 5:
        if (c5 == '5')
            return true;
        break;
    case 6:
        if (c6 == '6')
            return true;
        break;
    case 7:
        if (c7 == '7')
            return true;
        break;
    case 8:
        if (c8 == '8')
            return true;
        break;
    case 9:
        if (c9 == '9')
            return true;
        break;

    }
    return false;
}





// تقوم بإرجاع 
// true: إن كان هناك فائز سواء x or o 
// false: إن لم تجد فائز 
bool checkWinner(char player)
{
    // التأكد أن الصفوف أحدها تساوي ال X 
    bool ro1 = (c1 == player && c2 == player && c3 == player);
    bool ro2 = (c4 == player && c5 == player && c6 == player);
    bool ro3 = (c7 == player && c8 == player && c9 == player);

    // التأكد أن الإعمدة أحدها تساوي ال X 
    bool cl1 = (c1 == player && c4 == player && c7 == player);
    bool cl2 = (c2 == player && c5 == player && c8 == player);
    bool cl3 = (c3 == player && c6 == player && c9 == player);

    // التأكد أن القطران أحدها تساوي ال X 
    bool di1 = (c1 == player && c5 == player && c9 == player);
    bool di2 = (c3 == player && c5 == player && c7 == player);

    if (ro1 || ro2 || ro3 || cl1 || cl2 || cl3 || di1 || di2)
    {

        cout << player << " هو الفائز" << endl;

        return true;
    }
    return false;

}

