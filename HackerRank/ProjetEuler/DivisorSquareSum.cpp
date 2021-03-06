#include <bits/stdc++.h>

using namespace std;
long long sizeSigmaArray = 6000000;
long long sigmaArray[6000000];

void preCalc(){

	for(long long x = 1; x <= 6000000; x++){
		long long CurrVal = x;
		while(CurrVal <= 6000000){
			sigmaArray[CurrVal - 1] += x*x;
			CurrVal += x;
		}
	}

	long long sqRoot = 0, temp;
	for(long long index = 0; index < sizeSigmaArray; index++){
		sqRoot = std::sqrt( sigmaArray[index]);
		temp = std::min( std::abs( sigmaArray[index] - sqRoot*sqRoot), abs( sigmaArray[index] - (sqRoot + 1)*(sqRoot + 1)));
		sigmaArray[index] = temp;
	}
}

struct query{
	int index;
	long long n, k, ans;
};

bool sortByN( query a, query b){
	return (a.n < b.n);
}

bool sortByIndex( query a, query b){
	return a.index < b.index;
}

struct node{
	long long key;
	long long sum;
	node* right;
	node* left;
	 // *par;

	node(){
		key = 0;
		sum = 0;
		right = NULL;
		left = NULL;
		// par = NULL;
	}
};

node* makeNode( long long s, long long e/*, node *par*/){
	if(s > e){
		return NULL;
	}
	node* newNode = new node;
	newNode->key = (s + e)/2;
	// newNode->par = par;
	newNode->left = makeNode( s, newNode->key - 1/*, this*/);
	newNode->right = makeNode( newNode->key + 1, e/*, this*/);
	return newNode;
}

void addNodeToTree( node* root, long long k, long long n){
	if(root != NULL){
		if(k == root->key){
			root->sum += n;
		}

		if(k < root->key){
			root->sum += n;
			addNodeToTree( root->left, k, n);
		}
		if(k > root->key){
			addNodeToTree( root->right, k, n);
		}
	}
}

long long searchCurrTree( node* root, long long k){
	if(root == NULL){
		return 0ll;
	}
	long long ans;
	if( root->key == k){
		ans = root->sum;
	}

	if(root->key > k){
		ans = searchCurrTree( root->left, k);
	}

	if(root->key < k){
		ans = searchCurrTree( root->right, k) + root->sum;
	}
	return ans;
}


int main(){
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	preCalc();
	int q = 0;

	std::cin >> q;
	std::vector < query > queryArray( q);
	int minK = 0, maxK = 1000000;
	for(int index = 0; index < q; index++){
		queryArray[index].index = index;
		std::cin >> queryArray[index].n >> queryArray[index].k;
		queryArray[index].ans = 0;
	}

	std::sort( queryArray.begin(), queryArray.end(), sortByN);
	node* root = makeNode( 0ll, 1000000ll/*, NULL*/);
	
	long long currNodeToBAdded = 0;
	for(int index = 0; index < queryArray.size(); index++){
		while( currNodeToBAdded < queryArray[index].n && currNodeToBAdded < sizeSigmaArray){
				addNodeToTree( root, sigmaArray[currNodeToBAdded], currNodeToBAdded + 1);
				currNodeToBAdded++;
		}
		queryArray[index].ans = searchCurrTree( root, queryArray[index].k);
	}


	std::sort( queryArray.begin(), queryArray.end(), sortByIndex);
	for(int index = 0; index < queryArray.size(); index++){
		std::cout << queryArray[index].ans << "\n";
	}
	return 0;
}