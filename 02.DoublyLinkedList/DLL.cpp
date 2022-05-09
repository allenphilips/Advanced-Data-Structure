#include<iostream>
	
	using namespace std;
	struct node
	{
	struct node *prev;
	struct node *next;
	int data;
	};
	struct node *head;
	void insertion_beginning();
	void insertion_last();
	void insertion_specified();
	void deletion_beginning();
	void deletion_last();
	void deletion_specified();
	void display();
	void search();
	int main ()
	{
	int choice =0;
	while(choice != 9)
	{
	cout<<"\nChoose one option from the following list ...\n";
	cout<<"\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n";
	cout<<"\nEnter your choice?\n";
	cin>>choice;
	switch(choice)
	{
	case 1:
	insertion_beginning();
	break;
	case 2:
	insertion_last();
	break;
	case 3:
	insertion_specified();
	break;
	case 4:
	deletion_beginning();
	break;
	case 5:
	deletion_last();
	break;
	case 6:
	deletion_specified();
	break;
	case 7:
	search();
	break;
	case 8:
	display();
	break;
	case 9:
	exit(0);
	break;
	default:
	cout<<"Please enter valid choice..";
	}
	}
	}
	void insertion_beginning()
	{
	struct node *ptr;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
	cout<<"\nOVERFLOW";
	}
	else
	{
	cout<<"\nEnter Item value :";
	cin>>item;
	
	if(head==NULL)
	{
	ptr->next = NULL;
	ptr->prev=NULL;
	ptr->data=item;
	head=ptr;
	}
	else
	{
	ptr->data=item;
	ptr->prev=NULL;
	ptr->next = head;
	head->prev=ptr;
	head=ptr;
	}
	cout<<"\nNode inserted\n";
	}
	
	}
	void insertion_last()
	{
	struct node *ptr,*temp;
	int item;
	ptr = (struct node *) malloc(sizeof(struct node));
	if(ptr == NULL)
	{
	cout<<"\nOVERFLOW";
	}
	else
	{
	cout<<"\nEnter value :";
	cin>>item;
	ptr->data=item;
	if(head == NULL)
	{
	ptr->next = NULL;
	ptr->prev = NULL;
	head = ptr;
	}
	else
	{
	temp = head;
	while(temp->next!=NULL)
	{
	temp = temp->next;
	}
	temp->next = ptr;
	ptr ->prev=temp;
	ptr->next = NULL;
	}
	
	}
	cout<<"\nnode inserted\n";
	}
	void insertion_specified()
	{
	struct node *ptr,*temp;
	int item,loc,i;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
	cout<<"\n OVERFLOW";
	}
	else
	{
	temp=head;
	cout<<"Enter the location";
	cin>>loc;
	for(i=0;i<loc;i++)
	{
	temp = temp->next;
	if(temp == NULL)
	{
	cout<<"\n There are less than %d elements"<<loc;
	return;
	}
	}
	cout<<"Enter value";
	cin>>item;
	ptr->data = item;
	ptr->next = temp->next;
	ptr -> prev = temp;
	temp->next = ptr;
	temp->next->prev=ptr;
	cout<<"\nnode inserted\n";
	}
	}
	void deletion_beginning()
	{
	struct node *ptr;
	if(head == NULL)
	{
	cout<<"\n UNDERFLOW";
	}
	else if(head->next == NULL)
	{
	head = NULL;
	free(head);
	cout<<"\nnode deleted\n";
	}
	else
	{
	ptr = head;
	head = head -> next;
	head -> prev = NULL;
	free(ptr);
	cout<<"\nnode deleted\n";
	}
	
	}
	void deletion_last()
	{
			struct node *ptr;
			if(head == NULL)
			{
				cout<<"\n UNDERFLOW";
			}
			else if(head->next == NULL)
			{
					head = NULL;
					free(head);
					cout<<"\nnode deleted\n";
			}
			else
			{
		
				struct node	 *ptr = head;
			
				if(ptr->next != NULL)  
       			 {  
           			 ptr = ptr -> next; 
           			  
        		}  
       			 ptr -> prev -> next = NULL;   
       			 free(ptr);  
        		 cout<<"\nNode Deleted\n";  
		
			}
		
				/*struct node	 *ptr = head;
				//struct node	 *t;
				struct node	 *ptr2=ptr->next ;
					 while(ptr2->next!=NULL)
					 {
					 	ptr2=ptr2->next;
					 	ptr=ptr->next;
					 }
					//t = ptr2 -> prev;
					//if(ptr->next != NULL)
					//{
					//	ptr = ptr -> next;
					//}
					ptr2 -> prev = NULL;
					free(ptr2);
					cout<<"\nnode deleted\n";
				}*/
	}
	void deletion_specified()
	{
	struct node *ptr, *temp;
	int val;
	cout<<"\n Enter the data after which the node is to be deleted : ";
	cin>>val;
	ptr = head;
	while(ptr -> data != val)
	ptr = ptr -> next;
	if(ptr -> next == NULL)
	{
	cout<<"\nCan't delete\n";
	}
	else if(ptr -> next -> next == NULL)
	{
	ptr ->next = NULL;
	}
	else
	{
	temp = ptr -> next;
	ptr -> next = temp -> next;
	temp -> next -> prev = ptr;
	free(temp);
	cout<<"\nnode deleted\n";
	}
	}
	void display()
	{
	struct node *ptr;
	cout<<"\n printing values...\n";
	ptr = head;
	while(ptr != NULL)
	{
	cout<<ptr->data<<" ";
	ptr=ptr->next;
	}
	}
	void search()
	{
	struct node *ptr;
	int item,i=0,flag;
	ptr = head;
	if(ptr == NULL)
	{
	cout<<"\nEmpty List\n";
	}
	else
	{
	cout<<"\nEnter item which you want to search?\n";
	cin>>item;
	while (ptr!=NULL)
	{
	if(ptr->data == item)
	{
	cout<<"\nitem found at location  "<<i+1;
	flag=0;
	break;
	}
	else
	{
	flag=1;
	}
	i++;
	ptr = ptr -> next;
	}
	if(flag==1)
	{
	cout<<"\nItem not found\n";
	}
	}
	}