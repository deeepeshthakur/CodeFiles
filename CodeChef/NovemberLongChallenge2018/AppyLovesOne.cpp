#include <bits/stdc++.h>

using namespace std;
struct node{
	int s, e;

	node(int ss, int ee){
		s = ss;
		e = ee;
	}
};

int f(int m, std::vector < node >& seArray, std::vector < node >& top2, int k, std::vector < int >& nArray){
	int n = seArray.size(), sh = m%n;
	int index = n - 1 - sh;
	std::vector < node > t{{top2[0].s, top2[0].e}, {top2[1].s, top2[1].e}};
	if(nArray[index] == 1){
		t.push_back({seArray[index].s, seArray[index].e});
	}
	int ml = 0;
	if(sh && nArray[n - 1] == 1 && nArray[0] == 1){
		int s = std::max(seArray[n - 1].s + sh, n)%n, e = std::min(n - 1, seArray[0].e + sh)%n;
		ml = e - s + 1;
		if(ml >= k){
			return k;
		}
	}

	for(int i = 0; i < t.size(); i++){
		//l = std::max(ml, t[i].e + sh - n + 1);
		if(t[i].e >= 0 && t[i].s >= 0)
		{
			int s = t[i].s + sh, e = t[i].e + sh;
			if(s <= n - 1 && n - 1 <= e){
				ml = std::max(ml, std::max(n - s, e - n + 1));
			}
			else{
				ml = std::max(ml, e - s + 1);
			}
		}
	}

	ml = std::min(ml, k);
	return ml;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, q, k;
	std::cin >> n >> q >> k;
	std::vector < int > nArray( n, 0);
	for(int i = 0; i < n; i++){
		std::cin >> nArray[i];
	}

	std::string str{};
	std::cin >> str;

	if(n == 1){
		for(int i = 0; i < q; i++){
			if(str[i] == '?'){
				std::cout << nArray[0] << "\n";
			}
		}
		return 0;
	}

	std::vector < node > seArray( n, {-1, -2});
	for(int i = 0; i < n; i++){
		if(nArray[i] == 1){
			if(i > 0 && nArray[i - 1] == 1){
				seArray[i].s = seArray[i - 1].s;
			}
			else{
				seArray[i].s = i;
			}
		}
	}

	for(int i = n - 1; i > -1; i--){
		if(nArray[i] == 1){
			if(i < n - 1 && nArray[i + 1] == 1){
				seArray[i].e = seArray[i + 1].e;
			}
			else{
				seArray[i].e = i;
			}
		}
	}

	std::vector< node > top2{{-1, -2}, {-1, -2}};
	for(int s = 0; s < n; s++){
		if(nArray[s] == 1){
			int e = s;
			while(nArray[e + 1] == 1 && e + 1 < n){
				e++;
			}
			{
				node t{s, e};
				if(t.e - t.s +1 >= top2[0].e - top2[0].s + 1){
					top2[1].s = top2[0].s;
					top2[1].e = top2[0].e;
					top2[0].s = t.s;
					top2[0].e = t.e;
				}
				else{
					if(t.e - t.s + 1 >= top2[1].e - top2[1].s + 1){
						top2[1].s = t.s;
						top2[1].e = t.e;
					}
				}
			}
			s = e + 1;
		}
	}

	// for(int i = 0; i < 2; i++){
	// 	std::cout << top2[i].s << "-" << top2[i].e << "   ";
	// }
	// std::cout << "\n";

	// for(int i = 0; i < n; i++){
	// 	std::cout << seArray[i].s << "-" << seArray[i].e << "   ";
	// }
	// std::cout << "\n";


	int shifts = 0;
	for(int i = 0; i < q; i++){
		if(str[i] == '!'){
			shifts++;
		}
		if(str[i] == '?')
			std::cout << f(shifts, seArray, top2, k, nArray) << "\n";
	}
	return 0;
}