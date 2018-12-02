#include <bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int xx = 0, ss = 1;
	while(xx < n){
		ss *= 2;
		xx++;
	}
	// std::cout << ss <<"\n";
	std::vector < std::vector < int > > treeLayers( n + 1);
	for(int index = 0; index < n + 1; index++){
		treeLayers[index].resize( ss, 0ll);
		ss /= 2;
	}


	for(int index = 0; index < treeLayers[0].size(); index++){
		std::cin >> treeLayers[0][index];
	}

	for(int index = 1; index < n + 1; index++){
		if(index%2){
			for(int x = 0; x < treeLayers[index].size(); x++){
				treeLayers[index][x] = (treeLayers[index - 1][2*x] | treeLayers[index - 1][2*x + 1]);
			}
		}
		else{
			for(int x = 0; x < treeLayers[index].size(); x++){
				treeLayers[index][x] = (treeLayers[index - 1][2*x] ^ treeLayers[index - 1][2*x + 1]);
			}
		}
	}

	while(m--){
		int p, b;
		std::cin >> p >> b;
		p--;
		int layerL = 0, curr = b;
		while( layerL < n){
			treeLayers[layerL][p] = curr;
			if(layerL%2 == 0){
				if(p%2 == 1){
					curr = (curr | treeLayers[layerL][p - 1]);
				}
				else{
					curr = (curr | treeLayers[layerL][p + 1]);
				}
			}
			else{
				if(p%2){
					curr = (curr ^ treeLayers[layerL][p - 1]);
				}
				else{
					curr = (curr ^ treeLayers[layerL][p + 1]);
				}
			}
			p /= 2;
			layerL++;
		}
		std::cout << curr << "\n";
	}
	return 0;
}