#include<bits/stdc++.h>
using namespace std;
int x_A[26],x_B[26],f_A[26],f_B[26],str_ctr[26];

inline bool is_cons(char a){
	return !((a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u'));
}

int main(){
	std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);

	int test_cases;
	cin>>test_cases;
	while(test_cases>0){
		int l=0,n=0,m=0;
		cin>>l;
		string s;
		for(int i=0;i<26;i++){
			x_A[i]=0;
			x_B[i]=0;
			f_A[i]=0;
			f_B[i]=0;
		}
		for(int i=0;i<l;i++){
			cin>>s;
			bool is_alice=true;
			for(int j=0;j<s.size()-2;j++){
				if(is_cons(s[j]) && (is_cons(s[j+1]) || is_cons(s[j+2]))){
					is_alice=false;
					break;
				}
			}
			if(is_alice && is_cons(s[s.size()-2]) && is_cons(s[s.size()-1])){
				is_alice=false;
			}

			for(int j=0;j<26;j++)
				str_ctr[j]=0;
			for(int j=0;j<s.size();j++)
				str_ctr[int(s[j]-'a')]++;

			if(is_alice){
				n++;
				for(int j=0;j<26;j++){
					x_A[j] += (str_ctr[j]>0 ? 1:0);
					f_A[j] += str_ctr[j];
				}
			}
			else{
				m++;
				for(int j=0;j<26;j++){
					x_B[j] += (str_ctr[j]>0 ? 1:0);
					f_B[j] += str_ctr[j];
				}
			}
		}
		long double ans0=0,ans1=0,ans2=0;
		for(int i=0;i<26;i++){
			if(x_A[i] != 0)
				ans0 += log10((long double)(x_A[i]));
			if(x_B[i] != 0)
				ans0 -= log10((long double)(x_B[i]));
			if(f_A[i] != 0)
				ans1 += log10((long double)(f_A[i]));
			if(f_B[i] != 0)
				ans2 += log10((long double)(f_B[i]));
		}

		long double ans = ans0 + (min(n,m)*(ans2-ans1) + (m-min(m,n))*ans2 - (n-min(m,n))*ans1);
		if(ans > 7.0)
			cout<<"Infinity\n";
		else
			cout<<fixed<<setprecision(12)<<pow((long double)(10),ans)<<"\n";
		test_cases--;
	}
	return 0;
}