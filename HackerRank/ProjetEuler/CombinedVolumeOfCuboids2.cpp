#include <bits/stdc++.h>
using namespace std;
int modul = 1000000;

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

void randNumGen( int n, std::vector < int > inputs, std::vector < std::vector < int > >& cuboids){
	std::cout << n << std::endl;
	std::vector < int > randomNumbers(6*n);
	for(int index = 0; index < 55 && index < randomNumbers.size(); index++){
		randomNumbers[index] = randCalcFunc(index + 1);
	}
	for(int index = 55; index < 6*n; index++){
		randomNumbers[index] = (randomNumbers[index-23] + randomNumbers[index - 54])%1000000;
	}
	for(int index = 0; index < n; index++){
		cuboids[index][0] = randomNumbers[6*index]%inputs[0];
		cuboids[index][1] = randomNumbers[6*index + 1]%inputs[1];
		cuboids[index][2] = randomNumbers[6*index + 2]%inputs[2];
		cuboids[index][3] = randomNumbers[6*index + 3]%inputs[3] + 1 + cuboids[index][0];
		cuboids[index][4] = randomNumbers[6*index + 4]%inputs[4] + 1 + cuboids[index][1];
		cuboids[index][5] = randomNumbers[6*index + 5]%inputs[5] + 1 + cuboids[index][2];
	}
}

long volumeCalc( std::vector < int >& params){
	long ans;
	ans = (long)(params[3] - params[0]);
	ans *= (long)(params[4] - params[1]);
	ans *= (long)(params[5] - params[2]);
	return ans;
}

long baseCase2(int n, std::vector< std::vector < int > >& real_cuboids, std::vector < int > start, std::vector< int > end){
	long ans = 0;
	for(int x = start[0]; x <= end[0]; x++){
		for(int y = start[1]; y <= end[1]; y++){
			for(int z = start[2]; z <= end[2]; z++){
				for(int index = 0; index < n; index++){
					if(real_cuboids[index][0] <= x && real_cuboids[index][3] >= x &&
						 real_cuboids[index][1] <= y && real_cuboids[index][4] >= y &&
					   real_cuboids[index][2] <= z && real_cuboids[index][5] >= z){
							 ans++;
							 index = n;
						 }
				}
			}
		}
	}
	return ans;
}

