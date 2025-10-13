#ifndef O_H
#define O_H

#include <iostream>
#include <memory>

// Abstract class - Weapon
class Weapon {
public:
    virtual ~Weapon() = default; // Virtual destructor for proper cleanup
    virtual void Hit() = 0; // Pure virtual function
};

// Abstract class - Movement
class Movement {
public:
    virtual ~Movement() = default; // Virtual destructor for proper cleanup
    virtual void Move() = 0; // Pure virtual function
};

// Class - Arbalet
class Arbalet : public Weapon {
public:
    void Hit() override {
        std::cout << "Стреляем из арбалета" << std::endl;
    }
};

// Class - Sword
class Sword : public Weapon {
public:
    void Hit() override {
        std::cout << "Бьем мечом" << std::endl;
    }
};

// Class - FlyMovement
class FlyMovement : public Movement {
public:
    void Move() override {
        std::cout << "Летим" << std::endl;
    }
};

// Class - RunMovement
class RunMovement : public Movement {
public:
    void Move() override {
        std::cout << "Бежим" << std::endl;
    }
};


#endif