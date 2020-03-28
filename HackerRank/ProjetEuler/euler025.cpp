#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

void next_fibo_fun(vector<int>& a, vector<int>& b){
	vector<int> tmp(max(a.size(),b.size()),0);
	for(int i=0;i<tmp.size();i++){
		tmp[i] += (i<a.size() ? a[i] : 0) + (i<b.size() ? b[i] : 0);
		if(i<tmp.size()-1){
			tmp[i+1]+=(tmp[i]/10);
			tmp[i]%=10;
		}
	}

	if(tmp[tmp.size()-1]>9){
		int x=tmp[tmp.size()-1]/10;
		tmp[tmp.size()-1]%=10;
		tmp.pb(x);
	}

	for(int i=0;i<a.size();i++){
		if(i<b.size()){
			b[i]=a[i];
		}
		else{
			b.pb(a[i]);
		}
	}

	for(int i=0;i<tmp.size();i++){
		if(i<a.size())
			a[i]=tmp[i];
		else
			a.pb(tmp[i]);
	}
}

vector<int> dp(5001,-1);
void pre_calc(){
	vector<int> prev_fibo(1,0),curr_fibo(1,1);
	dp[1]=1;
	int i=1;
	while(curr_fibo.size()<5000){
		i++;
		next_fibo_fun(curr_fibo,prev_fibo);
		if(dp[curr_fibo.size()]==-1){
			dp[curr_fibo.size()]=i;
		}
	}
}

void solve(){
	int n;
	cin>>n;
	cout<<dp[n]<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	pre_calc();
	int t;       
	cin >> t;
	while(t--){
		solve();
	}

	return 0;
}