#include <iostream>

class Car {
private:
    int* kmsDrivenSnapshots;
    char pastOwners[10][60];
    int nrOfPastOwners;
    enum Make {Toyota, Dacia, Tesla, Volkswagen};
    Make make;
    bool isRefurbished;
public:
    Car() {
        kmsDrivenSnapshots = nullptr;
        int nrOfPastOwners = 0;
        make = Toyota;
        isRefurbished = false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