long baseCase(int n, std::vector< std::vector < int > >& real_cuboids, std::vector < int > start, std::vector< int > end){
	long ans;
	std::cout << "basecase " << std::endl;
	for( auto x : start){ std::cout << x << " ";}
	std::cout << "     ";
	for( auto x : end){ std::cout << x << " ";}
	std::cout << std::endl;
	// std::vector< std::pair < int, std::vector < int > > > qq{};
	std::vector< std::vector < int > >cuboids{};
	std::vector< int > common_index{};
	int total_Len = 0;
	for(int index = 0; index < n; index++){
		cuboids.push_back( real_cuboids[index]);
		common_index.push_back(1);
	}

	total_Len = n;
	for(int ii = 0; ii < total_Len; ii++){
		std::vector< std::vector < int > > temp_cuboids{};
		std::vector< int > temp_cc_ii{};
		for(int index = ii + 1; index < total_Len; index++){
			if(cuboids[ii][0] < cuboids[index][3] && cuboids[index][0] < cuboids[ii][3] &&
				cuboids[ii][1] < cuboids[index][4] && cuboids[index][1] < cuboids[ii][4] &&
				cuboids[ii][2] < cuboids[index][5] && cuboids[index][2] < cuboids[ii][5]){
					std::vector< int > params(6);
					params[0] = maxCoor( cuboids[index][0], cuboids[ii][0]);
					params[1] = maxCoor( cuboids[index][1], cuboids[ii][1]);
					params[2] = maxCoor( cuboids[index][2], cuboids[ii][2]);
					params[3] = minCoor( cuboids[index][3], cuboids[ii][3]);
					params[4] = minCoor( cuboids[index][4], cuboids[ii][4]);
					params[5] = minCoor( cuboids[index][5], cuboids[ii][5]);
					temp_cuboids.push_back( params);
					temp_cc_ii.push_back( common_index[index] + common_index[ii]);
				}
			}
			for(auto x : temp_cuboids){
				cuboids.push_back(x);
			}
			for(auto x : temp_cc_ii){
				common_index.push_back(x);
			}

			if(common_index[ii]%2 == 1){
				ans += volumeCalc( cuboids[ii]);
			}else{
				ans -= volumeCalc( cuboids[ii]);
			}
		}
		return ans;
	}

	struct gridElement{
		std::vector < std::vector < int > > cuboids;
		std::vector < int > start, end;
		int n;
		bool full_flag, is_initiated, is_valid;
		gridElement(){
			start = { 0, 0, 0};
			end = { 0, 0, 0};
			n = 0;
			cuboids.clear();
			full_flag = false;
			is_initiated = false;
			is_valid = true;
		}

		void addDiagonalPoints( std::vector < int > start1, std::vector < int > end1){
			if(is_valid){
				for(int index = 0; index < 3; index++){
					start[index] = start1[index];
					end[index] = end1[index];
				}
			}
		}

		void addChild( std::vector < int > params){
			if(is_valid){
				if(!is_initiated){
					is_initiated = true;
					cuboids.clear();
					n = 0;
				}
				cuboids.push_back( params);
				n++;
			}
		}

		void declareFull(){
			// std::cout << "declaredfull\n\n";
			if(is_valid){
				if(!is_initiated){
					is_initiated = true;
				}
				full_flag = true;
				cuboids.clear();
				n = 0;
			}
		}
	};

	void prelim( std::vector< std::vector < std::vector < gridElement > > >& grid, std::vector< int > start, std::vector< int > end){
		std::vector< int > mid{ (start[0] + end[0])/2, (start[1] + end[1])/2, (start[2] + end[2])/2};
		std::vector< int > middash{ mid[0] + 1, mid[1] + 1, mid[2] + 1};
		for(int x = 0; x < 2; x++){
			for(int y = 0; y < 2; y++){
				for(int z = 0; z < 2; z++){
					std::vector< int > temp_Start(3), temp_End(3);
					if(x == 0){
						temp_Start[0] = start[0];
						temp_End[0] = mid[0];
					}else{
						temp_Start[0] = middash[0];
						temp_End[0] = end[0];
					}

					if(y == 0){
						temp_Start[1] = start[1];
						temp_End[1] = mid[1];
					}else{
						temp_Start[1] = middash[1];
						temp_End[1] = end[1];
					}

					if(z == 0){
						temp_Start[2] = start[2];
						temp_End[2] = mid[2];
					}else{
						temp_Start[2] = middash[2];
						temp_End[2] = end[2];
					}

					if(temp_Start[0] > temp_End[0] || temp_Start[1] > temp_End[1] || temp_Start[2] > temp_End[2]){
						grid[x][y][z].is_valid = false;
					}

					if(grid[x][y][z].is_valid){
						grid[x][y][z]. addDiagonalPoints( temp_Start, temp_End);
						// std::cout << "\nadd diagonalpoints         ";
						// for(auto x : temp_Start){ std::cout << x << " ";}
						// for(auto x : temp_End){ std::cout << x << " ";}
					}
				}
			}
		}
	}

	long commonVolCalc( int n, std::vector< std::vector < int > >& cuboids, std::vector < int > start, std::vector< int > end){
		std::cout << "called   ";
		for(auto x : start){
			std::cout << x << " ";
		}
		std::cout << "         ";
		for(auto x : end){
			std::cout << x << " ";
		}

		if(n <= 40){
			std::cout << "...   " << std::endl;
			return baseCase( n, cuboids, start, end);
		}

		if(end[0] - start[0] < 8 && end[1] - start[1] < 8 && end[2] - start[2] < 8){
			std::cout << "***   " << n << std::endl;
			return baseCase2( n, cuboids, start, end);
		}

		std::cout << std::endl;

		std::vector< std::vector < std::vector < gridElement > > > grid( 2, std::vector< std::vector < gridElement > >( 2, std::vector< gridElement >(2)));
		prelim( grid, start, end);

		for(int index = 0; index < n; index++){
			std::vector< int > startpoint(3), endpoint(3), parameter(6);
			for(int x = 0; x < 2; x++){
				for(int y = 0; y < 2; y++){
					for(int z = 0; z < 2; z++){
						startpoint[0] = start[0]; startpoint[1] = start[1], startpoint[2] = start[2];
						endpoint[0] = end[0]; endpoint[1] = end[1]; endpoint[2] = end[2];
						if(grid[x][y][z].is_valid && (!grid[x][y][z].full_flag)){
							if((startpoint[0] < grid[x][y][z].end[0] && endpoint[0] > grid[x][y][z].start[0]) &&
							(startpoint[1] < grid[x][y][z].end[1] && endpoint[1] > grid[x][y][z].start[1]) &&
							(startpoint[2] < grid[x][y][z].end[2] && endpoint[2] > grid[x][y][z].start[2])){
								if(startpoint[0] < grid[x][y][z].start[0]){
									startpoint[0] = grid[x][y][z].start[0];
								}

								if(startpoint[1] < grid[x][y][z].start[1]){
									startpoint[1] = grid[x][y][z].start[1];
								}

								if(startpoint[3] < grid[x][y][z].start[3]){
									startpoint[3] = grid[x][y][z].start[3];
								}

								if(endpoint[0] > grid[x][y][z].end[0]){
									endpoint[0] = grid[x][y][z].end[0];
								}

								if(endpoint[1] > grid[x][y][z].end[1]){
									endpoint[1] = grid[x][y][z].end[1];
								}

								if(endpoint[2] > grid[x][y][z].end[2]){
									endpoint[2] = grid[x][y][z].end[2];
								}
								parameter[0] = startpoint[0];
								parameter[1] = startpoint[1];
								parameter[2] = startpoint[2];
								parameter[3] = endpoint[3];
								parameter[4] = endpoint[4];
								parameter[5] = endpoint[5];
								grid[x][y][z].addChild( parameter);

								if((startpoint[0] == grid[x][y][z].start[0]) &&
								(startpoint[1] == grid[x][y][z].start[1]) &&
								(startpoint[2] == grid[x][y][z].start[2]) &&
								(endpoint[0] == grid[x][y][z].end[0]) &&
								(endpoint[1] == grid[x][y][z].end[1]) &&
								(endpoint[2] == grid[x][y][z].end[2])){
									grid[x][y][z].declareFull();
								}

							}
						}
					}
				}
			}
		}

		long ans = 0;
		for(int x = 0; x < 2; x++){
			for(int y = 0; y < 2; y++){
				for(int z = 0; z < 2; z++){
					if(grid[x][y][z].is_valid && grid[x][y][z].is_initiated){
						if(grid[x][y][z].full_flag){
							// std::cout << "declaredfull\n";
							ans += ((long)(grid[x][y][z].end[0] - grid[x][y][z].start[0]))*((long)(grid[x][y][z].end[1] - grid[x][y][z].start[1]))*((long)(grid[x][y][z].end[2] - grid[x][y][z].start[2]));
						}
						else{
							ans += commonVolCalc(grid[x][y][z].n, grid[x][y][z].cuboids, grid[x][y][z].start, grid[x][y][z].end);
						}
					}
				}
			}
		}
		return ans;
	}

	int main(){
		int CapN;
		std::vector < int > Inputs(6);
		for(int index = 0; index < 6; index++){
			std::cin >> Inputs[index];
		}
		std::cin >> CapN;

		// std::cout << "check0" << std::endl;
		std::vector < std::vector < int > > cuboids(CapN, std::vector < int >(6));
		randNumGen( CapN, Inputs, cuboids);
		// std::cout << "check1" << std::endl;
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
