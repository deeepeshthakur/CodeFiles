#include <bits/stdc++.h>

using namespace std;

struct dayI{
	long long currCan;
	long long Ai, Bi;

	void operator = ( const dayI& b){
		currCan = b.currCan;
		Ai = b.Ai;
		Bi = b.Bi;
	}
};

dayI newNode( long long a, long long b){
	dayI temp;
	temp.currCan = 0;
	temp.Ai = a;
	temp.Bi = b;
	return temp;
}

inline bool operator < ( const dayI& a, const dayI& b){
	if(a.currCan < b.currCan){
		return true;
	}
	if(a.currCan == b.currCan && a.Bi < b.Bi){
		return true;
	}
	return false;
}

inline bool operator < ( dayI& a, dayI& b){
	if(a.currCan < b.currCan){
		return true;
	}
	if(a.currCan == b.currCan && a.Bi < b.Bi){
		return true;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	long long M = 0;
	std::cin >> M;
	long long SumN = 0;
	std::vector < long long > numBAlloons( n, 0), candySlope( n, 0);
	for(int index = 0; index < n; index++)
	{
		std::cin >> numBAlloons[index];
		SumN += numBAlloons[index];
	}

	for(int index = 0; index < n; index++){
		std::cin >> candySlope[index];
	}

	if(SumN <= M){
		std::cout << "0\n";
		return 0;
	}
	std::map < dayI, int> rbTree;
	for(int index = 0; index < n; index++){
		rbTree.insert( std::make_pair( newNode( numBAlloons[index], candySlope[index]), index));
	}



	std::pair < dayI, int > maxD{ std::make_pair( newNode( 0, 0), 0)}, minD{ std::make_pair( newNode( 0, 0), 0)};
	long long currMaxCandy = 0;
	if(currMaxCandy < rbTree.rbegin()->first.currCan){
		currMaxCandy = rbTree.rbegin()->first.currCan;
	}
	long long currDiff = SumN - M;
	while( currDiff > 0){
		if(rbTree.size() > 1){maxD.first = rbTree.rbegin()->first;
			maxD.second = rbTree.rbegin()->second;
			minD.first = rbTree.begin()->first;
			minD.second = rbTree.begin()->second;
			rbTree.erase( rbTree.begin());
				// rbTree.erase( rbTree.rbegin());
			long long X = (currMaxCandy - minD.first.currCan)/minD.first.Bi;
			if(X > 0)
			{
				X = std::min( std::min( X, minD.first.Ai), currDiff);
				minD.first.Ai -= X;
				SumN -= X;
				minD.first.currCan += (X*(minD.first.Bi));

				if(currMaxCandy < minD.first.currCan){
					currMaxCandy = minD.first.currCan;
				}

				if(minD.first.Ai > 0){
					rbTree.insert( minD);
				}
			}
			else{
				minD.first.Ai--;
				SumN--;
				minD.first.currCan += minD.first.Bi;

				if(currMaxCandy < minD.first.currCan){
					currMaxCandy = minD.first.currCan;
				}

				if(minD.first.Ai > 0){
					rbTree.insert( minD);
				}
			}
		}
		else{
			maxD.first = rbTree.begin()->first;
			maxD.second = rbTree.begin()->second;
			rbTree.erase( rbTree.begin());
			maxD.first.Ai -= currDiff;
			SumN -= currDiff;
			maxD.first.currCan += (min( currDiff, maxD.first.Ai) * (maxD.first.Bi));
			if(currMaxCandy < maxD.first.currCan){
				currMaxCandy = maxD.first.currCan;
			}
		}

		currDiff = SumN - M;
	}

	std::cout << currMaxCandy << "\n";
	return 0;
}