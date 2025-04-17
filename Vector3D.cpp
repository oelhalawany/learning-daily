#include <iostream>
#include <cmath>

class Vector3D {

private:
    double x_, y_, z_;

public:
    Vector3D(double x, double y, double z): x_(x), y_(y), z_(z){}

    double magnitude() const
    {
        return std::sqrt(std::pow(x_,2)+std::pow(y_,2)+std::pow(z_,2));
    }

    Vector3D operator+(const Vector3D& other) const
    {
        return Vector3D(x_+other.x_, y_+other.y_, z_+other.z_);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& vec)
    {
        os << "(" << vec.x_ << ", " << vec.y_ << ", " << vec.z_ << ")";
        return os;
    }

};


int main() {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);

    Vector3D result = v1 + v2;

    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;
    std::cout << "v1 + v2 = " << result << std::endl;
    std::cout << "Magnitude of v1: " << v1.magnitude() << std::endl;

    return 0;
}