#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
	char playlist[100];
	char songname[100];
	struct node *prev,*prevp;
	struct node *next,*nextp;
};
struct node *head,*headp;
int empty()
{
	if (head==NULL)
	return 1;
	else
	return 0;	
}
void addtolink(char x[])
{
	struct node *np,*temp;
	np=(struct node *)malloc(sizeof(struct node ));
	strcpy(np->songname,x);
	np->next=NULL;
	np->prev=NULL;
	if(empty()) 
	{
		head=np;
	
	}
	else // Linking at the end.
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=np;
		np->prev=temp;
	}
	
}

void writefile()
{
	char song[50];
	printf("\nEnter Song Name:- ");
	scanf("%s",song);
	addtolink(song);
	FILE *filePointer ; 
	filePointer = fopen("ALLSONGS.txt", "a") ; 
    if ( filePointer == NULL ) 
    { 
        printf( "\nFailed to open." ) ; 
    } 
    else
    { 
    	fprintf(filePointer,"\n");
        if ( strlen (song) > 0 ) 
        { 	
        	fputs(song, filePointer) ;    
            fputs("\n", filePointer) ; 
        } 
        
        fclose(filePointer) ; 
    } 	
}
void Readfile()
{
	FILE *filePointer ; 
    char dataToBeRead[50]; 
 	int cnt=0;
    filePointer = fopen("ALLSONGS.txt", "r") ; 
 
    if ( filePointer == NULL ) 
    { 
        printf( "\nFile failed to open." ) ; 
    } 
    else
    { 
        printf("\n__________________SONGSLIST_________________\n");

        while( fgets ( dataToBeRead, 50, filePointer ) != NULL ) 
        { 
        	addtolink(dataToBeRead);
			//printf( "%s" , dataToBeRead ) ; 
        } 
          
        fclose(filePointer) ; 
        }
}

void display()
{
	struct node * temp;
	int i=1;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		
		printf("\t%d %s",i,temp->songname);
		i++;
	}
	
}

/*void play()
{
	//char songname[100];
	//printf("\n Enter Song Name ");
	//scanf("%s",&songname);
	struct node * temp;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		
		printf("\t %s",temp->songname);
	printf("\n Playing Song....  ");	
	}
	
	
}*/
/*void playsong()
{
	int choice;
	
	do
	{
		printf("\n Enter Your Choice \n1.Play \n2.Stop \n3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	play();
					break;
			case 2:printf("\n !!Stoped Song   ");
					stop();
					break;
				
		}
	}while(choice!=3);
}
*/
void readplaylistsongs(char x[])
{
FILE *filePointer ; 
    char dataToBeRead[50]; 
 	int cnt=0;
    filePointer = fopen(x, "r") ; 
 
    if ( filePointer == NULL ) 
    { 
        printf( "\nFile failed to open." ) ; 
    } 
    else
    { 
        printf("\n__________________SONGSLIST_________________\n");

        while( fgets ( dataToBeRead, 50, filePointer ) != NULL ) 
        { 
        	addtolink(dataToBeRead);
			    printf("%s\n",dataToBeRead ) ; 
        } 
        
        fclose(filePointer) ; 
        }
}
int validateplaylist(char x[])
{
	struct node * temp;
	for(temp=headp;temp!=NULL;temp=temp->next)
	{
		
		if(strcmp(x,temp->playlist)==0)
			return 0;
		else
			return 1;
	}
}
void delete1()
{

struct node	*current = head;  
struct node *next;  
  
while (current != NULL)  
{  
    next = current->next;  
    free(current);  
    current = next;  
}  
}
void writetoplaylist(char x[],char y[])
{
	FILE *filePointer ; 
	//addtolinkplaylist(y);
	filePointer = fopen(x, "a") ; 
    if ( filePointer == NULL ) 
    { 
        printf( "\nFailed to open." ) ; 
    } 
    else
    { 	
        if ( strlen (y) > 0 ) 
        { 
            fputs(y, filePointer) ;    
            fputs("\n", filePointer) ; 
        } 
        
        fclose(filePointer) ; 
    } 	
}
int emptyplaylist()
{
	if (headp==NULL)
	return 1;
	else
	return 0;	
}
void addtolinkplaylist(char x[])
{
	struct node *np,*temp;
	
	np=(struct node *)malloc(sizeof(struct node ));
	strcpy(np->playlist,x);
	np->nextp=NULL;
	np->prevp=NULL;
	if(emptyplaylist()) 
	{
		headp=np;
	
	}
	else // Linking at the end.
	{
		for(temp=headp;temp->nextp!=NULL;temp=temp->nextp);
		temp->nextp=np;
		np->prevp=temp;
	}
	
}

