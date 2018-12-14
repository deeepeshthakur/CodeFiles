#include <bits/stdc++.h>

using namespace std;
// long long Volume = 0;
long long countts = 0;
// double vol = (1700.0*1700.0*1700.0);
double vol = 0.0, epsi = 0.001;

struct torus{
	double x, y, z, r, R;
};

struct node{
	double x1, x2, y1, y2, z1, z2;
	node(double xa, double xb, double ya, double yb, double za, double zb){
		x1 = xa;
		x2 = xb;
		y1 = ya;
		y2 = yb;
		z1 = za;
		z2 = zb;
	}
};

std::queue < node > bfsq{};

bool aFunction(int i, double x1, double x2, double y1, double y2, double z1, double z2, std::vector < torus >& tori){
	if(std::max(std::abs(tori[i].z - z1), std::abs(tori[i].z - z2)) > (tori[i].r - epsi)){
		return false;
	}
	else{
		double rM = tori[i].R + std::sqrt(tori[i].r*tori[i].r - std::max((z1 - tori[i].z)*(z1 - tori[i].z), (z2 - tori[i].z)*(z2 - tori[i].z)));
		double mx = std::max((tori[i].x - x1)*(tori[i].x - x1), (tori[i].x - x2)*(tori[i].x - x2)),
			   my = std::max((tori[i].y - y1)*(tori[i].y - y1), (tori[i].y - y2)*(tori[i].y - y2));
		if((rM + epsi) >= std::sqrt(mx + my)){
			return true;
		}
	}
	return false;
}

bool cFunction(int i, double x1, double x2, double y1, double y2, double z1, double z2, std::vector < torus >& tori){
	if(std::min(std::abs(tori[i].z - z1), std::abs(tori[i].z - z2)) >= (tori[i].r - epsi) && 
	   ((tori[i].z - z1)*(tori[i].z - z2) > 0.0)){
		return true;
	}
	else{
		double rM = 0.0;
		if((tori[i].z - z1)*(tori[i].z - z2) < 0.0){
			rM = tori[i].R + tori[i].r;
		}
		else
			rM = tori[i].R + std::sqrt(tori[i].r*tori[i].r - std::min((z1 - tori[i].z)*(z1 - tori[i].z), (z2 - tori[i].z)*(z2 - tori[i].z)));
		
		if((tori[i].x - x1)*(tori[i].x - x2) > 0.0 || (tori[i].y - y1)*(tori[i].y - y2) > 0.0){
			double mx = std::min((tori[i].x - x1)*(tori[i].x - x1), (tori[i].x - x2)*(tori[i].x - x2)),
				   my = std::min((tori[i].y - y1)*(tori[i].y - y1), (tori[i].y- y2)*(tori[i].y- y2));

			if((tori[i].x - x1)*(tori[i].x - x2) < 0.0 && (rM - epsi) <= std::sqrt(my)){
				return true;
			}

			if((tori[i].y - y1)*(tori[i].y - y2) < 0.0 && (rM - epsi) <= std::sqrt(mx)){
				return true;
			}

			if((rM - epsi) <= std::sqrt(mx + my)){
				return true;
			}
		}
	}
	return false;
}

bool eFuntion(int i, double x1, double x2, double y1, double y2, double z1, double z2, std::vector < torus >& tori){
	if(std::max(std::abs(tori[i].z - z1), std::abs(tori[i].z - z2)) > (tori[i].r - epsi)){
		return false;
	}
	else{
		double rM = tori[i].R - std::sqrt(tori[i].r*tori[i].r - std::max((z1 - tori[i].z)*(z1 - tori[i].z), (z2 - tori[i].z)*(z2 - tori[i].z)));
		if((tori[i].x - x1)*(tori[i].x - x2) > 0.0 || (tori[i].y - y1)*(tori[i].y - y2) > 0.0){
			double mx = std::min((tori[i].x - x1)*(tori[i].x - x1), (tori[i].x - x2)*(tori[i].x - x2)),
				   my = std::min((tori[i].y - y1)*(tori[i].y - y1), (tori[i].y- y2)*(tori[i].y- y2));

			if((tori[i].x - x1)*(tori[i].x - x2) <= 0.0 && (rM - epsi) <= std::sqrt(my)){
				return true;
			}

			if((tori[i].y - y1)*(tori[i].y - y2) <= 0.0 && (rM - epsi) <= std::sqrt(mx)){
				return true;
			}

			if((rM - epsi)<= std::sqrt(mx + my)){
				return true;
			}
		}
	}
	return false;
}

