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

long double time_fun(vector<long double> l, long double a, long double b){
	return (l[0]/a)+(l[1]/b);
}

bool delta(long double a, long double b){
	return abs(a-b)<1e-10;
}

vector<long double> dist_fun(long double theta, vector<long double> a){
	return vector<long double>{a[1]/cos(theta),sqrt(a[2]*a[2]+(a[0]-a[1]*tan(theta))*(a[0]-a[1]*tan(theta)))};
}

long double polynomial(long double theta, vector<long double> a){
	long double x=tan(theta);
	return a[0]*x*x*x*x + a[1]*x*x*x + a[2]*x*x + a[3]*x + a[4];

}

void pre(long double l, long double w, long double h, long double a, long double b){
	vector<long double> poly{l*l*(b*b-a*a),-2.0*h*l*(b*b-a*a),b*b*(w*w+h*h)-a*a*(l*l+h*h),2*h*l*a*a,-a*a*h*h},dl{h,l,w};
	long double theta1=0,theta2=atan(h/l);
	while(!delta(time_fun(dist_fun(theta1,dl),a,b),time_fun(dist_fun(theta2,dl),a,b))){
		long double mid=(theta1+theta2)/2.0;
		if(polynomial(mid,poly)>=0)
			theta2=mid;
		else
			theta1=mid;
	}
	cout<<fixed<<setprecision(5)<<min(time_fun(dist_fun(theta1,dl),a,b),time_fun(dist_fun(theta2,dl),a,b))<<"\n";
}

void solve(){
	long double x1,x2,y1,y2,v1,v2;
	cin>>x1>>y1>>x2>>y2>>v1>>v2;
	pre(abs(y1),abs(y2),abs(x1-x2),abs(v1),abs(v2));
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