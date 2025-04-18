
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
class Box
{
private:
    vector<T> items;

public:
    void add(T item)
    {
        items.push_back(item);
    }

    int size()
    {
        return items.size();
    }

    T get(int index)
    {
        if (index >= items.size() || index < 0)
        {
            throw std::out_of_range("index out of range!");
        }

        if constexpr(is_integral<T>::value)
        {
            cout<<"value of int: "<<items[index]<<endl;
        }
        else if constexpr(is_floating_point<T>::value)
        {
            cout<<"value of float: "<<items[index]<<endl;
        }
        else if constexpr(is_same<T, string>::value)
        {
            cout<<"value of string: "<<items[index]<<endl;
        }

        return items[index];
    }
};

int main()
{
    /* create a container of type int */
    Box<int>intBox;

    intBox.add(5);
    intBox.add(7);

    try
    {
        intBox.get(0);
        intBox.get(1);
        intBox.get(2); //uncommenting this line will throw an out_of_range exception
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << endl;
    }

    /* create a container of type string */
    Box<string>strBox;

    strBox.add("omar");
    strBox.add("bob");
    strBox.add("alice");

    try
    {
        strBox.get(0);
        strBox.get(1);
        strBox.get(2);

        //throw 40; //uncommenting this line will throw an "unknown exception"
        
        strBox.get(3); //uncommenting this line will throw an out_of_range exception
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
    catch (...)
    {
        cerr << "unknown exception!" << endl;
    }

    /* create a container of type struct */
    struct temp
    {
        float temprature;
        float time;
    };

    Box<temp>tempBox;

    temp t1;
    t1.temprature = 10;
    t1.time = 20;

    tempBox.add(t1);

    auto t2 = tempBox.get(0);
    cout<<t2.temprature<<" "<<t2.time<<endl;

    tempBox.add({23.7,13.5});

    auto t3 = tempBox.get(1);
    cout<<t3.temprature<<" "<<t3.time<<endl;

    return 0;
}