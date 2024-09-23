#include <iostream>
#include <string>

class Appliance {
protected:
    std::string brand;
    int powerUsage;

public:
    Appliance(std::string b, int p) : brand(b), powerUsage(p) {}
    
    virtual ~Appliance() {
        std::cout << "Destroying Appliance: " << brand << std::endl;
    }

    virtual void displayInfo() const = 0;
};

class WashingMachine : public Appliance {
private:
    int loadCapacity;

public:
    WashingMachine(std::string b, int p, int lc) 
        : Appliance(b, p), loadCapacity(lc) {}

    ~WashingMachine() {
        std::cout << "Destroying WashingMachine: " << brand << std::endl;
    }

    void displayInfo() const override {
        std::cout << "Washing Machine: Brand: " << brand 
                  << ", Power Usage: " << powerUsage 
                  << "W, Load Capacity: " << loadCapacity << "kg" << std::endl;
    }
};

class Refrigerator : public Appliance {
private:
    int volume;

public:
    Refrigerator(std::string b, int p, int v) 
        : Appliance(b, p), volume(v) {}

    ~Refrigerator() {
        std::cout << "Destroying Refrigerator: " << brand << std::endl;
    }

    void displayInfo() const override {
        std::cout << "Refrigerator: Brand: " << brand 
                  << ", Power Usage: " << powerUsage 
                  << "W, Volume: " << volume << "L" << std::endl;
    }
};

int main() {

    WashingMachine wm("Whirlpool", 500, 7);
    Refrigerator fridge("Samsung", 150, 350);


    Appliance* appliances[2];
    appliances[0] = &wm;
    appliances[1] = &fridge;

    for (int i = 0; i < 2; ++i) {
        appliances[i]->displayInfo();
    }


    return 0;
}
