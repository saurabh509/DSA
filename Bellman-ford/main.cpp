#include <bits/stdc++.h>
using namespace std;

//for storing graph in (u,v,w) form.
set<pair<pair<int,int>,int>> edges;

//driver code
int main(){
    int n,m;
    cout<<"Enter the number of vertices:";
    cin>>n;
    cout<<"Enter the number of Edges:";
    cin>>m;

    for(int i=1;i<=m;i++){
        int u,v,w;
        cout<<"Enter end points of edge "<<i<<endl;
        cout<<"P1:";cin>>u;
        cout<<"P2:";cin>>v;
        cout<<"Enter weight of the edge:";
        cout<<"W:";cin>>w;
        edges.insert({{u,v},w});
    }
    int s;
    cout<<"Enter the source node:";
    cin>>s;

    vector<int> dist(n+1,1e9);
    vector<int> pred(n+1,-1);
    dist[s]=0;

    bool isneg_cycle=false;
    int i=1;
    for(;i<=n-1;i++){
        bool isrelax=false;
        for(auto e:edges){
            int u=e.first.first;
            int v=e.first.second;
            int w=e.second;
            if(dist[u]<1e9 && dist[v]>dist[u]+w){
                pred[v]=u;
                isrelax=true;
                dist[v]=dist[u]+w;
            }
        }
        if(!isrelax)break;
    }

    //negative cycle found.
    if(i==n){
        //cout<<"here"<<endl;
         for(auto e:edges){
            int u=e.first.first;
            int v=e.first.second;
            int w=e.second;
            if(dist[u]<1e9 && dist[v]>dist[u]+w){
                pred[v]=u;
                dist[v]=dist[u]+w;
                cout<<"Negative weight cycle found"<<endl;
                return 0;
            }
        }
    }

    //display all distances and path from source
    for(int d=1;d<=n;d++){
        if(d!=s){
            cout<<"For Node"<<d<<":"<<endl;
            if(dist[d]<1e9){
                cout<<"Minimum distance is:";cout<<dist[d]<<endl;
                cout<<"Path is as follows"<<endl;
                vector<int> path;
                int x=d;
                while(pred[x]!=-1){
                    path.push_back(x);
                    x=pred[x];
                }
                path.push_back(s);
                reverse(path.begin(),path.end());

                for(auto x:path){
                    cout<<x<<" ";
                }cout<<endl;
            }
            else{
                cout<<"The node "<<d<<" is not reachable"<<endl;
            }
            cout<<endl;
        }
    }
}

