// Google prefers .h for headers. 
// Use #define guards based on the full path in the project.
#ifndef CLASS_H_
#define CLASS_H_

#include <string>

// Class names are CamelCase.
class Player {
 // Single space identation for access modifiers
 public:
  // 1. Types/Enums go at the top of the section.
  enum class State { kIdle, kWalking, kShooting };

  // 2. Constructors.
  // 'explicit' prevents the compiler from doing unintended type conversions.
  explicit Player(const std::string& name);
  Player(int health, int damage);

  // 3. Destructor.
  ~Player();

  // 4. Methods (CamelCase).
  void Shoot();
  void Walk();

  // 5. Accessors (Getters/Setters).
  // Google style: Getters are named like the variable, Setters use set_...
  int health() const { return health_; }
  void set_health(int health) { health_ = health; }

  const std::string& name() const { return name_; }

 protected:
  // Protected members also use the trailing underscore.
  void UpdateAnimation();

 private:
  // 6. Data Members (Trailing underscores).
  // Ordered usually by size/relevance; public first, private last.
  std::string name_;
  int health_;
  int damage_;
  State current_state_;

  // Google style: Macro to disallow copy constructor and assignment 
  // if you don't want the object to be copied (common in game entities).
  // In modern C++ (C++11+), we usually just delete them:
  Player(const Player&) = delete;
  Player& operator=(const Player&) = delete;
};

#endif  // MYGAME_PLAYER_H_