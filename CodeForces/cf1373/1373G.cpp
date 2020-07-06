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

#define MAX 2500000

int tree[MAX] = {0}; 
int lazy[MAX] = {0}; 

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff) 
{ 
	if (lazy[si] != 0) 
	{
		tree[si] += lazy[si]; 

		if (ss != se) 
		{ 

			lazy[si*2 + 1] += lazy[si]; 
			lazy[si*2 + 2] += lazy[si]; 
		} 

		lazy[si] = 0; 
	} 

	// out of range 
	if (ss>se || ss>ue || se<us) 
		return ; 

	if (ss>=us && se<=ue) 
	{ 
		tree[si] += (se-ss+1)*diff; 

		if (ss != se) 
		{ 

			lazy[si*2 + 1] += diff; 
			lazy[si*2 + 2] += diff; 
		} 
		return; 
	} 

	int mid = (ss+se)/2; 
	updateRangeUtil(si*2+1, ss, mid, us, ue, diff); 
	updateRangeUtil(si*2+2, mid+1, se, us, ue, diff); 

	tree[si] = max(tree[si*2+1],tree[si*2+2]); 
} 

void updateRange(int n, int us, int ue, int diff) { 
    updateRangeUtil(0, 0, n-1, us, ue, diff); 
} 


int getSumUtil(int ss, int se, int qs, int qe, int si) 
{ 

	if (lazy[si] != 0) 
	{ 

		tree[si] += lazy[si]; 
 
		if (ss != se) 
		{ 

			lazy[si*2+1] += lazy[si]; 
			lazy[si*2+2] += lazy[si]; 
		}
		lazy[si] = 0; 
	} 


	if (ss>se || ss>qe || se<qs) 
		return 0; 

	if (ss>=qs && se<=qe) 
		return tree[si]; 


	int mid = (ss + se)/2; 
	return max(getSumUtil(ss, mid, qs, qe, 2*si+1),getSumUtil(mid+1, se, qs, qe, 2*si+2)); 
} 
 
int getSum(int n, int qs, int qe) 
{ 

	if (qs < 0 || qe > n-1 || qs > qe) 
	{ 
		printf("Invalid Input"); 
		return -1; 
	} 

	return getSumUtil(0, n-1, qs, qe, 0); 
} 


void constructSTUtil(vector<int>& arr, int ss, int se, int si) 
{ 

	if (ss > se) 
		return ; 
	if (ss == se) 
	{ 
		tree[si] = arr[ss]; 
		return; 
	} 

	int mid = (ss + se)/2; 
	constructSTUtil(arr, ss, mid, si*2+1); 
	constructSTUtil(arr, mid+1, se, si*2+2); 

	tree[si] = tree[si*2 + 1] + tree[si*2 + 2]; 
} 

void constructST(vector<int>& arr, int n) 
{ 
	constructSTUtil(arr, 0, n-1, 0); 
} 

bool tf(int lim,vector<int>& v){
    for(int i=v.size()-1;i>=0;i--){
        if(lim-v[i]+1<v.size()-i) return false;
    }
    return true;
}

void solve(){
    int n,k,m;
    cin>>n>>k>>m;
    map<pair<int,int>,bool> ht;

    int len=4*int(1e5)+100;
    vector<int> arr(len,-len);
    constructST(arr, len);
    for(int i=0;i<len;i++) arr[i]=-1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(ht.find({x,y})!=ht.end()) ht[{x,y}]=!ht[{x,y}]; else ht[{x,y}]=true;
        int hh=abs(k-x)+y;
        if(ht[{x,y}]) arr[hh]++; else arr[hh]--;

        if(arr[hh]>1){
            
        }
        if(arr[hh]==1){

        }
        if(arr[hh]==0){

        }

    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}

