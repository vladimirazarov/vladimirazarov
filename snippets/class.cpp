#include <string>

class Player{
private:
    std::string name;
    double health;

public:
  // Constructor
  Player(const std::string& name, double health) 
    : name(name), health(health){}

  // Getter for name
  // Const means it doesnt and CANT modify any
  // member variables
  const std::string& GetName() const {
    return name;
  }

  // Getter for health
  double GetHealth() const {
    return health;
  }

  void setHealth(double new_health){
    if (new_health >= 0){
      health = new_health;
    }
  }
};