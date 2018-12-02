#include <bits/stdc++.h>

using namespace std;

long long getVal( char ch){
	if(ch == 'd'){
		return 1;
	}
	if(ch == 'f'){
		return 2;
	}
	if(ch == 'j'){
		return  3;
	}

	return 4;
}

long long getId( std::string& currStr, double& time){
	long long ans = 0, multiplier = 1;
	bool rh = false, lh = false;
	time = 0;
	long long id = getVal( currStr[0]);
	ans += (id*multiplier);
	multiplier *= 5ll;
	if(id < 3){
		time += 0.2;
		lh = true;
	}
	else{
		time += 0.2;
		rh = true;
	}

	for(int index = 1; index < currStr.length(); index++){
		id = getVal( currStr[index]);
		if(id < 3){
			if(lh){
				time += 0.4;
				rh = false;
				lh = true;
			}
			else{
				time += 0.2;
				rh = false;
				lh = true;
			}
		}
		else{
			if(lh){
				time += 0.2;
				rh = true;
				lh = false;
			}
			else{
				time += 0.4;
				rh = true;
				lh = false;
			}
		}
		ans += (id*multiplier);
		multiplier *= 5ll;
	}
	return ans;
}

void solve(){
	int n;
	std::cin >> n;
	double ans = 0;
	std::set < long long > words{};
	for(int index = 0; index < n; index++){
		std::string currStr;
		std::cin >> currStr;
		double time = 0;
		long long id = getId( currStr, time);
		// std::cout << id << " " << time << "\n";
		if(words.find(id) != words.end()){
			ans += (time/2.0);
		}
		else{
			ans += time;
			words.insert( id);
		}
		// std::cout << ans*10 << "\n";
	}
	std::cout << ans*10 << "\n";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int test;
	std::cin >> test;
	while( test--){
		solve();
	}
	return 0;
}