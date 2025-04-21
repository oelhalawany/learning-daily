#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <unordered_set>

int main() {
    // Example of std::vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6); // Add an element
    std::cout << "Vector elements: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << "\n";

    // Example of std::unordered_set
    std::unordered_set<int> uset = {1, 2, 3, 4, 5};
    uset.insert(6); // Add an element
    uset.insert(3); // Duplicate, will be ignored
    std::cout << "Unordered Set elements: ";
    for (int u : uset) {
        std::cout << u << " ";
    }
    std::cout << "\n";

    // Example of std::set
    std::set<int> st = {5, 3, 8, 1, 3}; // Duplicates are ignored
    st.insert(10); // Add an element
    std::cout << "Set elements: ";
    for (int s : st) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    // Example of std::unordered_map
    std::unordered_map<std::string, int> ump;
    ump["apple"] = 5;
    ump["banana"] = 3;
    ump["cherry"] = 8;
    std::cout << "Unordered Map elements:\n";
    for (const auto& [key, value] : ump) {
        std::cout << key << ": " << value << "\n";
    }

    // Example of std::map
    std::map<int, std::string> mp;
    mp[1] = "One";
    mp[2] = "Two";
    mp[3] = "Three";
    std::cout << "Map elements:\n";
    for (const auto& [key, value] : mp) {
        std::cout << key << ": " << value << "\n";
    }

    for(const auto& e : mp)
    {
        auto key = e.first;
        auto value = e.second;
    }

    // Example of std::deque
    std::deque<int> dq = {10, 20, 30};
    dq.push_front(5); // Add an element to the front
    dq.push_back(40); // Add an element to the back
    std::cout << "Deque elements: ";
    for (int d : dq) {
        std::cout << d << " ";
    }
    std::cout << "\n";

    // Example of std::list
    std::list<int> lst = {1, 2, 3, 4};
    lst.push_back(5); // Add an element to the back
    lst.push_front(0); // Add an element to the front
    std::cout << "List elements: ";
    for (int l : lst) {
        std::cout << l << " ";
    }
    std::cout << "\n";

    // Example of std::stack
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    std::cout << "Stack elements (top to bottom): ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << "\n";

    // Example of std::queue
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << "Queue elements (front to back): ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << "\n";

    // Example of std::priority_queue
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    std::cout << "Priority Queue elements (highest to lowest): ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";

    // Example of std::priority_queue with custom comparator (lowest to highest)
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    min_pq.push(10);
    min_pq.push(5);
    min_pq.push(20);
    std::cout << "Priority Queue elements (lowest to highest): ";
    while (!min_pq.empty()) {
        std::cout << min_pq.top() << " ";
        min_pq.pop();
    }
    std::cout << "\n";

    return 0;
}