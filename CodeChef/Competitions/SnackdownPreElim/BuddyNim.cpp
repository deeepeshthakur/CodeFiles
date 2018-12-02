#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mp make_pair
#define pb push_back

void f() 
{
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n), b(m);

	for(long long i = 0; i<n; i++)
		cin >> a[i];
	for(long long i = 0; i<m; i++)
		cin >> b[i];


	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());

	// long long suma = 0;
	// long long sumb = 0;

	// for(long long i = 0; i<n; i++)
	// 	suma+=a[i];
	// for(long long i = 0; i<m; i++)
	// 	sumb+=b[i];

	// bool flagEqual = false;


	if(a[0]==0ll && b[0]==0ll)
	{
		cout << "Bob\n";
		return;
	}

	if(n!=m)
	{
		cout << "Alice\n";
		return;
	}

	for(long long i = 0; i<n; i++)
	{
		if(a[i]!=b[i])
		{
			cout << "Alice\n";
			return;
		}
	}
	cout << "Bob\n";	
}

int main()
{
	// std::ios::sync_with_stdio(false);
	// cin.tie(NULL);
    long long t = 1;
    cin>>t;             //comment out if only one test case
    for (long long i = 0; i < t; ++i)
    {
        f();
    }
    return 0;
}
