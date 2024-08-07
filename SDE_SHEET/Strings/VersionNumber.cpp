class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        int i=0,j=0;
       
        while(i<version1.size()){
          string temp="";
          while(version1[i]!='.'&&i<version1.size()){
            temp+=version1[i];
            i++;
          }
          v1.push_back(stoi(temp));
          i++;
        }
        while(j<version2.size()){
          string temp="";
          while(version2[j]!='.'&&j<version2.size()){
            temp+=version2[j];
            j++;
          }
          v2.push_back(stoi(temp));
          j++;
        }
        i=0,j=0;
        while(i<v1.size()&&j<v2.size()){
            if(v1[i]>v2[j]) return 1;
            else if(v1[i]<v2[j]) return -1;
            i++;
            j++;
        }
        while(i<v1.size()){
            if(v1[i]>0) return 1;

            i++;
        }
        while(j<v2.size()){
            if(v2[j]>0) return -1;
            
            j++;
        }

        return 0;
    }
};