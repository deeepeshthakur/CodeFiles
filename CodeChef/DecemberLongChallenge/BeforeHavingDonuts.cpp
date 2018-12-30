#include<bits/stdc++.h>
#define ll int
#define pll std::pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define per(i,a,b) for(ll i=(ll)a;i>(ll)b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-5;

std::vector<double> xCoor,yCoor,zCoor,R1,R2;

inline double sq(double a){
	return a*a;
}

inline void f307(std::vector<std::vector<double>>& t,double a,double b){
	a=((a>pii)?a-pii:a);
	b=((b>pii)?b-pii:b);
	if(a<b){
		t.pb({a,b});
	}
	if(a>b){
		t.pb({a,pii});
		t.pb({0.0,b});
	}
}

inline double f306(double x,double y){
	if(x>0.0&&y==0.0){ return 0.0;}
	if(x>0.0&&y>0.0){ return std::atan(y/x);}
	if(x==0.0&&y>0){ return pi/2.0;}
	if(x<0.0&&y>0.0){ return pi-std::atan(std::abs(y/x));}
	if(x<0.0&&y==0.0){ return pi;}
	if(x<0.0&&y<0.0){ return pi+std::atan(std::abs(y/x));}
	if(x==0.0&&y<0.0){ return 1.5*pi;}
	if(x>0.0&&y<0.0){ return pii-std::atan(std::abs(y/x));}
	return 0.0;
}

inline bool f305(double x1,double y1,double x2,double y2,double r1,double r2){
	double d=std::sqrt(sq(x1-x2)+sq(y1-y2));
	return (d>=r1+r2 || std::abs(r1-r2)>=d) ? false:true;
}

inline bool f304(double x1,double y1,double x,double y,double r){
	return (std::sqrt(sq(x1-x)+sq(y1-y))<r) ? true:false;
}

inline bool f303(double x1,double y1,double x2,double y2,double r1,double r2){
	return (r1-r2>=std::sqrt(sq(x1-x2)+sq(y1-y2))) ? true:false;
}

inline double f302(double th1,double th2,double x,double y,double r){
	return x*r*(std::sin(th2)-std::sin(th1))+sq(r)*((th2+std::sin(th2)*std::cos(th2))-(th1+std::sin(th1)*std::cos(th1)))*0.5;
}

void quadratic(double a,double b,double c,double& x1,double& x2){
	x1 = (-b-std::sqrt(sq(b)-4*a*c))/(2*a);
	x2 = (-b+std::sqrt(sq(b)-4*a*c))/(2*a);
}

void lyx(double a,double b,double c,double& x, double& y){
	if(b){
		y=(c-a*x)/b;
	}
}

void lcf(double x,double y,double r,double a,double b, double c,std::vector<double>& ans){
	double x1,x2,y1,y2;
	if(b)
	{
		quadratic(1+sq(a/b),-2*x-2*(a/b)*(c/b-y),sq(x)+sq(c/b-y)-sq(r),x1,x2);
		lyx(a,b,c,x1,y1);
		lyx(a,b,c,x2,y2);
		ans={f306(x1-x,y1-y),f306(x2-x,y2-y)};
		if(ans[0]>ans[1]){
			std::swap(ans[0],ans[1]);
		}
	}
	else{
		quadratic(1,-2*y,sq(y)+sq(c/a-x)-sq(r),y1,y2);
		x1=c/a;
		ans={f306(x1-x,y1-y),f306(x1-x,y2-y)};
		if(ans[0]>ans[1]){
			std::swap(ans[0],ans[1]);
		}
	}
}

