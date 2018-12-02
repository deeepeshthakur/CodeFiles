#include <bits/stdc++.h>

using namespace std;

void auxF(int& s, long long& count, std::vector < std::vector < int > >& vec, std::string& str){
	if(str[s] == '.'){
		for(; s < str.length() && str[s] == '.'; s++);
		return;
	}
	else{
		int hcount = 1, dcount = 0, e = s;
		while(e + 1 < str.length() && hcount > dcount){
			if(str[e + 1] == '.'){
				dcount++;
			}
			else{
				hcount++;
			}

			e++;
		}

		if(e == str.length() - 1 && hcount > dcount){
			count = -1;
			return;
		}

		long long inbet = 0;
		int ee = e - 1, ss = e - 1;
		while(ss > s){
			if(str[ss] == '#'){
				inbet += (ee - ss)*1ll;
				ee -= 2;
			}
			ss--;
		}

		long long nn = dcount, kk;
		if(s > 0){
			kk = s - vec[s - 1][0];
		}
		else{
			kk = 0;
		}
		count += (nn*(nn - 1)/2ll) + (nn*kk) + inbet;
		s = e + 1;
	}
}

void f(){
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	std::vector < std::vector < int > > vec(n, std::vector < int >( 2, 0));
	for(int i = 0; i < n; i++){
		if(str[i] == '.'){
			vec[i][1]++;
		}
		else{
			vec[i][0]++;
		}

		if(i > 0){
			vec[i][0] += vec[i - 1][0];
			vec[i][1] += vec[i - 1][1];
		}
	}

	long long count = 0;
	int s = 0;
	while(str[s] != '.'){
		s++;
	}
	while(s < n && count != -1){
		auxF(s, count, vec, str);
	}

	std::cout << count << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--){
		f();
	}
	return 0;
}