bool dFunction(int i, double x1, double x2, double y1, double y2, double z1, double z2, std::vector < torus >& tori){
	if(std::min(std::abs(tori[i].z - z1), std::abs(tori[i].z - z2)) > (tori[i].r - epsi) && ((tori[i].z - z1)*(tori[i].z - z2) > 0.0)){
		return true;
	}
	else{
		double rM = 0.0;
		if((tori[i].z - z1)*(tori[i].z - z2) < 0.0){
			rM = tori[i].R - tori[i].r;
		}
		else
			rM = tori[i].R - std::sqrt(tori[i].r*tori[i].r - std::min((z1 - tori[i].z)*(z1 - tori[i].z), (z2 - tori[i].z)*(z2 - tori[i].z)));
		
		double mx = std::max((tori[i].x - x1)*(tori[i].x - x1), (tori[i].x - x2)*(tori[i].x - x2)),
			   my = std::max((tori[i].y - y1)*(tori[i].y - y1), (tori[i].y- y2)*(tori[i].y - y2));
		if((rM + epsi) >= std::sqrt(mx + my)){
			return true;
		}
	}
	return false;
}

void rec(double x1, double x2, double y1, double y2, double z1, double z2, std::vector < torus >& tori){
	// countts++;
	// std::cout << countts << " " << x1 << " " << x2 << " " << y1 << " " << y2 << " " << z1 << " " << z2  << "    " << vol << std::endl; 
	bool a, c, d, e, res;
	c = true;
	d = true;
	res = true;
	for(int i = 0; i < tori.size() && res; i++){
		c = cFunction(i, x1, x2, y1, y2, z1, z2, tori);
		d = dFunction(i, x1, x2, y1, y2, z1, z2, tori);
		res = (c || d);
	}
	if(res){
		// vol -= std::abs((x1 - x2)*(y1 - y2)*(z1 - z2));
		return;
	}

	res = false;
	for(int i = 0; i < tori.size() && !res; i++){
		a = aFunction(i, x1, x2, y1, y2, z1, z2, tori);
		e = eFuntion(i, x1, x2, y1, y2, z1, z2, tori);
		res = (a && e);
	}
	if(res){
		vol += std::abs((x1 - x2)*(y1 - y2)*(z1 - z2));
		return;
	}

	double lm = std::max(std::max(abs(x1 - x2), abs(y1 - y2)), std::abs(z1 - z2));

	if(std::abs((x1 - x2)*(y1 - y2)*(z1 - z2)) <= 0.00001){
		vol += std::abs((x1 - x2)*(y1 - y2)*(z1 - z2))/2.0;
		return;
	}

	if(lm == abs(z1 - z2)){
		bfsq.push(node(x1, x2, y1, y2, std::min(z1, z2), (z1 + z2)/2.0));
		bfsq.push(node(x1, x2, y1, y2, (z1 + z2)/2.0, std::max(z1, z2)));
	}
	else{
		if(lm == abs(x1 - x2)){
			bfsq.push(node(std::min(x1, x2), (x1 + x2)/2.0, y1, y2, z1, z2));
			bfsq.push(node((x1 + x2)/2.0, std::max(x1, x2), y1, y2, z1, z2));
		}
		else{
			bfsq.push(node(x1, x2, std::min(y1, y2), (y1 + y2)/2.0, z1, z2));
			bfsq.push(node(x1, x2, (y1 + y2)/2.0, std::max(y1, y2), z1, z2));
		}
	}
	return;
}


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector < torus > tori(n);
	for(int i = 0; i < n; i++){
		std::cin >> tori[i].x >> tori[i].y >> tori[i].z >> tori[i].R >> tori[i].r;
	}
	bfsq.push(node(-1000.0, 700.0, -1000.0, 700.0, -1000.0, 700.0));
	// bfsq.push(node(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0));
	// std::cout << std::fixed << std::setprecision(8) << 1.0 << "\n";
	while(!bfsq.empty()){
		rec(bfsq.front().x1, bfsq.front().x2, bfsq.front().y1, bfsq.front().y2, bfsq.front().z1, bfsq.front().z2, tori);
		bfsq.pop();
	}

	std::cout << std::fixed << std::setprecision(10) << vol << std::endl;
	return 0;
}