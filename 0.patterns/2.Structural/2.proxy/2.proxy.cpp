/*
    Proxy
    Прокси
*/

# include <iostream>
# include "2.subject.h"
# include "2.proxy.h"

using namespace std;

int main()
{
    shared_ptr<RealSubject> subject = make_shared<RealSubject>();
    shared_ptr<Subject> proxy = make_shared<ConcreteProxy>(subject);

    for (size_t i = 0; i < 21; ++i)
    {
        cout << "( " << i + 1 << ", " << proxy->request(i % 3).second << " )" << endl;
        if ((i + 1) % 3 == 0)
            cout << endl;
    }
    
    return 0;
}