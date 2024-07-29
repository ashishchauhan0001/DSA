#include <bits/stdc++.h> 

void InsertSorted(stack<int>&st,int val){
 
 if(st.empty()||st.top()<=val){
	 st.push(val);
	 return;
 }

 int x=st.top();
 st.pop();
 InsertSorted(st,val);
 st.push(x);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return ;
	}
	int val=stack.top();
	stack.pop();
	sortStack(stack);
	InsertSorted(stack,val);
}