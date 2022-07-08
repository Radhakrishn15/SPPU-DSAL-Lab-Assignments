/* Group C- Assignment No.-15
Problem Statement-
Implement all the functions of a dictionary (ADT) using hashing.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys
must be unique
Standard Operations: Insert(key, value), Find(key), Delete(key)
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

using namespace std;
class  Dictionary
{
private:
	int table[MAX];
	int count;
public:
	Dictionary();
	int hashfun(int);
	void insert(int,int);
	void search(int,int);
	void delete1(int,int);
	void display();
};
Dictionary::Dictionary()
{
	int i;
        count=0;
	for(i=0;i<MAX;i++)
	{
		table[i]=-1;
	}
}

int Dictionary::hashfun(int num)
{
	int key;
	key=num%10;
	return key;
}

void Dictionary::insert(int key,int num)
{

  if (count==MAX)
	 cout<<"\nCan't perform Insertion..Hash Table is full!!";
  else
  {
		if(table[key]==-1)
		table[key]=num;

		else if(key==MAX-1 && table[key]!=-1)
	   {
	   	key=(key+1)%MAX;
		  	while(table[key]!=-1)
			{
				if(key==MAX-1)
					break;
				else
				key++;
			}
			if(table[key]==-1)
			table[key]=num;
		 }

		 else
	 	{

				while(table[key]!=-1)
				{
					if(key==MAX-1 && table[key]!=-1)
					{
						key=(key+1)%MAX;
					}
					else
					key++;
				}
				if(table[key]==-1)
				table[key]=num;
	  }

 	count ++;


   }

}
void Dictionary::search(int key,int num)
{
	int i;
	if(table[key]==num)
		cout<<"\n Element is pesent at "<<key<< "position.";
	else
	{
		for(i=key+1; i<MAX; i++)
		{
			if(table[i]==num)
			{
				cout<<"\n Element is present at "<<i<<" position.";
				break;
			}
		}
		if(i==MAX)
		{
			for(i=0; i<key; i++)
			{
				if(table[i]==num)
				{
					cout<<"\n Element is present at "<<i<<" position.";
					break;
				}
			}
			if(i==key)
				cout<<"\n Element is not present in Hash Table.";
		}
	}

}

void Dictionary::delete1(int key,int num)
{
	int i;
	if(table[key]==num)
	{
		table[key]=-1;
		cout<<"\nElement "<<num<<" is deleted sucessfully.";
		count--;
	}
	else
	{
		for(i=key+1; i<MAX; i++)
		{
			if(table[i]==num)
			{
				table[i]=-1;
				cout<<"\nElement "<<num<<" is deleted sucessfully.";
				count--;
				break;
			}
		}
		if(i==MAX)
		{
			for(i=0; i<key; i++)
			{
				if(table[i]==num)
				{
					table[i]=-1;
					cout<<"\nElement "<<num<<" is deleted sucessfully.";
					count--;
					break;
				}
			}
			if(i==key)
				cout<<"\n Element is not present in Hash Table.";
		}
	}

}
void Dictionary::display()
{
int i;
cout<<"\n The hash table is.........\n";
cout<<"key\tValue";
for(i=0;i<MAX;i++)
	cout<<"\n"<<i<<"\t"<<table[i];

cout<<"\nHash Table Entries= "<<count;
}

int main()
{
	int num,key,i,ch;
	char ans;
	Dictionary h;
	while(1)
	{
		cout<<"\n Dictionary Program....";
		cout<<"\n1. Insert\n2. Delete\n3. Search\n4. Exit ";
		cout<<"\nEnter UR Choice= ";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"\n Enter the Value for Insert Operation= ";
				cin>>num;
				key=h.hashfun(num);
				h.insert(key,num);
				h.display();
			break;
			case 2:
				h.display();
				cout<<"\n Enter the Value for Delete Operation= ";
				cin>>num;
				key=h.hashfun(num);
				h.delete1(key,num);
				h.display();
			break;
			case 3:
				h.display();
				cout<<"\n Enter the Value for Search Operation= ";
				cin>>num;
				key=h.hashfun(num);
				h.search(key,num);
			break;
			case 4:
				exit(0);

		}
	}


return 0;
}


/*************** OUTPUT **********************************************
[yogesh@localhost ~]$ g++ hash.cpp
[yogesh@localhost ~]$ ./a.out

 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 1

 Enter the Value for Insert Operation= 30

 The hash table is.........
key	Value
0	30
1	-1
2	-1
3	-1
4	-1
5	-1
6	-1
7	-1
8	-1
9	-1
Hash Table Entries= 1
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 1

 Enter the Value for Insert Operation= 34

 The hash table is.........
key	Value
0	30
1	-1
2	-1
3	-1
4	34
5	-1
6	-1
7	-1
8	-1
9	-1
Hash Table Entries= 2
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 1

 Enter the Value for Insert Operation= 55

 The hash table is.........
key	Value
0	30
1	-1
2	-1
3	-1
4	34
5	55
6	-1
7	-1
8	-1
9	-1
Hash Table Entries= 3
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 144

 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 1

 Enter the Value for Insert Operation= 44

 The hash table is.........
key	Value
0	30
1	-1
2	-1
3	-1
4	34
5	55
6	44
7	-1
8	-1
9	-1
Hash Table Entries= 4
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 1

 Enter the Value for Insert Operation= 99

 The hash table is.........
key	Value
0	30
1	-1
2	-1
3	-1
4	34
5	55
6	44
7	-1
8	-1
9	99
Hash Table Entries= 5
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 1

 Enter the Value for Insert Operation= 19

 The hash table is.........
key	Value
0	30
1	19
2	-1
3	-1
4	34
5	55
6	44
7	-1
8	-1
9	99
Hash Table Entries= 6
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 2

 The hash table is.........
key	Value
0	30
1	19
2	-1
3	-1
4	34
5	55
6	44
7	-1
8	-1
9	99
Hash Table Entries= 6
 Enter the Value for Delete Operation= 19

Element 19 is deleted sucessfully.
 The hash table is.........
key	Value
0	30
1	-1
2	-1
3	-1
4	34
5	55
6	44
7	-1
8	-1
9	99
Hash Table Entries= 5
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 3

 The hash table is.........
key	Value
0	30
1	-1
2	-1
3	-1
4	34
5	55
6	44
7	-1
8	-1
9	99
Hash Table Entries= 5
 Enter the Value for Search Operation= 44

 Element is present at 7 position.
 Dictionary Program....
1. Insert
2. Delete
3. Search
4. Exit
Enter UR Choice= 4
[yogesh@localhost ~]$
*/
