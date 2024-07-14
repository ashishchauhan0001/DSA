class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        int size=abs(n);
        for(int i=0;i<size;i++){
            ans=ans*x;
        }
        if(n<0) ans=1.0/ans;
        return ans;
    }
};