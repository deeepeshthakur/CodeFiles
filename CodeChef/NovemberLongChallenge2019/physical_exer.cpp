#include<bits/stdc++.h>
using namespace std;

long double a[5000], b[5000], c[5000], d[5000], e[5000], f[5000], s_A[5000], s_C[5000], e_A[5000], e_C[5000];

inline long double sq(double a){
	return a*a;
}

int main(){

	int test_cases;
	cin >> test_cases;
	while(test_cases--){
		int n,m,k;
		double x,y;
		cin>>x>>y;
		cin>>n>>m>>k;
		
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			s_A[i]=sqrt(sq(a[i]-x)+sq(b[i]-y));
		}
		for(int i=0;i<m;i++){
			cin>>c[i]>>d[i];
			s_C[i]=sqrt(sq(c[i]-x)+sq(d[i]-y));
		}
		for(int i=0;i<k;i++){
			cin>>e[i]>>f[i];
		}

		for(int i=0;i<n;i++){
			e_A[i] = 1e11;
			for(int j=0;j<k;j++){
				e_A[i] = min(e_A[i],sqrt(sq(a[i]-e[j])+sq(b[i]-f[j])));
			}
		}

		for(int i=0;i<m;i++){
			e_C[i] = 1e11;
			for(int j=0;j<k;j++){
				e_C[i] = min(e_C[i],sqrt(sq(c[i]-e[j])+sq(d[i]-f[j])));
			}
		}

		long double ret_val = 1e15;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				ret_val = min(ret_val,min(s_A[i]+e_C[j],s_C[j]+e_A[i])+sqrt(sq(a[i]-c[j])+sq(b[i]-d[j])));
			}
		}
		cout<<fixed<<setprecision(11)<<ret_val<<"\n";
	}
	return 0;
}