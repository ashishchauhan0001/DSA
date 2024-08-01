class Solution {
public:


    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if((dividend==INT_MIN && divisor==1)) return INT_MIN;
        if((dividend==INT_MAX && divisor==-1)) return -1*INT_MAX;
        bool sign=true;// for +ve
        long long ans=0;
        if(dividend<=0 && divisor>0) sign=false;// -ve;
        if(dividend>=0 && divisor<0) sign=false;// -ve;
        long long n=abs(dividend);
        long long d=abs(divisor);
        while(n>=d){
            long long cnt=0;
            while((d<<cnt+1)<=n) cnt++;
            ans+=(1<<cnt);
            n=n-(d*(1<<cnt));
        }
        if(ans>=INT_MAX && sign == true) return INT_MAX;
        if(ans>=INT_MAX && sign == false) return INT_MIN;

        return sign? ans :(-1*ans);
    }
};