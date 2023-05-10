#include<iostream>
using namespace std;

class Stack
{
    int *arr;
    int capacity;
    int top;
    public:
        Stack(int cap)
        {
            arr = new int[cap];
            capacity = cap;
            top = -1;
        }

        void push(int ele)
        {
            if(top == capacity-1)
            {
                cout<<"Stack Overflow"<<endl;
            }
            arr[++top] = ele;
        }

        void pop()
        {
            if(top == -1)
            {
                cout<<"Stack is Empty"<<endl;
                return;
            }
            int val = arr[top];
            top--;
        }
        int peek()
        {
            if(top == -1)
            {
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            return arr[top];
        }

        void printStack()
        {
            for(int i = top; i >= 0 ; i--)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main()
{
    Stack s(5);
    s.push(1);
    s.push(3);
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    s.printStack();
}