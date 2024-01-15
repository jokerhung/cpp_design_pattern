// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

    ~Singleton() {
        std::cout << "Singleton instance destroyed." << std::endl;
    }

public:
    static Singleton& getInstance() {
        if (!instance) {
            instance = new Singleton();
        }

        return *instance;
    }

    void doSomething() {
        std::cout << "Singleton do somethings." << std::endl;
    }
};

// Initialize the static instance variable to nullptr
Singleton* Singleton::instance = nullptr;

int main()
{
    Singleton& singleton = Singleton::getInstance();

    singleton.doSomething();
}
