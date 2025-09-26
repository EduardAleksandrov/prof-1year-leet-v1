/*
    1114. Print in Order

    Suppose we have a class:

    public class Foo {
    public void first() { print("first"); }
    public void second() { print("second"); }
    public void third() { print("third"); }
    }
    The same instance of Foo will be passed to three different threads. 
    Thread A will call first(), thread B will call second(), and thread C will call third(). 
    Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

    Note:

    We do not know how the threads will be scheduled in the operating system, 
    even though the numbers in the input seem to imply the ordering. 
    The input format you see is mainly to ensure our tests' comprehensiveness.

    Done.
*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;


class ConcreteSubscriber
{
public:
    int x = 5;
	void method(int x)
	{ 
		cout << "method;"<< x << endl; 
	}
};

class Foo {
    using Action = void(ConcreteSubscriber::*)(int);
	using Pair = pair<shared_ptr<ConcreteSubscriber>, Action>;
private:
    std::mutex mtx;
    std::condition_variable cv;
    int step;

    vector<Pair> callback;

public:
    Foo() : step(1) {} // Initialize step to 1

    bool subscribe(shared_ptr<ConcreteSubscriber> r, Action a)
    {
        Pair pr(r, a);
        callback.push_back(pr);
        return true;
    }

    void run(int x)
    {
        cout << "Run:" << endl;
        for (auto elem : callback)
        {
            elem.first->x = 8;
            (*(elem.first).*(elem.second))(x);
        }
            
    }

    void first(std::function<void()> printFirst) {
        // Print "first"
        printFirst();
        // Notify that the first step is done
        {
            std::lock_guard<std::mutex> lock(mtx);
            step = 2; // Update step to 2
        }
        cv.notify_all(); // Notify waiting threads

        run(step);
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until the first step is done
        cv.wait(lock, [this]() { return step == 2; });
        // Print "second"
        printSecond();
        // Notify that the second step is done
        step = 3; // Update step to 3
        cv.notify_all(); // Notify waiting threads
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until the second step is done
        cv.wait(lock, [this]() { return step == 3; });
        // Print "third"
        printThird();
    }
};

int main() {
    Foo foo;

    shared_ptr<ConcreteSubscriber> sb = make_shared<ConcreteSubscriber>();
    foo.subscribe(sb, &ConcreteSubscriber::method);

    cout << sb->x << endl;

    std::thread t1(&Foo::first, &foo, []() { std::cout << "first"; });
    std::thread t2(&Foo::second, &foo, []() { std::cout << "second"; });
    std::thread t3(&Foo::third, &foo, []() { std::cout << "third"; });

    t1.join();
    t2.join();
    t3.join();

    cout << sb->x << endl;


    return 0;
}