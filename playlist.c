#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char playlst[100];
  char songnm[100];
  char moviename[100];
  int duration;
	struct node *prev,*prevp;
	struct node *next,*nextp;
};
struct node *head,*headp;
void addtolink()
{
  char sname[100],mvnm[100];
  int dur,count;
  head=0;
  printf("Enter songname,movie name and song duration in minutes\n");
  scanf("%s%s%d",&sname,&mvnm,&dur);
  
	struct node *newnode,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
  strcpy(newnode->songnm,sname);
  strcpy(newnode->moviename,mvnm);
  newnode->duration=dur;
  newnode->next=NULL;
  newnode->prev=NULL;
	if(head==NULL) 
	{
		head=newnode;
    temp=head;
  }
	else // Linking at the end.
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=newnode;
		newnode->prev=temp;
	}
}
void display()
{
	struct node * temp;
	int i=1;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%d.) %s\n%s\n%d\n",i,temp->songnm,temp->moviename,temp->duration);
		i++;
	}
}
int main()
{
  int ch;
  while(1)
  {
    printf("enter choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:addtolink();
      break;
      case 2:display();
      break;
    }
  }
}