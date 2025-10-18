#ifndef FMH_H
#define FMH_H

# include <memory>
# include <mutex>

using namespace std;

template <typename Type>
class EmployeePool
{
public:
	static shared_ptr<EmployeePool<Type>> instance();

	shared_ptr<Type> hireEmployee();
	bool fireEmployee(shared_ptr<Type>& employee);
	size_t count() const { return pool.size(); }

	EmployeePool(const EmployeePool&) = delete;
	EmployeePool& operator =(const EmployeePool&) = delete;

private:
	vector<pair<bool, shared_ptr<Type>>> pool;

    mutable mutex mtx;  // Mutex for thread safety

	EmployeePool() {}

	pair<bool, shared_ptr<Type>> createEmployee();

	template <typename T>
	friend ostream& operator << (ostream& os, const EmployeePool<T>& pl);
};

template <typename Type>
std::shared_ptr<EmployeePool<Type>> EmployeePool<Type>::instance()
{
    static mutex mtxx; // Mutex for thread safety
    lock_guard<mutex> lock(mtxx); // Lock for the duration of the scope

	static shared_ptr<EmployeePool<Type>> myInstance(new EmployeePool<Type>());

	return myInstance;
}

template <typename Type>
shared_ptr<Type> EmployeePool<Type>::hireEmployee()
{
    lock_guard<mutex> lock(mtx); // Lock for thread safety

	size_t i;
	for (i = 0; i < pool.size() && pool[i].first; ++i);

	if (i < pool.size())
	{
		pool[i].first = true;
	}
	else
	{
		pool.push_back(createEmployee());
	}

	return pool[i].second;
}

template <typename Type>
bool EmployeePool<Type>::fireEmployee(shared_ptr<Type>& employee)
{
    lock_guard<mutex> lock(mtx); // Lock for thread safety

	size_t i;
	for (i = 0; pool[i].second != employee && i < pool.size(); ++i);

	if (i == pool.size()) return false;

	employee.reset();
	pool[i].first = false;
	pool[i].second->clockIn();

	return true;
}

template <typename Type>
pair<bool, shared_ptr<Type>> EmployeePool<Type>::createEmployee()
{
	return { true, make_shared<Type>() };
}

template <typename Type>
ostream& operator << (ostream& os, const EmployeePool<Type>& pl)
{
    lock_guard<mutex> lock(pl.mtx); // Lock for thread safety

	for (auto elem : pl.pool)
		os << "{" << elem.first << ", 0x" << elem.second << "} ";

	return os;
}

#endif