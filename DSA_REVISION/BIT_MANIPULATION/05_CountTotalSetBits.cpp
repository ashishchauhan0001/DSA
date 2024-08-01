int pow2(int n){
       int ans=0;
       int a=1;
       while(n>=a){
           ans++;
           a=(1<<ans);
       }
       return ans-1; // bcz at ans we will get boundry cndtn
   }
   
   int countSetBits(int n)
    {
        if(n==0) return 0;
        
        int x=pow2(n); // largest power less or equal to n;
        int count1=x*(1<<(x-1)); // from 0 to x
        int count2=n-(1<<x)+1;// from x to n
        int rem=n-(1<<x);
        
        return count1+count2+countSetBits(rem);
        
    }