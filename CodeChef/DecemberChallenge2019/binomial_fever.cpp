#include<bits/stdc++.h>
using namespace std;
const long long modulo = 998244353ll;

long long f1(long long a, long long b){
	if(a == 0)
		return 0ll;
	if(b == 0)
		return 1ll;
	if(b == 1)
		return a;
	long long x = f1(a,b/2);
	x = (x*x)%modulo;
	if(b%2==1)
		return (x*a)%modulo;
	return x;
}

long long pow_mod(long long a,long long b){
	return f1(a%modulo,b);
}

long long sum_function(long long p,long long r, long long ind, long long n){
	if(n-ind<0ll)
		return 0ll;
	if(n-ind==0ll)
		return pow_mod(p,r*ind);
	long long p_to_r = pow_mod(p,r), 
			  p_to_int_r = pow_mod(p,ind*r),
			  inv_dn = pow_mod((p_to_r+modulo-1)%modulo,modulo-2), 
			  num = (pow_mod(p_to_r,n-ind+1)+modulo-1)%modulo;
	return (p_to_int_r*((num*inv_dn)%modulo))%modulo;
}

long long sum_gp(long long a, long long r, long long n){
	long long num = (pow_mod(r,n)-1+modulo)%modulo, den = pow_mod(r+modulo-1,modulo-2ll);
	return (a*((num*den)%modulo))%modulo;
}

void binomial_fever(){
	long long n,p,r;
	cin>>n>>p>>r;
	if(r == 1ll){
		if(p==1ll)
			cout << (n+1)%modulo << "\n";
		else
			cout << (pow_mod((p+modulo-1)%modulo,modulo-2)*(pow_mod(p%modulo,n+1)-1+modulo))%modulo << "\n";
		return;
	}

	if(r == 2ll){
		if(p==1ll){
			cout << "0\n";
			return;
		}
		long long num = (sum_gp((p*p)%modulo,(p*p)%modulo,n)+modulo-sum_gp(p%modulo,p%modulo,n))%modulo,
				  den = pow_mod(2ll,modulo-2ll);
		cout << (num*den)%modulo << "\n";
		return;
	}
	
	if(r <= 1000ll){
		if(p==1ll){
			cout <<"0\n";
			return;
		}
		long long ind=0ll,p_pow=1ll,fact_r=1,ans=0ll;
		vector<long long> tmp_vec(r+1,0ll),coeff_vec(r+1,0ll), pow_arr(r+1,0ll);
		while(p_pow<r){
			ind++;
			p_pow*=p;
		}

		coeff_vec[0]=1;
		for(int i=0;i<r;i++){
			for(int j=0;j<=r;j++){
				tmp_vec[j]=(modulo - ((coeff_vec[j]*i)%modulo) + (j>0 ? coeff_vec[j-1] : 0ll))%modulo;
			}
			for(int j=0;j<=r;j++){
				coeff_vec[j]=tmp_vec[j];
				tmp_vec[j]=0ll;
			}
		}

		for(int i=1;i<=r;i++)
			fact_r = (fact_r*i)%modulo;

		for(int i=1;i<=r;i++)
			pow_arr[i]=sum_function(p,1ll*i,ind,n);

		for(int i=0;i<=r;i++)
			ans = (ans + (pow_arr[i]*coeff_vec[i])%modulo)%modulo;

		ans = (ans*pow_mod(fact_r,modulo-2))%modulo;
		cout << ans << "\n";
		return;
	}

	cout << 1<< "\n";
}

int main(){
	int test_cases;       
	cin >> test_cases;
	while(test_cases--){
		binomial_fever();
	}
	return 0;
}