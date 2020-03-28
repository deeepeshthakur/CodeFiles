#include<bits/stdc++.h>
using namespace std;

inline bool palin(pair<int,int>& a){
  int b=a.first,c=a.second;
  return (b/10 == c%10) && (b%10 == c/10) && ((c>9 && b>9) || (c<=9 && b<=9));
}

void next_date(pair<int,int>& a){
  int b=a.first,c=a.second+1;
  if(c>60){
    c=1;
    b++;
  }

  if(b>30){
    b=1;
  }
  a.first=b;
  a.second=c;
}

void findNextPalinDate (string input) {
   // Write your code here
  int a = int(input[0]-'0')*10 + int(input[1]-'0'), b = int(input[3]-'0')*10 + int(input[4]-'0');
  pair<int,int> dt{a,b};
  next_date(dt);
  while(!palin(dt)){
   next_date(dt);
 }
 cout << dt.first << ":" << dt.second << "\n";
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  string input;
  cin >> input;
  findNextPalinDate(input);
  return 0;
}