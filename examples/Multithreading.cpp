#include <iostream>
#include <thread>
#include <mutex>

const int NUM_ITERATIONS = 1000;
int counter = 0;
std::mutex counterMutex;

void incrementCounter() {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        std::cout << "Thread ID: " << std::this_thread::get_id() << " is running." << std::endl;
        std::lock_guard<std::mutex> lock(counterMutex);
        ++counter;
    }
}

int main() {
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}