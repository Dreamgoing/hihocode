//
// Created by 王若璇 on 16/3/7.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 100010;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int segTree[max_n*4+10];
int lazy[max_n*4+10];
void pushUp(int rt){
    segTree[rt] = segTree[rt<<1]+segTree[rt<<1|1];
}
void build(int l,int r,int rt){

    if(l==r){
        //cout<<"ok"<<endl;
        cin>>segTree[rt];
      //  cout<<segTree[rt]<<" *"<<endl;
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushUp(rt);
}
void pushDown(int rt,int m){
    if(lazy[rt]){
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        segTree[rt<<1] = (m-(m>>1))*lazy[rt];
        segTree[rt<<1|1] = (m>>1)*lazy[rt];
        lazy[rt] = 0;
    }

}
void segUpdate(int L,int R,int p,int l,int r,int rt){
    if(L<=l&&r<=R){
        lazy[rt] = p;
        segTree[rt] = (l-r)*p;
        return;
    }
    pushDown(rt,r-l+1);
    int m = (l+r)>>1;
    if(L<=m){
        segUpdate(L,R,p,lson);
    }
    if(R>m){
        segUpdate(L,R,p,rson);
    }
    pushUp(rt);

}
int segQuery(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return segTree[rt];
    }
    int m = (l+r)>>1;
    int ret = 0;
    pushDown(rt,r-l+1);
    if(L<=m){
        ret+=segQuery(L,R,lson);
    }
    if(m<R){
        ret+=segQuery(L,R,rson);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        memset(segTree,0, sizeof(segTree));
        memset(lazy,0, sizeof(lazy));
        build(1,n,1);
        //cout<<"ok"<<endl;

        int q;
        cin>>q;
        int op,p,l,r;
        for(int i = 0;i<q;i++){
            cin>>op;
            if(op==0){
                cin>>l>>r;
                cout<<segQuery(l,r,1,n,1)<<endl;
            } else{
                cin>>l>>r>>p;
                segUpdate(l,r,p,1,n,1);
            }

        }
    }
    return 0;
}