double f301(int n,std::vector<double>& x,std::vector<double>& y,std::vector<double>& r1,std::vector<double>& r2){
	double ans=0.0;
	rep(i,0,n){
		//outer circle
		{
			std::vector<std::vector<double>> m{},z{},p{};
			rep(j,0,n){
				if(i!=j){
					if(f305(x[i],y[i],x[j],y[j],r1[i],r1[j])){
						if(f305(x[i],y[i],x[j],y[j],r1[i],r2[j])){
							std::vector<double> ans1{},ans2{};
							lcf(x[i],y[i],r1[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r1[i])-sq(r1[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans1);
							lcf(x[i],y[i],r1[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r1[i])-sq(r2[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans2);
							if(!f304(x[i]+r1[i]*std::cos((ans1[0]+ans1[1])*0.5),y[i]+r1[i]*std::sin((ans1[0]+ans1[1])*0.5),x[j],y[j],r1[j])){
								std::swap(ans1[0],ans1[1]);
							}

							if(!f304(x[i]+r1[i]*std::cos((ans2[0]+ans2[1])*0.5),y[i]+r1[i]*std::sin((ans2[0]+ans2[1])*0.5),x[j],y[j],r2[j])){
								std::swap(ans2[0],ans2[1]);
							}

							if(ans1[0]>ans1[1]){
								ans1[1]+=pii;
							}

							if(ans2[0]>ans2[1]){
								ans2[1]+=pii;
							}
							f307(z,ans1[0],ans2[0]);
							f307(z,ans2[1],ans1[1]);
							f307(m,ans2[0],ans2[1]);						
						}
						else{
							std::vector<double> ans1{};
							lcf(x[i],y[i],r1[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r1[i])-sq(r1[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans1);
							if(!f304(x[i]+r1[i]*std::cos((ans1[0]+ans1[1])*0.5),y[i]+r1[i]*std::sin((ans1[0]+ans1[1])*0.5),x[j],y[j],r1[j])){
								std::swap(ans1[0],ans1[1]);
							}

							if(ans1[0]>ans1[1]){
								ans1[1]+=pii;
							}

							f307(z,ans1[0],ans1[1]);
						}
					}
					else{
						if(f303(x[i],y[i],x[j],y[j],r1[i],r1[j])){
							if(f303(x[i],y[i],x[j],y[j],r1[i],r2[j])){
								m.pb({0.0,pii});
							}
							else{
								if(f305(x[i],y[i],x[j],y[j],r1[i],r2[j])){
									std::vector<double> ans1{0.0,pii},ans2{};
									lcf(x[i],y[i],r1[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r1[i])-sq(r2[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans2);

									if(!f304(x[i]+r1[i]*std::cos((ans2[0]+ans2[1])*0.5),y[i]+r1[i]*std::sin((ans2[0]+ans2[1])*0.5),x[j],y[j],r2[j])){
										std::swap(ans2[0],ans2[1]);
									}

									if(ans2[0]>ans2[1]){
										ans2[1]+=pii;
									}

									if(ans2[1]>pii){
										m.pb({ans2[1]-pii,ans2[0]});
										z.pb({0.0,ans2[1]-pii});
										z.pb({ans2[0],pii});
									}
									else{
										m.pb({0.0,ans2[0]});
										z.pb({ans2[0],ans2[1]});
										m.pb({ans2[1],pii});
									}
								}
								else{
									m.resize(0);
									z.resize(0);
									z.pb({0.0,pii});
									j=n+1;
								}
							}
						}
					}
				}
			}

			{
				p.resize(z.size()+m.size());
				rep(i,0,z.size()){
					p[i]=z[i];
				}
				rep(i,z.size(),z.size()+m.size()){
					p[i]=m[i-z.size()];
				}
			}

			std::sort(full(z));
			std::sort(full(m));
			std::sort(full(p));

			std::queue<std::pair<double,double>> qm{},qz{},qp{};
			{
				for(int i=0;i<z.size();i++){
					double s=z[i][0],e=z[i][1];
					while(i+1<z.size()&&e>=z[i+1][0]){
						e=std::max(e,z[i+1][1]);
						i++;
					}
					qz.push({s,e});
				}

				for(int i=0;i<m.size();i++){
					double s=m[i][0],e=m[i][1];
					while(i+1<m.size()&&e>=m[i+1][0]){
						e=std::max(e,m[i+1][1]);
						i++;
					}
					qm.push({s,e});
				}

				for(int i=0;i<p.size();i++){
					double s=p[i][0],e=p[i][1];
					while(i+1<p.size()&&e>=p[i+1][0]){
						e=std::max(e,p[i+1][1]);
						i++;
					}
					qp.push({s,e});
				}
			}

			{
				double s=0.0,e;
				while(!qp.empty()){
					e=qp.front().F;
					ans+=f302(s,e,x[i],y[i],r1[i]);
					s=qp.front().S;
					qp.pop();
				}
				e=pii;
				ans+=f302(s,e,x[i],y[i],r1[i]);

				while(!qm.empty()||!qz.empty()){
					if(qm.empty()||qz.empty()){
						if(qm.empty()){
							while(!qz.empty()){
								qz.pop();
							}
						}
						else{
							while(!qm.empty()){
								ans-=f302(qm.front().S,qm.front().F,x[i],y[i],r1[i]);
								qm.pop();
							}
						}
					}
					else{
						if(qz.front().F<=qm.front().F){
							if(qz.front().S<=qm.front().F){
								qz.pop();
							}
							else{
								if(qz.front().S<=qm.front().S){
									qm.front().F=qz.front().S;
									qz.pop();
								}
								else{
									qz.front().F=qm.front().S;
									qm.pop();
								}
							}
						}
						else{
							if(qz.front().F<=qm.front().S){
								ans-=f302(qz.front().F,qm.front().F,x[i],y[i],r1[i]);
								qm.front().F=qz.front().F;
							}
							else{
								ans-=f302(qm.front().S,qm.front().F,x[i],y[i],r1[i]);
								qm.pop();
							}
						}
					}
				}
			}
		}
		//inner circle
		{
			std::vector<std::vector<double>> z{};
			rep(j,0,n){
				if(i!=j){
					if(f305(x[i],y[i],x[j],y[j],r2[i],r1[j])){
						if(f305(x[i],y[i],x[j],y[j],r2[i],r2[j])){
							std::vector<double> ans1{},ans2{};
							lcf(x[i],y[i],r2[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r2[i])-sq(r1[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans1);
							lcf(x[i],y[i],r2[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r2[i])-sq(r2[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans2);

							if(!f304(x[i]+r2[i]*std::cos((ans1[0]+ans1[1])*0.5),y[i]+r2[i]*std::sin((ans1[0]+ans1[1])*0.5),x[j],y[j],r1[j])){
								std::swap(ans1[0],ans1[1]);
							}

							if(!f304(x[i]+r2[i]*std::cos((ans2[0]+ans2[1])*0.5),y[i]+r2[i]*std::sin((ans2[0]+ans2[1])*0.5),x[j],y[j],r2[j])){
								std::swap(ans2[0],ans2[1]);
							}

							if(ans1[0]>ans1[1]){
								ans1[1]+=pii;
							}

							if(ans2[0]>ans2[1]){
								ans2[1]+=pii;
							}

							f307(z,ans1[0],ans2[0]);
							f307(z,ans2[1],ans1[1]);							
						}
						else{
							std::vector<double> ans1{};
							lcf(x[i],y[i],r2[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r2[i])-sq(r1[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans1);
							if(!f304(x[i]+r2[i]*std::cos((ans1[0]+ans1[1])*0.5),y[i]+r2[i]*std::sin((ans1[0]+ans1[1])*0.5),x[j],y[j],r1[j])){
								std::swap(ans1[0],ans1[1]);
							}

							if(ans1[0]>ans1[1]){
								ans1[1]+=pii;
							}

							f307(z,ans1[0],ans1[1]);
						}
					}
					else{
						if(f303(x[i],y[i],x[j],y[j],r2[i],r1[j])){
							if(!f303(x[i],y[i],x[j],y[j],r2[i],r2[j])){
								if(f305(x[i],y[i],x[j],y[j],r1[i],r2[j])){
									std::vector<double> ans2{};
									lcf(x[i],y[i],r2[i],2*(x[j]-x[i]),2*(y[j]-y[i]),sq(r2[i])-sq(r2[j])+sq(x[j])-sq(x[i])+sq(y[j])-sq(y[i]),ans2);

									if(!f304(x[i]+r2[i]*std::cos((ans2[0]+ans2[1])*0.5),y[i]+r2[i]*std::sin((ans2[0]+ans2[1])*0.5),x[j],y[j],r2[j])){
										std::swap(ans2[0],ans2[1]);
									}

									if(ans2[0]>ans2[1]){
										ans2[1]+=pii;
									}

									if(ans2[1]>pii){
										z.pb({0.0,ans2[1]-pii});
										z.pb({ans2[0],pii});
									}
									else{
										z.pb({ans2[0],ans2[1]});
									}
								}
								else{
									z.resize(0);
									z.pb({0.0,pii});
									j=n+1;
								}
							}
						}
					}
				}
			}

			std::sort(full(z));
			std::queue<std::pair<double,double>> qz{};
			for(int i=0;i<z.size();i++){
				double s=z[i][0],e=z[i][1];
				while(i+1<z.size()&&e>=z[i+1][0]){
					e=std::max(e,z[i+1][1]);
					i++;
				}
				qz.push({s,e});
			}

			{
				double s=0.0,e;
				while(!qz.empty()){
					e=qz.front().F;
					ans-=f302(s,e,x[i],y[i],r2[i]);
					s=qz.front().S;
					qz.pop();
				}
				e=pii;
				ans-=f302(s,e,x[i],y[i],r2[i]);
			}
		}
	}
}

bool truef(int i,int j,std::vector<double>& x,std::vector<double>& y,std::vector<double>& r1,std::vector<double>& r2){
	if(
		(x[i]<x[j]) || 
		(x[i]==x[j] && y[i]<y[j]) ||
		(x[i]==x[j] && y[i]==y[j] && r2[i]<r2[j]) ||
		(x[i]==x[j] && y[i]==y[j] && r2[i]==r2[j] && r1[i]>=r1[j])
		){ return true;}
		return false;
}

void swapf(int i,int j,std::vector<double>& x,std::vector<double>& y,std::vector<double>& r1,std::vector<double>& r2){
	std::swap(x[i],x[j]);
	std::swap(y[i],y[j]);
	std::swap(r1[i],r1[j]);
	std::swap(r2[i],r2[j]);
}

double f300(int n,std::vector<double>& xp,std::vector<double>& yp,std::vector<double>& r1p,std::vector<double>& r2p){
	if(n==0){
		return 0.0;
	}
	if(n==1){
		return pi*(sq(r1p[0])-sq(r2p[0]));
	}

	std::vector<bool> flag(n,true);
	std::vector<double> x,y,r1,r2;
	
	{
		//n^2 sorting on basis of centre and then radius
		for(int i=0;i<n;i++){
			int cm=i;
			for(int j=i+1;j<n;j++){
				if(truef(j,cm,xp,yp,r1p,r2p)){
					cm=j;
				}
			}
			swapf(i,cm,xp,yp,r1p,r2p);
		}
	}

	rep(i,0,n){
		if(i+1<n){
			if(xp[i]==xp[i+1] && yp[i]==yp[i+1]){
				if(r2p[i+1]<=r1p[i] && r2p[i]<=r1p[i+1]){
					r1p[i+1]=std::max(r1p[i],r1p[i+1]);
					r2p[i+1]=std::min(r2p[i],r2p[i+1]);
					flag[i]=false;
				}
			}
		}
		if(flag[i]&&r2p[i]!=r1p[i]){
			x.pb(xp[i]);
			y.pb(yp[i]);
			r1.pb(r1p[i]);
			r2.pb(r2p[i]);
		}
	}
	return f301(x.size(),x,y,r1,r2);
}

double f101(int n,double zh){
	std::vector<double> x,y,r1,r2;
	rep(i,0,n){
		if(zCoor[i]-R2[i]<zh&&zh<zCoor[i]+R2[i]){
			double h=std::abs(zh-zCoor[i]);
			x.pb(xCoor[i]);
			y.pb(yCoor[i]);
			r1.pb(R1[i]+std::sqrt(sq(R2[i])-sq(h)));
			r2.pb(R1[i]-std::sqrt(sq(R2[i])-sq(h)));
		}
	}
	return f300(x.size(),x,y,r1,r2);
}

inline double f103(int& n,double& l,double& fl,double& r,double& fr){
	return std::abs((r-l)*(fl+fr+4*(f101(n,(l+r)*0.5)))/6.0);
}

double f102(int n,double l,double fl,double r,double fr,double simpf){
	double mid=(l+r)*0.5,fmid=f101(n,mid),simpfl=f103(n,l,fl,mid,fmid),simpfr=f103(n,mid,fmid,r,fr);
	if(std::abs(simpf-simpfl-simpfr)<=eps*std::abs(simpf)){
		return simpf;
	}
	return f102(n,l,fl,mid,fmid,simpfl)+f102(n,mid,fmid,r,fr,simpfr);
}

double f100(int n){
	std::vector<std::pair<double,double>> iLims{};
	{

		std::vector<double> zh{};
		rep(i,0,n){
			zh.pb(zCoor[i]);
			zh.pb(zCoor[i]-R2[i]);
			zh.pb(zCoor[i]+R2[i]);
		}
		std::sort(full(zh));
		// {
		// 	std::vector<double> zhh{};
		// 	rep(i,0,zh.size()){
		// 		if(i&&zh[i-1]!=zh[i]){
		// 			double delta=(zh[i]-zh[i-1])/5.0;
		// 			rep(j,1,5){
		// 				zhh.pb(zh[i-1]+j*delta);
		// 			}
		// 		}
		// 	}
		// 	rep(i,0,zhh.size()){
		// 		zh.pb(zhh[i]);
		// 	}
		// 	std::sort(full(zh));
		// }
		rep(i,0,zh.size()){
			if(i){
				iLims.pb({zh[i-1],zh[i]});
			}
		}

	}

	// rep(i,0,iLims.size()){
	// 	std::cout<<iLims[i].F<<" "<<iLims[i].S<<std::endl;
	// }

	double ans=0.0;
	rep(i,0,iLims.size()){
		double fl=f101(n,iLims[i].F),fr=f101(n,iLims[i].S);
		ans+=f102(n,iLims[i].F,fl,iLims[i].S,fr,f103(n,iLims[i].F,fl,iLims[i].S,fr));
		// if(ans>0.0)
		// 	std::cout<<ans<<"                          "<<iLims[i].F<<"  "<<iLims[i].S<<std::endl;
		// ans=0.0;
	}
	return ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n;
	std::cin>>n;
	xCoor.resize(n,0.0);
	yCoor.resize(n,0.0);
	zCoor.resize(n,0.0);
	R1.resize(n,0.0);
	R2.resize(n,0.0);
	rep(i,0,n){
		std::cin>>xCoor[i]>>yCoor[i]>>zCoor[i]>>R1[i]>>R2[i];
	}
	std::cout<<std::fixed<<std::setprecision(5)<<f100(n)<<std::endl;
	return 0;
}