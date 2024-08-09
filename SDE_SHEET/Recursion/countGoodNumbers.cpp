int mod=1e9+7;
class Solution {
public:
// log(N)
    long long expoMethod(long long base,long long exp){
        long long result=1;
        while(exp>0){
            if(exp%2==1){
                result=(result*base)%mod;
            }
            base=(base*base)%mod;
            exp=exp/2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans1=expoMethod(5,even);
        long long ans2=expoMethod(4,odd);

        return (ans1*ans2)%mod;
    }
};