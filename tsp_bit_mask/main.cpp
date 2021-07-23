				//Assignment: TSP using dynamic programming
/*
Name: Saurabh Badgujar
Roll: 33107
Batch: K9
*/

#include<bits/stdc++.h>

using namespace std;

//dp array and parent array
vector<vector<int>> dp,dist,parent;
int n;
vector<int> ans_path;

//tsp using dynamic programming using bitmask
int tsp_bitMasks(int mask,int position){
    if(mask==((1<<n)-1)){
        //ALL VISITED.
        return dist[position][0];
    }

    if(dp[mask][position]!=-1){
        //if present in dp table
        return dp[mask][position];
    }

    int Min_dist=INT_MAX;

    //go to unvisited cities.
    for(int city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int d=dist[position][city]+tsp_bitMasks(mask|(1<<city),city);
            if(Min_dist>d){
                Min_dist=d;
                parent[mask][position]=city;
            }
        }
    }

    return dp[mask][position]=Min_dist;
}

//driver code
int main(){
    //number of cities input
    cout<<"Enter the number of cities less than 7:"<<endl;
    cin>>n;

    if(n>=7){
        cout<<"Enter valid number of cities"<<endl;
        return 0;
    }

    dist=vector<vector<int>>(n,vector<int>(n,0));
    dp=vector<vector<int>>((1<<n),vector<int>(n,-1));
    parent=dp;

    cout<<"Enter the distances between cities"<<endl;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<"Enter distance between "<<i+1<<" "<<j+1<<": ";
            cin>>dist[i][j];
            dist[j][i]=dist[i][j];
        }
    }

    //Printing minimum weight and path that has minimum weight
    cout<<endl;
    cout<<"The minimum cost of travel:"<<tsp_bitMasks(1,0)<<endl;
    cout<<endl;
    cout<<"-----Path-----"<<endl;

    int i=1,j=0;
    cout<<"A ";
    while(j!=-1){
        ans_path.push_back(j);
        j=parent[i][j];
        i=(i)|(1 << j);
    }
    reverse(ans_path.begin(),ans_path.end());
    //cout<<ans_path.size()<<endl;
    for(auto x:ans_path){
        cout<<(char)(x+'A')<<" ";
    }
    cout<<endl;
}
