#include <bits/stdc++.h>

using namespace std;

void solveFunction(){
  int n = 0;
  std::cin >> n;
  // std::vector < int > evencheckArray( 24, 1), oddCheckArray( 24, 1);

  std::vector < int > inputArray( n, 0);
  long long oddTotal = 0, evenTotal = 0;
  for(int index = 0; index < n; index++){
    std::cin >> inputArray[index];
    if(inputArray[index]%2){
      oddTotal++;
    }
    else{
      evenTotal++;
    }
  }
  std::sort( inputArray.begin(), inputArray.end());

  std::vector < long long > oddNumbers{}, oddCounter{}, evenNumbers{}, evenCounter{};
  int count = 0, curr = inputArray[0];
  for(int index = 0; index < n; index++){
    if(inputArray[index] == curr){
      count++;
    }
    else{
      if(curr%2){
        oddNumbers.push_back( curr);
        oddCounter.push_back( count);
      }
      else{
        evenNumbers.push_back( curr);
        evenCounter.push_back( count);
      }

      curr = inputArray[index];
      count = 1;
    }
    if(index + 1 == n){
      if(curr%2){
        oddNumbers.push_back( curr);
        oddCounter.push_back( count);
      }
      else{
        evenNumbers.push_back( curr);
        evenCounter.push_back( count);
      }

      curr = 0;
      count = 0;
    }
  }

  long long xorTemp = 0;
  bool flag = false;
  long long xorZeroEven = 0, xorZeroOdd = 0, xorTwoOdd = 0, xorTwoEven = 0, inter = 0;
  for(int index = 0; index < evenNumbers.size(); index++){
    xorZeroEven += (evenCounter[index]*(evenCounter[index] - (long long)1))/(long long)2;
    if(index + 1 < evenNumbers.size()){
      if(evenNumbers[index] + 2 == evenNumbers[index + 1]){
        xorTemp = evenNumbers[index]^evenNumbers[index + 1];
        if(xorTemp%2 == 0 && xorTemp > 2){
          flag = true;
        }
        if(!flag){
          xorTwoEven += evenCounter[index]*evenCounter[index + 1];
        }
        flag = false;
      } 
    }
  }

  for(int index = 0; index < oddNumbers.size(); index++){
    xorZeroOdd += (oddCounter[index]*(oddCounter[index] - (long long)1))/(long long)2;
    if(index + 1 < oddNumbers.size()){
      if(oddNumbers[index] + 2 == oddNumbers[index + 1]){
        xorTemp = oddNumbers[index]^oddNumbers[index + 1];
        if(xorTemp%2 == 0 && xorTemp > 2){
          flag = true;
        }
        if(!flag){
          xorTwoOdd += oddCounter[index]*oddCounter[index + 1];
        }
        flag = false;
      }
    }
  }

  inter += oddTotal*evenTotal;
  long long ans = n - 1;
  ans *= (long long)n;
  ans /= (long long)2;
  ans -= ( xorZeroEven + xorZeroOdd + xorTwoEven + xorTwoOdd + inter);

  // if(evenNumbers.size() > 1 &&  evenNumbers[0] == 2 && evenNumbers[1] == 4){
  //   long long temp = evenCounter[0]*evenCounter[1];
  //   ans += temp;
  // }

  std::cout << ans << "\n";
}

int main(){
  int testCases = 0;
  std::cin >> testCases;
  while(testCases--){
    solveFunction();
  }
  return 0;
}