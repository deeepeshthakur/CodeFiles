#include <bits/stdc++.h>

using namespace std;
long long MOD = 1000000007;

long long powerF( long long a, long long b){
	if(a == 0){
		return 0ll;
	}

	if(b == 0){
		return 1ll;
	}

	if(b == 1){
		return a%MOD;
	}

	long long x = powerF( a, b/2)%MOD;
	long long ans = (x*x)%MOD;


	if(b%2 == 1){
		ans *= a;
		ans %= MOD;
	}
	return ans;
}


long long bcCoff( long long n, long long k){
	if(k < 0){
		return 0ll;
	}
	if(k == 0){
		return 1;
	}

	long long numMax = n, numMin = std::max( k, n - k) + 1, denMax = std::min( k, n - k), denMin = 1;
	long long num = 1, den = 1;
	for(long long index = numMin; index <= numMax; index++){
		num *= index;
		num %= MOD;
	}

	for(long long index = denMin; index <= denMax; index++){
		den *= index;
		den %= MOD;
	}
	long long denInerse = powerF( den, MOD - 2);
	long long ans = (num*denInerse)%MOD;
	return ans;
}


long long solveFor( long long n, long long k){
	if(k == 0){
		return 1ll;
	}
	
	std::vector < long long > pow2( k + 1, 1);
	for(int index = 1; index < pow2.size(); index++){
		pow2[index] = pow2[index - 1]*2;
		pow2[index] %= MOD;
	}

	long long ans = 0;
	for(long long index = 1; index <= k; index++){
		long long temp1 = bcCoff( n - k + 1, n + index - 2*k);
		long long temp2 = pow2[k - index + 1];
		long long temp3 = bcCoff(k - 1, index - 1);
		// std::cout << temp1 << " " << temp2 << " " << temp3 << "\n";
		long long temp = (temp1*temp2)%MOD;
		temp *= temp3;
		temp %= MOD;		
		ans += temp;
		ans %= MOD;
	}

	return ans%MOD;
}

int main()
{
	// std::ios::sync_with_stdio(false);
	int test = 0;
	std::cin >> test;
	if( test > 0){
		long long n1, k1;
		std::cin >> n1 >> k1;
		long long n = n1;
		long long k = k1;
		// for( long long n = 1; n <= n1; n++)
		// 	for(long long k = 1; k <= k1; k++){
				if(n >= k){
					std::cout << n << " " << k << " ";
					if(n > k){
						int ans = solveFor( n, k);
						std::cout << ans << "\n";
					}
					if(n == k){
						std::cout << 2 << "\n";
					}
				}
				// else{
				// 	if(n < k){
				// 		std::cout << 0 << "\n";
				// 	}
				// 	else
				// 		if(n == k){
				// 			std::cout << 2 << "\n";
				// 		}
				// 	}
				// }
			// }
		}
		return 0;
	}