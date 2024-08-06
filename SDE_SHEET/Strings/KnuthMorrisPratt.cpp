// // Naive Method
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {

//    string str,pat;
//    cin>>str>>pat;
//    int i=0;
//    int j=0;
//    while(j<pat.size()&&i<str.size()){

//       if(str[i]==pat[j]){
//         i++;
//         j++;
//       }else{
//         if(j==0) i++;
//         else{
//           i=i-j+1;
//           j=0;
//         }
//       }

//    }
//    if(j==pat.size()){
//     cout<<"Found at Index : "<<i-pat.size()<<endl;
//    }else{
//     cout<<"Not Found 400!"<<endl;
//    }

//  return 0;
// }


// Knuth Morris

#include <iostream>
#include <vector>
using namespace std;

// Function to create the LPS (Longest Prefix Suffix) array
void computeLPSArray(string pat, vector<int>& lps) {
    int i = 0; // i of the previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0
    int j = 1;

    // The loop calculates lps[i] for i = 1 to M-1
    while (j < pat.length()) {
        if (pat[j] == pat[i]) {
            i++;
            lps[j] = i;
            j++;
        } else {
            if (i != 0) {
                i = lps[i - 1];
            } else {
                lps[j] = 0;
                j++;
            }
        }
    }
}

// KMP search function
void KMPSearch(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();

    // Create the LPS array
    vector<int> lps(M);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, lps);

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]

    while (i < N) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
