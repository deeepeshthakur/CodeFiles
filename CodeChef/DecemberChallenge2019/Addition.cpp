#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

int calc_fun(int l,int r,vector<int>& a,vector<int>& b){
	int bit_c=0,prev=0,ctr=0,swap_tmp;
	for(int i=l;i<=r;i++){
		bit_c+=b[i];
	}
	while(bit_c>0){
		ctr++;
		prev=0;
		bit_c=0;
		for(int i=l;i<=r;i++){
			swap_tmp=prev;
			prev=(a[i]&b[i]);
			a[i]=(a[i]^b[i]);
			b[i]=swap_tmp;
			bit_c+=b[i];
		}
	}
	return ctr;
}

void solve(){
	string str_a,str_b;
	cin>>str_a>>str_b;
	int sa=str_a.size(),sb=str_b.size(),n=max(str_a.size(),str_b.size())+1;
	vector<int> a(n,0),b(n,0);
	int ind=0,prev=0,l=0,r=0,ctr=0,sm=0,curr,swap_temp;
	for(int i=0;i<n;i++){
		a[i]=(i<sa&&str_a[sa-1-i]=='1'? 1:0);
		b[i]=(i<sb&&str_b[sb-1-i]=='1'? 1:0);
		ctr+=b[i];
	}
	if(ctr==0){
		cout<<"0\n";
		return;
	}
	ctr=0;
	queue<int> lqueue,rqueue,currqueue;
	while(ind<n){
		ctr=ind;
		while(ctr<n&&a[ctr]+b[ctr]>0)
			ctr++;
		lqueue.push(ind);
		rqueue.push(ctr);
		currqueue.push(0);
		ind=ctr+1;
	}

	ind=0;ctr=0;
	while(!lqueue.empty()){
		prev=0;
		l=lqueue.front();lqueue.pop();
		r=rqueue.front();rqueue.pop();
		curr=currqueue.front();currqueue.pop();
		if(r-l>1000){
			sm=0;
			for(int i=l;i<=r;i++){
				swap_temp=prev;
				prev=(a[i]&b[i]);
				a[i]=(a[i]^b[i]);
				b[i]=swap_temp;
				sm+=b[i];
			}
			curr++;
			if(sm>1){
				ind=l;
				while(ind<=r){
					prev=ind;
					while(prev<=r&&a[prev]+b[prev]>0)
						prev++;
					lqueue.push(ind);
					rqueue.push(min(r,prev));
					currqueue.push(curr);
					ind=prev+1;
				}
			}
			else
				if(sm==1){
					ind=l;
					while(b[ind]==0){
						ind++;
					}
					int ones=0;
					for(int i=ind;i<=r && a[i]==1;i++){
						ones++;
					}
					curr+=(ones+1);
					ctr=((ctr<curr)?curr:ctr);
				}
				else
					ctr=((ctr<curr)?curr:ctr);
		}
		else{
			curr+=calc_fun(l,r,a,b);
			ctr=(ctr<curr?curr:ctr);
		}
	}
	cout<<ctr<<"\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	// auto st=chrono::high_resolution_clock::now();
	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	// auto sp=chrono::high_resolution_clock::now();
	// auto dura = chrono::duration_cast<chrono::microseconds>(sp-st);
	// cout<<(dura.count())/(1e6)<<"\n";
	return 0;
}