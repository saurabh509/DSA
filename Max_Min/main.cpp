/*
    Name: Saurabh Badgujar
    Roll: 33107
    Batch: K9
*/

#include <bits/stdc++.h>
using namespace std;

//Max-min function to calculate max,min of an array
pair<int,int> Max_Min(vector<int> &v,int L,int R){
    cout<<"L="<<L<<" R="<<R<<" :->";
    for(int i=L;i<=R;i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    if(L==R){
        return {v[L],v[L]};
    }
    else if(R-L==1){
        int Max=0,Min=0;
        if(v[L]>v[R]){
            Max=v[L];
            Min=v[R];
        }
        else{
            Min=v[L];
            Max=v[R];
        }
        return {Max,Min};
    }
    auto left_array=Max_Min(v,L,(L+R)/2);
    auto right_array=Max_Min(v,(L+R)/2+1,R);

    int Min=0,Max=0;

    if(left_array.first>right_array.first){
        Max=left_array.first;
    }
    else{
        Max=right_array.first;
    }

    if(left_array.second>right_array.second){
        Min=right_array.second;
    }
    else{
        Min=left_array.second;
    }

    return {Max,Min};
}

//checked for descending array
bool check(vector<int> &v){
    if(v.size()==1){
        return true;
    }
    else if(v[0]>=v[1]){//POSSIBLITY OF DES.
        for(int i=0;i<v.size()-1;i++){
            if(v[i]<v[i+1])return false;
        }
        cout<<"Given array was sorted in descending order"<<endl;
        cout<<"MAX:"<<v[0]<<endl;
        cout<<"MIN:"<<v.back()<<endl;
        return true;
    }
    return false;
}

//driver code
int main(){
    //Input
    vector<int> v={55,44,33,22,11,676,555,444,333,222,111,};
    cout<<"INPUT:->";
    for(auto x:v){
        cout<<x<<" ";
    }cout<<endl;
    if(check(v)){

    }
    else{
        auto ans=Max_Min(v,0,v.size()-1);
        cout<<"MAX:"<<ans.first<<endl;
        cout<<"MIN:"<<ans.second<<endl;
    }
}
