#ifndef FM_H
#define FM_H

#include <iostream>
#include <string>
#include <memory>
#include "1.objects.h"

using namespace std;

class Developer
{
public:
    Developer(const string& n): name{n} {}
    virtual unique_ptr<House> Create() = 0;
    virtual ~Developer() = default;

protected:
    string name;
};

class PanelDeveloper: public Developer
{
public:
    PanelDeveloper(const string& n): Developer(n) {}
    unique_ptr<House> Create() override {
        return make_unique<PanelHouse>();
    }
};

class WoodDeveloper: public Developer
{
public:
    WoodDeveloper(const string& n): Developer(n) {}
    unique_ptr<House> Create() override {
        return make_unique<WoodHouse>();
    }
};

#endif