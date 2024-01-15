// AbstractFactory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Button {
public:
    virtual void Paint() = 0;
};

class WindowButton : public Button {
public:
    void Paint() override {
        std::cout << "This is a Window button" << std::endl;
    }
};

class MacButton : public Button {
public:
    void Paint() override {
        std::cout << "This is a Mac button" << std::endl;
    }
};

class UIFactory {
public:
    virtual Button* createButton() = 0;
};

class WindowUIFactory : public UIFactory {
public:
    Button* createButton() override {
        return new WindowButton;
    }
};

class MacUIFactory : public UIFactory {
public:
    Button* createButton() override {
        return new MacButton;
    }
};

class Application {
private:
    Button* _button;

public:
    Application(UIFactory* factory) {
        _button = factory->createButton();
    }

    void Paint() {
        _button->Paint();
    }
};

int main()
{
    UIFactory* factoryWin = new WindowUIFactory();
    Application* appWin = new Application(factoryWin);
    appWin->Paint();

    UIFactory* factoryMac = new MacUIFactory();
    Application* appMac = new Application(factoryMac);
    appMac->Paint();

    delete factoryWin;
    delete appWin;
    delete factoryMac;
    delete appMac;
}
