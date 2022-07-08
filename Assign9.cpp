#include<iostream>
#include<string.h>
using namespace std;
#define infi -1
#define max 10
#define hash_fun(x) x%10

class hash
{
	private:
		int address,count;
		struct tele
		{
			long int ph_no;
			//char name[20];
			int link;
		}t[10];			
	public:
		hash()
		{
			for(int i=0;i<max;i++)
			{
				t[i].ph_no=-1;
				//strcpy(t[i].name, "");
				t[i].link=infi;
			}
			count=-1;
		}
		void chaining();	// Without Replacement
		void chaining_with();	// With Replacement
		void display();
}h1;

void hash::chaining()
{
	int ph_no;
	int i,k,cnt;
	char name[20];
	cout<<"enter the phone number & name:";
	cin>>ph_no;//>>name;
	address=hash_fun(ph_no);
	if(t[address].ph_no==-1)
	{
		t[address].ph=ph_no;
		//strcpy(t[address].name,name);
	}
	else
	{		
		//t[address].ph%10!=address


		
		i=address;
		count=0;         //find next empty slot.
		
		while(t[i].ph_no!=-1 && count<max)
		{
			i=(i+1)%max;
			count++;
		}
		if(count!=max)
		{
			t[i].ph_no=ph_no;
			//strcpy(t[i].name,name);
			//parent finding
			k=i;	//k=6	
			i=address;	//i=5
			cnt=0;	
			//if((t[address].ph%10)!=address)
			while(cnt<max && i!=k)	//0<10 && 5!=6
            		{
	if(t[i].link==infi && (t[address].ph_no%10)!=address)	
	//t[5].link==-1 && 5!=5
				{
                			t[i].link=k;
				}				
				else
				{
					i=t[i].link;	//i=-1
				}
				cnt++;
			}
		}
		 
		if(count==max)
			cout<<"t is full";
	}
}

void hash::chaining_with()
{
	int key,i,k,j,m,link,a;
	cout<<"enter the value:";
	cin>>key;
	address=hash_fun(key);
	if(t[address].ph==-1)
	{
		t[address].ph=key;

	}
	else{
	i=address;count=0;      //find next empty slot.
	k=t[address].ph;
	if(k%max==address)              //hashed location contains synonym
    {

			j=address,a=address;
			while(t[j].ph!=-1&&count<max)
            {
                j=(j+1)%max;
                if((t[j].ph%max)==address)           //to check the number of synonyms present.
                {
                    a=j;
                }
                count++;
            }
            if(count!=max)
            {
                t[j].ph=key;
                t[a].ph=k;
            }

    }
    else
    {
            t[address].ph=key;
            t[address+1].ph=infi;
            j=address;
            while(t[j].ph!=-1&&count<max)
            {
                j=(j+1)%max;
                count++;
            }
            if(count!=max)
                t[j].ph=k;
            for(i=0;i<max;i++)
            if(t[i+1].ph==address)
                t[i+1].ph=j;
    }
    }
}

void hash::display()
{
	cout<<"\n Address Key :  ";
	for(int i=0;i<max;i++)
	{
		cout<<"\n "<<i<<"\t"<<t[i].ph<<"\t"<<t[i].link;
	}
	cout<<"\n";
}


int main()
{
    hash h1,h2;
int ch,e,key;
  do
   {
     cout<<"\n --- MENU ---\n 1: chaining Without Replacement\n 2: chaining With Replacement\n 3: Exit\n Enter Your Choice : ";
     cin>>ch;
	switch(ch)
	{
		case 1:
			do
			{
				cout<<"\n ** MENU **";
				cout<<"\n 1: Insert a Key\n 2: Display Hash t\n 3: Exit\n Enter Your Choice : ";
				cin>>e;
				if(e==1)
				{
					/*cout<<" Enter Key : ";
					cin>>key;*/
					h1.chaining();
				}
				else if(e==2)
				{
					cout<<" Hash t Using Chaining Without Replacement";
					h1.display();
				}
				else if(e==3)
				{
					break;
				}
			}while(e<3);
			 break;
		case 2:
			do
			{
				cout<<"\n ** MENU **";
				cout<<"\n 1: Insert a Key\n 2: Display Hash t\n 3: Exit\n Enter Your Choice : ";
				cin>>e;
				if(e==1)
				{
					h2.chaining_with();
				}
				else if(e==2)
				{
					cout<<" Hash t Using Chaining With Replacement";
					h2.display();
				}
				else if(e==3)
				{
					break;
				}
			}while(e<3);
			 break; 
		//case 3: exit(0);
        }
     }while(ch<3);
return 0;
}

/* OUTPUT:

 --- MENU ---
 1: chaining Without Replacement
 2: chaining With Replacement
 3: Exit
 Enter Your Choice : 1

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:55

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:81

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:61

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:70

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 2
 Hash t Using Chaining Without Replacement
 Address Key :
 0      70      999
 1      81      1
 2      61      999
 3      -1      999
 4      -1      999
 5      55      999
 6      -1      999
 7      -1      999
 8      -1      999
 9      -1      999

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:60

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:82

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:40

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:66

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:89

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:44

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 2
 Hash t Using Chaining Without Replacement
 Address Key :
 0      70      3
 1      81      1
 2      61      2
 3      60      999
 4      82      4
 5      55      999
 6      40      6
 7      66      999
 8      44      999
 9      89      999

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 3

 --- MENU ---
 1: chaining Without Replacement
 2: chaining With Replacement
 3: Exit
 Enter Your Choice : 2

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:55

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:81

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:61

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:70

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 2
 Hash t Using Chaining With Replacement
 Address Key :
 0      70      999
 1      81      2
 2      61      999
 3      -1      999
 4      -1      999
 5      55      999
 6      -1      999
 7      -1      999
 8      -1      999
 9      -1      999

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:60

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:82

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 2
 Hash t Using Chaining With Replacement
 Address Key :
 0      70      3
 1      81      4
 2      82      999
 3      60      999
 4      61      999
 5      55      999
 6      -1      999
 7      -1      999
 8      -1      999
 9      -1      999

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:40

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:66

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:89

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 1
enter the value:44

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 2
 Hash t Using Chaining With Replacement
 Address Key :
 0      70      3
 1      81      8
 2      82      999
 3      60      7
 4      44      999
 5      55      999
 6      66      999
 7      40      999
 8      61      999
 9      89      999

 ** MENU **
 1: Insert a Key
 2: Display Hash t
 3: Exit
 Enter Your Choice : 3

 --- MENU ---
 1: chaining Without Replacement
 2: chaining With Replacement
 3: Exit
 Enter Your Choice : 3

Process returned 0 (0x0)   execution time : 114.897 s
Press any key to continue.


*/
