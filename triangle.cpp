#include <iostream>

using namespace std;

// class dot_3D ----------- start
class dot_3D {
    private:
        float x_dot3D, y_dot3D, z_dot3D;
    public:
        dot_3D();
        ~dot_3D();
        dot_3D(float x, float y, float z);
        //dot_3D(float x, float y, float z) : x_dot3D(x), y_dot3D(y), z_dot3D(z);
        void set�oordinate(float x, float y, float z);
        void print�oordinate();
        float get�oordinateX();
        float get�oordinateY();
        float get�oordinateZ();    
};

dot_3D::dot_3D() {
    x_dot3D = 0;
    y_dot3D = 0;
    z_dot3D = 0;
}

dot_3D::~dot_3D()
{
}

dot_3D::dot_3D(float x, float y, float z) {
    x_dot3D = x;
    y_dot3D = y;
    z_dot3D = z;
}

void dot_3D::set�oordinate(float x, float y, float z) {
    x_dot3D = x;
    y_dot3D = y;
    z_dot3D = z;
}

void dot_3D::print�oordinate() {
    cout << "x = " << x_dot3D << ", y = " << y_dot3D << ", z = " << z_dot3D;
}
float dot_3D::get�oordinateX() {
    return x_dot3D;
}
float dot_3D::get�oordinateY() {
    return y_dot3D;
}
float dot_3D::get�oordinateZ() {
    return z_dot3D;
}
// class dot_3D ----------- End

// class triangle ----------- Start
class triangle_3D {
private:
    dot_3D apex[3];
public:
    triangle_3D();
    ~triangle_3D();
    triangle_3D(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2);
    void setTriangle�oordinate(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2);
    void printTriangle();
    float perimeterTriangle();
    float areaTriangle();
    void normalTriangle();
    void inner_corners();
    void center_of_gravity();
};

triangle_3D::triangle_3D() {
    apex[0].set�oordinate(0, 0, 0);
    apex[1].set�oordinate(0, 0, 0);
    apex[2].set�oordinate(0, 0, 0);
}

triangle_3D::~triangle_3D()
{
}

triangle_3D::triangle_3D(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2) {
    apex[0].set�oordinate(x0, y0, z0);
    apex[1].set�oordinate(x1, y1, z1);
    apex[2].set�oordinate(x2, y2, z2);
}

void triangle_3D::printTriangle() {
    cout << "A("; apex[0].print�oordinate(); cout << ")\n"; 
    cout << "B("; apex[1].print�oordinate(); cout << ")\n";
    cout << "C("; apex[2].print�oordinate(); cout << ")\n";
}

void triangle_3D::setTriangle�oordinate(float x0, float y0, float z0, float x1, float y1, float z1, float x2, float y2, float z2) {
    apex[0].set�oordinate(x0, y0, z0);
    apex[1].set�oordinate(x1, y1, z1);
    apex[2].set�oordinate(x2, y2, z2);
}

float triangle_3D::perimeterTriangle() {
    float triangle_side01, triangle_side12, triangle_side20;
    
    triangle_side01 = sqrt( pow((apex[0].get�oordinateX() - apex[1].get�oordinateX()), 2) + pow((apex[0].get�oordinateY() - apex[1].get�oordinateY()), 2) + pow((apex[0].get�oordinateZ() - apex[1].get�oordinateZ()), 2));
    triangle_side12 = sqrt( pow((apex[1].get�oordinateX() - apex[2].get�oordinateX()), 2) + pow((apex[1].get�oordinateY() - apex[2].get�oordinateY()), 2) + pow((apex[1].get�oordinateZ() - apex[2].get�oordinateZ()), 2));
    triangle_side20 = sqrt( pow((apex[2].get�oordinateX() - apex[0].get�oordinateX()), 2) + pow((apex[2].get�oordinateY() - apex[0].get�oordinateY()), 2) + pow((apex[2].get�oordinateZ() - apex[0].get�oordinateZ()), 2));

    return triangle_side01 + triangle_side12 + triangle_side20;
}

float triangle_3D::areaTriangle() {
    dot_3D vector1, vector2;
    
    vector1.set�oordinate(apex[1].get�oordinateX() - apex[0].get�oordinateX(), apex[1].get�oordinateY() - apex[0].get�oordinateY(), apex[1].get�oordinateZ() - apex[0].get�oordinateZ());
    vector2.set�oordinate(apex[2].get�oordinateX() - apex[0].get�oordinateX(), apex[2].get�oordinateY() - apex[0].get�oordinateY(), apex[2].get�oordinateZ() - apex[0].get�oordinateZ());
    

    float vector_productX = vector2.get�oordinateY() * vector1.get�oordinateZ() - vector2.get�oordinateZ() * vector1.get�oordinateY();
    float vector_productY = vector2.get�oordinateZ() * vector1.get�oordinateX() - vector2.get�oordinateX() * vector1.get�oordinateZ();
    float vector_productZ = vector2.get�oordinateX() * vector1.get�oordinateY() - vector2.get�oordinateY() * vector1.get�oordinateX();

    return sqrt(pow(vector_productX, 2) + pow(vector_productY, 2) + pow(vector_productZ, 2)) / 2;
}

