#include<iostream>
#include<cstdio>
//#include<csdtlib>
#include<cstring>
using namespace std;

struct node{
	int priority;
	int item;
	node *link;
};

class Priority_Q
{
   private:
   	node *front;
   	public:
   		Priority_Q()
   		{
   			front=NULL;
	    }

	    void insert(int item,int priority)
	    {
	    	node *temp,*q;
	    	temp->item=item;
	    	temp->priority=priority;
	    	if(front==NULL || priority<front->priority){
	    		temp->link=front;
	    		front=temp;
			}
			else{
				q=front;
				while(q->link!=NULL && q->link->priority<=priority){
					q=q->link;
					temp->link=q->link;
					q->link=temp;
				}
			}
		}

		void delete1(){
			node *temp;
			if(front==NULL){
				cout<<"\n Queue is empty";
			}
			else{
				temp=front;
				cout<<"\nElement deleted is "<<temp->item;
				front=front->link;
				//free(temp);
			}
		}
		void display()
		{
			node *ptr;
			ptr=front;
			if(front==NULL){
				cout<<"\n Queue is empty";
			}
			else
			{
				cout<<"Elements and their priority are:";
				while(ptr!=NULL)
				{
						cout<<"\nElement is "<<ptr->item;
							cout<<"\n Priority is "<<temp->priority;
						ptr=ptr->link
				}
			}
		}

};

int main()
{
	int choice,item,priority;
	Priority_Q pq;
	do{

	cout<<"\n 1.Insert";
	cout<<"\n 2.Delete";
	cout<<"\n 3.Display";
	cout<<"\n Exit";

	cout<<"\n Enter your choice:";
	cin>>choice;

	switch(choice)
	{
		case 1:
			cout<<"Enter element to be inserted:"<<endl;
			cin>>item;
			cout<<"\n Enter priority for it:";
			cin>>priority;
			pq.insert(iten,priority);
			break;

	    case 2:
	    	pq.delete1();
	    	break;
	    case 3:
	    	pq.display();
	    	break;
	    case 4:
            cout<<"Exit";
	    	break;
	    default:
	    	cout<<"Invalid choice"<<endl;
			break;
	}

  }while(choice!=4);
  return 0;
}
