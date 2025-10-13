#ifndef FMH_H
#define FMH_H

template <typename T>
class AllDeveloper
{
public:
    AllDeveloper(const string& n): name{n} {}
    virtual unique_ptr<T> Create() = 0;
    virtual ~AllDeveloper() = default;

protected:
    string name;
};

template <typename T, typename V>
class ParticularDeveloper: public AllDeveloper<T>
{
public:
    ParticularDeveloper(const string& n): AllDeveloper<T>(n) {}
    unique_ptr<T> Create() override {
        return make_unique<V>();
    }
};

#endif