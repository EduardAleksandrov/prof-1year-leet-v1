/*
    Objects Pool
    Пул объектов
*/
#include <iostream>
#include <memory>
#include <iterator>
#include <vector>

#include "6.employee_pool.h"

using namespace std;

class Employee
{
private:
	static size_t count;

public:
	Employee() 
	{ 
		cout << "Constructor(" << ++count << ");" << endl; 
	}
	
	~Employee() 
	{ 
		cout << "Destructor(" << count-- << ");" << endl; 
	}

	void clockIn() 
	{ 
		cout << "Employee clocked in: 0x" << this << endl; 
	}
};

size_t Employee::count = 0;

int main()
{
	shared_ptr<EmployeePool<Employee>> pool = EmployeePool<Employee>::instance();

	vector<shared_ptr<Employee>> vec(4);

	for (auto& elem : vec)
		elem = pool->hireEmployee();

	pool->fireEmployee(vec[1]);

	cout << *pool << endl;

	shared_ptr<Employee> ptr = pool->hireEmployee();
	vec[1] = pool->hireEmployee();

	cout << *pool << endl;
}