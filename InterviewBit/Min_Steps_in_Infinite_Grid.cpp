vector<int> Solution::repeatedNumber(const vector<int> &A){
	int n_int = A.size();
	long long a1, a2, n = A.size();
	a1 = (n*(n+1))/2;
	a2 = (n*(n+1)*(2*n+1))/6;
	for(int i =0; i < n_int; i++){
		long long tmp = A[i];
		a1 -= tmp;
		a2 -= tmp*tmp;
	}

	a2 /= a1;
	std::vector<int> ans(2,0);
	if(a1 >= 0){
		ans[1] = (a1 + a2)/2;
		ans[0] = a2 - ans[1];
	}
	else{
		ans[0] = (a1 + a2)/2;
		ans[1] = a2 - ans[0];
	}
	return ans;
}