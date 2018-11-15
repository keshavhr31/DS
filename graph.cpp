#include<iostream>
using namespace std;
void printmat(int **mat,int n)
{
int i,j;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cout<<mat[i][j]<<" ";
}
cout<<endl;
}}
int main()
{
    int v,l,v1,v2;
    cout<<"Enter the size for matrix\n";
cin>>v;
int **graph;
graph=new int*[v];
for(int i=0;i<v;i++)
{
graph[i]=new int[v];
for(int j=0;j<v;j++)
{
graph[i][j]=0;
}
}
cout<<"Enter the pairs \n";
cin>>l;
for(int i=0;i<l;i++)
{
cin>>v1>>v2;
graph[v1-1][v2-1]=1;
graph[v2-1][v1-1]=1;
}
printmat(graph,v);
}

