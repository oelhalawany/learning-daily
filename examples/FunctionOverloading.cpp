#include <iostream>
#include <string>

class Printer {
public:
    // Overloaded function to print an integer
    void print(int value) {
        std::cout << "Integer: " << value << std::endl;
    }

    // Overloaded function to print a double
    void print(double value) {
        std::cout << "Double: " << value << std::endl;
    }

    // Overloaded function to print a string
    void print(std::string& value) {
        std::cout << "String: " << value << std::endl;
    }

    // Overloaded function to print a character
    void print(char value) {
        std::cout << "Character: " << value << std::endl;
    }
};

int main() {
    Printer printer;

    std::string s = "Hello World!";

    // Testing the overloaded print functions
    printer.print(42);               // Calls the integer version
    printer.print(3.14);             // Calls the double version
    printer.print(s);                // Calls the string version
    printer.print('A');              // Calls the character version

    return 0;
}