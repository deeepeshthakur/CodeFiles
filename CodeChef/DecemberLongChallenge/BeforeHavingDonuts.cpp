#include <bits/stdc++.h>

using namespace std;
double vol = 0.0;

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

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;
	std::vector < torus > tori(n);
	for(int i = 0; i < n; i++){
		std::cin >> tori[i].x >> tori[i].y >> tori[i].z >> tori[i].R >> tori[i].r;
	}

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

		long long zd, zm, xd, xm, yd, ym;
		{
			zd = (zl - zs)*100000 + 1;
			zm = zs*100000;
			xd = (xl - xs)*100000 + 1;
			xm = xs*100000;
			yd = (yl - ys)*100000 + 1;
			ym = ys*100000;

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