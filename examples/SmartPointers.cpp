/** 
 * @file SmartPointers.cpp
 * @brief Demonstrates the use of different types of pointers in C++:
 * 1. std::unique_ptr: A smart pointer that owns and manages a single object, ensuring 
 *    that the object is deleted when the unique_ptr goes out of scope.
 * 2. std::shared_ptr: A smart pointer that allows multiple shared ownership of an object.
 *    The object is deleted when the last shared_ptr owning it is destroyed or reset.
 * 3. std::weak_ptr: A smart pointer that provides a non-owning reference to an object 
 *    managed by std::shared_ptr, avoiding circular references.
 * 4. Raw pointers: Demonstrates manual memory management using raw pointers, including 
 *    allocation and deallocation of memory.
 *
 * The code includes examples of creating, transferring ownership, and resetting these 
 * pointers, as well as the implications of their use in terms of memory management.
 */


#include <iostream>
#include <memory> // For std::unique_ptr

// Function to demonstrate unique_ptr
void uniquePointerDemo() {
    // Creating a unique_ptr
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(10);
    std::cout << "Value in unique_ptr: " << *uniquePtr << std::endl;

    // Transferring ownership
    std::unique_ptr<int> uniquePtr2 = std::move(uniquePtr);
    if (!uniquePtr) {
        std::cout << "uniquePtr is now null after move." << std::endl;
    }
    std::cout << "Value in uniquePtr2: " << *uniquePtr2 << std::endl;

    // uniquePtr2 goes out of scope and deletes the managed object automatically
}

// Function to demonstrate shared_ptr and weak_ptr
void sharedAndWeakPointerDemo() {
    // Creating a shared_ptr
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(30);
    std::cout << "Value in shared_ptr1: " << *sharedPtr1 << std::endl;
    std::cout << "sharedPtr1 use count: " << sharedPtr1.use_count() << std::endl;

    // Creating another shared_ptr sharing ownership
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;
    std::cout << "Value in shared_ptr2 (shared ownership): " << *sharedPtr2 << std::endl;
    std::cout << "sharedPtr1 use count after sharedPtr2: " << sharedPtr1.use_count() << std::endl;

    // Resetting sharedPtr2
    sharedPtr2.reset();
    std::cout << "sharedPtr1 use count after resetting sharedPtr2: " << sharedPtr1.use_count() << std::endl;

    {
    // Creating another shared_ptr sharing ownership inside a certain scope 
    std::shared_ptr<int> sharedPtr3 = sharedPtr1;
    std::cout << "Value in shared_ptr3 (shared ownership): " << *sharedPtr3 << std::endl;
    std::cout << "sharedPtr1 use count after sharedPtr3: " << sharedPtr1.use_count() << std::endl;
    }

    std::cout << "sharedPtr1 use count after getting out of scope: " << sharedPtr1.use_count() << std::endl;
    
    // Creating a weak_ptr from shared_ptr
    std::weak_ptr<int> weakPtr = sharedPtr1;
    if (auto lockedPtr = weakPtr.lock()) { // Check if weak_ptr is still valid
        std::cout << "Value in weak_ptr (locked): " << *lockedPtr << std::endl;
    } else {
        std::cout << "weak_ptr is expired." << std::endl;
    }

    // Reset sharedPtr1 to demonstrate weak_ptr expiration
    sharedPtr1.reset();
    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "Value in weak_ptr (locked after reset): " << *lockedPtr << std::endl;
    } else {
        std::cout << "weak_ptr is expired after shared_ptr reset." << std::endl;
    }
}

// Function to demonstrate raw pointers
void rawPointerDemo() {
    // Creating a raw pointer
    int* rawPtr = new int(20);
    std::cout << "Value in raw pointer: " << *rawPtr << std::endl;

    // Manually deleting the raw pointer
    delete rawPtr;
    rawPtr = nullptr; // Avoid dangling pointer
    std::cout << "Raw pointer manually deleted." << std::endl;
}

int main() {
    std::cout << "Demonstrating unique_ptr:" << std::endl;
    uniquePointerDemo();
    std::cout << "\nDemonstrating shared_ptr and weak_ptr:" << std::endl;
    sharedAndWeakPointerDemo();
    std::cout << "\nDemonstrating raw pointers:" << std::endl;
    rawPointerDemo();

    return 0;
}