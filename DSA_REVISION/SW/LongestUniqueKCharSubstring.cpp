int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>m;
    int i=0,j=0;
    int ans=-1;
    
    while(j<s.size()){
        m[s[j]]++;
        
        if(m.size()<k) j++;
        else if(m.size()==k){
            ans=max(ans,(j-i+1));
            j++;
        }
        else{
            while(m.size()>k){
                m[s[i]]--;
                if(m[s[i]]==0){
                    m.erase(s[i]); // to remove it completly
                }
                i++;
            }
            j++;
        }
    }
    return ans;
    }