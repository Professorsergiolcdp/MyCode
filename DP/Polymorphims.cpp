#include <iostream>
#include<list>
#include<iterator>
using namespace std;

class BaseClass {
    public: 
    virtual void nonVirtual(){
      cout<<"Show from A"<<endl;
    }
};

class DerivedClass: public BaseClass{

  public:
    void nonVirtual()
    {
      cout<<"Calling derived class method from base pointer"<<endl;
    }
};


int main()
{
  BaseClass bc;
  DerivedClass dc;
	list<BaseClass*> bptr;
  bptr.push_back(&dc);
  bptr.push_back(&bc);
  for(auto item : bptr)
  {
    item->nonVirtual();
  }
  
}
