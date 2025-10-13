#ifndef FMH_H
#define FMH_H

#include <iostream>
#include <string>
#include <memory>
#include "2.objects.h"

// Abstract factory class
class HeroFactoryT {
public:
    virtual ~HeroFactoryT() = default; // Virtual destructor for proper cleanup
    virtual std::unique_ptr<Movement> CreateMovement() = 0; // Pure virtual function
    virtual std::unique_ptr<Weapon> CreateWeapon() = 0; // Pure virtual function
};

template<typename T, typename V>
class FactoryT : public HeroFactoryT {
public:
    std::unique_ptr<Movement> CreateMovement() override {
        return std::make_unique<T>();
    }
   
    std::unique_ptr<Weapon> CreateWeapon() override {
        return std::make_unique<V>();
    }
};


#endif