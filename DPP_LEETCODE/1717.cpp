class Solution {
public:
  int find(string &s,int val,char c,char p){
    int ans=0;
    for(int i=1;i<s.size();i++){
      if(s[i]==c&&s[i-1]==p){
        s.erase(i-1,2);
        ans+=val;
        i = max(0, i-1); // moving back to the index
        cout<<"out: "<<s[i]<<" ";
        while((i-1>=0&&i<s.size())&&(s[i]==c&&s[i-1]==p)){
        s.erase(i-1,2);
        ans+=val;
        i = max(0, i-1);
        cout<<"in: "<<s[i]<<" ";
        }
      }
    }

    return ans;
  }

    int maximumGain(string s, int x, int y) {
        int ans=0;
        if(x>=y){ // ab
         ans+=find(s,x,'b','a');
         cout<<s<<endl;
         ans+=find(s,y,'a','b');
        }
        else{ // ba
         ans+=find(s,y,'a','b');
          cout<<s<<endl;
         ans+=find(s,x,'b','a');
        }

        return ans;

    }
};