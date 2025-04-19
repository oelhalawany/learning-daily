#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <initializer_list>

using namespace std;

class Circle
{   
    public:
        int radius;
        Circle(int r): radius(r){}
};

class Box
{   
    public:
        int side;
        Box(int s): side(s){}
};

class Shapes
{
    private:
        set<int>circles;
        set<int>boxes;

    public:
        Shapes(){}
        Shapes(initializer_list<int>c, initializer_list<int>b): circles(c), boxes(b){}

        /* Adds a Circle to the current Shapes object by modifying it in place.
           Returns a reference to the current object to allow chaining. */
        Shapes& operator+(const Circle&c)
        {
            circles.insert(c.radius);
            return *this;
        }

        /* Adds a Box to the current Shapes object by creating a new Shapes object.
           Returns the new Shapes object without modifying the original. */
        Shapes operator+(const Box&b)
        {
            Shapes out = *this;
            out.boxes.insert(b.side);
            return out;
        }

        /* Combines the current Shapes object with another Shapes object.
           Returns a new Shapes object containing the union of both objects' circles and boxes.*/
        Shapes operator+(const Shapes& other)
        {
            Shapes out = *this;
            out.circles.insert(other.circles.begin(), other.circles.end());
            out.boxes.insert(other.boxes.begin(), other.boxes.end());
            return out;
        }

        void print()
        {
            cout<<"circles:"<<endl;
            for(auto c:circles) cout<<c<<" ";
            cout<<endl;

            cout<<"boxes:"<<endl;
            for(auto b:boxes) cout<<b<<" ";
            cout<<endl<<endl;
        }
};


int main() {

    Shapes s1({1,2,3},{6,7,8});

    s1.print();

    Circle c1(5);
    Box b1(9);

    cout<<"add circle 5:"<<endl;
    s1 + c1; // Modifies `s1` directly
    s1.print();

    cout<<"add box 9:"<<endl;
    s1 = s1 + b1; // Creates a new `Shapes` object and assigns it to `s1`
    s1.print();

    Shapes s2({10,20,30},{60,70});

    cout<<"shapes 1:"<<endl;
    s1.print();

    cout<<"shapes 2:"<<endl;
    s2.print();

    cout<<"add shapes 2 to shapes 1: "<<endl;
    s1 = s1 + s2;

    s1.print();

    return 0;
}
