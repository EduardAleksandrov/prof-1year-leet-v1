#ifndef FMHH_H
#define FMHH_H

# include <memory>
# include <map>
# include "2.subject.h"

using namespace std;

class Proxy : public Subject
{
protected:
    shared_ptr<RealSubject> realsubject;
public:
    Proxy(shared_ptr<RealSubject> real) : realsubject(real) {}
};

class ConcreteProxy : public Proxy
{
private:
    map<size_t, double> cache;
public:
    using Proxy::Proxy;
    virtual pair<bool, double> request(size_t index) override;
};

pair<bool, double> ConcreteProxy::request(size_t index)
{
    pair<bool, double> result;

    if (!realsubject)
    {
        cache.clear();
        result = pair<bool, double>(false, 0.);
    }
    else if (!realsubject->changed())
    {
        cache.clear();
        result = realsubject->request(index);
        cache.insert(map<size_t, double>::value_type(index, result.second));
    }
    else
    {
        map<size_t, double>::const_iterator it = cache.find(index);
        if (it != cache.end())
        {
            result = pair<bool, double>(true, it->second);
        }
        else
        {
            result = realsubject->request(index);
            cache.insert(map<size_t, double>::value_type(index, result.second));
        }
    }
    return result;
}

#endif
