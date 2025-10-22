/*
    Bridge
    Мост
*/
#include <iostream>
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
    ILanguage* language; // Pointer to ILanguage
public:
    Programmer(ILanguage* lang) : language(lang) {}

    virtual void DoWork() {
        language->Build();
        language->Execute();
    }

    void setLanguage(ILanguage* lang) { 
        delete language;
        language = lang; 
    }

    virtual void EarnMoney() = 0; // Pure virtual function for earning money
    
    virtual ~Programmer()
    {
        delete language;
        cout << "destruct language" << endl;
    }; // Virtual destructor for cleanup
};

// Freelance Programmer Class
class FreelanceProgrammer : public Programmer {
public:
    FreelanceProgrammer(ILanguage* lang) : Programmer(lang) {}

    void EarnMoney() override {
        cout << "Получаем оплату за выполненный заказ" << endl;
    }
};

// Corporate Programmer Class
class CorporateProgrammer : public Programmer {
public:
    CorporateProgrammer(ILanguage* lang) : Programmer(lang) {}

    void EarnMoney() override {
        cout << "Получаем в конце месяца зарплату" << endl;
    }
};

// Main Function
int main() {
    // Create a new freelancer programmer working with C++
    FreelanceProgrammer freelancer(new CPPLanguage());
    freelancer.DoWork();
    freelancer.EarnMoney();

    // New request requires C#
    freelancer.setLanguage(new CSharpLanguage());
    freelancer.DoWork();
    freelancer.EarnMoney();

    // Clean up dynamically allocated memory
    // delete freelancer.getLanguage();
    
    return 0;
}