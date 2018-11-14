
#include <iostream>
#include <cstring>
#include <memory>
using namespace std;
struct node
{
    char name;
    struct node *left;
    struct node *right;
};
struct node *root=NULL;
class tree
{
public:
    void insert(char);
    void ddelete(char);
    void preorder(struct node *);
    void inorder(struct node *);
    void postorder(struct node *);
};
void tree::insert(char str)
{
    struct node *ptr;
    ptr=new node;
    struct node *temp;
    struct node *prev =NULL;
    ptr->name=str;
    ptr->right=NULL;
    ptr->left=NULL;
    if(root==NULL)
    {
        root=ptr;
    }
    else
    {
        temp=root;
        while(temp!=NULL)
        {
            prev=temp;
            if(str<temp->name)
                temp=temp->left;
            else
                temp=temp->right;
        }

    if(ptr->name<prev->name)
        prev->left=ptr;
    else
        prev->right=ptr;
}
}
void tree::ddelete(char str1)
{
 if(root==NULL)
 {
     cout<<"underflow";
     return;
 }
    struct node *temp;
    struct node *prev=NULL;
    temp=root;
    while((str1!=temp->name)&&(temp!=NULL))
    {
        prev=temp;
        if(str1<temp->name)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if((temp==NULL)&&(str1!=temp->name))
    {
        cout<<"does not exit";
        return;
    }
    if((temp->left==NULL)&&(temp->right==NULL))
    {
        if(temp==root)
        {
            root=NULL;
            delete temp;
            return;
        }
        if(str1<prev->name)
        {
            prev->left=NULL;
            delete temp;
        }
        else
        {
            prev->right=NULL;
            delete temp;
        }
    }
    else if((temp->left!=NULL)&&(temp->right!=NULL))
    {
        struct node *base;
        char x =NULL;
        base=temp;
        temp=temp->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        x=temp->name;
        ddelete(x);
        base->name=x;
    }
    else
    {
        if(temp==root)
        {
            if(temp->left!=NULL)
                root=temp->left;
            else
                root=temp->right;
        }
        else
        {
            if(temp->name<prev->name)
            {
                if(temp->left!=NULL)
                {
                    prev->left=temp->left;
                    temp->left=NULL;
                    delete temp;
                }
                else
                {
                    prev->left=temp->right;
                    temp->right=NULL;
                    delete temp;
                }
            }
            else
            {
                if(temp->left!=NULL)
                {
                    prev->right=temp->left;
                    temp->left=NULL;
                    delete temp;
                }
                else
                {
                    prev->right=temp->right;
                    temp->right=NULL;
                    delete temp;
                }
            }
        }
    }
}
void tree::preorder(struct node *root)
{

    if (root!=NULL)

    {
        cout<<root->name;
        preorder(root->left);
        preorder(root->right);
    }
}
void tree::inorder(struct node *root)
{
    if(root==NULL)
        cout<<"tree empty";
    else
    {
        inorder(root->left);
        cout<<root->name;
        inorder(root->right);
    }
}
void tree::postorder(struct node *root)
{
    if(root==NULL)
        cout<<"tree empty";
    else
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->name;
    }
}

int main()
{
    tree t;
    int n;
    char str1;
    char str;

    while(1)
    {
        cout<<"Enter your choice";
        cin>>n;
        switch(n)
        {
            case 1:
                cin>>str;
                t.insert(str);
                break;
            case 2:
                cin>>str1;
                t.ddelete(str1);
                break;
            case 3:
                t.preorder(root);
                break;
            case 4:
                t.inorder(root);
                break;
            case 5:
                t.postorder(root);
                break;
            case 6:
                exit(0);
        }
    }
}

