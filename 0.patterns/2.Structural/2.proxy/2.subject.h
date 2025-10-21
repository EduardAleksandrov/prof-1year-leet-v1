#ifndef FMH_H
#define FMH_H

# include <iostream>
# include <random>

using namespace std;

class Subject
{
public:
    virtual ~Subject() = default;

    virtual pair<bool, double> request(size_t index) = 0;
    virtual bool changed() 
    { 
        return true; 
    }
};

class RealSubject : public Subject
{
private:
    bool flag{ false };
    size_t counter{ 0 };
public:
    virtual pair<bool, double> request(size_t index) override;
    virtual bool changed() override;
};

bool RealSubject::changed()
{
    if (counter == 0)
    {
        flag = true;
    }
    if (++counter == 7)
    {
        counter = 0;
        flag = false;
    }
    return flag;
}

pair<bool, double> RealSubject::request(size_t index)
{
    random_device rd;
    mt19937 gen(rd());

    return pair<bool, double>(true, generate_canonical<double, 10>(gen));
}

#endif