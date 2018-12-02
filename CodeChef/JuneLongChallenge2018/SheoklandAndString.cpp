#include <bits/stdc++.h>
using namespace std;

std::vector < long long int > multiplier(10,0);

void fill_table(){
	multiplier[0] = 1;
	long long int two_six = 27;
	for(int index = 1; index < 10; index++){
		multiplier[index] = multiplier[index-1]*two_six;
	}
}

long long int convert_to_num( std::string str){
	long long int ans = 0;
	std::vector< long long int > digits(10, 0);
	for(int index = 0; index < str.length(); index++){
		digits[9 - index] = (long long int)(str[index] - 'a' + 1);
	}
	for(int index = 0; index < 10; index++){
		ans += (digits[index]*multiplier[index]);
	}
	return ans;
}

long long int valCalc1( std::string str, int i){
	long long int ans = 0;
	std::vector < long long int > digits(10, 0);
	for(int index = 0; index < i; index++){
		digits[9 - index] = (long long int)(str[index] - 'a' + 1);
	}
	
	for(int index = 0; index < 10; index++){
		ans += (digits[index]*multiplier[index]);
	}
	return ans;
}

long long int valCalc2( std::string str, int i){
	long long int ans = 0;
	std::vector< long long int > digits( 10, 26);
	for(int index = 0; index < i; index++){
		digits[9 - index] = (long long int)(str[index] - 'a' + 1);
	}
	for(int index = 0; index < 10; index++){
		ans += (digits[index]*multiplier[index]);
	}
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	fill_table();
	int n, queries;
	std::cin >> n;
	std::vector < std::string > strings(n);
	std::vector < std::pair < long long int, int > > string_array(n);
	for(int index = 0; index < n; index++){
		std::string temp;
		std::cin >> temp;
		strings[index] = temp;
		string_array[index].second = index;
		string_array[index].first = convert_to_num(temp);
	}

	std::sort(string_array.begin(), string_array.end());
	// for( auto x : string_array){
	// 	std::cout << x.first <<"\n";
	// }
	// std::cout << std::endl;

	std::cin >> queries;
	while(queries--){
		int r;
		std::string pString;
		std::cin >> r >> pString;
		int pref = pString.length();
		bool flag = true;
		while(flag){
			long long int pVal1 = valCalc1(pString, pref);
			long long int pVal2 = valCalc2(pString, pref);

			int indexOne = std::lower_bound(string_array.begin(), string_array.end(),std::make_pair( pVal1, -1)) - string_array.begin();
			int indexTwo = std::upper_bound(string_array.begin(), string_array.end(),std::make_pair( pVal2, -1)) - string_array.begin();
			// std::cout << pref << "\n" << pVal1 << " " << indexOne << "\n" << pVal2 << " " <<  indexTwo << "\n";
			if(string_array[indexOne].first < pVal1){
				indexOne++;
			}
			
			for(int index = indexOne; index < indexTwo; index++){
				if(string_array[index].second < r){
					flag = false;
					std::cout << strings[string_array[index].second] << "\n";
					index = indexTwo + 1;
				}
			}
			pref--;
			if(pref <= 0){
				flag = false;
			}
		}
	}
	return 0;
}