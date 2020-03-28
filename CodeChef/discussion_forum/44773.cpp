#include<bits/stdc++.h>
using namespace std;

int gay(int n){
	cout << n << endl;
	int sum=0;
	while(n!=0){
		int a;
		a=n%10;
		sum+=a*a;
		n=n/10;
	}

	if(sum>=9)
		sum = gay(sum);

	return sum;
}

int is_prime(int n){
	if(n==1)
		return 0;
	else{
		int i,c=0;
		for(int i=2;i<=n/2;i++)
			if(n%i==0)
				c++;
		
		if(c==0)
			return 1;
		else
			return 0;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a=0,b=0,c=0;
		a=n;
		b=gay(n);
		c=is_prime(a);
		if(b==1&&c==1)
			cout<< n << " YES"<<endl;
		// else
		// 	cout<<"NO"<<endl;
	}
}