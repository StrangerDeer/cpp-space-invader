#pragma once
#include <cstdlib> // For rand()
#include <ctime>   // For time()

class Util {
public:
    // Static method to get a random number within a range [min, max]
    static int getRandomNumber(int min, int max) {
        initialize(); // Ensure the random number generator is initialized
        return rand() % (max - min + 1) + min;
    }

private:
    // Helper function to initialize the random number generator
    static void initialize() {
        static bool initialized = false;
        if (!initialized) {
            srand(static_cast<unsigned>(time(nullptr)));
            initialized = true;
        }
    }
};