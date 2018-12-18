#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
public:
    Car(const std::string& name, double speed);

    bool operator==(const Car& rhs) const;

    std::string getName() const;

    double getSpeed() const;

private:
    std::string name;
    double speed;

};

#endif