#include<bits/stdc++.h>
#define ll int
#define lll long long
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
using namespace std;

lll powf(lll a,lll b,lll mod){
	if(b==0){
		return 1;
	}
	if(b==1){
		return a%mod;
	}

	lll x=powf(a,b/2,mod);
	x=(x*x)%mod;
	if(b%2){
		x=(x*a)%mod;
	}
	return x%mod;
}

int main(){
	lll n=1,b=1234567890,c=2147483648,a,d,r,s;
	lll x[]={2,3,5,7,61},p2[40];
	p2[0]=1;
	rep(i,1,40){
		p2[i]=p2[i-1]*2;
	}

	auto t1 = std::chrono::high_resolution_clock::now();

	bool f;
	int cnt=0;
	while(cnt<849000){
		cnt++;
		f=false;
		if(n<8){
			if(n==2||n==3||n==5||n==7)
				f=true;
		}
		else{
			if(n%2){
				f=true;
				bool f2,f3;
				s=0;
				while((n-1)%p2[s+1]==0)
					s++;
				d=(n-1)/p2[s];
				for(int i=0;i<4;i++){
					f3=true;
					f2=false;
					a=x[i];
					if(powf(a,d,n)!=1)
						f2=true;
					for(int j=0;j<s;j++){
						if(powf(a,p2[j]*d,n)==n-1)
							f3=false;
					}

					if(f2&&f3){
						f=false;
						i=4;
					}
				}
			}
		}

		if(f)
			printf("1");
		else
			printf("0");
		n=(n+b)%c;
	}
	std::cout<<std::flush<<std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-t1).count()<<std::endl;
	return 0;
}