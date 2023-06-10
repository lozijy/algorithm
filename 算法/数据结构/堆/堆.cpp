#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int heap[N],sz=0;
void down(int k){
    int t=k;
    if(2*k<=sz&&heap[k]>heap[2*k])t=2*k;
    if(2*k+1<=sz&&heap[t]>heap[2*k+1])t=2*k+1;
    if(t!=k){
        swap(heap[t],heap[k]);
        down(t);
    }
}
void up(int k){
    int t=k;
    while(t/2&&heap[t/2]>heap[t]){
        swap(heap[t/2],heap[t]);
        t/=2;
    }
}
void del(){
    heap[1]=heap[sz];
    sz--;
    down(1);
}
void del2(int k){
    heap[k]=heap[sz];
    sz--;
    up(k);
    down(k);
}
void insert(int x){
    heap[++sz]=x;
    up(sz);
}
void modify(int k,int x){
    heap[k]=x;
    up(k);
    down(k);
}

int head(){
    return heap[1];
}
int main(){
    int n,m;
    cin>>n>>m;
    while(n--){
        int x;
        cin>>x;
        insert(x);
    }
    while(m--){
        cout<<head()<<" ";
        del();
    }

}