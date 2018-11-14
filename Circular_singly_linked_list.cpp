#include<iostream>
using namespace std;
struct node
{
	public:
		int data;
		node *next;
};
struct node *start=NULL;
void InsertEnd()
{
	node *temp=new node();
	cout<<"Enter value to be inserted"<<endl;
	cin>>temp->data;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
		temp->next=start;
	}
	else
	{
		node *t=start;
		while(t->next!=start)
		  t=t->next;
		 t->next=temp;
		 temp->next=start; 
	}
}
void InsertFront()
{
    node *temp=new node();
	
	if(start==NULL)
	InsertEnd();
	else
	{   
	   cout<<"Enter value to be inserted"<<endl;
	   cin>>temp->data;
	   temp->next=NULL;
		node *t=start;
		temp->next=start;
		
		while(t->next!=start)
         t=t->next;
	     
	      t->next=temp;
	      start=temp;
	}	 
}
void InsertMiddle()
{
}
void DeleteEnd()
{
}
void DeleteFront()
{
}
void DeleteMiddle()
{
}
void PrintList()
{
	node *t=start;
	cout<<"List = ";
	if(start!=NULL)
	{
		do{
			cout<<t->data<<" ";
			t=t->next;
		 }while(t!=start);
	}
	cout<<endl;
}

int main()
{
	int choice;
	cout<<"Enter choice"<<endl<<"1 Insert At End"<<endl<<"2 Insert At Front"<<endl<<"3 Insert At Middle"<<endl;
	cout<<"4 Delete At End"<<endl<<"5 Delete At Front"<<endl<<"6 Delete At Any Location"<<endl<<"7 Print List"<<endl<<"8 End Program"<<endl;
    while(1)
    {   
        cout<<"Enter choice"<<endl;
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
    				InsertEnd();
    				break;
				}
			case 2:
    			{
    				InsertFront();
    				break;
				}
			case 3:
    			{
    				InsertMiddle();
    				break;
				}
			case 4:
    			{
    				DeleteEnd();
    				break;
				}
			case 5:
    			{
    				DeleteFront();
    				break;
				}
			case 6:
    			{
    				DeleteMiddle();
    				break;
				}
			case 7:
    			{
    				PrintList();
    				break;
				}
			case 8:
    			{
    			    exit(0);
				}	
			default:
			    cout<<"Enter valid choice"<<endl;						
		}
	}
}
