/**
 * @file Buffer.cpp
 * @brief Demonstrates the implementation of a custom Buffer class with proper 
 *        resource management using constructors, destructors, and assignment operators.
 *
 * This example showcases:
 * - Constructor for resource allocation.
 * - Destructor for resource deallocation.
 * - Copy constructor for deep copying of resources.
 * - Move constructor for efficient transfer of resources.
 * - Copy assignment operator for deep copying of resources.
 * - Move assignment operator for efficient transfer of resources.
 *
 * The program demonstrates the usage of these features by creating, copying, 
 * and moving Buffer objects, while ensuring proper memory management and avoiding 
 * resource leaks or dangling pointers.
 */

#include <iostream>
#include <utility> // For std::move

class Buffer {
private:
    size_t size;
    char* data;

public:
    // Constructor
    Buffer(size_t size) : size(size), data(new char[size]) {
        std::cout << "Buffer created with size: " << size << std::endl;
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        data = nullptr; // Prevent dangling pointer
        std::cout << "Buffer destroyed" << std::endl;
    }

    // Copy Constructor
    Buffer(const Buffer& other) : size(other.size), data(new char[other.size]) {
        std::copy(other.data, other.data + other.size, data);
        std::cout << "Buffer copied (constructor) " << std::endl;
    }

    // Move Constructor
    Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
        other.size = 0;
        other.data = nullptr;
        std::cout << "Buffer moved (constructor)" << std::endl;
    }

    // Copy Assignment Operator
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        data = new char[other.size];
        std::copy(other.data, other.data + other.size, data);

        std::cout << "Buffer copied (assignment)" << std::endl;
        return *this;
    }

    // Move Assignment Operator
    Buffer& operator=(Buffer&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        size = other.size;
        data = other.data;

        other.size = 0;
        other.data = nullptr;

        std::cout << "Buffer moved (assignment)" << std::endl;
        return *this;
    }
};

int main() {
    Buffer buf1(10);               // Create a buffer
    Buffer buf2 = std::move(buf1); // Move constructor
    Buffer buf3(20);
    buf3 = std::move(buf2);        // Move assignment operator

    Buffer buf4(15);               // Normal constructor
    Buffer buf5 = buf4;            // Copy constructor
    Buffer buf6(25);
    buf6 = buf5;                   // Copy assignment operator
    return 0;
}