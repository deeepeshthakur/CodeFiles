#include <bits/stdc++.h>

using namespace std;
long long ten10 = 10000000000ll, ten12 = 1000000000000ll;
long long ncrCalc( long long n, long long r){
	if(n < 0ll || r < 0ll){
		return 0ll;
	}

	if(n < r){
		return 0ll;
	}

	long long numr = 1ll;
	if( r > n - r){
		r = n - r;
	}

	for(long long index = 0ll; index < r; ++index){
		numr *= (n - index);
		numr /= (index + 1ll);
	}

	return numr;
}

long long getOnes( long long n){
	long long ans = 0ll;
	while(n){
		ans += n%2ll;
		n /= 2ll;
	}
	return ans;
}

long long getP( long long n){
	long long ans = 0ll;
	while(n){
		ans++;
		n /= 2ll;
	}
	return ans;
}

long long rec( long long a, long long b, long long n, std::unordered_map < long long, long long >& dpTable){
	if(a < 0ll || b < 0ll){
		return 0ll;
	}

	if( dpTable.find( a*ten12 + b*ten10 + n) != dpTable.end()){
		return dpTable[a*ten12 + b*ten10 + n];
	}

	long long p = getOnes( n);
	if( a + b < p){
		dpTable[ a*ten12 + b*ten10 + n] = 0ll;
		return 0ll;
	}

	if(a + b == p){
		dpTable[ a*ten12 + b*ten10 + n] = ncrCalc( a + b, a);
		return dpTable[a*ten12 + b*ten10 + n];
	}

	if(n == 0ll && (a != 0ll || b != 0ll)){
		dpTable[ a*ten12 + b*ten10 + n] = 0ll;
		return 0ll;
	}

	if(n%2ll == 1ll){
		dpTable[a*ten12 + b*ten10 + n] = rec( a - 1ll, b, n/2ll, dpTable) + rec( a, b - 1ll, n/2ll, dpTable);
		return dpTable[a*ten12 + b*ten10 + n];
	}

	dpTable[a*ten12 + b*ten10 + n] = rec( a, b, n/2ll, dpTable) + rec( a - 1ll, b - 1ll, n/2ll - 1ll, dpTable);
	return dpTable[a*ten12 + b*ten10 + n];
}

void solve(){
	long long x, y, numb;
	std::cin >> x >> y >> numb;
	long long a = getOnes( x), b = getOnes( y), c = getOnes( numb);
	std::unordered_map < long long, long long > dpTable{};
	// std::vector < std::vector < std::vector < std::vector < long long > > > > dpTable( a + 1ll, std::vector < std::vector < std::vector < long long > > >( b + 1ll, std::vector < std::vector < long long > >( c + 1ll, std::vector < long long >( getP( numb) + 1ll, -1ll))));
	std::cout << rec( a, b, numb, dpTable) << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long test;
	std::cin >> test;
	while( test--){
		solve();
	}
	return 0ll;
}