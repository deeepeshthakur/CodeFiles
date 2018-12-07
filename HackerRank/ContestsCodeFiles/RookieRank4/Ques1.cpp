#include <bits/stdc++.h>

using namespace std;

int examRush(vector <int> tm, int t) {
    // Complete this function
    std::sort( tm.begin(), tm.end());
    bool flag = true;
    int curr_time_utilised = 0;
    int chapter_count = 0;
    for(int index = 0; index < tm.size() && flag; index++)
    {
        if(curr_time_utilised + tm[index] <= t)
        {
            chapter_count++;
            curr_time_utilised += tm[index];
        }
        else
        {
            flag = false;
        }
    }

    return chapter_count;
}

int main() {
    int n;
    int t;
    cin >> n >> t;
    vector<int> tm(n);
    for(int tm_i = 0; tm_i < n; tm_i++){
       cin >> tm[tm_i];
    }
    int result = examRush(tm, t);
    cout << result << endl;
    return 0;
}
