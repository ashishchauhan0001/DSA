#include<bits/stdc++.h>
using namespace std;


string solve(string str){
    int start=0;
    int val=1;
    for(int i=1;i<str.size();i++){
        int left=i-1;
        int right=i;
        while(left>=0 && right<str.size() && str[left]==str[right]){
              if(right-left+1>val){
                val=right-left+1;
                start=left;
              }
              left--;
              right++;
        }
        left=i-1;
        right=i+1;

        while(left>=0 && right<str.size() && str[left]==str[right]){
              if(right-left+1>val){
                val=right-left+1;
                start=left;
              }
              left--;
              right++;
        }
    }
    return str.substr(start,val);

}

int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
 return 0;
}