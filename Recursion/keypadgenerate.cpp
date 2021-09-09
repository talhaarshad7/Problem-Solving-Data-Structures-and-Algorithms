#include<iostream>
using namespace std;
char key[][10]={"","","abc","def","ghi","jkl","mno","pqr","wxyz"};
void gen(char *ip,char* o,int i,int j)
{
    if(ip[i]=='\0')
    {
        o[j]='\0';
        cout<<o<<endl;
        return;
    }
    int digit=(int)ip[i]-48;//ip[i]-'0';
    for(int k=0;key[digit][k]!='\0';k++)
    {
        o[j]=key[digit][k];
        gen(ip,o,i+1,j+1);
    }
    return;
}
int main()
{
    char in[100];
    char out[100];
    cin>>in;
    gen(in,out,0,0);
}