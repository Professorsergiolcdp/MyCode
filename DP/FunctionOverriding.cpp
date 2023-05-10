#include<iostream>
using namespace std;

class A{

    public:
        void show()
        {
            cout<<"From A"<<endl;
        }

};
class B:public A{
    public:
       void show()
        {
            cout<<"From B"<<endl;
        }
};


int main()
{
    A a;
    B b;
    a.show();
    b.A::show();
}
