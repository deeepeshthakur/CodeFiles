#include <bits/stdc++.h>

using namespace std;
long long countts = 0;
double vol = 0.0, epsi = 0.0, dv1 = 0.0, dv2 = 0.0, dv3 = 0.0, dv4 = 0.0, pi = 3.14159265359;

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

double areaT(double x1, double y1, double x2, double y2, double x3, double y3){
	return std::abs((x1*y2 - x2*y1) + (x2*y3 - x3*y2) + (x3*y1 - x1*y3))/2.0;
}

double areaSeg(double r, double m){
	return std::abs(std::asin(m/(2.0*r))*r*r) - (m*std::sqrt(r*r - (m*m/4.0))/2.0);
}

double areaC(double r, double x1, double x2, double y1, double y2){
	if(x1*x2 >= 0 && y1*y2 >= 0){
		x1 = std::abs(x1);
		x2 = std::abs(x2);
		y1 = std::abs(y1);
		y2 = std::abs(y2);
		if(x1 > x2){
			std::swap(x1, x2);
		}
		if(y1 > y2){
			std::swap(y1, y2);
		}

		if(r*r >= (x2*x2 + y2*y2)){
			return (x2 - x1)*(y2 - y1);
		}
		else{
			if(r*r <= (x1*x1 + y1*y1)){
				return 0;
			}
			else{
				if(r*r <= std::min((x1*x1 + y2*y2), (x2*x2 + y1*y1))){
					double a = std::sqrt(r*r - x1*x1), b = std::sqrt(r*r - y1*y1);
					return areaT(x1, y1, x1, a, b, y1) + areaSeg(r, std::sqrt((x1 - b)*(x1 - b) + (y1 - a)*(y1 - a)));
				}
				else{
					if(r*r >= std::max((x1*x1 + y2*y2), (x2*x2 + y1*y1))){
						double b = std::sqrt(r*r - x2*x2), a = std::sqrt(r*r - y2*y2);
						return areaT(x1, y1, x1, y2, a, y2) + areaT(x1, y1, x2, y1, x2, b) + areaT(x1, y1, a, y2, x2, b) + areaSeg(r, std::sqrt((x2 - a)*(x2 - a) + (y2 - b)*(y2 - b)));
					}

					if(r*r >= x2*x2 + y1*y1){
						double b = std::sqrt(r*r - x2*x2), a = std::sqrt(r*r - x1*x1);
						return areaT(x1, y1, x2, b, x1, y2) + areaT(x1, y1, x2, b, x1, a) + areaSeg(r, std::sqrt((x1 -x2)*(x1 -x2) + (a - b)*(a - b)));
					}

					if(r*r >= x1*x1 + y2*y2){
						double a = std::sqrt(r*r - y2*y2), b = std::sqrt(r*r - y1*y1);
						return areaT(x1, y1, x1, y2, a, y2) + areaT(x1, y1, a, y2, b, y1) + areaSeg(r, std::sqrt((y1 - y2)*(y1 - y2) + (a - b)*(a - b)));
					}
				}
			}
		}
	}
	else{
		if(x1*x2 >= 0 || y1*y2 >= 0){
			if(y1*y2 >= 0){
				std::swap(x1, y1);
				std::swap(x2, y2);
			}
			x1 = std::abs(x1);
			x2 = std::abs(x2);
			if(std::abs(y1) > std::abs(y2)){
				swap(y1, y2);
			}
			if(x1 > x2){
				swap(x1, x2);
			}

			if(x1 >= r){
				return 0.0;
			}

			if(r*r >= x2*x2 + y2*y2){
				return (x2 - x1)*abs(y2 - y1);
			}

			return areaC(r, x1, x2, 0.0, std::abs(y1)) + areaC(r, x1, x2, 0.0, std::abs(y2));
		}

		return areaC(r, 0.0, std::abs(x1), 0.0, std::abs(y1)) + areaC(r, 0.0, std::abs(x1), 0.0, std::abs(y2)) + areaC(r, 0.0, std::abs(x2), 0.0, std::abs(y1)) + areaC(r, 0.0, std::abs(x1), 0.0, std::abs(y2));
	}
	return 0.0;
}

