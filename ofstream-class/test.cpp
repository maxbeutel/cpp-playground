#include <iostream>
#include <fstream>

class DataFile
{
private:
    int someInt;
    std::ofstream *outputStream;

public:
    DataFile(int s) :someInt{s} {
    }

    DataFile(int s, std::string fileName) :someInt{s} {
        std::ofstream *os = new std::ofstream(fileName);

        if (!os->is_open()) {
            // @TODO this is bad!
        }

        outputStream = os;
    }

    int getSomeInt() {
        return someInt;
    }

    ~DataFile() {
        std::cout << "destructor called\n";

        delete outputStream;
    }
};

// @TODO rewrite using smart pointers

int main()
{
    std::cout << "Hello\n";

    DataFile dataFile_stack(1234, "/tmp/test.txt");

    DataFile *dataFile_heap = new DataFile(5678);
    delete dataFile_heap;
}
