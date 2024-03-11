#pragma once
class HealthObject
{
public:
    HealthObject(int health) : health(health) {};

protected:
    int health;
    void takeDamage() { health--; }
};

