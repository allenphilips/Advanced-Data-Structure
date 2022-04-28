#include<iostream>
using namespace std;
int s[10],d,n,set[10],count=0;
void display(int);
int flag = 0;
int main()
{
 int subset(int,int);
 int i;
  cout<<"ENTER THE NUMBER OF THE ELEMENTS IN THE SET : ";
 cin>>n;
 cout<<"ENTER THE SET OF VALUES : ";
 for(i=0;i<n;i++)
   cin>>s[i];
 cout<<"ENTER THE SUM : ";
 cin>>d;
 cout<<"THE PROGRAM OUTPUT IS: ";
 subset(0 , 0);
 if(flag == 0)
 cout<<"There is no solution";
 }
int subset(int sum,int i)
{
if(sum == d)
{
 flag = 1;
 display(count);
 return 0;
}
if(sum>d || i>=n)
return 1;
else
{
 set[count]=s[i];
 count++;
 subset(sum+s[i],i+1);
 count--;
 subset(sum,i+1);
}
}
void display(int count)
{
 int i;
 cout<<"\t{";
 for(i=0;i<count;i++)
 cout<<set[i];
 cout<<"}";
}