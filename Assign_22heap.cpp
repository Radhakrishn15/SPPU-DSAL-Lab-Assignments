#include<iostream>
using namespace std;
#define max 20

class student
{
    private:
    int marks[max];
    public:
    student()
    {
        for(int i=0;i<max;i++)
        {
            marks[i]=0;
        }
    }
        void insert(int tot);
        void display(int tot);
        void heapmax(int tot);
        void heapmin();
};

void student::insert(int tot)
{
    for(int i=1;i<=tot;i++)
    {
        //int j;
        cout<<"enter the marks";
        cin>>marks[i];

        int j=i;
        int part=j/2;

        while(marks[j]<=marks[part] &&j!=0)
        {
            int temp=marks[j];
            marks[j]=marks[part];
            marks[part]=temp;
            j= part;
            part=j/2;
        }
    }
}

void student::display(int tot)
{
    for(int i=1;i<=tot;i++)
    {
        cout<<" "<<marks[i];
        cout<<endl;
    }
}

void student::heapmax(int tot)
{
    int i;
    int max1=marks[i];
    for(int i=2;i<=tot;i++)
    {
        if(max1<marks[i]);
        max1=marks[i];
    }
    cout<<"Max marks : "<<max1<<endl;

}

void student::heapmin()
{
    cout<<"Min marks : "<<marks[1]<<endl;
}

int main()
{
    int ch,n,tmp,total,count;
    student s1;
    do
    {
        cout<<"*******MENU********"<<endl;
        cout<<"1.inserting into heap"<<endl;
        cout<<"2.display min heap"<<endl;
        cout<<"3.max heap"<<endl;
        cout<<"4.min heap"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"enter the number of students : ";
            cin>>total;
            s1.insert(total);
            break;

            case 2:
            s1.display(total);
            break;

            case 3:
            s1.heapmax(total);break;

            case 4:
            s1.heapmin();break;
        }
        cout<<"do you want to continue ?(1 for continue)";
        cin>>count;
    } while (count==1);
    return 0;
}