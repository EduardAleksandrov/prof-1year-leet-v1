#ifndef FM_H
#define FM_H

# include <iostream>
# include <memory>
# include <vector>

class Component;

using namespace std;
using PtrComponent = shared_ptr<Component>;
using VectorComponent = vector<PtrComponent>;

class Component
{
public:
    using value_type = Component;
    using size_type = size_t;
    using iterator = VectorComponent::const_iterator;
    using const_iterator = VectorComponent::const_iterator;

    virtual ~Component() = default;

    virtual void operation() = 0;

    virtual bool isComposite() const 
    { 
        return false; 
    }
    virtual bool add(initializer_list<PtrComponent> comp) 
    { 
        return false; 
    }
    virtual bool remove(const iterator& it) 
    { 
        return false; 
    }
    virtual iterator begin() const 
    { 
        return iterator(); 
    }
    virtual iterator end() const 
    { 
        return iterator(); 
    }
};

class Figure : public Component
{
public:
    virtual void operation() override 
    { 
        cout << "Figure method;" << endl; 
    }
};

class Camera : public Component
{
public:
    virtual void operation() override 
    { 
        cout << "Camera method;" << endl; 
    }
};
#endif