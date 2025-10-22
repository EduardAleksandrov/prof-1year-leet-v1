/*
    Builder
    Строитель
*/
#include <iostream>
#include <string>
#include <sstream>
#include <memory>

// Forward declarations
class Flour;
class Salt;
class Additives;
class Bread;
class breadBuilder;

// Мука
class Flour {
public:
    std::string Sort;

    Flour(const std::string& sort) : Sort(sort) {}
};

// Соль
class Salt {
public:
    Salt() {}
};

// Пищевые добавки
class Additives {
public:
    std::string Name;

    Additives(const std::string& name) : Name(name) {}
};

// Буханка хлеба
class Bread {
public:
    Flour* flour = nullptr;
    Salt* salt = nullptr;
    Additives* additives = nullptr;

    ~Bread() {
        delete flour;
        delete salt;
        delete additives;
    }

    std::string toString() const {
        std::ostringstream oss;

        if (flour != nullptr)
            oss << flour->Sort << "\n";
        if (salt != nullptr)
            oss << "Соль \n";
        if (additives != nullptr)
            oss << "Добавки: " << additives->Name << " \n";
        
        return oss.str();
    }
};

// Абстрактный класс строителя
class BreadBuilder {
protected:
    std::shared_ptr<Bread> bread;

public:
    BreadBuilder() {
        bread = std::make_unique<Bread>();
    }

    virtual ~BreadBuilder() = default;

    virtual void SetFlour() = 0;
    virtual void SetSalt() = 0;
    virtual void SetAdditives() = 0;

    std::shared_ptr<Bread> getBread() {
        return bread;
    }
};

// Строитель для ржаного хлеба
class RyeBreadBuilder : public BreadBuilder {
public:
    void SetFlour() override {
        bread->flour = new Flour("Ржаная мука 1 сорт");
    }

    void SetSalt() override {
        bread->salt = new Salt();
    }

    void SetAdditives() override {
        // не используется
    }
};

// Строитель для пшеничного хлеба
class WheatBreadBuilder : public BreadBuilder {
public:
    void SetFlour() override {
        bread->flour = new Flour("Пшеничная мука высший сорт");
    }

    void SetSalt() override {
        bread->salt = new Salt();
    }

    void SetAdditives() override {
        bread->additives = new Additives("улучшитель хлебопекарный");
    }
};

// Пекарь
class Baker {
public:
    std::shared_ptr<Bread> Bake(std::shared_ptr<BreadBuilder>& breadBuilder) {
        breadBuilder->SetFlour();
        breadBuilder->SetSalt();
        breadBuilder->SetAdditives();
        return breadBuilder->getBread();
    }
};

int main() {
    // Создаем объект пекаря
    Baker baker;

    // Создаем билдер для ржаного хлеба
    std::shared_ptr<BreadBuilder> ryeBuilder = std::make_shared<RyeBreadBuilder>();
    std::shared_ptr<Bread> ryeBread = baker.Bake(ryeBuilder);
    std::cout << ryeBread->toString();

    // Создаем билдер для пшеничного хлеба
    std::shared_ptr<BreadBuilder> wheatBuilder = std::make_shared<WheatBreadBuilder>();
    std::shared_ptr<Bread> wheatBread = baker.Bake(wheatBuilder);
    std::cout << wheatBread->toString();

    return 0;
}
