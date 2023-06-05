#include<iostream>
#include<stdlib.h>
#include <vector>

using namespace std;

class Shape{
    private:
        int x ;
        int y ;

    public:
        Shape();
        Shape (int , int);
        virtual string draw();
        virtual float calculateArea()=0;
        int getX();
        int getY();
};

Shape::Shape(){
    x =0;
    y =0;
}

Shape::Shape(int _x, int _y){
    x = _x;
    y = _y;
}

string Shape::draw(){
    string msg = "I'm a shape";
    return msg;
}

int Shape::getX(){
    return x;
}

int Shape::getY(){
    return y;
}

class Circle:public Shape
{
    private:
        int radius;
    public:
        Circle();
        Circle(int _x, int _y, int _radius);
        int getRadius();
        string draw() override;
        float calculateArea() override;
};

Circle::Circle()
{
    radius = 0;
}
Circle::Circle(int _x, int _y, int _radius) : Shape(_x, _y)
{
    radius = _radius;
}

int Circle::getRadius()
{
return radius;
}

string Circle::draw() {
    string msg = "I'm a CIRCLE";
    return msg;
}

float Circle::calculateArea(){
    return (radius*radius*3.1416);
}



int main()
{
    vector <Shape*> shapes;
   // shapes.push_back(new Shape(1,1));
    shapes.push_back(new Circle(4, 4, 7));
   // shapes.push_back(new Shape(4, 5));
    shapes.push_back(new Circle(1, 2, 5));

    vector<Shape*>::const_iterator i;
    for(i = shapes.begin(); i != shapes.end(); ++i)
    {
        cout << "Shape: " << (*i)->draw() << endl;
        cout << "Shape: " << (*i)->calculateArea() << endl;
    }


    Shape *c1 = new Circle(1,1,1);
    cout << "\n\nC1: " << c1->draw() << endl;

    cout << "\nC1: " << c1->Shape::draw() << endl;

    return 0;
}
