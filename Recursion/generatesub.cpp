#include<iostream>
using namespace std;

void generate(char *a,char *out,int j,int i)
{
    if(a[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    out[j]=a[i];
    generate(a,out,j+1,i+1);
    generate(a,out,j,i+1);
    return;
}
int main()
{
    char o[10];
    char a[]="abc";
    generate(a,o,0,0);

}