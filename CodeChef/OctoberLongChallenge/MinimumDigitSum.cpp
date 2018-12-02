#include <bits/stdc++.h>

using namespace std;

struct currNode{
	long n;
	long steps;
};

long digitSumFunc( long n){
	long sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

long nextStep( long d, std::set < long >& collectN, std::queue < currNode >& currQ, currNode &currMin, bool flag){
	if(flag){
		long retV = 0;
		currNode temp;
		temp.n = currQ.front().n;
		temp.steps = currQ.front().steps;
		retV = temp.steps;
		if(collectN.find( temp.n) == collectN.end()){
			collectN.insert( temp.n);
			retV++;
			currNode c1, c2;
			c1.n = digitSumFunc( temp.n);
			c1.steps = temp.steps + 1;
			c2.n = temp.n  + d;
			c2.steps = temp.steps + 1;
			currQ.push( c1);
			currQ.push( c2);
			if(currMin.n > temp.n){
				currMin.n = temp.n;
				currMin.steps = temp.steps;
			}
		}
		return retV;
	}
	
	currNode newNode;
	newNode.n = currQ.front().n;
	newNode.steps = currQ.front().steps;
	if(collectN.find(newNode.n) == collectN.end()){
		if(currMin.n > newNode.n){
			currMin.n = newNode.n;
			currMin.steps = newNode.steps;
		}
		collectN.insert(newNode.n);
	}
	return newNode.steps;
}



long f(){
	long stepLimit = 18;
	long n, d;
	std::cin >> n >> d;
	// if(n%3 == 0 && d%3 == 0){
	// 	stepLimit = 18;
	// }
	// long ansLimit = 1;
	// if(n%9 == 0 && d%9 == 0){
	// 	ansLimit = 9;
	// }
	// else{
	// 	if(n%6 == 0 && d%6 == 0){
	// 		if(d%9 == 0)
	// 	}
	// 	else{
	// 		if(n%3 == 0 && d%3 == 0){
	// 			ansLimit = 3;
	// 		}
	// 	}
	// }
	currNode diffNumbers;
	std::set < long > collectN;
	std::queue < currNode > currQ;
	
	diffNumbers.n = n;
	diffNumbers.steps = 0;
	long steps = 0;
	
	currNode newNode;
	newNode.n = n;
	newNode.steps = 0;
	
	currQ.push( newNode);
	long retValue = 0;
	bool checkFlag = true;
	while( !currQ.empty() && checkFlag){
		if(steps < stepLimit){
			retValue = nextStep( d, collectN, currQ, diffNumbers, true);
			if(retValue > steps){
				steps = retValue;
			}
			currQ.pop();
		}
		else{
			retValue = nextStep( d, collectN, currQ, diffNumbers, false);
			currQ.pop();
		}
		// if( diffNumbers.n <= 1){
		// 	checkFlag = false;
		// }
	}

	std::cout << diffNumbers.n << " " << diffNumbers.steps << "\n";
	return 0;
}

int main(){
	long test = 0;
	std::cin >> test;
	while( test--){
		f();
	}
	return 0;
}