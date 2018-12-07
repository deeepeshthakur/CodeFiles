#include <bits/stdc++.h>

using namespace std;

long inter_count( std::vector < int > &arr, int first, int mid, int last)
{
    // for(int index = first; index <= last; index++)
    //     std::cout << arr[index] << " ";
    // std::cout << "                ";
    // std::cout << first << " " << mid << " " << mid + 1 << " " << last << " ";
    long inver = 0;
    if(first > mid || mid  + 1 > last)
        return 0;
    else
    {
        int l_count = first, r_count = mid + 1;
        std::vector < int > temp(last - first + 1);
        for(int index = 0; index < temp.size(); index++)
        {
            if(l_count <= mid && r_count <= last)
            {
                if(arr[l_count] <= arr[r_count])
                {
                    temp[index] = arr[l_count];
                    l_count++;
                }
                else
                {
                    temp[index] = arr[r_count];
                    inver += mid - l_count + 1;
                    r_count++;
                }
            }
            else
                if(l_count <= mid && r_count > last)
                {
                    temp[index] = arr[l_count];
                    l_count++;
                }
                else
                    if(l_count > mid && r_count <= last)
                    {
                        temp[index] = arr[r_count];
                        r_count++;
                    }
        }

        for( int index = first; index <= last; index++)
            arr[index] = temp[index - first];
    }

    //std::cout << inver << "\n";
    return inver;
}

long intra_count( std::vector < int > &arr, int first, int last)
{
    long inver = 0;
    if(first >= last)
        inver = 0;
    else
    {
        int mid = (first + last)/2;
        inver += intra_count( arr, first, mid);
        inver += intra_count( arr, mid + 1, last);
        inver += inter_count( arr, first, mid, last);
    }
    return inver;
}

long count_inversions( std::vector < int > &arr, int first, int last)
{
    long inver = 0;
    if(first != last)
    {
        int mid = (first + last)/2;
        inver += intra_count( arr, first, mid);
        inver += intra_count( arr, mid + 1, last);
        inver += inter_count( arr, first, mid, last);
    }

    return inver;
}

long insertionSort(vector <int> arr) {
    // Complete this function
    long inver = 0;
    inver = count_inversions( arr, 0, arr.size() - 1);
    return inver;    
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long result = insertionSort(arr);
        cout << result << endl;
    }
    return 0;
}
