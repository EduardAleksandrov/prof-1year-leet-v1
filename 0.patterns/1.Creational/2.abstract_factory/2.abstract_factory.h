#ifndef FM_H
#define FM_H

#include <iostream>
#include <string>
#include <memory>
#include "2.objects.h"

// Abstract factory class
class HeroFactory {
public:
    virtual ~HeroFactory() = default; // Virtual destructor for proper cleanup
    virtual std::unique_ptr<Movement> CreateMovement() = 0; // Pure virtual function
    virtual std::unique_ptr<Weapon> CreateWeapon() = 0; // Pure virtual function
};

// Factory for creating flying hero with a crossbow
class ElfFactory : public HeroFactory {
public:
    std::unique_ptr<Movement> CreateMovement() override {
        return std::make_unique<FlyMovement>();
    }
   
    std::unique_ptr<Weapon> CreateWeapon() override {
        return std::make_unique<Arbalet>();
    }
};

// Factory for creating running hero with a sword
class VoinFactory : public HeroFactory {
public:
    std::unique_ptr<Movement> CreateMovement() override {
        return std::make_unique<RunMovement>();
    }
   
    std::unique_ptr<Weapon> CreateWeapon() override {
        return std::make_unique<Sword>();
    }
};

#endif