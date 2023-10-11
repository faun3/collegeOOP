#include <iostream>

class Car {
private:
    char sellerName[30];
    enum Make {Toyota, Dacia, Tesla, Volkswagen};
    Make make;
    bool isRefurbished;
};

int main()
{
    std::cout << "Hello World!\n";
}
