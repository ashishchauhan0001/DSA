// Reverse words in a string
// Given a string str, the task is to reverse the order of the words in the given string. Note that str may contain leading or trailing dots(.) or multiple trailing dots(.) between two words. The returned string should only have a single dot(.) separating the words.

// Examples:

// Input: str = “i.like.this.program.very.much” 
// Output: str = “much.very.program.this.like.i” 


// Input: str = ”..geeks..for.geeks.” 
// Output: str = “geeks.for.geeks”

#include<bits/stdc++.h>
using namespace std;


string solve(string &s) {
        // code here
        string temp="";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                temp+=s[i];
            }else{
                if(!temp.empty()){
                    st.push(temp);
                    temp="";
                }
            }
        }
        if(!temp.empty()){
            st.push(temp);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty()){
                ans+=".";
            }
        }
        return ans;
    }


int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
 return 0;
}