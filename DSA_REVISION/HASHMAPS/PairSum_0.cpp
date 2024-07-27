
#include <iostream>
#include<unordered_map>
using namespace std;

int pairSum(int *arr, int n)
 {
	
    int count=0;
    unordered_map<int,int>m;
    // 2 3 -2 2 5=2
    for(int i=0;i<n;i++)
    {
        if(m[-arr[i]]>0)
        {
            count+=m[-arr[i]];
        }
        m[arr[i]]++;
    }
    return count; 
 }


 int fun(int arr[],int n){ 
    unordered_map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++){
        if(m[-arr[i]]>0){
            ans+=m[-arr[i]];
        }
        m[arr[i]]++;
    }
    return ans;
 }

int main()
{
     int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout <<"no of pair whose sum is zero  : "<< pairSum(arr, n);
    cout<<"\n";
     cout <<"no of pair whose sum is zero  : "<< fun(arr, n);

    delete[] arr;
    return 0;
}



