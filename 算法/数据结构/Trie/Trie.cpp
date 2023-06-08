#include<iostream>
using namespace std;
int n;
const int N=1e5+10;
char str[N];
int son[N][26],cnt[N],idx=0;
void insert(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
int query(char str[]){
    int p=0;
    for(int i=0;str[i];i++){
        int u=str[i]-'a';
        if(!son[p][u])return 0;
        p=son[p][u];
    }
    return cnt[p];
}
int main(){
    cin>>n;
    char chr;
    while(n--){
        cin>>chr>>str;
        if(chr=='I')insert(str);
        else cout<<query(str)<<endl;
    }
}