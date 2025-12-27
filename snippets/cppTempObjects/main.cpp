#include <iostream>
#include <string>

/**
 * STEP 1: The Tracker Class
 * This class is your "microscope." Every time a Tracker object is 
 * created, copied, or destroyed, it will tell you.
 */

class Tracker {
public:
    std::string name;
    Tracker(std::string n) : name(n) { 
        std::cout << "[CONSTRUCT] " << name << " is born.\n"; 
    }
    Tracker(const Tracker& other) : name(other.name + " (copy)") { 
        std::cout << "[COPY] Creating " << name << " from " << other.name << ".\n"; 
    }
    ~Tracker() { 
        std::cout << "[DESTROY] " << name << " is gone.\n"; 
    }
};

/**
 * STEP 2: The Factory Function
 * This returns an object by value, which creates a temporary.
 */
Tracker createTracker() {
    return Tracker("TemporaryObject");
}

int main() {
    std::cout << "--- START OF LAB ---\n\n";

    // TODO 1: Observe the Temporary Lifecycle
    // Write a line that calls createTracker() but DOES NOT assign it to anything.
    // OBSERVE: Does it die before or after the next line of code prints?


    // TODO 2: The "Dangling" Danger (Mental Exercise)
    // If you did: Tracker* ptr = &createTracker(); 
    // Why would using 'ptr' on the next line be a disaster? 
    // (Don't actually write this code, it might crash your compiler!)


    // TODO 3: Lifetime Extension with 'const &'
    // Use: const Tracker& myRef = createTracker();
    // OBSERVE: Does the object die at the semicolon, or does it stay alive
    // until the end of the main() function?


    // TODO 4: The Compiler "Cheat" (RVO)
    // Use: Tracker myNormalObj = createTracker();
    // OBSERVE: Modern compilers use Return Value Optimization. 
    // Do you see a [COPY] happen, or is the compiler smart enough 
    // to build it directly into 'myNormalObj'?
    std::cout << "Normal assignment...\n";
    Tracker myNormalObj = createTracker();


    std::cout << "\n--- END OF main() ---\n";
    // Final Observation: Watch when the remaining objects are destroyed.
    return 0;
}