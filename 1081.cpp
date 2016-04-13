//
// Created by 王若璇 on 16/3/10.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int max_n = 2000;
const int inf = 0x3f3f3f3f;
struct Edge{
    int to;
    int cost;
    Edge(){}
    Edge(int _to,int _cost){
        this->to = _to;
        this->cost = _cost;
    }
    bool operator<(const Edge &a) const{
        return cost>a.cost;
    }
};
vector<Edge> v[max_n];
int dist[max_n];
bool visit[max_n];
void init(int n){
    for(int i = 0;i<=n;i++){
        dist[i] = inf;
    }
}
void dijkstra(const vector<Edge> graph[],int s){
    priority_queue<Edge> qu;
    qu.push(Edge(s,0));
    while (!qu.empty()){
        Edge now = qu.top();
        qu.pop();
        if(visit[now.to]){
            continue;
        }
        visit[now.to] = true;
        int min_cost = now.cost;
        for(int i = 0;i<graph[now.to].size();i++){
            if(!visit[graph[now.to][i].to]&&graph[now.to][i].cost+min_cost<dist[graph[now.to][i].to]){
                dist[graph[now.to][i].to] = graph[now.to][i].cost+min_cost;
                qu.push(Edge(graph[now.to][i].to,dist[graph[now.to][i].to]));
            }

        }

    }

}
bool pairCompare(const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b){
    return a.second<b.second;
}
bool isExist[max_n][max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,s,t;
    pair<pair<int,int>,int> pp[max_n];
    while (cin>>n>>m>>s>>t){
        int a,b,c;
        for(int i = 0;i<=n;i++){
            v[i].clear();
        }
        for(int i = 0;i<m;i++){
            cin>>a>>b>>c;
            pp[i] = make_pair(make_pair(a,b),c);
        }

        class prioritize {
        public:bool operator()(const pair<pair<int,int>,int>& p1,const pair<pair<int,int>,int>& p2)const {
                return p1.second>p2.second;
            }
        };
        memset(isExist,0, sizeof(isExist));
        memset(visit,0, sizeof(visit));
        for(int i = 0;i<m;i++){
            int aa = pp[i].first.first;
            int bb = pp[i].first.second;
            if(!isExist[aa][bb]&&!isExist[bb][aa]){
                isExist[bb][aa] = true;
                isExist[aa][bb] = true;
                v[aa].push_back(Edge(bb,pp[i].second));
                v[bb].push_back(Edge(aa,pp[i].second));
            }
        }
        sort(pp,pp+m,pairCompare);
        for(int i = 0;i<m;i++){
            cout<<pp[i].second<<" ";
        }
        init(n);
        memset(visit,0, sizeof(visit));
        dijkstra(v,s);
        if(dist[t]!=inf){
            cout<<dist[t]<<endl;
        } else{
            cout<<"can't reach to the destination!"<<endl;
        }
    }
    return 0;
}
