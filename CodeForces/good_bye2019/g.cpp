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

struct node{
	int val=0;
	node* next=NULL;
};

struct tot{
	long long sm=0;
	node *st=NULL, *en=NULL;
};

struct compare_fun{
	bool operator()(tot const *a, tot const *b){
		return (a->sm)>(b->sm);
	}
};

void solve(){
	int n;
	cin>>n;
	vector<long long> a(n,0);
	for(int i=0;i<n;i++)
		cin>>a[i];

	priority_queue<tot*,vector<tot*>,compare_fun> pos_pq, neg_pq;
	for(int i=0;i<n;i++){
		if(a[i]==0){
			cout<<1<<"\n"<<i+1<<"\n";
			return;
		}

		if(a[i]>0){
			tot *tmp = new tot;
			tmp->sm=a[i];
			tmp->st = new node;
			tmp->en=tmp->st;
			(tmp->st)->val=i+1;
			(tmp->st)->next=NULL;
			pos_pq.push(tmp);
		}
		else{
			tot *tmp = new tot;
			tmp->sm=-a[i];
			tmp->st = new node;
			tmp->en=tmp->st;
			(tmp->st)->val=i+1;
			(tmp->st)->next=NULL;
			neg_pq.push(tmp);
		}
	}

	while(!pos_pq.empty() && !neg_pq.empty()){
		auto p1 = pos_pq.top();
		auto n1 = neg_pq.top();
		pos_pq.pop();
		neg_pq.pop();
		long long curr=(p1->sm)-(n1->sm);
		(p1->en)->next=(n1->st);
		node *curr_st=p1->st,*curr_en=n1->en;
		if(curr==0){
			vector<int> ans;
			while(curr_st!=NULL){
				ans.pb(curr_st->val);
				curr_st=curr_st->next;
			}
			cout<<ans.size()<<"\n";
			for(int i=0;i<ans.size();i++)
				cout<<ans[i]<<(i+1<ans.size()?" ":"\n");
			return;
		}

		if(curr>0){
			tot *tmp= new tot;
			tmp->sm=curr;
			tmp->st=curr_st;
			tmp->en=curr_en;
			pos_pq.push(tmp);
		}
		else{
			tot *tmp= new tot;
			tmp->sm=-curr;
			tmp->st=curr_st;
			tmp->en=curr_en;
			neg_pq.push(tmp);
		}
	}
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