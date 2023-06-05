#include <iostream>
#include <string>
using namespace std;

class BaseClass {
    public:
        void disp(){
            cout<<"Function of Parent Class"<<endl;
}
};

class DerivedClass: public BaseClass{
    public:
        void disp(){
            cout<<"Function of Child Class"<<endl;
}
};

int main(){
    BaseClass obj;
    obj.disp();

    DerivedClass obj2;
    obj2.disp();

    cout << "Hola, esta es una prueba" << endl;
}