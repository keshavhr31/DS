#include <iostream>
using namespace std;
class linearsearch
{
public:
    int a[100];
    void input(int);
    void search(int,int);
};
void linearsearch::input(int n)
{
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
}
void linearsearch::search(int n,int m)
{
    int i,c=0;
    for(i=0;i<n;i++)
        if(a[i]==m)
            c=1;

    if(c==1)
        cout<<"value present";
    else

        cout<<"value not present";
}
int main()
{
    linearsearch obj;
    int n,m;
    cout<<"enter no of inputs";
    cin>>n;
    obj.input(n);
    cout<<"enter the value to be searched";
    cin>>m;
    obj.search(n,m);

}

