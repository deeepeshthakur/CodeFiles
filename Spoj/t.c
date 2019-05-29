#include <stdio.h>
#include <stdbool.h>
unsigned long long powf(unsigned long long a,unsigned long long b,unsigned long long mod){
	if(b<2){
		if(b==0)
	    	return 1;
		return a;
	}

	unsigned long long x=powf(a,b/2,mod);
	x*=x;
	x%=mod;
	if(b%2){
		x*=a;
		x%=mod;
	}
	return x;
}

int main(void) {
	unsigned long long n=1,b=1234567890,c=2147483648,a,d,s;
	long long x[]={2,3,61},p2[40];
	p2[0]=1;
	for(int i=1;i<40;i++){
		p2[i]=p2[i-1]*2;
	}

	bool f,f2,f3;
	int cnt=0;
	while(cnt<2100000){
		cnt++;
		f=false;
		if(n<8){
			if(n!=1)
				f=true;
		}
		else{
				f=true;
				s=0;
				while((n-1)%p2[s+1]==0)
					s++;
				d=(n-1)/p2[s];
				for(int i=0;i<3;i++){
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

		if(f)
			printf("1");
		else
			printf("0");
		n=(n+b)%c;
	}
	return 0;
}