void triangle_3D::normalTriangle() {
    dot_3D vector1, vector2, normal, normal_new;

    vector1.set�oordinate(apex[1].get�oordinateX() - apex[0].get�oordinateX(), apex[1].get�oordinateY() - apex[0].get�oordinateY(), apex[1].get�oordinateZ() - apex[0].get�oordinateZ());
    vector2.set�oordinate(apex[2].get�oordinateX() - apex[0].get�oordinateX(), apex[2].get�oordinateY() - apex[0].get�oordinateY(), apex[2].get�oordinateZ() - apex[0].get�oordinateZ());


    float vector_productX = vector2.get�oordinateY() * vector1.get�oordinateZ() - vector2.get�oordinateZ() * vector1.get�oordinateY();
    float vector_productY = vector2.get�oordinateZ() * vector1.get�oordinateX() - vector2.get�oordinateX() * vector1.get�oordinateZ();
    float vector_productZ = vector2.get�oordinateX() * vector1.get�oordinateY() - vector2.get�oordinateY() * vector1.get�oordinateX();

    float normalization = sqrt(pow(vector_productX,2) + pow(vector_productY,2) + pow(vector_productZ,2));
    
    normal.set�oordinate(vector_productX, vector_productY, vector_productZ);
    cout << "coordinate of normal: "; normal.print�oordinate(); cout << endl;
    
    normal_new.set�oordinate(vector_productX / normalization, vector_productY / normalization, vector_productZ / normalization);
    cout << "coordinate of normal after normalization: "; normal_new.print�oordinate(); cout << endl;
}

void triangle_3D::inner_corners() {
    float triangle_side01, triangle_side12, triangle_side20;

    float area = areaTriangle();

    triangle_side01 = sqrt(pow((apex[0].get�oordinateX() - apex[1].get�oordinateX()), 2) + pow((apex[0].get�oordinateY() - apex[1].get�oordinateY()), 2) + pow((apex[0].get�oordinateZ() - apex[1].get�oordinateZ()), 2));
    triangle_side12 = sqrt(pow((apex[1].get�oordinateX() - apex[2].get�oordinateX()), 2) + pow((apex[1].get�oordinateY() - apex[2].get�oordinateY()), 2) + pow((apex[1].get�oordinateZ() - apex[2].get�oordinateZ()), 2));
    triangle_side20 = sqrt(pow((apex[2].get�oordinateX() - apex[0].get�oordinateX()), 2) + pow((apex[2].get�oordinateY() - apex[0].get�oordinateY()), 2) + pow((apex[2].get�oordinateZ() - apex[0].get�oordinateZ()), 2));

    cout << "1. inner corner of a triangle: " << (asin(2 * area / (triangle_side01 * triangle_side12))) * 180 / 3.141592653589793 << endl;
    cout << "2. inner corner of a triangle: " << (asin(2 * area / (triangle_side01 * triangle_side20))) * 180 / 3.141592653589793 << endl;
    cout << "3. inner corner of a triangle: " << (asin(2 * area / (triangle_side12 * triangle_side20))) * 180 / 3.141592653589793 << endl;

}

void triangle_3D::center_of_gravity() {
    dot_3D grav;
    
    float x_grav = (apex[0].get�oordinateX() + apex[1].get�oordinateX() + apex[2].get�oordinateX()) / 3;
    float y_grav = (apex[0].get�oordinateY() + apex[1].get�oordinateY() + apex[2].get�oordinateY()) / 3;
    float z_grav = (apex[0].get�oordinateZ() + apex[1].get�oordinateZ() + apex[2].get�oordinateZ()) / 3;

    grav.set�oordinate(x_grav, y_grav, z_grav);

    cout << "center of gravity: ";
    grav.print�oordinate();
    cout << endl;

}
// class triangle ----------- End

int main()
{
    triangle_3D trian;

    trian.setTriangle�oordinate(0,0,0,4,3,0,4,0,0);
    trian.printTriangle();
    cout << "perimeter of triangle: " << trian.perimeterTriangle() << endl;
    cout << "area of triangle: " << trian.areaTriangle() << endl;
    trian.normalTriangle();
    //trian.areaTriangle();
    trian.inner_corners();
    trian.center_of_gravity();

    return 0;
}
