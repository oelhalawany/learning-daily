#include <iostream>

using namespace std;

class Singleton
{
    private:
    Singleton(){
        cout<<"I am created!"<<endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    public:

    static Singleton* getInstance()
    {
        static Singleton instance_;
        return &instance_;
    }

};

int main()
{
    // Attempt to get multiple instances
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();
    Singleton* instance3 = Singleton::getInstance();

    // Verify that all instances point to the same object
    if (instance1 == instance2 && instance2 == instance3) {
        cout << "All instances are the same!" << endl;
    } else {
        cout << "Instances are different!" << endl;
    }

    return 0;
}