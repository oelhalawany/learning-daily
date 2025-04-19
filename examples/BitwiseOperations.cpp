#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;

void setBit(uint8_t& reg, uint8_t bit)
{
    reg |= (1u<<bit);
}

void resetBit(uint8_t& reg, uint8_t bit)
{
    reg &= ~(1u<<bit);
}

void toggleBit(uint8_t& reg, uint8_t bit)
{
    reg ^= (1u<<bit);
}

int readBit(const uint8_t& reg, uint8_t bit)
{
    return (int)(reg>>bit)&1u;
}

int main() {
    int a = 5;  // Binary: 0101
    int b = 3;  // Binary: 0011

    // AND operation
    cout << "a & b = " << (a & b) << " (Binary: " << bitset<4>(a & b) << ")" << endl;

    // OR operation
    cout << "a | b = " << (a | b) << " (Binary: " << bitset<4>(a | b) << ")" << endl;

    // XOR operation
    cout << "a ^ b = " << (a ^ b) << " (Binary: " << bitset<4>(a ^ b) << ")" << endl;

    // NOT operation
    cout << "~a = " << (~a) << " (Binary: " << bitset<8>(~a) << ")" << endl;

    // Left shift
    cout << "a << 1 = " << (a << 1) << " (Binary: " << bitset<4>(a << 1) << ")" << endl;

    // Right shift
    cout << "a >> 1 = " << (a >> 1) << " (Binary: " << bitset<4>(a >> 1) << ")" << endl;


    uint8_t registerX = 5;

    cout<< bitset<8>(registerX)<< endl;

    setBit(registerX, 5);
    cout<<"after set bit 5: "<<bitset<8>(registerX)<< endl;

    resetBit(registerX, 2);
    cout<< "after reset bit 2: "<<bitset<8>(registerX)<< endl;

    toggleBit(registerX, 7);
    cout<< "after toggle bit 7: "<<bitset<8>(registerX)<< endl;

    toggleBit(registerX, 7);
    cout<< "after toggle bit 7: "<<bitset<8>(registerX)<< endl;

    registerX = 55;
    cout<< "register current value: "<<bitset<8>(registerX)<< endl;
    cout<<"bit 1 value is: "<<readBit(registerX, 1)<<endl;
    cout<<"bit 2 value is: "<<readBit(registerX, 2)<<endl;
    cout<<"bit 6 value is: "<<readBit(registerX, 6)<<endl;
    cout<<"bit 7 value is: "<<readBit(registerX, 7)<<endl;

    return 0;
}