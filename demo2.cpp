// Question 2:

// Imagine you’re planning a road trip along a circular route, with several pit stops along the way. Each pit stop has a certain amount of fuel available, represented by gas[i]. Your car has an unlimited fuel tank, but it requires a specific amount of fuel, cost[i], to travel from the current pit stop to the next one on the route. 

// You start your journey with an empty fuel tank at one of these pit stops. Your task is to figure out if you can complete the entire circular trip, stopping at each pit stop once and returning to the starting point without running out of fuel. 

// Given two arrays gas and cost, where gas[i] represents the fuel available at each pit stop and cost[i] represents the fuel needed to travel to the next stop, determine the starting pit stop (index) where you can begin the journey and complete the entire loop. If it’s not possible to complete the trip, return -1. If a solution exists, it is guaranteed to be unique.   

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]    
// Output: 3 
// Explanation: Start at stop 3 (index 3) and fill up with 4 units of gas. 
// Your tank = 0 + 4 = 4 Travel to stop 4. 
// Your tank = 4 - 1 + 5 = 8 Travel to stop 0. 
// Your tank = 8 - 2 + 1 = 7 Travel to stop 1. 
// Your tank = 7 - 3 + 2 = 6 Travel to stop 2. 
// Your tank = 6 - 4 + 3 = 5 Travel to stop 3. 
// The cost is 5. Your gas is just enough to travel back to station 3. Therefore, return 3 as the starting index.


// Input: gas = [2,3,4], cost = [3,4,3]
// Output: -1
// Explanation:
// You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
// Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 0. Your tank = 4 - 3 + 2 = 3
// Travel to station 1. Your tank = 3 - 3 + 3 = 3
// You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
// Therefore, you can't travel around the circuit once no matter where you start.


#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &gas,vector<int> &cost,int index){
    bool flag=false;
    int i=0;
    while(true){
        
    }
    
}


int main()
{
    int n;
    cin>>n;

    vector<int>gas(n),cost(n);
    for(int i=0;i<n;i++){
        cin>>gas[i];
    }
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    vector<int> temp;
    int index=-1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
      if(maxi<=(gas[i]-cost[i])){
        index=i;
        maxi=(gas[i]-cost[i]);
      }
    }

    cout<<solve(gas,cost,index);

    

 return 0;
}