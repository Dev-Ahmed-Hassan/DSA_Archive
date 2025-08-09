#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
#include<climits>

using namespace std;
vector<int> findArraySum(vector<int>&a,int m, vector<int>&b, int n) {
	int sum = 0;
	int multiplier = 1;
	for(int i=a.size()-1; i>=0; i--)
	{
		sum+=multiplier*a[i];
		multiplier*=10;
	}
	multiplier = 1;
	for(int i=b.size()-1; i>=0; i--)
	{
		sum+=multiplier*b[i];
		multiplier*=10;
	}

	vector<int> result;

	while(sum >0)
	{
		result.push_back(sum%10);
		sum /= 10;
	}

	reverse(result.begin(), result.end());
	return result;
}


vector<int> findArraySum(vector<int>&a,int m, vector<int>&b, int n) {
	int carry = 0;

	int i=m-1; int j=n-1;
	int multiplier = 1;
	vector<int> result;
	while(i>=0 || j>=0 || carry > 0)
	{
		int sum = 0;
		if(i>=0) sum+=a[i];
		if(j>=0) sum += b[j];
		sum += carry;

		if(sum > 9) {carry = 1;}
		else{carry = 0;}

		result.push_back(sum%10);
		i--;
		j--;
	}
	reverse(result.begin(), result.end());
	return result;
}