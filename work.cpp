#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
    int real;
    int img;
    public:
    Complex(){};
    Complex(int a,int b):real(a),img(b){};
    
    Complex operator+(Complex &obj){
        Complex res;
        res.real=real+obj.real;
        res.img=img+obj.img;
        return res;
    }
    void print(){
        cout<<real<<"+"<<img<<"i"<<endl;
    }

};

int main()
{
    Complex obj1(1,2);
    Complex obj2(2,3);
    Complex obj3=obj1+obj2;
    obj3.print();

 return 0;
}