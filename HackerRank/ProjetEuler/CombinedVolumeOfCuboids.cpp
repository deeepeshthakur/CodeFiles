#include <bits/stdc++.h>
using namespace std;
int modul = 1000000;

//Variables
int CapN;
std::vector < std::vector < int > > cuboids;


int minCoor( int a, int b){
	if(b < a){
		return b;
	}
	return a;
}

int maxCoor( int a, int b){
	if(b > a){
		return b;
	}
	return a;
}

int randCalcFunc( int index){
	int ans = (300007*index)%modul;
	ans = (ans*index + modul - 200003)%modul;
	ans = (ans*index + 100003)%modul;
	return ans;
}

void randNumGen(std::vector < int > inputs){
	int n = CapN;
	std::cout << n << std::endl;
	std::vector < int > randomNumbers(6*n);
	for(int index = 0; index < 55 && index < randomNumbers.size(); index++){
		randomNumbers[index] = randCalcFunc(index + 1);
	}
	for(int index = 55; index < 6*n; index++){
		randomNumbers[index] = (randomNumbers[index-23] + randomNumbers[index - 54])%1000000;
	}
	std::vector < int > param(6);
	for(int index = 0; index < n; index++){
		param[0] = randomNumbers[6*index]%inputs[0];
		param[1] = randomNumbers[6*index + 1]%inputs[1];
		param[2] = randomNumbers[6*index + 2]%inputs[2];
		param[3] = randomNumbers[6*index + 3]%inputs[3] + 1 + param[0];
		param[4] = randomNumbers[6*index + 4]%inputs[4] + 1 + param[1];
		param[5] = randomNumbers[6*index + 5]%inputs[5] + 1 + param[2];
		cuboids.push_back(param);
	}
}



int main(){
	std::vector < int > Inputs(6);
	for(int index = 0; index < 6; index++){
		std::cin >> Inputs[index];
	}
	std::cin >> CapN;
	randNumGen( CapN, Inputs, cuboids);
	for(auto x : cuboids){
		for(auto y : x){
			std::cout << y << " ";
		}
		std::cout << std::endl;
	}
	std::vector < int > start{ 0, 0, 0}, end{ Inputs[0] + Inputs[3] + 1000, Inputs[1] + Inputs[4] + 1000, Inputs[2] + Inputs[5] + 1000};
	long ans = commonVolCalc( CapN, cuboids, start, end);
	std::cout << ans << "\n";
	return 0;
}
