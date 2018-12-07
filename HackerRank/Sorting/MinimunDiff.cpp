#include <bits/stdc++.h>

using namespace std;

void partition( std::vector < int > & arr, int first, int last)
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
            partition( arr, first, small - 1);
            partition( arr, small + 1, last);
        }
        
}

vector <int> quickSort(vector <int> arr) {
    // Complete this function
    partition( arr, 0, arr.size() - 1);
    return arr;
}



vector <int> closestNumbers(vector <int> arr) {
    // Complete this functiont

    int mini = 100000000;
    arr = quickSort( arr);
        std::vector < int > diff(arr.size() - 1);
        for( int index = 0; index < arr.size() - 1; index++)
            {
                diff[index] = arr[index + 1] - arr[index];
                if( mini > diff[index])
                    mini = diff[index];
            }
        std::vector < int > ans{};
        for( int index = 0; index < diff.size(); index++)
        {
            if(diff[index] == mini)
            {
                ans.push_back(arr[index]);
                ans.push_back(arr[index+1]);
            }
        }

    return ans;

}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       std::cin >> arr[arr_i];
    }
    std::vector <int> result = closestNumbers(arr);
    for (ssize_t i = 0; i < result.size(); i++) {
        std::cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    std::cout << std::endl;


    return 0;
}
