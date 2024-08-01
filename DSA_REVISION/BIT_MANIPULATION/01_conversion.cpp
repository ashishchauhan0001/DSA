#include<bits/stdc++.h>
using namespace std;

string blackBox(int n){
    string str="";

    while(n>0){
        if(n%2==1) str+='1';
        else str+='0';
        n=n/2;
    }
    reverse(str.begin(),str.end());
    return (str);
}


int blackBox2(int n){
    int ans=0;
    string str=to_string(n);
    reverse(str.begin(),str.end());
    for(int i=0;i<str.size();i++){
        if(str[i]=='1')ans+=pow(2,i);
    }

    return ans;
}

int main()
{

   int n;
   cin>>n;
   cout<<"Decimal to binary : "<<blackBox(n)<<endl;
   int b;
   cout<<"Enter the binary Number : ";
   cin>>b;
   cout<<" binary to decimal : "<<blackBox2(b)<<endl;

 return 0;
}