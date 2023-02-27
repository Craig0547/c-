#include<iostream>
using namespace std;

void merge(int Arr[],int l, int m, int r){
    int i=l;
    int j=m+1;
    int k=l;
    
    int temp[r];
    
    while(i<=m&&j<=r){
        if(Arr[i]<Arr[j]){
            temp[k]=Arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=Arr[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        temp[k]=Arr[i];
        k++;
        i++;
    }
    while(j<=r){
        temp[k]=Arr[j];
        k++;
        j++;
    }
    for(i=l;i<=r;i++){
        Arr[i]=temp[i];
    }
}

void sort(int Arr[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        sort(Arr, l, m);
        sort(Arr, m+1, r);
        merge(Arr, l, m, r);
    }
}

int main(){
    int Size=5;
    int MyArr[Size];
    for(int i=0;i<Size;i++){
        cin>>MyArr[i];
    }
    sort(MyArr,0,Size-1);
    for(int i=0;i<Size;i++){
        cout<<MyArr[i]<<" ,";
    }
    return 0;
}
