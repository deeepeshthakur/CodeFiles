#include <bits/stdc++.h>

using namespace std;

void showpq(std::priority_queue < long long > g){
	while(!g.empty()){
		std::cout << g.top() << " ";
		g.pop();
	}
	// std::cout << std::endl;
}

int main(){
	int n;
	std::cin >> n;
	// std::vector < bool > isBaseSoup(n, true);
	std::vector < vector< int > > compositon(n);
	std::vector< long long > soupIndex(n, -1ll);
	int p, c;
	for(int i = 0; i < n; i++){
		std::cin >> p;
		int level = 0;
		if(p){
			compositon[i].resize(p);
			for(int x = 0; x < p; x++){
				std::cin >> c;
				compositon[i][x] = c;
				if(level < soupIndex[c - 1] + 1){
					level = soupIndex[c - 1] + 1;
				}
			}
		}
		soupIndex[i] = level;
	}

	// for(int i = 0; i < n; i++){
	// 	std::cout << i + 1 << "    ";
	// 	for(int x : compositon[i]){
	// 		std::cout << x << " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	for(int i = 0; i < n; i++){
		soupIndex[i] = soupIndex[i]*100000 + i;
	}

	// for(auto x : soupIndex){
	// 	std::cout << x << " ";
	// }
	// std::cout << std::endl;

	int q;
	std::cin >> q;
	std::vector < int > ansArray(q, 0);
	for(int qq = 0; qq < q; qq++){
		std::priority_queue< long long > pq;
		int x;
		std::cin >> x;
		for(int xx = 0; xx < x; xx++){
			std::cin >> c;
			pq.push(soupIndex[c - 1]);
		}

		long long tp;
		while(pq.size() > 1 && pq.top()/100000ll > 0){
			// showpq(pq);
			tp = pq.top();
			pq.pop();
			std::cout << "  " << tp << " - " << pq.top() << std::endl;
			if(tp == pq.top()){
				pq.pop();
			}
			else{
				int cc = tp%100000ll;
				for(x = 0; x < compositon[cc].size(); x++){
					pq.push(soupIndex[compositon[cc][x] - 1]);
				}
			}
		}

		if(!pq.empty() && pq.top()/100000ll > 0){
			int cc = pq.top()%100000ll;
			pq.pop();
			for(int i = 0; i < compositon[cc].size(); i++){
				pq.push(soupIndex[compositon[cc][i] - ]1);
			}
		}
		// std::cout << qq << "     ";
		// showpq( pq); std::cout << std::endl;

		bool flag = false;
		if(pq.size()%2 == 0){
			flag = true;
		}

		while(flag && !pq.empty()){
			tp = pq.top();
			pq.pop();
			if(tp == pq.top()){
				pq.pop();
			}
			else{
				flag = false;
			}
		}

		if(flag){
			ansArray[qq] = 1;
		}
	}

	for(int i = 0; i < ansArray.size(); i++){
		std::cout << ansArray[i];
	}
	std::cout << std::endl;
	return 0;
}