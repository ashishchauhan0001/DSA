// Count number of Distinct Substring in a String
// Last Updated : 22 May, 2023
// Given a string, count all distinct substrings of the given string.

// Examples: 

// Input : abcd
// Output : abcd abc ab a bcd bc b cd c d
// All Elements are Distinct

// Input : aaa
// Output : aaa aa a aa a a
// All elements are not Distinct

#include <bits/stdc++.h>
using namespace std;

vector<string> solve(string str) {
    set<string> substrings; // To store distinct substrings

    // Generate all substrings
    for (int i = 0; i < str.size(); i++) {
        string temp = "";
        for (int j = i; j < str.size(); j++) {
            temp += str[j];
            substrings.insert(temp); // Insert the substring into the set
        }
    }

    // Convert set to vector for output
    vector<string> result(substrings.begin(), substrings.end());
    return result;
}

int main() {
    string str;
    cin >> str;

    vector<string> ans = solve(str);

    cout<<ans.size()+1;
    return 0;
}
