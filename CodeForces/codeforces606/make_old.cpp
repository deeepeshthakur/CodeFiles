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

// void solve(){
// 	int n;
// 	cin>>n;
// 	vector<pair<int,int>> next(35,{0,0}),curr(35,{0,0});
// 	for(int i=0;i<n;i++){
// 		long long x;
// 		cin>>x;
// 		int ctr=0;
// 		while(x%2==0){
// 			ctr++;
// 			x/=2ll;
// 		}
// 		curr[ctr].first++;
// 	}

// 	bool flag=true;
// 	int ans=0;
// 	while(flag){
// 		cout << ans << endl;
// 		int sc=0,ind=0,tmp_sc;
// 		flag=false;
// 		for(int i=curr.size()-1;i>=0;i--){
// 			if(i+1<curr.size()){
// 				curr[i].second = curr[i+1].second+curr[i].first;
// 			}
// 			else
// 				curr[i].second=curr[i].first;
// 		}

// 		for(int i=0;i<curr.size();i++){
// 			if(i>0 && curr[i].first>0)
// 				flag=true;
// 			tmp_sc=i*(curr[i].second);
// 			if(tmp_sc>sc){
// 				sc=tmp_sc;
// 				ind=i;
// 			}
// 		}

// 		if(flag){
// 			ans++;
// 			for(int i=0;i<curr.size();i++){
// 				if(i<ind){
// 					next[i].first += curr[i].first;
// 				}
// 				else{
// 					next[i-ind].first += curr[i].first;
// 				}
// 			}

// 			for(int i=0;i<curr.size();i++){
// 				curr[i].first=next[i].first;
// 				curr[i].second=0;
// 				next[i].first=0;
// 			}
// 		}
// 	}
// 	cout<<ans<<"\n";
// }

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,int> ht;
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			if(ht.find(a[i])==ht.end()){
				pq.push(a[i]);
				ht.insert({a[i],1});
			}
			else
				ht.find(a[i])->second+=1;
		}
	}

	int ans=0,tp;
	while(!pq.empty()){
		tp=pq.top();
		pq.pop();
		if(tp%2==0){
			auto itr=ht.find(tp);
			if(itr!=ht.end()){
				ans++;
				if(tp%4==0){
					auto itr_half=ht.find(tp/2);
					if(itr_half!=ht.end()){
						itr_half->second+=(itr->second);
					}
					else{
						ht.insert({tp/2,itr->second});
						pq.push(tp/2);
					}
				}
			}
		}
	}
	cout<<ans<<"\n";

}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;       
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}