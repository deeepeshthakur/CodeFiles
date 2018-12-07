#include <bits/stdc++.h>

using namespace std;

long count_inter_inversions( std::vector < int > &arr, int start_first, int end_first, int start_second, int end_second)
{
  long ans = 0;
  int first_counter = start_first, second_counter = start_second;
  int curr_length = end_first - start_first + 1 + end_second - start_second + 1;
  std::vector < int > Temp(curr_length);
  for(int index = 0; index < curr_length; index++)
  {
    if(first_counter <= end_first && second_counter <= end_second)
    {
      if(arr[first_counter] <= arr[second_counter])
      {
        Temp[index] = arr[first_counter];
        first_counter++;
      }
      else
      {
        ans += (long)(end_first - first_counter + 1);
        Temp[index] = arr[second_counter];
        second_counter++;
      }
    }
    else
    {
      if(first_counter > end_first)
      {
        while(second_counter <= end_second && index <= end_second)
        {
          Temp[index] = arr[second_counter];
          index++;
          second_counter++;
        }
      }
      else
      {
        while(first_counter <= end_first && index <= end_second)
        {
          Temp[index] = arr[first_counter];
          first_counter++;
          index++;
        }
      }
    }
  }
  for(int index = start_first; index <= end_second; index++)
  {
    arr[index] = Temp[index - start_first];
  }
  return ans;
}

long count_intra_inversions( std::vector < int > &arr, int start_index, int end_index)
{
  long ans = 0;
  if(start_index < end_index)
  {
    int mid_index = (start_index + end_index)/2;
    ans += count_intra_inversions( arr, start_index, mid_index);
    ans += count_intra_inversions( arr, mid_index + 1, end_index);
    ans += count_inter_inversions( arr, start_index, mid_index, mid_index + 1, end_index);
  }
  return ans;
}

long count_inversions( std::vector < int > &arr, int start_index, int end_index)
{
  long ans = 0;
  ans = count_intra_inversions( arr, start_index, end_index);
  long max_inversions = (((long)arr.size())*((long)(arr.size() - 1)))/2;
  std::cout << ans << " " << max_inversions - ans << "\n";
  if(max_inversions - ans < ans)
    ans = max_inversions - ans;
  return ans;
}

long lilysHomework(vector < int > arr) {
    // Complete this function
    long ans = count_inversions( arr, 0, arr.size() - 1);
    //std::cout << ans << " " ;
    long n = arr.size();
    long max_inver = ((n)*(n - 1))/2;
    if(max_inver - ans < ans)
        ans = max_inver - ans;
    return ans;

}

int main() {
    int n;
    cin >> n;
    vector< int > arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long result = lilysHomework(arr);
    cout << result << endl;
    return 0;
}
