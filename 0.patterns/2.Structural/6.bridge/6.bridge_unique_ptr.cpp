/*
    Bridge
    Мост

    С unique_ptr
    
Why Use std::move() in the Code

Ownership Transfer: When you pass a std::shared_ptr<ILanguage> as a parameter, 
you typically want to transfer ownership (or shared ownership) to the receiving object. 
If you just assign it without std::move(), it would create a copy, and the original pointer would still 
hold the reference to the same object. This could lead to issues like double deletion in cases 
where ownership semantics expected only one owner.

Efficiency: Using std::move() allows the compiler to optimize since 
it can just move the internal pointer rather than clone the object. 
This can result in better performance, especially for large objects.
*/
#include <iostream>
#include <memory> // For std::unique_ptr
#include <string>
using namespace std;

// ILanguage Interface
class ILanguage {
public:
    virtual void Build() = 0;     // Pure virtual function for building
    virtual void Execute() = 0;   // Pure virtual function for executing
    virtual ~ILanguage() = default; // Virtual destructor for cleanup
};

// C++ Language Class
class CPPLanguage : public ILanguage {
public:
    void Build() override {
        cout << "С помощью компилятора C++ компилируем программу в бинарный код" << endl;
    }

    void Execute() override {
        cout << "Запускаем исполняемый файл программы" << endl;
    }
};

// C# Language Class
class CSharpLanguage : public ILanguage {
public:
    void Build() override {
        cout << "С помощью компилятора Roslyn компилируем исходный код в файл exe" << endl;
    }

    void Execute() override {
        cout << "JIT компилирует программу в бинарный код" << endl;
        cout << "CLR выполняет скомпилированный бинарный код" << endl;
    }
};

// Abstract Programmer Class
class Programmer {
protected:
    unique_ptr<ILanguage> language; // Unique pointer to ILanguage
public:
    Programmer(unique_ptr<ILanguage> lang) : language(move(lang)) {}

    virtual void DoWork() {
        language->Build();
        language->Execute();
    }

    void setLanguage(unique_ptr<ILanguage> lang) { 
        language = move(lang); 
    }

    virtual void EarnMoney() = 0; // Pure virtual function for earning money
    
    virtual ~Programmer() = default; // Virtual destructor for cleanup
};

// Freelance Programmer Class
class FreelanceProgrammer : public Programmer {
public:
    FreelanceProgrammer(unique_ptr<ILanguage> lang) : Programmer(move(lang)) {}

    void EarnMoney() override {
        cout << "Получаем оплату за выполненный заказ" << endl;
    }
};

// Corporate Programmer Class
class CorporateProgrammer : public Programmer {
public:
    CorporateProgrammer(unique_ptr<ILanguage> lang) : Programmer(move(lang)) {}

    void EarnMoney() override {
        cout << "Получаем в конце месяца зарплату" << endl;
    }
};

// Main Function
int main() {
    // Create a new freelancer programmer working with C++
    FreelanceProgrammer freelancer(make_unique<CPPLanguage>());
    freelancer.DoWork();
    freelancer.EarnMoney();

    // New request requires C#
    freelancer.setLanguage(make_unique<CSharpLanguage>());
    freelancer.DoWork();
    freelancer.EarnMoney();

    return 0; // Unique pointers clean up automatically
}