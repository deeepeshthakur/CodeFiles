#include <bits/stdc++.h>

using namespace std;
long long MOD = 1000000007;

long long powF( long long a, long long b){
	if(a == 0){
		return 0ll;
	}

	if(b == 0){
		return 1ll;
	}

	if(b == 1){
		return a%MOD;
	}

	long long x = powF( a, b/2);
	if(b%2 == 1){
		return (((x*x)%MOD)*a)%MOD;
	}

	return (x*x)%MOD;
}

long long calcF( long long n){
	if(n < 2){
		return 1ll;
	}

	long long num = 1;
	for( long long index = 1; index <= n; index++){
		num *= (index%MOD);
		num %= MOD;
	}

	long long den = powF( 2ll, n/2)%MOD;

	long long denI = powF( den, MOD - 2)%MOD;
	return (num*denI)%MOD;
}

void solveF(){
	int n;
	std::cin >> n;
	std::set < int > countr{};
	std::vector < int > inpArray( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inpArray[index];
		countr.insert( inpArray[index]);
	}
	std::sort( inpArray.begin(), inpArray.end());
	std::vector < long long > Si( countr.size(), 0), Ci( countr.size(), 0);
	int i = 0;
	Si[0] = inpArray[0];
	for(int index = 0; index < n; index++){
		if(Si[i] == inpArray[index]){
			Ci[i]++;
		}
		else{
			Si[i + 1] = inpArray[index];
			Ci[i + 1] = 1;
			i++;
		}
	}
	

	long long teams = 1;

	for(int index = 0; index < Si.size(); index++){
		if(Ci[index] != 0){
			if(Ci[index]%2 == 0){
				teams *= calcF(Ci[index]);
				teams %= MOD;
			}
			else{
				teams *= calcF(Ci[index] - 1);
				teams %= MOD;
				teams *= (Ci[index]*Ci[index + 1])%MOD;
				teams %= MOD;
				Ci[index + 1]--;
			}
		}	
	}
	teams %= MOD;
	std::cout << teams << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	int t = 0;
	std::cin >> t;
	while(t--){
		solveF();
	}
	return 0;
}