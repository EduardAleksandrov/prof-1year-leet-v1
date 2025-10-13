/*
    Abstract factory
    Абстрактная фабрика
*/
#include <iostream>
#include <memory>

#include "2.objects.h"
#include "2.abstract_factory.h"
#include "2.abstract_factory_template.h"

// Hero class definition
class Hero {
public:
    Hero(HeroFactory&factory) {
        weapon = factory.CreateWeapon();
        movement = factory.CreateMovement();
    }

    void Run() {
        movement->Move();
    }

    void Hit() {
        weapon->Hit();
    }

private:
    std::unique_ptr<Weapon> weapon;   // Use unique_ptr for automatic memory management
    std::unique_ptr<Movement> movement; // Use unique_ptr for automatic memory management
};

// композиция
class HeroTwo {
public:
    HeroTwo(std::shared_ptr<HeroFactoryT>& factory) {
        weapon = factory->CreateWeapon();
        movement = factory->CreateMovement();
    }

    void Run() {
        movement->Move();
    }

    void Hit() {
        weapon->Hit();
    }

private:
    std::unique_ptr<Weapon> weapon;   // Use unique_ptr for automatic memory management
    std::unique_ptr<Movement> movement; // Use unique_ptr for automatic memory management
};

int main() {
    // Create an elf hero
    ElfFactory elfFactory;
    Hero elf(elfFactory); // Direct object creation instead of unique_ptr for simplicity
    elf.Hit();  // Outputs: Стреляем из арбалета
    elf.Run();  // Outputs: Летим

    // Create a warrior hero
    VoinFactory voinFactory;
    Hero voin(voinFactory); // Direct object creation instead of unique_ptr for simplicity
    voin.Hit(); // Outputs: Бьем мечом
    voin.Run(); // Outputs: Бежим


    // using template
    std::shared_ptr<HeroFactoryT> ptr = std::make_shared<FactoryT<RunMovement, Arbalet>>();
    std::unique_ptr<HeroTwo> Herop = std::make_unique<HeroTwo>(ptr);
    Herop->Hit();
    Herop->Run();

    return 0;
}