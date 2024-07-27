
#include <iostream>
#include <vector>
using namespace std;

#include<unordered_map>

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
	unordered_map<int,bool> m;
    int max=INT16_MIN;
    int start,end;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
		m[arr[i]]=true;
    }
    for(int i=0;i<n;i++)
    {

        if(m.count(arr[i]))
        {
            start=end=arr[i];
            m[arr[i]]=false;
        }
        else
            continue;
        int j=1;
        while(true)
        {
           if(m.count(arr[i]+j))
           {
               end++;
               m[arr[i]+j]=false;
               j++;
           }
            else
                break;
        }
        j=1;
        while(true)
        {
           if(m.count(arr[i]-j))
           {
               start--;
               m[arr[i]-j]=false;
               j++;
           }
            else
                break;
            
        }
        int temp=end-start+1;// SIZE OF THE CONSECUTIVE MAP
        if(temp>max)
        {
            max=temp;
            if(ans.size())
                ans.clear(); 
            
            ans.push_back(start);
            if(start!=end)
            	ans.push_back(end);
        }
        if(temp==max)
        {
            for(int x=0;x<n;x++)
            {
                if(arr[x]==start)
                {
                    ans.clear();
					ans.push_back(start);
            		if(start!=end)
            			ans.push_back(end);
                    break;
                }
                if(arr[x]==ans[0])	
                    break;
            
            }
        }
    }
    return ans;
    
}
/*
int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        if(nums.size()==0) return 0;
        int ans=1;
        for(auto it:nums){
            s.insert(it); // unique and sorted O(1) complexity
        }

        for(auto it:s){
            if(s.find(it-1)==s.end()){ // means 2,3,4,5,6  inme se hum sirf 2 ke liye check krenge not for all others
                int curr=it;
                int cnt=1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    cnt++;
                }
                    ans=max(ans,cnt);
            }
        }

        return ans;

    }
*/



int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
