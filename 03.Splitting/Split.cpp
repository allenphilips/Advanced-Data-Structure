#include<iostream>
using namespace std;
struct Node{
int value;
struct Node *next;
};
struct Node* head = NULL;
struct Node* sHead = NULL;
struct Node* temp = NULL;
void insert(int new_data){
struct Node* new_node = new Node(); //(struct Node*)malloc(sizeof(struct Node));
new_node->value = new_data;
new_node->next = head;
head = new_node;
}
int n;
int ele;
int splitIndex;
int main(){
int i;
cout<<"Enter number of elements you want in the list\t";
cin>>n;
cout<<"Enter elements :" <<endl;
for(i=0;i<n;i++){
cin>>ele;
insert(ele);
}
cout<<"\nList of elements : "<<endl;
Node *t;
t = head;
while(t != NULL){
cout<<t->value<<"\t";
t = t->next;
}
cout<<"\n\nEnter the position you want the list to split ";
cin>>splitIndex;
while(splitIndex < 0 || splitIndex > n-1){
cout<<"Invalid position. Try again."<<endl;
cin>>splitIndex;
}
temp = head;
for(i=0;i<=splitIndex;i++){
if(i==splitIndex-1){
Node *tN;
tN = temp->next;
sHead = tN;
temp->next = NULL;
break;
}
temp = temp->next;
}
temp = head;
if(temp == NULL){
cout<<"\nFirst list is empty"<<endl;
}else{
cout<<"\n\nFirst list element "<<endl;
while(temp != NULL){
cout<<temp->value<<"\t";
temp = temp->next;
}
}
temp = sHead;
if(temp == NULL){
cout<<"\nSecond list is empty"<<endl;
}else{
cout<<"\n\nSecond list elements "<<endl;
while(temp != NULL){
cout<<temp->value<<"\t";
temp = temp->next;
}
}
return 0;
}