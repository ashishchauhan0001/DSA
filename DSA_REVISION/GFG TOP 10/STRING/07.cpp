// Minimum Characters to Add at Front for Palindrome

// Given a string s, the task is to find the minimum number of characters to be added to the front of s to make it palindrome. A palindrome string is a sequence of characters that reads the same forward and backward.

// Examples: 

// Input: s = “abc”
// Output: 2
// Explanation: We can make above string palindrome as “cbabc”, by adding ‘b’ and ‘c’ at front.

// Input: str = “aacecaaaa”
// Output: 2
// Explanation: We can make above string palindrome as “aaaacecaaaa” by adding two a’s at front of string.

#include<bits/stdc++.h>
using namespace std;

int solve(string str){

    int i=0;
    int j=str.size()-1;
    int l=j;
    while(i<=j){
        if(str[i]==str[j]){
            i++;
            j--;
        }else{
            i=0;
            l--;
            j=l;
        }
    }
    int ans=str.size()-l-1;
    return ans;
}


int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
 return 0;
}