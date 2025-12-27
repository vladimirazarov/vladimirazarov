#include <iostream>
#include <memory> // Required for smart pointers

class Thing {
 public:
  Thing(int id) : id_(id) { std::cout << "Thing " << id_ << " created.\n"; }
  ~Thing() { std::cout << "Thing " << id_ << " Says bye.\n"; }
  void Hello() { std::cout << "  Thing " << id_ << " Says hi!\n"; }

 private:
  int id_;
};

int main() {
  std::cout << "--- Unique Pointer Demo ---\n";
  {
    // unique_ptr: Solo ownership.
    // make_unique is the modern way to 'new' an object safely.
    std::unique_ptr<Thing> u_ptr = std::make_unique<Thing>(1);
    u_ptr->Hello();

    // std::unique_ptr<Thing> u_ptr2 = u_ptr; // ERROR! Cannot copy a unique_ptr.
  } // <--- Thing 1 dies here automatically because u_ptr goes out of scope.

  std::cout << "\n--- Shared Pointer Demo ---\n";
  {
    std::shared_ptr<Thing> s_ptr1 = std::make_shared<Thing>(2);
    {
      std::shared_ptr<Thing> s_ptr2 = s_ptr1; // Copying is allowed!
      std::cout << "  (Count is now 2)\n";
      s_ptr2->Hello();
    } // <--- s_ptr2 dies, but Thing 2 is NOT destroyed yet (Count is 1).
    std::cout << "  (Back to count 1, Thing 2 is still alive)\n";

  } // <--- s_ptr1 dies. Count hits 0. Thing 2 is DESTROYED here.

  return 0;
}




// https://en.cppreference.com/w/cpp/memory/unique_ptr.html
// https://en.cppreference.com/book/intro/smart_pointers