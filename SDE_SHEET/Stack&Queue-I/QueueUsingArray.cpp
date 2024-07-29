#include <iostream>
using namespace std;
template<typename T>

// STATICALLY MEMORY ALLOCATION


// it works on FIFO principle means first in and first out.
class QueueUsingArray
{
    T * data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    public:
    //QueueUsingArray(){};
    QueueUsingArray(int s)// size of the queue
    {
        data=new T[s];
        nextIndex=0;
        firstIndex=-1;// we have to add 1 by which we get element at 0th index
        size=0;
        capacity=s;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size==0;
    }

    void enqueue(T element)
    {
        if(size==capacity)
        {
            cout<<"queue is full"<<endl;
            return ;
        }
       data[nextIndex]=element; 
       nextIndex=(nextIndex+1)%capacity;
       if(firstIndex==-1)
       {
        firstIndex=0;
       }
       size++;
    }
    T front()
    {
        if(isEmpty())
      {
        cout<<"queue is empty"<<endl;
        return 0;
      } 
        return data[firstIndex];
    }
    T dequeue()
    {
      if(isEmpty())
      {
        cout<<"queue is empty"<<endl;
      } 
      T ans= data[firstIndex];
      firstIndex=(firstIndex+1) % capacity;
      size--;
      if(size==0)// for better pratice;
      {
        firstIndex=-1;
        nextIndex=0;
      }
      return ans;
    }
};


int main()
{
    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout<< q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
      
    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;

    return 0;
}