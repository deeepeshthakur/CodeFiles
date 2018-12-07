#include <bits/stdc++.h>

using namespace std;

int introTutorial(int V, vector <int> arr) {
    // Complete this function
    bool flag = true;
    if( V < arr[0] || V == arr[0])
        return 0;
    else
        if( V > arr[arr.size() - 1])
            return arr.size();
        else
            {
                for(int index = 0; index < arr.size() && flag; index++)
                    {
                        if(V == arr[index])
                        {
                            flag = false;
                            V = index + 1;
                        }
                        else
                        if(V < arr[index])
                        {
                            flag = false;
                            V = index;
                        }
                    }
            }
    return V - 1;
    }

int main() {
    int V;
    cin >> V;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = introTutorial(V, arr);
    cout << result << endl;
    return 0;
}
