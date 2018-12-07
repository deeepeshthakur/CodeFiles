#include <bits/stdc++.h>

using namespace std;

int partition( std::vector < int > & arr, int first, int last, int n)
{
    //std::cout << first << " " << last << "\n";
    
    if(last > first)
        {   
            bool flag = true;
            int pivot = (first + last)/2;
            int val = arr[pivot];
            int small = first, large = last;
            if(small >  large)
                flag = false;
            while(flag)
            {
                while(arr[small] <= val && small < large)
                    small++;
                while(arr[large] > val && small < large)
                    large--;
                if(small < large)
                {
                    if(large == pivot)
                        pivot = small;

                    int temp = arr[small];
                    arr[small] = arr[large];
                    arr[large] = temp;
                }

                if(small == large)
                {
                    flag = false;
                    if(arr[small] <= val)
                    {
                        int temp = arr[small];
                        arr[small] = arr[pivot];
                        arr[pivot] = temp;
                    }
                    else
                    {
                        small--;
                        int temp = arr[small];
                        arr[small] = arr[pivot];
                        arr[pivot] = temp;
                    }
                }
            }
            if(small == n)
                return arr[small];
            else
                if(small > n)
                {
                    return partition( arr, first, small - 1, n);
                }
                else
                    if(small < n)
                        return partition( arr, small + 1, last, n);
        }
        
}

int findMedian(vector <int> &arr, int n) {
    // Complete this function
    int med = n/2;
    return partition( arr, 0, n - 1, med);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = findMedian( arr, n);
    cout << result << endl;
    return 0;
}
