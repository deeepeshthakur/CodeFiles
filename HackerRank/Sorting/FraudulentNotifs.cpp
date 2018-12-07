#include <bits/stdc++.h>

using namespace std;

int binary_search(std::vector < int > &arr, int first, int last, int key)
{
    int ans = 0;
    int mid = (first + last)/2;
    if(key <= arr[first])
    {
        ans = first;
    }
    else
        if(key >= arr[last])
        {
            ans = last;
        }
        else
            if(key == arr[mid] || (key < arr[mid] && key > arr[mid- 1]))
            {
                ans = mid;
            }
            else
                if(key > arr[mid])
                {
                    ans = binary_search( arr, mid + 1, last - 1, key);
                }
                else
                    if(key < arr[mid])
                    {
                        ans = binary_search(arr, first + 1, mid - 1, key);
                    }
    return ans;
}

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

// int partition( std::vector < int > &exp, int first, int last, int n)
// {
//     std::cout << first << " " << last << " " << n << std::endl;
//     int ret_value = 0;
//     int pivot = first;
//     int small = first, large = last;
//     bool flag = true;
//     if(first > last)
//         flag = false;
//     //std::cout << "here" << std::endl;
//     while(flag)
//     {
//         while(exp[small] <= exp[pivot] && small < large)
//             small++;
//         while(exp[large] > exp[pivot] && small < large)
//             large--;

//         if(small < large)
//         {
//             int temp = exp[small];
//             exp[small] = exp[large];
//             exp[large] = temp;
//         }

//         if(small >= large)
//         {
//             flag = false;
//             if(exp[small] <= exp[pivot])
//             {
//                 int temp = exp[small];
//                 exp[small] = exp[pivot];
//                 exp[pivot] = temp;
//                 pivot = small;
//             }
//             else
//             {
//                 int temp = exp[small - 1];
//                 exp[small -1] = exp[pivot];
//                 exp[pivot] = temp;
//                 pivot = small - 1;
//             }

//             if(n == pivot)
//                 return exp[pivot];
//             else
//                 if(n > pivot)
//                     ret_value = partition( exp, pivot + 1, last, n);
//                 else
//                     if(n < pivot)
//                         ret_value = partition( exp, first, pivot - 1, n);

//         }
//     }

//     return ret_value;
// }

int activityNotifications(vector <int> expenditure, int d) {
    // Complete this function
    int ans = 0;

    std::vector < int > exp(d);
    for(int index = 0; index < d; index++)
        exp[index] = expenditure[index];

    partition( exp, 0, d - 1);

    int limit = 0;
    if(d%2)
    {
        limit = exp[d/2] * 2;
    }
    else
    {
        limit = exp[d/2] + exp[d/2 - 1];
    }

    if(expenditure[d] >= limit)
        ans++;

    for( int index = d + 1; index < expenditure.size(); index++)
    {
        std::cout << index << "    ";
        int exit_index = binary_search( exp, 0, d - 1, expenditure[index - d - 1]);
        int entry_index = binary_search( exp, 0, d - 1, expenditure[index - 1]);

        if(entry_index == exit_index)
        {
            exp[entry_index] = expenditure[index - 1];
        }
        else
            if(entry_index > exit_index)
            {
                for(int inner = exit_index + 1; inner <= entry_index; inner++)
                    exp[inner - 1] = exp[inner];
                exp[entry_index] = expenditure[index - 1];
            }
            else
            {
                for(int inner = exit_index - 1; inner >= entry_index; inner--)
                    exp[inner + 1] = exp[inner];
                exp[entry_index] = expenditure[index - 1];
            }

        if(d%2)
        {
            limit = exp[d/2] * 2;
        }
        else
        {
            limit = exp[d/2] + exp[d/2 - 1];
        }

        if(expenditure[index] >= limit)
            ans++;

    }
    return ans;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int expenditure_i = 0; expenditure_i < n; expenditure_i++){
       cin >> expenditure[expenditure_i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}
