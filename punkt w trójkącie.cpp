#include<iostream>
#include <cmath>
using namespace std;

//funkcja obliczaj¹ca pole trójk¹ta o danych wspó³rzêdnych
float pole(int x1, int y1, int x2, int y2, int x3, int y3)
{
return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
//funkcja sprawdzaj¹ca czy pola BCD, ACD i ABD s¹ równe ABC
bool wSrodku(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{

float P = pole(x1, y1, x2, y2, x3, y3);
float P1 = pole(x, y, x2, y2, x3, y3);
float P2 = pole(x1, y1, x, y, x3, y3);
float P3 = pole(x1, y1, x2, y2, x, y);


return (P == P1 + P2 + P3);
}


int main(){
int x1, y1, x2, y2, x3, y3, x4, y4;
cout<<"podaj x,y punktu a"<<endl;
cin>>x1>>y1;
cout<<"podaj x,y punktu b"<<endl;
cin>>x2>>y2;
cout<<"podaj x,y punktu c"<<endl;
cin>>x3>>y3;
cout<<"podaj x,y punktu d"<<endl;
cin>>x4>>y4;
if (wSrodku(x1, y1, x2, y2, x3, y3, x4, y4)){
cout<<" punkt nalezy do trojkata AB";
}
else{
    cout<<"punkt nie nalezy do trojkata AB";
}
return 0;
}
