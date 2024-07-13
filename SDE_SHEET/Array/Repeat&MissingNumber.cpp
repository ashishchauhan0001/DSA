vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // Write your code here
    long long n=a.size();
    long long x=accumulate(a.begin(),a.end(),0);
    long long y=(n*(n+1))/2;
    // cout<<y<<" ";
    long long val1=x-y;
    long long x2=0;
    long long y2=(n*(n+1)*(2*n+1))/6;

    for(long long i=0;i<n;i++){
        x2+=((long long)a[i]*(long long)a[i]);
    }
    long long val2=(x2-y2);
    long long val3=val2/val1;
    long long repeated=(val3+val1)/2;
    long long missing=(val3-repeated);

    return {(int)repeated,(int)missing};


}