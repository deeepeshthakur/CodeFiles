#include<bits/stdc++.h>
#define iint int
#define pll std::pair<iint,iint>
#define rep(i,a,b) for(iint i=(iint)a;i<(iint)b;i++)
#define per(i,a,b) for(iint i=(iint)a;i>(iint)b;i--)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const double MOD=1e9+7;

bool f2(int a, std::vector<int>& code, int ind){
	return code[ind] >= a;
}

bool f1(int a, int b, std::vector<std::vector<int>>& sVec, std::vector<int>& code, std::vector<int>& eat){
	int n = code.size();
	int l = 0, mid, r = code.size()-1;
	while(r - l > 1){
		mid = (l+r)/2;
		if(f2(a,code,mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}

	int ind = f2(a,code,l) ? l : r;
	double a_curr = 0.0, b_curr = 0.0;

	if(code[ind] == a && ind == n - 1)
		return false;

	if(code[ind] == a && ind < n - 1)
		return (code[ind] >= a) && (eat[ind + 1] >= b);


	if(ind == 0){
		a_curr = a;
		b_curr = (1.0 - a_curr/(1.0*sVec[0][1]))*sVec[0][0];
		if(code.size() > 1){
			b_curr += eat[1];
		}
	}

	if(ind > 0 && ind < n - 1){
		a_curr = std::max(0,code[ind] - a);
		b_curr = (1.0 - (a_curr/(1.0*sVec[ind][1])))*sVec[ind][0];
		a_curr += code[ind - 1];
		b_curr += eat[ind + 1];
	}

	if(ind != 0 && ind == n - 1){
		a_curr = std::max(0,code[ind] - a);
		b_curr = (1.0 - (a_curr/(1.0*sVec[ind][1])))*sVec[ind][0];
		a_curr += code[ind - 1];
	}

	return (a_curr >= 1.0*a) && (b_curr >= 1.0*b);
}

bool f3(std::vector<int>& a, std::vector<int>& b){
	return (1.0*a[0]/a[1]) < (1.0*b[0]/b[1]) || ((1.0*a[0]/a[1]) == (1.0*b[0]/b[1]) && (a[0] < b[0])); 
}

void solve(int tc){
	int d,s;
	std::cin >> d >> s;
	std::vector<std::vector<int>> sVec(s,std::vector<int>(2,0)), dVec(d,std::vector<int>(2,0));
	for(int i = 0; i < s; i++){
		std::cin >> sVec[i][1] >> sVec[i][0];
	}

	for(int i = 0; i < d; i++){
		std::cin >> dVec[i][0] >> dVec[i][1];
	}

	std::sort(sVec.begin(),sVec.end(),f3);
	std::vector<int> countingArray0(s,0), countingArray1(s,0);

	for(int i = 0; i < s; i++){
		if(i == 0){
			countingArray0[i] = sVec[i][1];
			countingArray1[s - 1 - i] = sVec[s - 1 - i][0];
		}
		else{
			countingArray0[i] = countingArray0[i] + sVec[i][1];
			countingArray1[s - 1 - i] = countingArray1[s - i] + sVec[s - 1 - i][0];
		}
	}
	
	std::vector<bool> ans(d,false);
	std::cout << "Case #" << tc << ": ";
	for(int i = 0; i < d; i++){
		if(f1(dVec[i][0],dVec[i][1],sVec,countingArray0,countingArray1))
			std::cout << "Y";
		else
			std::cout << "N";
	}
	std::cout << std::endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int i = 1,t;
	std::cin >> t;
	while(i <= t){
		solve(i);
		i++;
	}
	return 0;
}