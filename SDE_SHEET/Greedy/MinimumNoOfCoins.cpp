/*
Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change.

Examples:

Example 1:

Input: V = 70

Output: 2

Explaination: We need a 50 Rs note and a 20 Rs note.
*/

#include<bits/stdc++.h>
using namespace std;

int fun(int n){

    int ans=0;
    vector<int> c={1,2,5,10,20,50,100,500,1000};
    int j=8;
    while(n>0&&j>=0){
      if(n>=c[j]){
        int temp=n/c[j];
        n=n%c[j];
        ans+=temp;
      }
      j--;
    }

    return ans;
}

int main()
{
    int V;
    cin>>V;
    cout<<fun(V);
 return 0;
}