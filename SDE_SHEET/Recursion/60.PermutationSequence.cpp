class Solution {
public:

    void solve(string str,vector<string> &val,int index){
            if(index==str.size()){
                val.push_back(str);
            }
            for(int i=index;i<str.size();i++){
                swap(str[i],str[index]);
                solve(str,val,index+1);
                swap(str[i],str[index]);
                swap(str[i],str[index]); // so that elements remain sorted.
            }

            return ;
    }

    string getPermutation(int n, int k) {
         string str="";
         for(int i=1;i<=n;i++){
            str+=to_string(i);
         }
         vector<string> val;
         solve(str,val,0);
         return (val[k-1]);
        
    }
};