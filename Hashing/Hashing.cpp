#include<iostream>
#include<limits.h>

using namespace std;
void Insert(int ary[],int hFn, int Size){
int element,pos,n=0;

cout<<"Enter key element to insert\n";
cin>>element;

pos = element%hFn;
while(ary[pos]!= INT_MIN) {
if(ary[pos]== INT_MAX)
break;
pos = (pos+1)%hFn;
n++;
if(n==Size)
break;
}
if(n==Size)
cout<<"Hash table was full of elements\nNo Place to insert this element\n\n";
else
ary[pos] = element;
}
void display(int ary[],int Size){
int i;
cout<<"Index\tValue\n";

for(i=0;i<Size;i++)
cout<<i<<"\t"<<ary[i]<<"\n";
}
int main(){
int Size,hFn,i,choice;
cout<<"Enter size of hash table\n";
cin>>Size;
hFn=Size;
int ary[Size];
for(i=0;i<Size;i++)
ary[i]=INT_MIN;
do{
cout<<"Enter your choice\n";
cout<<" 1-> Insert\n 2-> Display\n 0-> Exit\n";
cin>>choice;
switch(choice){
case 1:
Insert(ary,hFn,Size);
break;
case 2:
display(ary,Size);
break;
default:
cout<<"Enter correct choice\n";
break;
}
}while(choice);
return 0;
}