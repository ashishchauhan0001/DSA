#include<bits/stdc++.h>
using namespace std;


void swap(int &a,int &b){
   a= a^b;b=a^b;a=a^b;
}

void swap2(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

int main()
{
    int a,b; cin>>a>>b;
     swap2(a,b); cout<<"After swapping: "<<"a = "<<a<<" b= "<<b;
   return 0;
}