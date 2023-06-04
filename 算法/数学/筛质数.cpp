#include<iostream>
using namespace std;
const int N=1e6+10;
bool p[N]={false};
int prime_count=0;
int find_prime(int n){
    int count=0;
    for(int i=2;i<=n;i++){
        if(!p[i]){
            count++;
            for(int x=2*i;x<=n;x+=i){
                p[x]=true;
            }
        }
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<find_prime(n);
}