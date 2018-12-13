#include <bits/stdc++.h>

using namespace std;
double vol = 0.0;
const double pi = 3.1415926535897932384626;

struct torus{
	double x, y, z, r, R;
};

bool compareBV(torus& a, torus& b){
	return a.r*a.r*a.R > b.r*b.r*b.R;
}

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

double probCommon(int i, double theta1, double theta2, int k, std::vector < torus >& tori){
	// srand(time(0));
	// double pi = 3.141592654;
	double alpha, beta, mag, prob = 0.0, inv = 0.0, x, y, z;
	int c = 0, acc = 10000000;
	bool ft = true;
	for(int j = 1; j <= k; j++){
		alpha = theta1 + (theta2 - theta1)*(((rand()%acc)*1.0)/(acc*1.0));
		beta = pi*(((rand()%acc)*1.0)/(acc*1.0)) - pi;
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

		if(j == 100 && c == 0){
			return 1.0;
		}
	}

	return ((k - c)*1.0)/(k*1.0);
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

	std::sort(tori.begin(), tori.end(), compareBV);

	vol = 0.0;
	srand(time(0));
	double prob = 0.0;
	int div = 100000, trials = 1000;
	for(int i = 0; i < n; i++)
	{
		double vZero = 2*pi*pi*tori[i].r*tori[i].r*tori[i].R;
		if(i == 0){
			vol += vZero;
		}
		else{
			for(int j = 0; j < div; j++){
				vol += (probCommon(i, (2*pi*j)/(div*1.0), (2*pi*(j + 1))/(div*1.0), trials, tori)*vZero)/(div*1.0);
			}
		}
	}

	std::cout << std::fixed << std::setprecision(10)<< vol << "\n";
	return 0;
}