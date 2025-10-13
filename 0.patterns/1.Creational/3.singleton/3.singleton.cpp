/*
    Singleton
    Одиночка

    Потокобезопасный
*/
#include <iostream>
#include <memory>
#include <mutex>
#include <vector>
#include <thread>

using namespace std;

class Sun
{
public:
	static shared_ptr<Sun> instance()
	{
        static mutex mtx; // Mutex for thread safety
        lock_guard<mutex> lock(mtx); // Lock for the duration of the scope

		class SunProxy : public Sun {};

		static shared_ptr<Sun> myInstance = make_shared<SunProxy>();

		return myInstance;
	}
	
	~Sun() 
	{ 
		cout << "Calling the destructor;" << endl; 
	}

	void shine() 
	{ 
        lock_guard<mutex> lock(xm);
        x++;
		cout << "The sun is shining;" << x << endl; 
	}

	Sun(const Sun&) = delete;
	Sun& operator =(const Sun&) = delete;

private:
	Sun() 
	{ 
		cout << "Calling the default constructor;" << endl; 
	}

    int x;
    std::mutex xm;
};

void threadFunction() {
    auto sunInstance = Sun::instance();
    sunInstance->shine();
}

int main()
{
	shared_ptr<Sun> sun(Sun::instance());

	sun->shine();
    sun->shine();

    // Потокобезопасность
    const int numThreads = 10;
    vector<thread> threads;

    // Create multiple threads
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(thread(threadFunction));
    }

    // Join all threads
    for (auto& th : threads) {
        th.join();
    }
}