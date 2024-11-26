// Check if a given string is a rotation of a palindrome.

// Given a string, check if it is a rotation of a palindrome. For example your function should return true for “aab” as it is a rotation of “aba”. 

// Examples: 

// Input:  str = "aaaad"
// Output: 1  
// // "aaaad" is a rotation of a palindrome "aadaa"

// Input:  str = "abcd"
// Output: 0
// // "abcd" is not a rotation of any palindrome.

#include<bits/stdc++.h>
using namespace std;

bool isPal(string s){
    int low=0;
    int high=s.size()-1;
    while(low<=high){
        if(s[low]!=s[high]) return false;
        low++;
        high--;
    }
    return true;
}


bool solve(string str){

     for(int i=0;i<str.size();i++){
        string s1=str.substr(i+1,str.size()-1-i);
        string s2=str.substr(0,i+1);
        if(isPal(s1+s2)) return true;
     }

     return false;
}

int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
 return 0;
}