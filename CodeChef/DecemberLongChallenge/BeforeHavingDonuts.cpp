#include <bits/stdc++.h>

using namespace std;
double vol = 0.0;
// std::unordered_set < double > ht{};
// bool checkBox(double a, double b, double c){
// 	double t = (a + 2000.0)*100000000.0 + (b + 2000.0)*10000.0 + (c + 2000.0);
// 	if(ht.find(t) == ht.end()){
// 		ht.insert(t);
// 		return false;
// 	}
// 	return true;
// }

// std::vector < std::vector < double > > corMat{{1.0, 1.0, 1.0},
// 											  {1.0, 1.0, -1.0},
// 											  {1.0, -1.0, 1.0},
// 											  {1.0, -1.0, -1.0},
// 											  {-1.0, 1.0, 1.0},
// 											  {-1.0, 1.0, -1.0},
// 											  {-1.0, -1.0, 1.0},
// 											  {-1.0, -1.0, -1.0}};

struct torus{
	double x, y, z, r, R;
};

bool cPnt(int i, double x, double y, double z, std::vector < torus >& tori){
	if(std::abs(tori[i].z - z) <= tori[i].r){
		double d = std::sqrt((x - tori[i].x)*(x - tori[i].x) + (y - tori[i].y)*(y - tori[i].y)),
			   rr = std::sqrt(tori[i].r*tori[i].r - (tori[i].z - z)*(tori[i].z - z));
		if(tori[i].R - rr <= d && d <= tori[i].R + rr){
			return true;
		}
	}
	return false;
}

// bool cCube(int i, double cx, double cy, double cz, double s, std::vector < torus >& tori){
// 	bool f = true;
// 	for(int j = 0; j < 8 && f; j++){
// 		f = (f && cPnt(i, cx + corMat[j][0]*s, cy + corMat[j][1], cz + corMat[j][2]*s, tori));
// 	}
// 	return f;
// }

// bool cNotCube(int i, double cx, double cy, double cz, double s, std::vector < torus >& tori){
// 	bool f = false;
// 	for(int j = 0; j < 8 && !f; j++){
// 		f = (f || cPnt(i, cx + corMat[j][0]*s, cy + corMat[j][1], cz + corMat[j][2]*s, tori));
// 	}
// 	return !f;
// }

// void rec(int i, double cx, double cy, double cz, double s, std::vector < torus >& tori){
// 	if(cNotCube(i, cx, cy, cz, s, tori)){
// 		return;
// 	}

// 	if(cCube(i, cx, cy, cz, s, tori)){
// 		if(s == 1.0 && checkBox(cx, cy, cz)){
// 			return;
// 		}

// 		bool fchk = true;
// 		for(int j = 0; j < i; j++){
// 			fchk = (fchk && cNotCube(j, cx, cy, cz, s, tori));
// 		}

// 		if(!fchk){
// 			return;
// 		}

// 		// if(s == 1.0)
// 			// std::cout << cx << " " << cy << " " << cz << "\n";
// 		vol += (s*s*s);
// 		return;
// 	}

// 	if(s <= 0.01){
// 		return;
// 	}

// 	for(int j = 0; j < 8; j++){
// 		rec(i, cx + corMat[j][0]*s*0.5, cy + corMat[j][1]*s*0.5, cz+ corMat[j][2]*s*0.5, s*0.5, tori);
// 	}
// }


int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	// for(int i = 0; i < 8; i++){
	// 	for(int j = 0; j < 3; j++){
	// 		corMat[i][j] /= 2.0;
	// 		// std::cout << corMat[i][j] << " ";
	// 	}
	// 	// std::cout << std::endl;
	// }

	int n;
	std::cin >> n;
	std::vector < torus > tori(n);
	for(int i = 0; i < n; i++){
		std::cin >> tori[i].x >> tori[i].y >> tori[i].z >> tori[i].R >> tori[i].r;
	}

	// for(int i = 0; i < n; i++){
	// 	int xs, xl, ys, yl, zs, zl;
	// 	xs = tori[i].x - (tori[i].r + tori[i].R);
	// 	xl = tori[i].x + (tori[i].r + tori[i].R) + 1;
	// 	ys = tori[i].y - (tori[i].r + tori[i].R);
	// 	yl = tori[i].y + (tori[i].r + tori[i].R) + 1;
	// 	zs = tori[i].z - tori[i].r;
	// 	zl = tori[i].z + tori[i].r + 1;
	// 	for(int x = xs; x <= xl; x += 4){
	// 		for(int y = ys; y <= yl; y += 4){
	// 			for(int z = zs; z <= zl; z += 4){
	// 				rec(i, x*1.0 + 2.0, y*1.0 + 2.0, z*1.0 + 2.0, 4.0, tori);
	// 			}
	// 		}
	// 	}
	// }
	for(int k = 0; k < 1; k++)
	{
		double xs = 0, xl = 0, ys = 0, yl = 0, zs = 0, zl = 0;
		for(int i = 0; i < n; i++){
			if(zs > tori[i].z - tori[i].r){
				zs = tori[i].z - tori[i].r;
			}

			if(zl < tori[i].z + tori[i].r){
				zl = tori[i].z + tori[i].r;
			}

			if(xs > tori[i].x - (tori[i].R + tori[i].r)){
				xs = tori[i].x - (tori[i].R + tori[i].r);
			}

			if(xl < tori[i].x + (tori[i].R + tori[i].r)){
				xl = tori[i].x + (tori[i].R + tori[i].r);
			}

			if(ys > tori[i].y - (tori[i].R + tori[i].r)){
				ys = tori[i].y - (tori[i].R + tori[i].r);
			}

			if(yl < tori[i].y + (tori[i].R + tori[i].r)){
				yl = tori[i].y + (tori[i].R + tori[i].r);
			}
		}

		// std::cout << RAND_MAX << " == " << std::endl;
		long long zd, zm, xd, xm, yd, ym;
		{
			zd = (zl - zs)*100000 + 1;
			zm = zs*100000;
			xd = (xl - xs)*100000 + 1;
			xm = xs*100000;
			yd = (yl - ys)*100000 + 1;
			ym = ys*100000;

			// std::cout << xd << " " << xm << " " << yd << " " << ym << " " << zd << " " << zm << "\n";
		}

		srand(time(0));
		int c = 0;
		bool ft = true;
		for(int i = 0; i < 1000000; i++){
			ft = false;
			double xx = (rand()%xd + xm)*0.00001, yy = (rand()%yd + ym)*0.00001, zz = (rand()%zd + zm)*0.00001;
			// std::cout << xx << " " << yy << " " << zz << "\n"; 
			for(int j = 0; j < n && !ft; j++){
				if(cPnt(j, xx, yy, zz, tori)){
					c++;
					ft = true;
				}
			}
		}

		vol += ((xl - xs)*(yl - ys)*(zl - zs)/1000000.0)*c;
		// std::cout << c << "\n";
	}

	std::cout << vol << "\n";// << ht.size() << "\n";
	return 0;
}