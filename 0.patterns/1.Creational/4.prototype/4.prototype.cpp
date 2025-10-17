/*
    Prototype
    Прототип
*/
# include <iostream>
# include <memory>

using namespace std;

class Car
{
public:
	virtual ~Car() = default;
	virtual unique_ptr<Car> clone() = 0;
};


class Sedan : public Car
{
public:
	Sedan() 
	{ 
		cout << "Calling the default constructor;" << endl; 
	}
	
	Sedan(const Sedan& car) 
	{ 
		cout << "Calling the Copy constructor;" << endl; 
	}
	
	~Sedan() override 
	{ 
		cout << "Calling the destructor;" << endl; 
	}

	unique_ptr<Car> clone() override
	{
        cout << "Car cloned" << endl;
		return make_unique<Sedan>(*this);
	}
};

class User
{
public:
	void use(shared_ptr<Car> &car)
	{
		auto newCar = car->clone();
	}
};

int main()
{
	shared_ptr<Car> sedan = make_shared<Sedan>();
	User{}.use(sedan);
    return 0;
}