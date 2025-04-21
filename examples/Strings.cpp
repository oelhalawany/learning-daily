#include <iostream>
#include <string>
#include <algorithm>

int main() {
    // Basic string initialization
    std::string str1 = "Hello";
    std::string str2 = "World";

    // Concatenation
    std::string concatenated = str1 + " " + str2;
    std::cout << "Concatenated string: " << concatenated << std::endl;

    // Accessing characters
    std::cout << "First character of str1: " << str1[0] << std::endl;

    // String length
    std::cout << "Length of str1: " << str1.length() << std::endl;

    // Substring
    std::string substring = concatenated.substr(0, 5);
    std::cout << "Substring: " << substring << std::endl;

    // Find a substring
    size_t position = concatenated.find("World");
    if (position != std::string::npos) {
        std::cout << "'World' found at position: " << position << std::endl;
    } else {
        std::cout << "'World' not found" << std::endl;
    }

    // Replace a substring
    concatenated.replace(position, 5, "Everyone");
    std::cout << "After replacement: " << concatenated << std::endl;

    // Convert to uppercase
    std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    std::cout << "Uppercase str1: " << str1 << std::endl;

    // Convert to lowercase
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    std::cout << "Lowercase str2: " << str2 << std::endl;

    // String comparison
    if (str1 == str2) {
        std::cout << "str1 and str2 are equal" << std::endl;
    } else {
        std::cout << "str1 and str2 are not equal" << std::endl;
    }

    return 0;
}