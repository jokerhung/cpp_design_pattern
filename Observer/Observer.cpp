// Observer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Observer {
public:
    virtual void update(float temperature, float humidity, float presure) = 0;
};

class WeatherStation {
private:
    float _temperature;
    float _humidity;
    float _presure;
    std::vector<Observer*> listObservers;

public:
    void attach(Observer* observer) {
        listObservers.push_back(observer);
    }

    void detach(Observer* observer) {
        // You can implement the removal logic if needed.
    }

    void notify() {
        for (Observer* observer : listObservers) {
            observer->update(_temperature, _humidity, _presure);
        }
    }

    void setMeasurement(float temperature, float humidity, float presure) {
        _temperature = temperature;
        _humidity = humidity;
        _presure = presure;

        notify();
    }
};

class Display : public Observer {
public:
    void update(float temperature, float humidity, float presure) {
        std::cout << "Display: Temperature = " << temperature
            << "°C, Humidity = " << humidity
            << "%, Pressure = " << presure << " hPa"
            << std::endl;
    }
};

int main()
{
    WeatherStation weatherStation;

    // Create displays
    Display display1;
    Display display2;

    // Register displays as observers
    weatherStation.attach(&display1);
    weatherStation.attach(&display2);

    // Simulate weather data updates
    weatherStation.setMeasurement(25.5, 60, 1013.2);
    weatherStation.setMeasurement(24.8, 58, 1014.5);

    return 0;
}