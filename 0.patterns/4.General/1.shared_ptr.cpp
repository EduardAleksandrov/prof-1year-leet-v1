/*
    Разбираем умные указатели
*/
#include <iostream>
#include <memory> // For std::unique_ptr
#include <string>
using namespace std;

unique_ptr<int> one(unique_ptr<int>& s)
{
    return move(s);  // move удаляет перемещаемый указатель
}

shared_ptr<int> two(shared_ptr<int> s)
{
    return s;
}

class BreadBuilder {
public:
    std::shared_ptr<int> bread;
    BreadBuilder() {
        bread = std::make_unique<int>(5);
    }

    std::shared_ptr<int> getBread() {
        return bread;
    }
};

int main()
{
    int s = 5;
    unique_ptr<int> ss = make_unique<int>(s);
    unique_ptr<int> result = one(ss);

    cout << *result << endl;

    shared_ptr<int> ss2 = make_shared<int>(s);
    shared_ptr<int> result2 = two(ss2);

    BreadBuilder bread;
    cout << *bread.getBread() << " " << *bread.bread<< endl;
    
    return 0;
}