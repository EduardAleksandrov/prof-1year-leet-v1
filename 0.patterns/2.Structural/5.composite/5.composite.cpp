/*
    Composite
    Компоновщик
*/
# include <iostream>
# include <initializer_list>
# include <memory>
# include <vector>

# include "5.component.h"
# include "5.composite.h"

int main()
{
    using Default = shared_ptr<Component>;
    PtrComponent fig = make_shared<Figure>(), cam = make_shared<Camera>();
    auto composite1 = make_shared<Composite>(fig, cam, Default{});

    composite1->add({ make_shared<Figure>(), make_shared<Camera>() });
    composite1->operation();
    cout << endl;

    auto it = composite1->begin();

    composite1->remove(++it);
    composite1->operation();
    cout << endl;

    auto composite2 = make_shared<Composite>(make_shared<Figure>(), composite1, Default());

    composite2->operation();
}