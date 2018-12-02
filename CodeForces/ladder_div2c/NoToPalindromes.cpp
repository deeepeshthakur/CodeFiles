#include <bits/stdc++.h>

using namespace std;

void trivial( int n, int k){
	if(k == 1){
		std::cout << "NO\n";		
	}
	if(k == 2){
		if(n > 2){
			std::cout << "NO\n";
		}
		else{
			if(n == 1){
				std::string s;
				std::cin >> s;
				if(s[0] == 'a'){
					std::cout << "b\n";
				}
				else{
					std::cout << "NO\n";
				}
			}
			else{
				std::string s;
				std::cin >> s;
				if(s == "ab"){
					std::cout << "ba\n";
				}
				else{
					std::cout << "NO\n";
				}
			}
		}
	}
}

void makeArr( char x, std::string& str, int index, int k){
	char l = 'a' + k;
	str[index] = x;
	index++;
	// std::cout << x << " " << str << " " << index << " " << k << "\n";
	if(index == 1){
		for(char x = 'a'; x < l; x++){
			if(str[index - 1] != x){
				str[index] = x;
				x = l;
			}
		}
		index++;
	}

	for(int i = index; i < str.length(); i++){
		for(char x = 'a'; x < l; x++){
			if(str[i - 2] != x && str[i - 1] != x){
				str[i] = x;
				x = l;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	if(k < 3){
		trivial( n, k);
		return 0;
	}
	bool flag = true;
	{
		std::string str{};
		std::cin >> str;
		for(int index = str.length() - 1; index >= 0 && flag; index--){
			for(char x = str[index] + 1; x < char('a' + k) && flag; x++){
				if(index >= 2){
					if(str[index - 2] != x && str[index - 1] != x){
						makeArr( x, str, index, k);
						std::cout << str << "\n";
						return 0;
					}
				}

				if(index == 1){
					if(str[index - 1] != x){
						makeArr( x, str, index, k);
						std::cout << str << "\n";
						return 0;
					}
				}

				if(index == 0){
					makeArr( x, str, index, k);
					std::cout << str << "\n";
					return 0;
				}
			}
		}
	}

	if(flag){
		std::cout << "NO\n";
	}
	return 0;
}