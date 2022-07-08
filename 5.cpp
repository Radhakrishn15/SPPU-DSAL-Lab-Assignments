#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

struct node{
    char label[10];
    int ch_count;
    node *child[10];
}*root;

class GT
{
    
    public:
    void create();
    void display(node *r1);
     GT()
    {
        root=NULL;
    }
};

void GT::create(){
    int tchapters,i,j,k;
    root = new node;
    cout<<"\nEnter book name:";
    cin>>root->label;
     cout<<"\nEnter no. of chapters:";
    cin>>tchapters;
    root->ch_count=tchapters;
    for(i=0;i<tchapters;i++)
    {
        root->child[i]=new node;
        cout<<"\nEnter chpater"<<i+1<<" name"<<endl;
        cin>>root->child[i]->label;
        cout<<"\nEnter no. of sections:";
        cin>>root->child[i]->ch_count;
        
        for(j=0;j<root->child[i]->ch_count;j++)
        {
            root->child[i]->child[j]=new node;
            cout<<"\nEnter section"<<j+1<<" name"<<endl;
            cin>>root->child[i]->child[j]->label;
        }
    }
}


void GT::display(node *r1){
    int i,j,tchapters;
    if(r1!=NULL)
    {
        cout<<"----------Book Hierarchy-----------"<<endl;
        cout<<"\nBook Name:"<<r1->label;
        tchapters=r1->ch_count;
        cout<<"\nChapters:";
        for(i=0;i<tchapters;i++)
        {
            cout<<"\n"<<i+1<<r1->child[i]->label<<endl;
            cout<<"\nSections:";
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                 cout<<"\n"<<j+1<<r1->child[i]->child[j]->label<<endl;
            }
            
        }
    }
    
}

int main(){
    int ch;
    GT gt;
    while(1){
        cout<<"\n-------------Book Menu------------";
        cout<<"\n1.Create"<<"\n2.Display"<<"\n3.Exit"<<endl;
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1 : gt.create();
                     break;
            case 2 : gt.display(root);
                     break;
            case 3 : exit(1);
            default : cout<<"\nInvalid choice";
                     break;
        }
    }
    return 0;
}