void getInitialQ( std::vector < torus >& tori){
	std::vector < double > zs{};
	for(int i = 0; i < tori.size(); i++){
		zs.push_back(tori[i].z + tori[i].r);
		zs.push_back(tori[i].z - tori[i].r);
	}

	std::sort( zs.begin(), zs.end());	
	for(int i = 0; i + 1 < zs.size(); i++){
		std::vector < std::vector < double > > circles{};
		double z1 = zs[i], z2 = zs[i + 1];
		for(int j = 0; j < tori.size(); j++){
			if(std::min(std::abs(z1 - tori[j].z), std::abs(z2 - tori[j].z)) < tori[j].r || (z1 - tori[j].z)*(z2 - tori[j].z) <= 0.0){
				double rm;
				if((z1 - tori[j].z)*(z2 - tori[j].z) <= 0.0){
					rm = tori[j].R + tori[j].r;
				}
				else{
					rm = tori[j].R + std::sqrt(tori[j].r*tori[j].r - std::min((z1 - tori[j].z)*(z1 - tori[j].z), (z2 - tori[j].z)*(z2 - tori[j].z)));
				}
				circles.push_back({tori[j].x, tori[j].y, rm});
			}
		}

		std::vector < double > xs{}, ys{};
		for(int j = 0; j < circles.size(); j++){
			xs.push_back(circles[j][0] + circles[j][2]);
			xs.push_back(circles[j][0] - circles[j][2]);
			ys.push_back(circles[j][1] + circles[j][2]);
			ys.push_back(circles[j][1] - circles[j][2]);			
		}
		std::sort(xs.begin(), xs.end());
		std::sort(ys.begin(), ys.end());
		for(int m = 0; m + 1 < xs.size(); m++){
			for(int n = 0; n + 1 < ys.size(); n++){
				double x1 = xs[m], x2 = xs[m + 1], y1 = ys[n], y2 = ys[n + 1];
				bool f = true;
				for(int j = 0; j < circles.size() && f; j++){
					if((circles[j][0] - x1)*(circles[j][0] - x2) <= 0 || (circles[j][1] - y1)*(circles[j][1] - y2) <= 0){
						if((circles[j][0] - x1)*(circles[j][0] - x2) >  0 && std::min(std::abs(circles[j][0] - x1), std::abs(circles[j][0] - x2)) < circles[j][2]){
							f = false;
							bfsq.push(node(x1, x2, y1, y2, z1, z2));
						}
						if((circles[j][1] - y1)*(circles[j][1] - y2) > 0 && std::min(std::abs(circles[j][1] - y1), std::abs(circles[j][1] - y2)) < circles[j][2]){
							f = false;
							bfsq.push(node(x1, x2, y1, y2, z1, z2));
						}
						if((circles[j][0] - x1)*(circles[j][0] - x2) <= 0 && (circles[j][1] - y1)*(circles[j][1] - y2) <= 0){
							f = false;
							bfsq.push(node(x1, x2, y1, y2, z1, z2));
						}
					}
					else{
						if(std::sqrt(std::min((circles[j][0] - x1)*(circles[j][0] - x1), (circles[j][0] - x2)*(circles[j][0] - x1)) + std::min((circles[j][1] - y1)*(circles[j][1] - y1), (circles[j][1] - y2)*(circles[j][1] - y2))) < circles[j][2]){
							f = false;
							bfsq.push(node(x1, x2, y1, y2, z1, z2));
						}
					}
				}	
			}
		}
	}
}

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

			if((tori[i].x - x1)*(tori[i].x - x2) < 0.0){
				if((rM - epsi) <= std::sqrt(my))
					return true;
				else{
					return false;
				}
			}

			if((tori[i].y - y1)*(tori[i].y - y2) < 0.0){
				if((rM - epsi) <= std::sqrt(mx))
					return true;
				else{
					return false;
				}
			}

			if((rM - epsi) <= std::sqrt(mx + my)){
				return true;
			}
			else{
				return false;
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

			if((tori[i].x - x1)*(tori[i].x - x2) <= 0.0){
				if((rM - epsi) <= std::sqrt(my))
					return true;
				else{
					return false;
				}
			}

			if((tori[i].y - y1)*(tori[i].y - y2) <= 0.0){
				if((rM - epsi) <= std::sqrt(mx))
					return true;
				else
					return false;
			}

			if((rM - epsi)<= std::sqrt(mx + my)){
				return true;
			}
			else
				return false;
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
				zm = std::sqrt(r*r - (d - R)*(d - R)) - 0.00001;
			}
			z1 = std::min(z1, zm);
			z2 = std::min(z2, zm);
		}

		if(z1 == z2){
			return 0.0;
		}

		int cnt;
		if(std::abs(z2 - z1) < 0.01*r)
			cnt = 2;
		else{
			cnt = 10;
		}

		if(std::abs(z2 - z1) > 0.1){
			cnt += (int)(std::abs(z2 -z1)*100);
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
		if(std::abs(z2 - z1) < 0.01*r)
			cnt = 2;
		else{
			cnt = 10;
		}

		if(std::abs(z2 - z1) > 0.1){
			cnt += (int)(std::abs(z2 - z1)*100);
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

void baseCase(int i, int a, double x1, double x2, double y1, double y2, double z1, double z2, std::vector < torus >& tori){
	if(a == -1){
		dv2 += std::abs((x2 - x1)*(y2 - y1)*(z2 - z1));
		dv3 += f1(tori[i].R, tori[i].r, x1 - tori[i].x, x2 - tori[i].x, y1 - tori[i].y, y2 - tori[i].y, z1 - tori[i].z, z2 - tori[i].z, a*1.0);
	}
	else{
		dv1 += f1(tori[i].R, tori[i].r, x1 - tori[i].x, x2 - tori[i].x, y1 - tori[i].y, y2 - tori[i].y, z1 - tori[i].z, z2 - tori[i].z, a*1.0);
	}
}

void rec(double x1, double x2, double y1, double y2, double z1, double z2, std::vector < torus >& tori){
	bool a, c, d, res;
	int t = 0, ti = 0;	
	c = true;
	d = true;
	res = true;
	for(int i = 0; i < tori.size(); i++){
		c = cFunction(i, x1, x2, y1, y2, z1, z2, tori);
		d = dFunction(i, x1, x2, y1, y2, z1, z2, tori);
		a = (c || d);
		res = (res && a);
		if(!a){
			t++;
			ti = i;
		}
	}
	if(res){
		return;
	}

	res = false;
	for(int i = 0; i < tori.size() && !res; i++){
		c = aFunction(i, x1, x2, y1, y2, z1, z2, tori);
		d = eFuntion(i, x1, x2, y1, y2, z1, z2, tori);
		res = (c && d);
	}
	if(res){
		vol += ((x2 -x1)*(y2 - y1)*(z2 - z1));
		return;
	}

	double lm = std::max(std::max(x2 - x1, y2 - y1), z2 - z1);

	if((lm < 0.1*tori[ti].r && t == 1)){
		if(aFunction(ti, x1, x2, y1, y2, z1, z2, tori)){
			baseCase(ti, -1, x1, x2, y1, y2, z1, z2, tori);
		}
		else{
			baseCase(ti, 1, x1, x2, y1, y2, z1, z2, tori);
		}		
		return;
	}

	if(lm < 0.01){
		dv4 += std::abs((x2 - x1)*(y2 -y1)*(z2 - z1))/2.0;
		return;
	}

	if(lm >= 2.0*(z2 -z1) || lm >= 2.0*(x2 -x1) || lm >= 2.0*(y2 - y1)){
		if(lm == (x2 - x1)){
			bfsq.push(node(x1, (x1 + x2)/2.0, y1, y2, z1, z2));
			bfsq.push(node((x1 + x2)/2.0, x2, y1, y2, z1, z2));
		}
		else{
			if(lm == (y2 - y1)){
				bfsq.push(node(x1, x2, y1, (y1 + y2)/2.0, z1, z2));
				bfsq.push(node(x1, x2, (y1 + y2)/2.0, y2, z1, z2));
			}
			else{
				bfsq.push(node(x1, x2, y1, y2, z1, (z1 + z2)/2.0));
				bfsq.push(node(x1, x2, y1, y2, (z1 + z2)/2.0, z2));
			}
		}
		return;
	}

	bfsq.push(node(x1, (x1 + x2)/2.0, y1, (y1 + y2)/2.0, z1, (z1 + z2)/2.0));
	bfsq.push(node((x1 + x2)/2.0, x2, y1, (y1 + y2)/2.0, z1, (z1 + z2)/2.0));
	bfsq.push(node(x1, (x1 + x2)/2.0, (y1 + y2)/2.0, y2, z1, (z1 + z2)/2.0));
	bfsq.push(node((x1 + x2)/2.0, x2, (y1 + y2)/2.0, y2, z1, (z1 + z2)/2.0));
	bfsq.push(node(x1, (x1 + x2)/2.0, y1, (y1 + y2)/2.0, (z1 + z2)/2.0, z2));
	bfsq.push(node((x1 + x2)/2.0, x2, y1, (y1 + y2)/2.0, (z1 + z2)/2.0, z2));
	bfsq.push(node(x1, (x1 + x2)/2.0, (y1 + y2)/2.0, y2, (z1 + z2)/2.0, z2));
	bfsq.push(node((x1 + x2)/2.0, x2, (y1 + y2)/2.0, y2, (z1 + z2)/2.0, z2));
	return;
}

bool inter(int i, int j, std::vector < torus >& tori){
	if(i != j){
		if((tori[i].r + tori[j].r)*(tori[i].r + tori[j].r) + (tori[i].R + tori[j].R)*(tori[i].R + tori[j].R) 
			> (tori[i].x - tori[j].x)*(tori[i].x - tori[j].x) + (tori[i].y - tori[j].y)*(tori[i].y - tori[j].y) + (tori[i].z - tori[j].z)*(tori[i].z - tori[j].z)){
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
	std::vector < torus > inptori(n), tori{};
	for(int i = 0; i < n; i++){
		std::cin >> inptori[i].x >> inptori[i].y >> inptori[i].z >> inptori[i].R >> inptori[i].r;
	}

	for(int i = 0; i < n; i++){
		bool f = true;
		for(int j = 0; j < n; j++){
			if(inter(i, j, inptori)){
				tori.push_back(inptori[i]);
				j = n;
				f = false;
			}
		}
		if(f){
			vol += 2.0*pi*pi*inptori[i].r*inptori[i].r*inptori[i].R;
		}
	}

	getInitialQ(inptori);
	while(!bfsq.empty()){
		rec(bfsq.front().x1, bfsq.front().x2, bfsq.front().y1, bfsq.front().y2, bfsq.front().z1, bfsq.front().z2, inptori);
		bfsq.pop();
	}
	std::cout << std::fixed << std::setprecision(5) << vol + dv1 + dv2 - dv3 + dv4 << std::endl;
	return 0;
}