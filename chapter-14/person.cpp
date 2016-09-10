#include "person.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
using std::cin;

void Person::Show() const
{
    cout << "Name: " << fname << " " << lname << endl;
}

void Person::SET()
{
    cout << "Enter first name: ";
    getline(cin, fname);
    cout << "Enter last name: ";
    getline(cin, lname);
}
void Gunslinger::Show() const
{
    Person::Show();
    cout << "This person's draw time: " << dtime << endl;
    cout << "Notches: " << notch << endl;
}

void Gunslinger::SET()
{
    Person::SET();
    cout << "Enter time: ";
    cin >> dtime;
    cout << "Enter notches: ";
    cin >> notch;
    while (cin.get() != '\n')
        continue;
}

int PokerPlayer::Draw()
{
    srand(52);
    return rand();
}

void PokerPlayer::Show()
{
    Person::Show();
    cout << "Card value: " << Draw() << endl;
}

void PokerPlayer::SET()
{
    Person::SET();
}

void BadDude::Show()
{
    Person::Show();
    cout << "Dude time: " << Gdraw() << endl;
    cout << "Card value: " << Cdraw() << endl;
}

void BadDude::SET()
{
    Gunslinger::SET();
}
