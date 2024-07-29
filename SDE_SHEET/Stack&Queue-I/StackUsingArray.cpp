#include <iostream>
#include<vector>
#include<climits>
// statically stack
using namespace std;

 
class StackUsingArray
{
    private:
    vector<int> data; // int *data;
    int nextIndex;
    int capacity;// to store the value of nextIndex througout the code
    public:
    // alloated the size of the array or can say the size of the array.
    StackUsingArray(){};
    StackUsingArray(int totalSize)
    {
     data.resize(totalSize); // data=new int[totalsize]
     nextIndex=0;
     capacity=totalSize;
    }

    // return the number or size of elements present in my stack.
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        // if(nextIndex==0)
        // {
        //     return true;
        // }
        // else{
        //     return false;
        // }
    //  *****OR*****
     return nextIndex==0;
    }
    void push(int element)
    {
        if(nextIndex==capacity)
        {
            cout<<"stack is full please dont do any other operation"<<endl;
            return ;
        }
        data[nextIndex]=element;
        nextIndex++;
    }

    int pop()
    {
        // if(nextIndex==0)
        // {
        //     cout<<"Stack is empty "<<endl;
        // }
        if(isEmpty())
        {
            cout<<"Stack is empty "<<endl;
            return INT8_MIN; 
        }
        nextIndex--;
        return data[nextIndex];

    }

    int top()
    {
        // we can use nextIndex==0;
        if(isEmpty())
        {
            cout<<"Stack is empty "<<endl;
            return INT8_MIN;
        }
        return data[nextIndex-1];
    }
 

};
int main()
{
    StackUsingArray s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;
}