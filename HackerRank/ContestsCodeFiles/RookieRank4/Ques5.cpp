#include <bits/stdc++.h>

using namespace std;

int longest_palin( std::string &s, int index){
	int ans = 0;
	int k = 1;

	while((s[k-1] == s[index + k -1]) && (s[k-1] == s[index - k +1]) && (index - k + 1 >= 0) && (index + k -1 < s.length()))
	{
		k++;
	}
	return k - 1;
}

vector <int> DNAValue(string s) {
    // Complete this function
    std::vector < int > ans(s.length(), 0);
    for(int index = 0; index < ans.size(); index++)
    {
    	ans[index] = longest_palin( s, index);
    }

    return ans;
}

int main() {
    string s;
    cin >> s;
    vector <int> result = DNAValue(s);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
