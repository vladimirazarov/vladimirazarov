#include <string>

// CASE 1: Pass by Value, Return by Value
// C equivalent: char* func(char* str) { /* malloc new string, return it */ }
// Logic: Heavy. Copies the string entering the function, copies it again exiting.
// SLOW!!! DeepCopy
std::string ReturnByValuePassByValue(std::string str){
  return str + "Hi";
}

// CASE 2: Pass by Reference, Return by Value
// C equivalent: char* func(const char* str) { /* malloc new string, return it */ }
// Logic: Efficient input. No copy made on entry. Returns a brand new string object.
std::string ReturnByValuePassByRef(std::string& str){
  return str + "Hi";
}

// CASE 3: Pass by Reference, Return by Reference (CRITICAL ERROR)
// Logic: This will NOT compile or will crash. 
// The expression (str + "Hi") creates a "Temporary Object" (R-Value).
// You cannot take the address of a temporary that is about to die.
std::string& ReturnByRefPassByRef(std::string& str) {
    // ERROR: Can't return reference to local temporary
    //return str + "Hi"; 
}

// CASE 4: Pass by Value, Return by Reference (CRITICAL ERROR)
// Logic: This is the "Dangling Pointer" of C++. 
// 'str' is a local copy on the stack. When the function ends, 'str' is deleted.
// Returning a reference to it means the caller gets a pointer to dead memory.
std::string& ReturnByRefPassByValue(std::string str) {
    str += "Hi";
    return str; // WARNING: Returns reference to stack memory!
}


// CASE 5: Pass by Ref, modify in-situ
void ModifyPassedRefValue(std::string& str){
  str += "Hi";
}

// CASE 6: Pass by Ref, read the value
void ReadPassedRefValue(const std::string& name){
  std::cout << name;
}


int main(){

  std::string test1 = "Hello and ";
  ReturnByValuePassByValue(test1);

  std::string test2 = "Hello and ";
  ReturnByValuePassByRef(test2);

  std::string test3 = "Hello and ";
  ReturnByValuePassByRef(test3);

  std::string test4 = "Hello and ";
  ReturnByValuePassByRef(test4);
}