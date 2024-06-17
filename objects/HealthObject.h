#pragma once
class HealthObject
{
public:
    HealthObject(int health) : health(health) {};
    [[nodiscard]] int getHealth() const {return health;};
    virtual void takeDamage() { health--; }
protected:
    int health;
};

