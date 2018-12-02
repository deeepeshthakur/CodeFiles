#include <bits/stdc++.h>

using namespace std;

class point3d{
private:
	double x, y, z;
public:
	point3d(){
		x = 0;
		y = 0;
		z = 0;
	}

	point3d( double xdash, double ydash, double zdash){
		x = xdash;
		y = ydash;
		z = zdash;
	}

	void setX( double xdash){
		x = xdash;
	}

	void setY( double ydash){
		y = ydash;
	}

	void setZ( double zdash){
		z = zdash;
	}

	void setPoint( double xdash, double ydash, double zdash){
		setX( xdash);
		setY( ydash);
		setZ( zdash);
	}

	void takeInput(){
		std::cin >> x >> y >> z;
	}

	double getX(){
		return x;
	}

	double getY(){
		return y;
	}

	double getZ(){
		return z;
	}

	// void print(){
	// 	std::cout << x << " " << y << " " << z << "\n";
	// }
};

void rotatePoint( point3d &point, std::vector< std::vector < double > >& rotationMatrix){
	std::vector< double > point_matrix( 3);
	point_matrix[0] = point.getX();
	point_matrix[1] = point.getY();
	point_matrix[2] = point.getZ();

	std::vector< double > point_dash_matrix( 3);
	for(int x = 0; x < 3; x++){
		double temp_sum = 0;
		for(int y = 0; y < 3; y++){
			temp_sum += (rotationMatrix[x][y]*point_matrix[y]);
		}
		point_dash_matrix[x] = temp_sum;
	}

	point.setPoint( point_dash_matrix[0], point_dash_matrix[1], point_dash_matrix[2]);
}

void setOrigin( point3d &p1, point3d p){
	p1.setPoint( p1.getX() - p.getX(), p1.getY() - p.getY(), p1.getZ() - p.getZ());
}

void adjustAxis( point3d &p1, std::vector < double > multipliers){
	p1.setPoint( p1.getX()*multipliers[0], p1.getY()*multipliers[1], p1.getZ()*multipliers[2]);
}

std::vector < std::vector < double > > multiply_matrix( std::vector < std::vector < double > > m1, std::vector < std::vector < double > > m2){
	std::vector < std::vector < double > > ans( 3, std::vector < double >(3, 0));
	for(int x = 0; x < 3; x++){
		for( int y = 0; y < 3; y++){
			double temp_sum = 0;
			for(int index = 0; index < 3; index++){
				temp_sum += (m1[x][index]*m2[index][y]);
			}
			ans[x][y] = temp_sum;
		}
	}
	return ans;
}

// void print_matrix( std::vector < std::vector < double > > mat){
// 	for(auto x : mat){
// 		for( auto y : x){
// 			std::cout << y << " ";
// 		}
// 		std::cout << "\n";
// 	}
// 	std::cout << "\n";
// }

void solve(){
	point3d p, q, c;
	double radius;
	std::vector < double > direction( 3, 0);


	// Input Taken
	p.takeInput();
	q.takeInput();
	std::cin >> direction[0] >> direction[1] >> direction[2];
	c.takeInput();
	std::cin >> radius;

	double cp_sq = pow( c.getX() - p.getX(), (double)2) + pow( c.getY() - p.getY(), (double)2) + pow( c.getZ() - p.getZ(), (double)2),
		   radius_sq = pow( radius, (double)2);

	// std::cout << cp_sq << "  " << radius_sq << "\n";
	// Point Q at time 1 sec to calculate direction vector after rotation
	point3d qOne;

	// Origin set at P
	setOrigin( q, p);
	setOrigin( c, p);
	setOrigin( p, p);
	qOne.setPoint( q.getX() + direction[0], q.getY() + direction[1], q.getZ() + direction[2]);

	// Setting quadrant
	std::vector < double > multipliers(3, 1.0);
	if(c.getX() < 0.0){
		multipliers[0] = -1.0;
	}

	if(c.getY() < 0.0){
		multipliers[1] = -1.0;
	}

	if(c.getZ() < 0.0){
		multipliers[2] = -1.0;
	}

	adjustAxis( c, multipliers);
	adjustAxis( q, multipliers);
	adjustAxis( qOne, multipliers);

	// p.print(); q.print(), c.print(), qOne.print();

	double theta_one = (-1.0)*atan2( c.getY(), c.getX()),
		   theta_two = (1.0)*atan2( c.getZ(), sqrt(pow( c.getX(), 2.0) + pow( c.getY(), 2.0)));
		   // theta_two = atan(sqrt(3.0));
	std::vector< std::vector < double > > z_rotation { { cos(theta_one), (-1.0)*sin(theta_one), 0}, { (1.0)*sin(theta_one), cos(theta_one), 0}, { 0, 0, 1}},
	y_rotation{ { cos(theta_two), 0, (1.0)*sin(theta_two)}, { 0, 1, 0}, { (-1.0)*sin(theta_two), 0, cos(theta_two)}},
	total_rotation( 3, std::vector < double > (3, 0));

	// print_matrix( z_rotation); print_matrix( y_rotation);
	// total_rotation = multiply_matrix( z_rotation, y_rotation);
	total_rotation = multiply_matrix( y_rotation, z_rotation);
	// print_matrix(total_rotation);

	rotatePoint( q, total_rotation);
	rotatePoint( c, total_rotation);
	rotatePoint( qOne, total_rotation);
	rotatePoint( p, total_rotation);
	// p.print(); std::cout << "\n"; q.print();std::cout << "\n"; c.print(); std::cout << "\n"; qOne.print(); std::cout << "\n";

	direction[0] = qOne.getX() - q.getX();
	direction[1] = qOne.getY() - q.getY();
	direction[2] = qOne.getZ() - q.getZ();

	// for(auto x : direction){
	// 	std::cout << x << " ";
	// }
	// std::cout << "\n\n";

	double c_sq = (radius_sq)/(cp_sq - radius_sq);
	double coeff_A = (direction[1]*direction[1]) + (direction[2]*direction[2]) - (c_sq*direction[0]*direction[0]),
		   coeff_B = (2.00)*((direction[1]*q.getY()) + (direction[2]*q.getZ()) - (c_sq*direction[0]*q.getX())),
		   coeff_C = (q.getY()*q.getY()) + (q.getZ()*q.getZ()) - (c_sq*q.getX()*q.getX());

	double ans, root1, root2;
	double temp1 = (-1.0)*coeff_B, temp3 = (2.0)*coeff_A, temp2 = sqrt((coeff_B * coeff_B) - (4.0 * coeff_A * coeff_C));
	root1 = (temp1 + temp2)/temp3;
	root2 = (temp1 - temp2)/temp3;

	// if(root1 > root2){
	// 	ans = root1;
	// }
	// else{
	// 	ans = root2;
	// }

	// std::cout << std::setprecision(12) << ans << "\n";
	if(root1 > 0.0 && root2 > 0.0){
		if(root1 < root2){
			ans = root1;
		}
		else{
			ans = root2;
		}
	}
	else{
		if(root1 > 0){
			ans = root1;
		}
		else{
			ans = root2;
		}
	}

	std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main(){
	int testcases;
	std::cin >> testcases;
	while(testcases--){
		solve();
	}
	return 0;
}
