#include <bits/stdc++.h>

using namespace std;

string checkAll(int n, vector <int> height, vector <int> position) {
    // Complete this function
    //std::cout << "called\n";
    bool safety_left = false, safety_right = false;
    bool effect_left[1001], effect_right[1001];
    std::memset( effect_right, true, sizeof(effect_right));
    std::memset( effect_left, true, sizeof(effect_left));

    bool flag = true;
    effect_left[position[0]] = false;
    int curr_unsafe_pos = position[0];
    for(int index = 0; index < n && flag; index++)
    {
        if(effect_left[position[index]])
            {
                safety_left = true;
                flag = false;
            }
            else
            {
                int danger_limit = position[index] + height[index];
                if(danger_limit > curr_unsafe_pos)
                {
                    for(int x = curr_unsafe_pos + 1; x <= danger_limit; x++)
                    {
                        effect_left[x] = false;                        
                    }
                    curr_unsafe_pos = danger_limit;
                }
            }
    }
    flag = true;
    effect_right[position[n-1]] = false;
    curr_unsafe_pos = position[n-1];
    for(int index = n - 1; index >= 0 && flag; index--)
    {
        if(effect_right[position[index]])
        {
            safety_right = true;
            flag = false;
        }
        else
        {
            int danger_limit = position[index] - height[index];
            if(danger_limit < curr_unsafe_pos)
            {
                for(int x = curr_unsafe_pos - 1; x >= danger_limit; x--)
                {
                    effect_right[x] = false;
                }
                curr_unsafe_pos = danger_limit;
            }
        }
    }

    std::string ans{};
    if(safety_left || safety_right)
    {
        if(safety_left)
        {
            if(safety_right)
                ans = "NONE";
            else
                ans = "RIGHT";
        }
        else
        {
            ans = "LEFT";
        }
    }
    else
        ans = "BOTH";

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> position(n);
    for(int position_i = 0; position_i < n; position_i++){
       cin >> position[position_i];
    }
    vector<int> height(n);
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
    }
    string ret = checkAll(n, height, position);
    cout << ret << endl;
    return 0;
}
