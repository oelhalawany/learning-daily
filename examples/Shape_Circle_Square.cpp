#include <iostream>
#include <memory>

using namespace std;

class Shape
{
    protected:
    string color;

    public:

    Shape():color("white"){
        cout<<"Shape's default constructor is called."<<endl;
    }

    Shape(string color_): color(color_) {
        cout<<"Shape created with color "<<color<<endl;
    };

    virtual double area() 
    {
        return 0;
    };

    virtual ~Shape(){
        cout<<"Shape deleted with color "<<color<<endl;
    };
};

class Circle : public Shape
{
    private:
    int radius;

    public:
    Circle(int radius_, string color_):radius(radius_), Shape(color_){
        cout<<"Circle created with radius "<<radius<<" and color "<<color<<endl;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
    
    ~Circle(){
        cout<<"Circle deleted with radius "<<radius<<" and color "<<color<<endl;
    }
};

class Square : public Shape
{
    private:
    int side;

    public:
    Square(int side_, string color_):side(side_), Shape(color_){
        cout<<"Square created with side "<<side<<" and color "<<color<<endl;
    }

    double area() override {
        return side*side;
    }

    ~Square(){
        cout<<"Square deleted with side "<<side<<" and color "<<color<<endl;
    }

};


int main()
{
    Shape * shape1;
    Circle c1(5,"red");
    shape1 = &c1;
    cout << "Area of Circle: " << shape1->area() << endl;

    Shape* shape2 = new Square(4,"blue");
    cout << "Area of Square: " << shape2->area() << endl;
    delete shape2;

    unique_ptr<Shape> shape3 = make_unique<Circle>(7, "green");
    cout << "Area of Circle (unique_ptr): " << shape3->area() << endl;

    return 0;
}