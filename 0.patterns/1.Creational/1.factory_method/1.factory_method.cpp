/*
    Factory Method
    Фабричный метод
*/
#include <iostream>
#include <string>
#include <memory>

#include "1.objects.h"
#include "1.factory_method.h"
#include "1.factory_method_template.h"

using namespace std;

int main() {

    unique_ptr<Developer> dev = make_unique<PanelDeveloper>("ООО КирпичСтрой");
    unique_ptr<House> house1 = dev->Create();
    dev = make_unique<WoodDeveloper>("Частный застройщик");
    unique_ptr<House> house2 = dev->Create();

    unique_ptr<AllDeveloper<House>> alldev = make_unique<ParticularDeveloper<House, PanelHouse>>("ООО КирпичСтрой");
    unique_ptr<House> house3 = alldev->Create();
    alldev = make_unique<ParticularDeveloper<House, WoodHouse>>("Частный застройщик");
    unique_ptr<House> house4 = alldev->Create();

    return 0;
}