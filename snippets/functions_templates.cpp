// Type Deduction: Unlike classes, you often 
// don't need to specify the type for functions; 
// the compiler looks at the arguments you 
// pass and "deduces" what T should be.

// Member Functions: These are functions inside
// a class. Even in a non-template class, 
// you can have a specific member function 
// that is a template.

template <typename T>
T findMax(T a, T b) {
  return (a > b) ? a : b;
}

int main(){
  auto result1 = findMax(10, 20);
  auto result2 = findMax(1.1f, 2.3f);
}