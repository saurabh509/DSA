#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int> &a,int N,int i){

    int parent=i;
    int left=2*parent+1;
    int right=2*parent+2;
    int large=i;

    if(left<N && a[large]<a[left]){
        large=left;
    }
    if(right<N && a[large]<a[right]){
        large=right;
    }

    if(large!=parent){
        swap(a[parent],a[large]);
        heapify(a,N,large);
    }
}

void Heap_sort(vector<int> &a){
    int n=a.size();
    for(int i=n-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    vector<int> a={4,1,3,9,7};
    Heap_sort(a);

    for(auto x:a){
        cout<<x<<" ";
    }
}
