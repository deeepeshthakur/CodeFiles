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

void print_vec(vector<int>& a,int n=-1){
	n = (n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

void print_vec(vector<long long>& a,int n=-1){
	n=(n==-1 ? a.size():n);
	for(int i=0;i<n;i++)
		cout << a[i] << (i<n-1 ? " ":"\n");
}

bool check_f(int n, vector<int>& a, vector<int>& b){
	for(int i=0;i<n;i++){
		if(a[i]<b[i])
			return false;
		if(a[i]>b[i])
			return true;
	}
	return true;
}

bool is_mid_max(int n, int k, vector<int>& a){
	int l=n-k,r=k-1;
	vector<int> mid(r-l+1),mid_max(r-l+1,9);
	for(int i=l;i<=r;i++)
		mid[i-l]=a[i];
	return check_f(mid.size(),mid,mid_max);
}

void solve(){
	int n,k;
	cin>>n>>k;
	string a;
	cin>>a;
	vector<int> inp(n,0),fir(n,0);
	for(int i=0;i<n;i++){
		inp[i]=int(a[i]-'0');
		if(i-k>=0){
			fir[i]=fir[i-k];
		}
		else{
			fir[i]=inp[i];
		}
	}

	if(!check_f(n,fir,inp)){
		if(2*k-1<n){
			for(int i=k-1;i>=0;i--){
				if((fir[i]+1)%10>fir[i]){
					fir[i]++;
					for(int j=i;j<n;j+=k)
						fir[j]=fir[i];
					break;
				}
				else{
					fir[i]=0;
					for(int j=i;j<n;j+=k)
						fir[j]=0;
				}
			}
		}
		else{
			if(is_mid_max(n,k,fir)){
				int l=n-k,r=k-1;
				for(int i=l;i<=r;i++)
					fir[i]=0;
				for(int i=n-k-1;i>=0;i--){
					if((fir[i]+1)%10>fir[i]){
						fir[i]++;
						for(int j=i;j<n;j+=k)
							fir[j]=fir[i];
						break;
					}
					else{
						fir[i]=0;
						for(int j=i;j<n;j+=k)
							fir[j]=0;
					}
				}
			}
			else{
				for(int i=k-1;i>n-k-1;i--){
					if(fir[i]<9){
						fir[i]++;
						break;
					}
					else{
						fir[i]=0;
					}
				}
			}
		}
	}

	cout<<fir.size()<<"\n";
	for(int i=0;i<n;i++){
		cout<<fir[i];
	}
	cout<<"\n";
}	

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	solve();
	return 0;
}