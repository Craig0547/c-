#include<iostream>
using namespace std;
int main()
{
    int dec, bin, decCopy;
    cout<<"input number:\n";
    cin>>dec;
    decCopy=dec;

    //calculate how many digits in binary number
    int N=0;
    while (decCopy != 0)
    {
        decCopy=decCopy/2;
        N++;
    }
    int Arr[N];

    //convert decimal int to binary number in array
    for(int i=0;i<N;i++)
    {
        if (dec%2==0) Arr[i]=0;
        else Arr[i]=1;
        dec = dec/2;
    }

    //add first block
    int blocks=1, bzeros=0, bones=0, currdigit=0;
    currdigit=Arr[0];
    if(currdigit==0) bzeros++;
    else bones++;
    //check for blocks of numbers and count them
    for(int i=0;i<N;i++)
    {
        if(Arr[i]!=currdigit)
        {
            blocks++;
            currdigit++;
            if(Arr[i]==1) bones++;
            if(Arr[i]==0) bzeros++;
        }
    }

    //display results
    cout<<"blocks counted: "<<blocks<<endl;
    cout<<"blocks of ones: "<<bones<<endl;
    cout<<"blocks of zeros: "<<bzeros<<endl;
    return 0;
}
