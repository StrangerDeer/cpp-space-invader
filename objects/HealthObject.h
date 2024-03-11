#pragma once
class HealthObject
{
public:
    HealthObject(int health) : health(health) {};
    [[nodiscard]] int getHealth() const {return health;};

protected:
    int health;
    void takeDamage() { health--; }
};

