#include<iostream>
using namespace std;
int main(){
int *w=new int [3];

for(int i=0;i<3;i++) cin>>w[i];
for(int i=0;i<3;i++){
    cout<<w[i];
    w=&w[i];
    cout<<" "<<w<<endl;
}

delete[] w;
return 0;
}
