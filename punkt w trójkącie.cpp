#include<algorithm>
#include<iostream>
#include <cmath>
using namespace std;

//funkcja obliczaj¹ca pole trójk¹ta o danych wspó³rzêdnych
float pole(int x1, int y1, int x2, int y2, int x3, int y3)
{
int a, b, c, p;
a=sqrt((x2-x1)^2+(y2-y1)^2);
b=sqrt((x3-x2)^2+(y3-y2)^2);
c=sqrt((x1-x3)^2+(y1-y3)^2);
p=(a+b+c)/2;
//wzór Herona 
return sqrt(p*(p-a)*(p-b)*(p-c))
}

//funkcja sprawdzająca czy zmienne float są mniej więcej równe
//credit to author
bool approx_equal(double x, double y)
{  
   const double EPSILON = 1E-14;
   if (x == 0) return fabs(y) <= EPSILON;
   if (y == 0) return fabs(x) <= EPSILON;
   return fabs(x - y) / max(fabs(x), fabs(y)) <= EPSILON;
}

//funkcja sprawdzaj¹ca czy pola BCD, ACD i ABD s¹ równe ABC
bool wSrodku(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{

float P = pole(x1, y1, x2, y2, x3, y3);
float P1 = pole(x, y, x2, y2, x3, y3);
float P2 = pole(x1, y1, x, y, x3, y3);
float P3 = pole(x1, y1, x2, y2, x, y);


return approx_equal(P, P1+P2+P3);
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
