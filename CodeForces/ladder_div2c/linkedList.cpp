#include <bits/stdc++.h>

using namespace std;

struct node{
	int val, index;
	node *left, *right;
};

node* makeNode( int v, int i){
	node* newNode = new node;
	newNode->val = v;
	newNode->index = i;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bool check( node* a, node* b){
	if(b){
		if(a->val < b->val){
			return false;
		}
		return true;
	}
	return false;
}

void rec( node* root, std::vector < int >& iterations){
	while( check( root, root->right)){
		iterations[root->index]++;
		node* a = root->right;
		root->right = a->right;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < int > inpArray( n, 0);
	for(int index = 0; index < n; index++){
		std::cin >> inpArray[index];
	}

	std::vector < int > iterations( n, 0);

	node *root = makeNode( inpArray[0], 0), *start, *end;
	start = root;
	for(int index = 1; index < n; index++){
		node* temp = makeNode( inpArray[index], index);
		root->right = temp;
		temp->left = root;
		root = root->right;
	}

	end = root;
	while(root){
		rec( root, iterations);
		root = root->left;
	}

	int ans = 0;
	for(int index = 0; index < n; index++){
		if(ans < iterations[index]){
			ans = iterations[index];
		}
	}

	std::cout << ans << "\n";
	return 0;
}