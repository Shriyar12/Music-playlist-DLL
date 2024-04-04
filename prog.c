#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int count = 0;
struct node
{
	struct node *prev;
	int dur;
	char sngnm[20], mvnm[10];
	struct node *next;
}*h, *temp, *temp1, *temp2, *temp4;

void create()
{
	int dur;
	char sngnm[20], mvnm[10];
	temp = (struct node *)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("Enter song name, movie name and duration :\n");
	scanf("%s%s%d",&sngnm,&mvnm,&dur);
	strcpy(temp->sngnm, sngnm);
	strcpy(temp->mvnm, mvnm);
	temp->dur = dur;
	count++;
}
void insertbeg()
{
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}
	else
	{
		create();
		temp->next = h;
		h->prev = temp;
		h = temp;
	}
}
void insertend()
{
	if (h == NULL)
	{
		create();
		h = temp;
		temp1 = h;
	}
	else
	{
		create();
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
}
void displaybeg()
{
	temp2 = h;
	if (temp2 == NULL)
	{
		printf("List empty to display \n");
		return;
	}
	while (temp2 != NULL)
	{
    printf("------------------------------------------------------------\n");
		printf("song name: %s\nmovie name:%n\nduration:%d minutes\n", temp2->sngnm, temp2->mvnm,temp2->dur);
    printf("------------------------------------------------------------\n");
		temp2 = temp2->next;
	}
	printf(" No of employees = %d ", count);
}
int deleteend()
{
	struct node *temp;
	temp = h;
	if (temp->next == NULL)
	{
		free(temp);
		h = NULL;
		return 0;
	}
	else
	{
		temp2 = temp1->prev;
		temp2->next = NULL;
		printf("%s %s %d\n\n", temp2->sngnm, temp2->mvnm,temp2->dur);
		temp2 = temp2->next;
		free(temp1);
	}
	count--;
	return 0;
}
int deletebeg()
{
	struct node *temp;
	temp = h;
	if (temp->next == NULL)
	{
		free(temp);
		h = NULL;
	}
	else
	{
		h = h->next;
		printf("%s %s %d\n\n", temp2->sngnm, temp2->mvnm,temp2->dur);
		temp2 = temp2->next;
		free(temp);
	}
	count--;
	return 0;
}
int main()
{
	int ch, n, i;
	h = NULL;
	temp = temp1 = NULL;
	printf("-----------------MENU--------------------\n");
	printf("\n 1 - Create a song of n emp");
	printf("\n 2 - Display from beginning");
	printf("\n 3 - Insert at end");
	printf("\n 4 - delete at end");
	printf("\n 5 - Insert at beg");
	printf("\n 6 - delete at beg");
	printf("\n 7 - exit\n");
	printf("------------------------------------------\n");
	while (1)
	{
		printf("\n Enter choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:printf("\n Enter no of songs to be added: ");
			scanf("%d", &n);
			for (i = 0; i<n; i++)
				insertend();
			break;
		case 2:displaybeg();
			break;
		case 3:insertend();
			break;
		case 4:deleteend();
			break;
		case 5:insertbeg();
			break;
		case 6:deletebeg();
			break;
		case 7: 	exit(1);
		default: printf("wrong choice\n");
		}
	}
}