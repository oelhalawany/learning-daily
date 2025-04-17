#include <iostream>
#include <optional>
#include <string>

// Function that returns an optional value
std::optional<std::string> findNameById(int id) {
    if (id == 1) {
        return "Alice";
    } else if (id == 2) {
        return "Bob";
    }
    // Return an empty optional if no match is found
    return std::nullopt;
}

int main() {
    int id = 1;
    auto name = findNameById(id);

    if (name) {
        std::cout << "Found name: " << *name << std::endl;
    } else {
        std::cout << "No name found for ID: " << id << std::endl;
    }

    id = 3;
    name = findNameById(id);

    if (name) {
        std::cout << "Found name: " << *name << std::endl;
    } else {
        std::cout << "No name found for ID: " << id << std::endl;
    }

    return 0;
}