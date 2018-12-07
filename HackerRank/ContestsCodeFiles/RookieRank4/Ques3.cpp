#include <bits/stdc++.h>

using namespace std;


struct node
{
	int value;
	int height = -1;
	int Total_Height_child = -1;
	node *left_child = NULL, *right_child = NULL;
};

int maxi( int a, int b)
{
	if(a < b)
		return b;
	return a;
}

node* create_node( int x)
{
	node* temp;
	temp = new node;
	temp->value = x;
	return temp;
}

void fill_tree( node* curr_node, int x)
{
	if(x < curr_node->value)
	{
		if(curr_node->left_child == NULL)
		{
			curr_node->left_child = create_node(x);
			// std::cout << "left " << x << "\n";
		}
		else
		{
			fill_tree( curr_node->left_child, x);
		}
	}
	else
		if(x > curr_node->value)
		{
			if(curr_node->right_child == NULL)
			{
				curr_node->right_child = create_node(x);
				// std::cout << "right " << x << "\n";
			}
			else
			{
				fill_tree( curr_node->right_child, x);
			}
		}

}

int calc_height(node* curr_node)
{
	int ans = 0;

	if(curr_node->height == -1)
	{
		if(curr_node->left_child == NULL && curr_node->right_child == NULL)
		{
			curr_node->height = 0;
			ans = curr_node->height;
		}
		else
		{
			if(curr_node->left_child != NULL)
				ans = calc_height(curr_node->left_child);
			if(curr_node->right_child != NULL)
				ans = maxi(ans, calc_height(curr_node->right_child));
			ans += 1;
			curr_node->height = ans;
		}
	}
	else
	{
		ans = curr_node->height;
	}
	return ans;
}

int calc_total_height(node* curr_node)
{
	int ans = 0;
	if(curr_node->Total_Height_child == -1)
	{
		ans = curr_node->height;
		if(curr_node->left_child != NULL)
		{
			ans += calc_total_height(curr_node->left_child);
		}
		if(curr_node->right_child != NULL)
		{
			ans += calc_total_height(curr_node->right_child);
		}
		curr_node->Total_Height_child = ans;
	}
	else
	{
		ans = curr_node->Total_Height_child;
	}
	return ans;
}

std::vector<int> heightAndTotalHeight(std::vector<int> arr) {
    // Write your code here.
    std::vector < int > ans( 2, 0);
    node* root;
    root = new node;
    root -> value = arr[0];

    for(int index = 1; index < arr.size(); index++)
    {
    	fill_tree( root, arr[index]);
    }

    ans[0] = calc_height( root);
   	ans[1] = calc_total_height( root);

   	return ans;
}

int main()
{
	int n;
	std::cin >> n;
	std::vector < int > arr( n, 0);
	for(int index = 0; index < n; index++)
	{
		std::cin >> arr[index];
	}
	std::vector < int > result = heightAndTotalHeight( arr);
	std::cout << result[0] << " " << result[1] << "\n";
	return 0;
}