#include<iostream>
using namespace std;
int subset(int a[],int op[][100],int n)
{
    if(n==0)
    {
        op[0][0]=0;
        return 1;
    }
    int smalloplen=subset(a+1,op,n-1);
    for(int i=0;i<smalloplen;i++)
    {
        int columns=op[i][0]+1;
        op[i+smalloplen][0]=columns;
        op[i+smalloplen][1]=a[0];
        for(int j=2;j<=columns;j++)
        op[i+smalloplen][j]=op[i][j-1];   
    }
    return 2*smalloplen;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int op[100][100];
    int l=subset(a,op,n);
    for(int i=0;i<l;i++){
    for(int j=1;j<=op[i][0];j++)
    cout<<op[i][j];
    cout<<endl;}
    free(a);
}