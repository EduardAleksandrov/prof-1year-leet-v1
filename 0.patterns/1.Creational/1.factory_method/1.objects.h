#ifndef O_H
#define O_H

#include <iostream>
using namespace std;

class House
{

};

class PanelHouse: public House
{
public:
    PanelHouse()
    {
        cout << "Панельный дом построен" << endl;
    }
};

class WoodHouse: public House
{
public:
    WoodHouse()
    {
        cout << "Деревянный дом построен" << endl;
    }
};

#endif