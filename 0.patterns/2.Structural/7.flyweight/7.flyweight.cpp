/*
    Flyweight
    Приспособленец
*/
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Abstract House Class
class House {
protected:
    int stages; // Number of floors
public:
    virtual void Build(double longitude, double latitude) = 0; // Pure virtual function
};

// Panel House Class
class PanelHouse : public House {
public:
    PanelHouse() {
        stages = 16;
    }
    
    void Build(double longitude, double latitude) override {
        cout << "Построен панельный дом из " << stages 
             << " этажей; координаты: " << latitude 
             << " широты и " << longitude << " долготы" << endl;
    }
};

// Brick House Class
class BrickHouse : public House {
public:
    BrickHouse() {
        stages = 5;
    }
    
    void Build(double longitude, double latitude) override {
        cout << "Построен кирпичный дом из " << stages 
             << " этажей; координаты: " << latitude 
             << " широты и " << longitude << " долготы" << endl;
    }
};

// House Factory Class
class HouseFactory {
private:
    unordered_map<string, House*> houses; // Dictionary to hold house types
public:
    HouseFactory() {
        houses["Panel"] = new PanelHouse();
        houses["Brick"] = new BrickHouse();
    }

    ~HouseFactory() {
        for (auto& pair : houses) {
            delete pair.second; // Clean up dynamically allocated houses
        }
    }

    House* GetHouse(const string& key) {
        if (houses.find(key) != houses.end()) {
            return houses[key];
        }
        return nullptr;
    }
};

// Main Function
int main() {
    double longitude = 37.61;
    double latitude = 55.74;

    HouseFactory houseFactory;

    // Build Panel Houses
    for (int i = 0; i < 5; i++) {
        House* panelHouse = houseFactory.GetHouse("Panel");
        if (panelHouse) {
            panelHouse->Build(longitude, latitude);
        }
        longitude += 0.1;
        latitude += 0.1;
    }

    // Build Brick Houses
    for (int i = 0; i < 5; i++) {
        House* brickHouse = houseFactory.GetHouse("Brick");
        if (brickHouse) {
            brickHouse->Build(longitude, latitude);
        }
        longitude += 0.1;
        latitude += 0.1;
    }

    return 0;
}