#ifndef FMH_H
#define FMH_H

# include <iostream>
# include <memory>
# include <vector>
# include "5.component.h"

using namespace std;
using PtrComponent = shared_ptr<Component>;
using VectorComponent = vector<PtrComponent>;

class Composite : public Component
{
private:
    VectorComponent vec;
public:
    Composite() = default;
    Composite(PtrComponent first, ...);

    void operation() override;

    bool isComposite() const override 
    { 
        return true; 
    }
    bool add(initializer_list<PtrComponent> list) override;
    bool remove(const iterator& it) override 
    { 
        vec.erase(it); return true; 
    }
    iterator begin() const override 
    { 
        return vec.begin(); 
    }
    iterator end() const override 
    { 
        return vec.end(); 
    }
};

Composite::Composite(PtrComponent first, ...)
{
    for (shared_ptr<Component>* ptr = &first; *ptr; ++ptr)
        vec.push_back(*ptr);
}

void Composite::operation()
{
    cout << "Composite method:" << endl;
    for (auto elem : vec)
        elem->operation();
}

bool Composite::add(initializer_list<PtrComponent> list)
{
    for (auto elem : list)
        vec.push_back(elem);
return true;
}

#endif