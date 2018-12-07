#include <bits/stdc++.h>

using namespace std;

struct cell{
	int id;
	std::vector < std::vector < int > > children;
	long double total_prob, div;
	std::vector< long double > marginal_prob;
	bool is_tunnel, is_parent;
	int x_tunnel, y_tunnel;

	cell(){
		is_parent = false;
		div = 0;
		children.clear();
		marginal_prob.clear();
		marginal_prob.resize( 10, 0.0);
		total_prob = 0;
		is_tunnel = false;
		x_tunnel = 0;
		y_tunnel = 0;
	}
};

bool isValid( int x, int y, int n, int m){
	bool ans;
	if(x >= 0 && y >= 0 && x < n && y < m){
		ans = true;
	}else{
		ans = false;
	}
	return ans;
}

int main(){
  int n, m, k;
	std::vector < int > start_coor(2);
	std::vector < std::pair< int, int > > exits{};
    std::cin >> n >> m >> k;
	std::vector < std::string > maze(n);
	std::vector < std::vector < cell > > maze_node( n, std::vector < cell >( m));

	for(int index = 0; index < n; index++){
		std::cin >> maze[index];
	}

	for(int index = 0; index < k; index++){
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		maze_node[x1 - 1][y1 - 1].is_tunnel = true;
		maze_node[x1 - 1][y1 - 1].x_tunnel = x2 - 1;
		maze_node[x1 - 1][y1 - 1].y_tunnel = y2 - 1;
		maze_node[x2 - 1][y2 - 1].is_tunnel = true;
		maze_node[x2 - 1][y2 - 1].x_tunnel = x1 - 1;
		maze_node[x2 - 1][y2 - 1].y_tunnel = y1 - 1;
	}

	std::vector < std::vector < int > > neighbour_matrix{ { 1, 0}, { -1, 0}, { 0, 1}, { 0, -1}};
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			char curr_cell = maze[x][y];
			if(curr_cell == 'A' || curr_cell == 'O'){
				if(curr_cell == 'A'){
					maze_node[x][y].total_prob = 1;
					maze_node[x][y].marginal_prob[0] = 1;
					start_coor[0] = x;
					start_coor[1] = y;
				}
				maze_node[x][y].is_parent = true;
			}
			else{
				if(curr_cell == '%'){
					exits.push_back(std::make_pair( x, y));
				}
				maze_node[x][y].is_parent = false;
			}

			if(maze_node[x][y].is_parent){
				for(int child = 0; child < 4; child++){
					int x_child = x + neighbour_matrix[child][0], y_child = y + neighbour_matrix[child][1];
					if(isValid( x_child, y_child, n, m)){
						if(maze[x_child][y_child] != '#'){
							std::vector< int > xy(2);
							if(maze_node[x_child][y_child].is_tunnel){
								xy[0] = maze_node[x_child][y_child].x_tunnel;
								xy[1] = maze_node[x_child][y_child].y_tunnel;
							}else{
								xy[0] = x_child;
								xy[1] = y_child;
							}
							maze_node[x][y].children.push_back(xy);
						}
					}
				}
				maze_node[x][y].div = (long double)(maze_node[x][y].children.size());
			}
		}
	}



	int prev_move, curr_move;
	for(int move = 1; move < 10000; move++){
		curr_move = move%10;
		prev_move = (move - 1)%10;
		for(int x = 0; x < n; x++){
			for(int y = 0; y < m; y++){
				if(maze_node[x][y].is_parent){
					for( auto xy : maze_node[x][y].children){
						maze_node[xy[0]][xy[1]].marginal_prob[curr_move] += (maze_node[x][y].marginal_prob[prev_move])/(maze_node[x][y].div);
					}
				}
			}
		}

		for(int x = 0; x < n; x++){
			for(int y = 0; y < m; y++){
				maze_node[x][y].total_prob += maze_node[x][y].marginal_prob[curr_move];
				maze_node[x][y].marginal_prob[prev_move] = 0.0;
			}
		}
	}
	long double exit_prob_a = 0.0, exit_prob_b = 0.0;
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++){
			if(maze[x][y] == '*' || (maze[x][y] == 'O' && maze_node[x][y].children.size() == 0)){
				exit_prob_a += (maze_node[x][y].total_prob);
			}
			if(maze[x][y] == '%'){
				exit_prob_b += maze_node[x][y].total_prob;
			}
		}
	}
	long double ans;
	// std::cout << std::setprecision(9) << exit_prob_a << "   " << exit_prob_b << "\n";
	if(exit_prob_a == 0 && exit_prob_b == 0){
		ans = 0.0;
	}else{
		ans = (exit_prob_b/(exit_prob_a + exit_prob_b));
	}

	std::cout << std::setprecision(15) << ans << std::endl;
	return 0;
}
