class Solution {
public:
    vector<int> NSE(vector<int> arr){
        vector<int> ans;
        stack<int>s; // store indexes 
        s.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(!s.empty() && s.top()!=-1 && arr[s.top()]>=arr[i]) s.pop();
            int NSEt=s.top()==-1?-1:s.top();
            ans.push_back(s.top());
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> PSE(vector<int> arr){
        vector<int> ans;
        stack<int>s; // store indexes 
        s.push(-1);
        for(int i=0;i<arr.size();i++){
            while(!s.empty() && s.top()!=-1 && arr[s.top()]>=arr[i]) s.pop();
            ans.push_back(s.top());
             s.push(i);
        }
        return ans;
    } 

    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> next(n);
        next=NSE(heights);
        vector<int> prev(n);
        prev=PSE(heights);

        int area=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int l=heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            int newArea=l*b;
            area=max(newArea,area);
        }
        return area;
    }
};