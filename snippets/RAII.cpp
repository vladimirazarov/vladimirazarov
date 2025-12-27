/* 
Resource acquisition is initialization - basic concept that means that resource lifetime and
memory it takes is strictly tied to its lifetime on stack.
*/

#include <iostream>
#include <fstream> 
#include <string>

class FileWrapper{
  public:
    // Acquisition is Constructor
    FileWrapper(const std::string& filename) : stream(filename) {
      if (stream.is_open()){
        std::cout << "File opened. \n";
      }
    }
    // Release in Destructor
    ~FileWrapper() {
      if (stream.is_open()){
        stream.close();
        std::cout << "File closed automatically. \n";
      }
    }

    void write(const std::string& msg) {stream << msg; }

    private:
      std::ofstream stream;
};

void useRAII(){
  FileWrapper myFile("test.txt");
  myFile.write("RAII is powerful");
}
