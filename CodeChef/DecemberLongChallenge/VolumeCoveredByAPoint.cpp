#include <bits/stdc++.h>
double pi = 3.141592654;

using namespace std;

double f3(double R, double r, double theta1, double theta2, double x, double y, double a){
	if(theta1 == theta2){
		return 0;
	}
	double qt1, qt2, a1, a2, stt, ctt, tt, t1, t2;
	tt = theta1;
	stt = std::sin(theta1);
	ctt = std::cos(theta1);
	a1 = std::asin(x/(R + a*r*std::cos(theta1)));
	t1 = r*R*stt + a*r*r*(tt + stt*ctt)/2.0;
	qt1 = r*R*R*stt + tt*a*r*r*R + a*r*r*R*stt*ctt + a*a*r*r*r*stt - a*a*r*r*r*(stt*stt*stt/3.0);

	tt = theta2;
	stt = std::sin(theta2);
	ctt = std::cos(theta2);
	a2 = std::asin(y/(R + a*r*std::cos(theta1)));
	t2 = r*R*stt + a*r*r*(tt + stt*ctt)/2.0;
	qt2 = r*R*R*stt + tt*a*r*r*R + a*r*r*R*stt*ctt + a*a*r*r*r*stt - a*a*r*r*r*(stt*stt*stt/3.0);
	return 0.5*((pi*0.5 - (a1 + a2))*std::abs(qt1 - qt2) - (std::cos(a1)*x + std::cos(a2)*y)*std::abs(t1 - t2));
}

double f2(double R, double r, double x, double y, double z1, double z2, double a){
	double ans = 0.0;
	if(a > 0){
		double zm = 0.0, d = std::sqrt(x*x + y*y);
		if(d >= (r + R)){
			return 0.0;
		}
		else{
			if(d <= R){
				zm = r;
			}
			else{
				zm = std::sqrt(r*r - (d - R)*(d - R)) - 0.000001;
			}
			z1 = std::min(z1, zm);
			z2 = std::min(z2, zm);
		}

		if(z1 == z2){
			return 0.0;
		}

		int cnt;
		if((z2 - z1) < 0.01*r)
			cnt = 2;
		else{
			cnt = 12;
		}

		double delta = (z2 - z1)/(cnt*1.0);
		for(int i = 0; i < cnt; i++){
			double theta1 = std::asin((z1 + i*delta)/r), theta2 = std::asin((z1 + i*delta + delta)/r);
			ans += f3(R, r, theta1, theta2, x, y, a); 
		}
		ans += std::abs(x*y*(z2 - z1));
	}
	else{
		double zm, d = std::sqrt(x*x + y*y);
		if(d >= R){
			return 0.0;
		}
		else{
			if(d <= (R - r)){
				zm = 0.0;
			}
			else{
				zm = std::sqrt(r*r - (R - d)*(R - d)) + 0.00001;
		    }
		}
		z1 = std::min(std::max(z1, zm), r);
		z2 = std::min(std::max(z2, zm), r);

		int cnt;
		if((z2 - z1) < 0.01*r)
			cnt = 2;
		else{
			cnt = 12;
		}
		double delta = (z2 - z1)/(cnt*1.0);
		for(int i = 0; i < cnt; i++){
			double theta1 = std::asin((z1 + i*delta)/r), theta2 = std::asin((z1 + i*delta + delta)/r);
			ans += f3(R, r, theta2, theta1, x, y, a); 
		}
		ans += std::abs(x*y*(z2 - z1));
	}
	return ans;
}

double f1(double R, double r, double x1, double x2, double y1, double y2, double z1, double z2, double a){
	if(z1*z2 < 0.0){
		return f1(R, r, x1, x2, y1, y2, 0.0, std::abs(z1), a) + f1(R, r, x1, x2, y1, y2, 0.0, std::abs(z2), a);
	}

	if(x1*x2 < 0.0){
		return f1(R, r, 0.0, std::abs(x1), y1, y2, z1, z2, a) + f1(R, r, 0.0, std::abs(x2), y1, y2, z1, z2, a);
	}

	if(y1*y2 < 0.0){
		return f1(R, r, x1, x2, 0.0, std::abs(y1), z1, z2, a) + f1(R, r, x1, x2, 0.0, std::abs(y2), z1, z2, a);
	}

	{
		x1 = std::abs(x1);
		x2 = std::abs(x2);
		y1 = std::abs(y1);
		y2 = std::abs(y2);
		z1 = std::abs(z1);
		z2 = std::abs(z2);

		if(z1 > z2){
			std::swap(z1, z2);
		}

		if(x1 > x2){
			std::swap(x1, x2);
		}

		if(y1 > y2){
			std::swap(y1, y2);
		}
	}
	if(z1 >= r){
		return 0.0;
	}

	if(z2 > r){
		z2 = r;
	}

	return f2(R, r, x1, y1, z1, z2, a) - f2(R, r, x1, y2, z1, z2, a) - f2(R, r, x2, y1, z1, z2, a) + f2(R, r, x2, y2, z1, z2, a);
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	double x, y, z, r, R, x1, x2, y1, y2, z1, z2, a;
	srand(time(0));

	std::cin >> R >> r >> x1 >> x2 >> y1 >> y2 >> z1 >> z2 >> a;
	// int t;
	// std::cin >> t;
	// std::cout << std::fixed << std::setprecision(3);
	// for(int i = 0; i < t; i++){
	// 	x = (rand()%100000)*0.0001;
	// 	y = (rand()%100000)*0.0001;
	// 	z = (rand()%100000)*0.0001;
	// 	x1 = (rand()%100000)*0.0001;
	// 	x2 = x1 + (rand()%100000)*0.00001;
	// 	y1 = (rand()%100000)*0.0001;
	// 	y2 = y1 + (rand()%100000)*0.00001;
	// 	z1 = (rand()%100000)*0.0001;
	// 	z2 = z1 + (rand()%100000)*0.00001;
	// 	R = (rand()%100 + 3);
	// 	r = (rand()%((int)R))*0.1;
	// 	R *= 0.1;
	// 	if(rand()%2){
	// 		a = 1.0;
	// 	}
	// 	else{
	// 		a = -1;
	// 	}
	// 	std::cout << x << "  " << y << "  " << z << "  " << R << "  " << r << "  " << x1 << "  " << x2 << "  " << y1 << "  " << y2 << "  " << z1 << "  " << z2 << "  " << a << "\n";
	// 	x1 -= x;
	// 	x2 -= x;
	// 	y1 -= y;
	// 	y2 -= y;
	// 	z1 -= z;
	// 	z2 -= z;
		std::cout << f1( R, r, x1, x2, y1, y2, z1, z2, a) << "\n";	
	// }
	return 0;
}