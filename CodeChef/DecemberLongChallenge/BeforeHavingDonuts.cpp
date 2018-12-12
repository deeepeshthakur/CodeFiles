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

	for(int i = 0; i < n; i++)
	{
		// double xs = 0, xl = 0, ys = 0, yl = 0, zs = 0, zl = 0;
		// for(int i = 0; i < n; i++){
		// 	if(zs > tori[i].z - tori[i].r){
		// 		zs = tori[i].z - tori[i].r;
		// 	}

		// 	if(zl < tori[i].z + tori[i].r){
		// 		zl = tori[i].z + tori[i].r;
		// 	}

		// 	if(xs > tori[i].x - (tori[i].R + tori[i].r)){
		// 		xs = tori[i].x - (tori[i].R + tori[i].r);
		// 	}

		// 	if(xl < tori[i].x + (tori[i].R + tori[i].r)){
		// 		xl = tori[i].x + (tori[i].R + tori[i].r);
		// 	}

		// 	if(ys > tori[i].y - (tori[i].R + tori[i].r)){
		// 		ys = tori[i].y - (tori[i].R + tori[i].r);
		// 	}

		// 	if(yl < tori[i].y + (tori[i].R + tori[i].r)){
		// 		yl = tori[i].y + (tori[i].R + tori[i].r);
		// 	}
		// }

		// long long zd, zm, xd, xm, yd, ym;
		// {
		// 	zd = (zl - zs)*100000 + 1;
		// 	zm = zs*100000;
		// 	xd = (xl - xs)*100000 + 1;
		// 	xm = xs*100000;
		// 	yd = (yl - ys)*100000 + 1;
		// 	ym = ys*100000;
		// }

		srand(time(0));
		int c = 0, tot = 1000000, acc = 100000000;
		double prob = 0.0, inv =0.0;
		double pi = 3.141592654;
		double alpha, beta, mag;
		double x, y, z;
		bool ft = true;
		for(int j = 1; j <= tot; j++){
			alpha = 2*pi*(((rand()%acc)*1.0)/(acc*1.0));
			beta = 2*pi*(((rand()%acc)*1.0)/(acc*1.0));
			mag = tori[i].r*(((rand()%acc)*1.0)/(acc*1.0));
			x = tori[i].x + tori[i].R*std::cos(alpha) + mag*std::cos(beta)*std::cos(alpha);
			y = tori[i].y + tori[i].R*std::sin(alpha) + mag*std::cos(beta)*std::sin(alpha);
			z = tori[i].z + mag*std::sin(beta);

			ft = true;
			for(int t = 0; t < i && ft; t++){
				if(cPnt(t, x, y, z, tori)){
					c++;
					ft = false;
				}
			}

			if(j%1000 == 0)
			{
				prob += ((j - c)*1.0)/(j*1.0);//*(j);
				inv += 1.0; //(j);
				if(i > 0){
					// std::cout << std::fixed << setprecision(6) << ((j - c)*1.0)/(j*1.0) << "\n";
				}
			}
		}
		// std::cout << c << std::endl;
		// prob /= 1000.0;
		std::cout << std::fixed << std::setprecision(10)<< prob << "\n";
		vol += (2.0*pi*pi*tori[i].r*tori[i].r*tori[i].R)*(prob/inv);
		// std::cout << c << "\n";
	}

	std::cout << std::fixed << std::setprecision(10)<< vol << "\n";
	return 0;
}