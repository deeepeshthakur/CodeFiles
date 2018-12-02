#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	std::cin >> n;
	std::vector < std::pair < long long, long long > > aArray( n);
	for(int index = 0; index < n; index++){
		std::cin >> aArray[index].first;
	}

	for(int index = 0; index < n; index++){
		std::cin >> aArray[index].second;
	}

	long long ans = 0;
	long long minb = aArray[0].second;
	for(int index = 0; index < n; index++){
		if(minb > aArray[index].second){
			minb = aArray[index].second;
		}
	}

	for( int index = 0; index < n; index++){
		if(aArray[index].first%aArray[index].second > minb - 1)
		{
			ans+=(aArray[index].second - aArray[index].first%aArray[index].second);
			aArray[index].first = 0;
		}
		else{
			aArray[index].first %= aArray[index].second;
		}
	}

	std::sort( aArray.begin(), aArray.end());

	std::vector < long long > gArray( n, 0), sArray( n, 0);
	for(int index = 0; index < n; index++){
		sArray[index] = -aArray[index].first;
		gArray[n - 1 - index] = aArray[n - 1 - index].second - aArray[n - 1 - index].first;
		if(index){
			sArray[index] += sArray[index - 1];
			gArray[n - 1 - index] += gArray[n - index];
		}
	}

	long long diff = LONG_LONG_MAX;
	for(int index = 0; index < n; index++){
		long long curr = 0;
		curr += (index + 1)*aArray[index].first + sArray[index];
		if(index + 1 < n){
			curr += ((n - index - 1)*aArray[index].first + gArray[index + 1]);
		}

		diff = std::min( diff, curr);
	}

	ans += diff;

	std::cout << ans << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	for(int index = 0; index < t; index++){
		solve();
	}
	return 0;
}