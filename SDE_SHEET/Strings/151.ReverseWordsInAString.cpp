string reverseWords(string s) {
        vector<string> v; 
        string str="";
        int it=0;
        int j=s.size()-1;
        while(it<s.size()){
             if(s[it]==' ') it++;
             else break;  
        }

        while(j>=0){
            if(s[j]==' ') j--;
            else break;
        }

        for(int i=it;i<=j;i++){
            if(s[i]==' '&&s[i-1]!=' '){ // " It_is_a__blue__sky"  --> '_' represent space
                v.push_back(str);
                str="";
                continue;
            }
            else if(s[i]==' '&&s[i-1]==' '){  // for avoiding added the space into the result.
               continue;
            }
            else if(i+1==j+1){
                str+=s[i];
                v.push_back(str);
                break;
            }
            str+=s[i];
        }
        str="";
        for(int i=v.size()-1;i>=0;i--){
            str+=v[i];
            if(i-1>=0)str+=" ";
        }
        return str;
    }