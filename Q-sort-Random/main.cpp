#include<bits/stdc++.h>

using namespace std;

int Partition(vector<int> &a,int L,int R){
    //swap a random element
    swap(a[R],a[L+rand()%(R-L+1)]);

    int ptr=L;

    for(int i=L;i<R;i++){
        if(a[i]<a[R]){
            swap(a[ptr],a[i]);
            ptr++;
        }
    }
    /*for(int i=L;i<=R;i++){
        cout<<a[i]<<" ";
    }cout<<endl;*/
    swap(a[R],a[ptr]);
    return ptr;
}

void Qsort(vector<int> &a,int L,int R){
    if(L<R){
        int pi=Partition(a,L,R);
        Qsort(a,L,pi-1);
        Qsort(a,pi+1,R);
    }
}

int Partition1(vector<int> &a,int L,int R){
    int ptr=L;

    for(int i=L;i<R;i++){
        if(a[i]<a[R]){
            swap(a[ptr],a[i]);
            ptr++;
        }
    }
    /*for(int i=L;i<=R;i++){
        cout<<a[i]<<" ";
    }cout<<endl;*/
    swap(a[R],a[ptr]);
    return ptr;
}

void Qsort1(vector<int> &a,int L,int R){
    if(L<R){
        int pi=Partition1(a,L,R);
        Qsort1(a,L,pi-1);
        Qsort1(a,pi+1,R);
    }
}

int main(){
    srand(time(0));
    vector<int> a;

    for(int i=1e5;i>=0;i--){
        a.push_back(i);
    }
    cout<<"Random running"<<endl;
    Qsort(a,0,a.size()-1);
    cout<<"Random done..."<<endl;

    cout<<"Normal running"<<endl;
    Qsort1(a,0,a.size()-1);
    cout<<"Normal done..."<<endl;
}
