/*
    Decorator
    Декоратор
*/
# include <iostream>
# include <memory>

using namespace std;

class Component
{
public:
    virtual ~Component() = default;
    virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
public:
    void operation() override 
    { 
        cout << "ConcreteComponent; "; 
    }
};

class Decorator : public Component
{
protected:
    shared_ptr<Component> component;
public:
    Decorator(shared_ptr<Component> comp) : component(comp) {}
};

class ConcreteDecorator : public Decorator
{
public:
    using Decorator::Decorator;
    void operation() override;
};

void ConcreteDecorator::operation()
{
    if (component)
    {
        component->operation();
        cout << "ConDecorator; ";
    }
}


int main()
{
    shared_ptr<Component> component = make_shared<ConcreteComponent>();
    shared_ptr<Component> decorator1 = make_shared<ConcreteDecorator>(component);

    decorator1->operation();
    cout << endl;

    shared_ptr<Component> decorator2 = make_shared<ConcreteDecorator>(decorator1);

    decorator2->operation();
    cout << endl;

    return 0;
}