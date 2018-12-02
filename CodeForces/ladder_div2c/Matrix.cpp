#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	long long a;
	std::cin >> a;
	std::string str{};
	std::cin >> str;
	std::vector < int > Vec( str.length(), 0);
	for(int index = 0; index < Vec.size(); index++){
		Vec[index] = str[index] - '0';
		if(index){
			Vec[index] += Vec[index - 1];
		}
	}

	std::vector < long long > countR( Vec.size()*10, 0);
	for(int x = 0; x < Vec.size(); x++){
		for(int y = x; y < Vec.size(); y++){
			countR[Vec[y] - (x > 0 ? Vec[x - 1] : 0)]++;
		}
	}

	long long ans = 0;
	//std::set < int > factors{};
	if(a > 0)
	for(int i = 1; i < countR.size(); i++){
		if(a%i == 0 && a >= i && a/i < countR.size()){
			ans += (countR[i]*countR[a/i]);
		}
	}
	else{
		long long ll = Vec.size()*(Vec.size() + 1);
		ll /= 2ll;
		ans = countR[0]*ll*2;
		ans -= (countR[0]*countR[0]);
	}
	std::cout << ans << "\n";
	return 0;
}