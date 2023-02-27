#include<iostream>
#define pkt pair<int, int>
using namespace std;

int CrossProduct(pkt X, pkt Y, pkt Z){
    int x1=Z.first-X.first,
    y1=Z.second-X.second,
    x2=Y.first-X.first,
    y2=Y.second-X.second;
return x1*y2-x2*y1;
}

bool IfOnLine(pkt X, pkt Y, pkt Z){
if((min(X.first, Y.first)<=Z.first<=max(X.first, Y.first))&&(min(X.second, Y.second)<=Z.second<=max(X.second, Y.second))){
    return true;
}

return false;
}

bool IfCross(pkt A, pkt B, pkt C, pkt D){
    int v1 = CrossProduct(A, B, C),
		v2 = CrossProduct(A, B, D),
		v3 = CrossProduct(C, D, A),
		v4 = CrossProduct(C, D, B);

    if(((v1>0&&v2<0)||(v1<0&&v2>0))&&((v3>0&&v4<0)||(v3<0&&v4>0))) return 1;

    if(v1 == 0 && IfOnLine(A, B, C)) return 1;
	if(v2 == 0 && IfOnLine(A, B, D)) return 1;
	if(v3 == 0 && IfOnLine(C, D, A)) return 1;
	if(v4 == 0 && IfOnLine(C, D, B)) return 1;

	return 0;
}

int main(){
    pair<int, int> A, B, C, D;
    cout<<"wprowadz koordynaty x,y poczatku pierwszego odcinka\n";
    cin>>A.first>>A.second;
    cout<<"wprowadz koordynaty x,y konca pierwszego odcinka\n";
    cin>>B.first>>B.second;
    cout<<"wprowadz koordynaty x,y poczatku drugiego odcinka\n";
    cin>>C.first>>C.second;
    cout<<"wprowadz koordynaty x,y konca drugiego odcinka\n";
    cin>>D.first>>D.second;
    if(IfCross){
        cout<<"odcinki przecinaja sie";
    }
    else{
        cout<<"odcinki nie przecinaja sie";
    }
return 0;
}
