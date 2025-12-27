#include <string>

// a family of classes (class template),
// which may be nested classes

template <typename T>
class Box {
  public:
    T content;
    void setContent(T val) { content = val; }
};

int main(){
  Box<int> intBox;
  Box<std::string> strBox;
}