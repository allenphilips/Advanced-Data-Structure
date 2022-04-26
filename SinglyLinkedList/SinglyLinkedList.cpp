#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
int info;
struct node *next;
}*start;
class single_llist
{
public:
node* create_node(int);
void insert_begin();
void insert_last();
void insert_pos();
void delete_begin();
void delete_last();
void delete_pos();
void search();
void display();
single_llist()
{
start = NULL;
}
};
int main()
{
int choice;
single_llist sl,s2;
start = NULL;
do
{
cout<<"1.Insert at first"<<endl;
cout<<"2.Insert at last"<<endl;
cout<<"3.Insert at position"<<endl;
cout<<"4.Delete at first"<<endl;
cout<<"5.Delete at Last"<<endl;
cout<<"6.Delete at position"<<endl;
cout<<"7.Search"<<endl;
cout<<"8.Display"<<endl;
cout<<"9.Exit "<<endl;
cout<<"Enter your choice :";
cin>>choice;
switch(choice)
{
case 1: sl.insert_begin();
sl.display();
break;
case 2: sl.insert_last();
sl.display();
break;
case 3: sl.insert_pos();
sl.display();
break;
case 4: s2.delete_begin();
sl.display();
break;
case 5: s2.delete_last();
sl.display();
break;
case 6: sl.delete_pos();
sl.display();
break;
case 7:sl.search();
sl.display();
break;
case 8:sl.display();
break;
case 9:exit(0);
break;
default:cout<<"Wrong choice...???"<<endl;
break;
}
}
while(choice != 9);
}
node *single_llist::create_node(int value)
{
struct node *temp, *s;
temp = new(struct node);
if (temp == NULL)
{
cout<<"Memory not allocated"<<endl;
return 0;
}
else
{
temp->info = value;
temp->next = NULL;
return temp;
}
}
void single_llist::insert_begin()
{
int value;
cout<<"Enter the value to be inserted : ";
cin>>value;
struct node *temp, *s;
temp = create_node(value);
if (start == NULL)
{
start = temp;
start->next = NULL;
cout<<temp->info<<" is inserted at first in the empty list"<<endl;
}
else
{
s = start;
start = temp;
start->next = s;
cout<<temp->info<<" is inserted at first"<<endl;
}
}
void single_llist::insert_last()
{
int value;
cout<<"Enter the value to be inserted : ";
cin>>value;
struct node *temp, *s;
temp = create_node(value);
if (start == NULL)
{
start = temp;
start->next = NULL;
cout<<temp->info<<" is inserted at last in the empty list"<<endl;
}
else
{
s = start;
while (s->next != NULL)
{
s = s->next;
}
temp->next = NULL;
s->next = temp;
cout<<temp->info<<" is inserted at last"<<endl;
}
}
void single_llist::insert_pos()
{
int value, pos, counter = 0, loc = 1;
struct node *temp, *s, *ptr;
s = start;
while (s != NULL)
{
s = s->next;
counter++;
}
if (counter == 0){}
else
{
cout<<"Enter the postion from "<<loc<<" to "<<counter+1<<" : ";
cin>>pos;
s = start;
if(pos == 1)
{
cout<<"Enter the value to be inserted : ";
cin>>value;
temp = create_node(value);
start = temp;
start->next = s;
cout<<temp->info<<" is inserted at first"<<endl;
}
else if (pos > 1 && pos <= counter)
{
cout<<"Enter the value to be inserted : ";
cin>>value;
temp = create_node(value);
for (int i = 1; i < pos; i++)
{
ptr = s;
s = s->next;
}
ptr->next = temp;
temp->next = s;
cout<<temp->info<<" is inserted at position "<<pos<<endl;
}
else if (pos == counter+1)
{
cout<<"Enter the value to be inserted : ";
cin>>value;
temp = create_node(value);
while (s->next != NULL)
{
s = s->next;
}
temp->next = NULL;
s->next = temp;
cout<<temp->info<<" is inserted at last"<<endl;
}
else
{
cout<<"Positon out of range...!!!"<<endl;
}
}
}
void single_llist::delete_begin()
{
if (start == NULL){}
else
{
struct node *s, *ptr;
s = start;
start = s->next;
cout<<s->info<<" deleted from first"<<endl;
free(s);
}
}
void single_llist::delete_last()
{
int i, counter = 0;
struct node *s, *ptr;
if (start == NULL){}
else
{
s = start;
while (s != NULL)
{
s = s->next;
counter++;
}
s = start;
if (counter == 1)
{
start = s->next;
cout<<s->info<<" deleted from last"<<endl;
free(s);
}
else
{
for (i = 1;i < counter;i++)
{
ptr = s;
s = s->next;
}
ptr->next = s->next;
cout<<s->info<<" deleted from last"<<endl;
free(s);
}
}
}
void single_llist::delete_pos()
{
int pos, i, counter = 0, loc = 1;
struct node *s, *ptr;
s = start;
while (s != NULL)
{
s = s->next;
counter++;
}
if (counter == 0){}
else
{
if (counter == 1)
{
cout<<"Enter the postion [ SAY "<<loc<<" ] : ";
cin>>pos;
s = start;
if (pos == 1)
{
start = s->next;
cout<<s->info<<" deleted from first"<<endl;
free(s);
}
else
cout<<"Position out of range...!!!"<<endl;
}
else
{
cout<<"Enter the postion from "<<loc<<" to "<<counter<<" : ";
cin>>pos;
s = start;
if (pos == 1)
{
start = s->next;
cout<<s->info<<" deleted from first"<<endl;
free(s);
}
else if (pos > 1 && pos <= counter)
{
for (i = 1;i < pos;i++)
{
ptr = s;
s = s->next;
}
ptr->next = s->next;
if(pos == counter)
{cout<<s->info<<" deleted from last"<<endl;
free(s);}
else
{cout<<s->info<<" deleted from postion "<<pos<<endl;
free(s);}
}
else
cout<<"Position out of range...!!!"<<endl;
}
}
}
void single_llist::search()
{
int value, loc = 0, pos = 0, counter = 0;
struct node *s;
s = start;
while (s != NULL)
{
s = s->next;
counter++;
}
if (start == NULL){}
else
{
cout<<"Enter the value to be searched : ";
cin>>value;
struct node *s;
s = start;
while (s != NULL)
{
pos++;
if (s->info == value)
{
loc++;
if(loc == 1)
cout<<"Element "<<value<<" is found at position "<<pos;
else if(loc <= counter)
cout<<" , "<<pos;
}
s = s->next;
}
cout<<endl;
if (loc == 0)
cout<<"Element "<<value<<" not found in the list"<<endl;
}
}
void single_llist::display()
{
struct node *temp;
if (start == NULL)
cout<<"Linked list is empty...!!!"<<endl;
else
{
cout<<"Linked list contains : ";
temp = start;
while (temp != NULL)
{
cout<<temp->info<<" ";
temp = temp->next;
}
cout<<endl;
}
}
