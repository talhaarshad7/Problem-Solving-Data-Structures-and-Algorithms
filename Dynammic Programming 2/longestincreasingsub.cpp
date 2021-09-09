#include<iostream>
using namespace std;
int lcs(int *input,int n)
{
    int *output=new int[n];
    output[0]=1;
    for(int i=0;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(input[j]>input[i])
            continue;
            int possibleAns=1+output[j];
            if(output[j]<possibleAns)
            output[j]=possibleAns;
        }
    }
    int best=0;
    for(int i=0;i<n;i++)
    {
        if(best<output[i])
        best=output[i];
    }
    delete [] output;
    return best;
}
int main()
{
    int n;
    cin>>n;
    int *input=new int[n];
    for(int i=0;i<n;i++)
    cin>>input[i];
    cout<<lcs(input,n)<<endl;
    delete [] input;
}