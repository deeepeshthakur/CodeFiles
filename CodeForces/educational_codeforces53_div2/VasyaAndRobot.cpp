#include <bits/stdc++.h>

using namespace std;
int minM = INT_MAX;
int x, y, x11, y11;

struct node{
	int u, d, l, r;
	node(){
		u = 0;
		d = 0;
		l = 0;
		r = 0;
	}
};

bool checkF( int s, int e, std::vector < node >& counter){
	if(s  > e){
		return false;
	}
	int r = counter[e].r, l = counter[e].l, u = counter[e].u, d = counter[e].d, dx, dy;
	if(s > 0){
		r -= counter[s - 1].r;
		l -= counter[s - 1].l;
		u -= counter[s - 1].u;
		d -= counter[s - 1].d;
	}

	dx = x - x11 - l + r, dy = y - y11 - d + u;
	int sd = std::abs(dx) + std::abs( dy), ll = e - s + 1;
	if(sd == ll || (ll > sd && (ll - sd)%2 == 0)){
		return true;
	}

	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	// int x, y;
	std::cin >> x >> y;
	std::vector < node > counter( n);
	for(int index = 0; index < n; index++){
		if(str[index] == 'R'){
			counter[index].r++;
		}
		if(str[index] == 'U'){
			counter[index].u++;
		}
		if(str[index] == 'L'){
			counter[index].l++;
		}
		if(str[index] == 'D'){
			counter[index].d++;
		}

		if(index){
			counter[index].r += counter[index - 1].r;
			counter[index].u += counter[index - 1].u;
			counter[index].l += counter[index - 1].l;
			counter[index].d += counter[index - 1].d;
		}
	}
	x11 = counter[n - 1].r - counter[n - 1].l;
	y11 = counter[n - 1].u - counter[n - 1].d;
	if(x == x11 && y == y11){
		std::cout << 0 << "\n";
		return 0;
	}
	if(!checkF( 0, n - 1, counter)){
		std::cout << -1 << "\n";
		return 0;
	}
	// std::vector < node > st( 3*n + 5, 0);
	// constructF( counter, 0, n - 1, st, 0);

	int s = 0, e = 0;
	while(!checkF( s, e, counter)){
		e++;
	}

	while(checkF( s + 1, e, counter)){
		s++;
	}

	int l = e - s + 1;
	for(; e < n; e++){
		s = e + 1 - l;
		while( checkF( s + 1, e, counter)){
			s++;
		}

		l = e - s + 1;
	}

	std::cout << l << "\n";
	
	return 0;
}