void ReadPlaylist()
{
	FILE *fp;
	char ALLplaylist[50];
	int cnt=0;	
	
    fp = fopen("ALLPLAYLISTS.txt", "r") ; 
 
    if ( fp == NULL ) 
    { 
        printf( "\nFile failed to open." ) ; 
    } 
    else
    { 
        while( fgets ( ALLplaylist, 50, fp ) != NULL ) 
        { 
          
		  	if(cnt==0)
        	{
		   	addtolinkplaylist(ALLplaylist);
			
			}
			else
			{
        	int flag=validateplaylist(ALLplaylist);
        	if(flag==1)
		   		addtolinkplaylist(ALLplaylist);
			} 
        }  
         cnt++;
        fclose(fp) ; 
    }
}

void Displayplaylist()
{
	struct node * temp;
	int i=1;
	int ch;
	char play[50];
	for(temp=headp;temp!=NULL;temp=temp->nextp)
	{
		
		printf("\t%d %s",i,temp->playlist);
		i++;
	}
	do
	{
		
		printf("\n_____Enter Choice_____");
		printf("\n1.Open Playlist\n2.BACK\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter Playlist Name:-");
					scanf("%s",play);
					//delete1();
					readplaylistsongs(play);
					display();
					break;
		}
	}while(ch!=2);
}
void createplaylist()
{
	FILE *fp;
	char playlistname[50],song[50],ch;
	char ALLplaylist[50]="ALLPLAYLISTS.txt";
	int choice;
	printf("Enter Playlist Name\n");
	scanf("%s",playlistname);
	
	fp = fopen (playlistname, "w");
	if(fp==NULL)
		printf("\nFailed To Create File");
	else
		printf("\nPlaylist Created Sucessfully");
	
	fclose(fp);
	addtolinkplaylist(playlistname);
	writetoplaylist(ALLplaylist,playlistname);
	
	
	printf("\nADD SONGS TO %s",playlistname);
	display();
	do
	{
		printf("\n Enter Choice 1.Add Song \t 2.Stop :-\n ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("\nEnter Songs Name:-");
				scanf("%s",song);
				writetoplaylist(playlistname,song);
				break;
		case 2:printf("STOP");
		}
	}while(choice!=2);	
}
void playlist()
{
	int choice;
	ReadPlaylist();
	do	
	{
		
		printf("\n.1.Make A Playlist.\n2.Show All Playlist.\n3.HOME\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:createplaylist();
				break;
			case 2:Displayplaylist();
				break;
			case 3:
				break;
			default:printf("!!!--Invalid Option--!!!");
			
		}
	}while(choice!=3);
}
char *ltrim(char *s) 
{     
    while(isspace(*s)) s++;     
    return s; 
}  

char *rtrim(char *s) 
{     
    char* back;
    int len = strlen(s);

    if(len == 0)
        return(s); 

    back = s + len;     
    while(isspace(*--back));     
    *(back+1) = '\0';     
    return s; 
}  

char *trim(char *s) 
{     
    return rtrim(ltrim(s));  
} 
void playasong(char x[])
{
	struct node * temp;
	char y[50];
	int flag=0;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		strcpy(y,temp->songname);
		trim(y);
		if(strcmp(x,y)==0)
		{
			printf("\n Found:-");
			printf("%s",temp->songname);
			printf("\n cuurently playing %s song....",temp->songname);
			    Beep(1000,500);
    			Beep(950,500);
   				Beep(825,500);
   				Beep(750,500);
    			Beep(314,500);
    			Beep(350,500);
    			Beep(390,500);
    			Beep(467,500);
    			Beep(526,500);
    			Beep(624,500);
    			Beep(250,500); 
			flag++;
			break;
		}
		
	}
	if(flag==0)
		printf("Song Not Found");
}
void search(char x[])
{
	struct node * temp;
	char y[50];
	int flag=0;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		strcpy(y,temp->songname);
		trim(y);
		if(strcmp(x,y)==0)
		{
			printf("\n Found song:-");
			printf("\n %s",temp->songname);
			flag++;
			break;
		}
		
	}
	if(flag==0)
		printf("Song Not Found");
}
int main()
{
	int choice,flag=0;
	char song[50];
	Readfile();
	do
	{	
		printf("\n___MUSIC PLAYER___\n");
		printf("1.All Songs List.\n2.PLAYLIST.\n3.Search Song.\n4.Add New Song.\n5.Play song\n6.Exit\n");
		scanf("%d",&choice);
		
		
		switch(choice)
		{
			case 1:
					display();
				break;
			case 2:playlist();
				break;
			case 3:printf("\nSEARCH -- Enter Song name:- ");
					scanf("%s",&song);
					search(song);
				break;
			case 4:writefile();
				break;
			case 5:printf("\nSEARCH Enter Song name to e played:-");
					scanf("%s",&song);
					playasong(song);
				break;
			case 6:exit(0);
			default:printf("!! --INVALID CHOICE-- !!\n");
				break;
		}
	}while(choice!=5);
return 0;	
}
