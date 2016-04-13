//
// Created by 王若璇 on 16/3/11.
//
/*Kurskal algorithm
 * sort the weight of each edge*/
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
/*union_find*/
const int max_n = (int)1e5+100;
using namespace std;
int par[max_n];
int vrank[max_n];
void init(int n){
    for(int i = 0;i<=n;i++){
        vrank[i] = 0;
        par[i] = i;
    }

}
/*path compression find*/
int find(int x){
    if(par[x]==x){
        return x;
    } else{
        return par[x] = find(par[x]);
    }
}
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x==y){
        return;
    }
    if(vrank[x]<vrank[y]){
        par[x] = y;
    } else{
        par[y] = x;
        if(vrank[x]==vrank[y]){
            vrank[x]++;
        }
    }
}
bool same(int x,int y){
    return find(x) == find(y);
}
struct Edge{
    int u,v,cost;
    Edge(){}
    Edge(int _u,int _v,int _cost){
        u = _u;
        v = _v;
        cost = _cost;
    }
    bool operator<(const Edge& a)const{
        return cost<a.cost;
    }
};
vector<Edge> es;
int kruskal(vector<Edge> es,int n){
    sort(es.begin(),es.end());
    init(n);
    int res = 0;
    for(vector<Edge>::iterator it = es.begin();it!=es.end();++it){
        if (!same(it->u,it->v)){
            unite(it->u,it->v);
            res+=it->cost;
        }
    }
    return res;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m){
        int u,v,c;
        es.clear();
        for(int i = 0;i<m;i++){
            cin>>u>>v>>c;
            es.push_back(Edge(u,v,c));
        }
        cout<<kruskal(es,n)<<endl;
    }

    return 0;
}

