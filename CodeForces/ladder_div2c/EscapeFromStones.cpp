#include <bits/stdc++.h>

using namespace std;

struct node{
	int index;
	node *right, *left;

	node(){
		index = -1;
		right = NULL;
		left = NULL;
	}
};	

node* makeNode( int i){
	node* temp = new node;
	temp->index = i;
	return temp;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::string inpS{};
	std::cin >> inpS;
	// std::map < double, int > orderStones{};
	node *root = makeNode(0);
	for(int index = 0; index < inpS.length(); index++){
		if(inpS[index] == 'l'){
			if(root->left){
				node* x = makeNode( index + 1);
				x->left = root->left;
				root->left->right = x;
				x->right = root;
				root->left = x;
				root = root->left;
			}
			else{
				node* x = makeNode( index + 1);
				x->right = root;
				root->left = x;
				root = root->left;
			}
		}
		else{
			if(root->right){
				node* x = makeNode( index + 1);
				root->right->left = x;
				x->right = root->right;
				root->right = x;
				x->left = root;
				root = root->right;
			}
			else{
				node* x = makeNode( index + 1);
				x->left = root;
				root->right = x;
				root = root->right;
			}
		}
	}

	while(root->left){
		root = root->left;
	}

	while(root){
		if(root->index < inpS.length()){
			std::cout << root->index + 1 << "\n";
		}
		root = root->right;
	}

	return 0;
}