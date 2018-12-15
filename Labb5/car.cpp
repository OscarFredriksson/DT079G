#include "car.h"

Car::Car(const std::string& name, double speed):
    name(name),
    speed(speed)
{}

bool Car::operator==(const Car& rhs) const
{
    return name == rhs.name;
}