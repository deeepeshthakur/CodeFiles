#include<bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<"1\n1 1\n";
        }
        else{
            if(n%2==1){
                cout<<n/2<<"\n";
                for(int i=1;i<=n/2;i++){
                    if(i==1){
                        cout<<"3 1 2 "<<n<<"\n";
                    }
                    else{
                        cout<<"2 "<<2*i-1<<" "<<2*i<<"\n";
                    }
                }
            }
            else{
                cout<<n/2<<"\n";
                for(int i=1;i<=n/2;i++){
                    cout<<"2 "<<2*i-1<<" "<<2*i<<"\n";
                }
            }
        }
    }
    return 0;
}