#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct entry{
    char website_name[30];
    char username[40];
    char password[30];
    struct entry* next;
}entry;

entry* head=NULL;
entry* make_entry(char* web,char* uname,char *pass)
{
    entry* temp = (entry*)malloc(sizeof(entry));
    temp->website_name=web;
    temp->username=uname;
    temp->password=pass;
    temp->next= NULL;
    return temp;
}

void add_entry(char* web,char* uname,char *pass)
{
    if(head==NULL)
    {
        head=make_entry(web,uname,pass);
        return;
    }
    entry* q = head;
    while(q->next!=NULL)
    {
        q= q->next;
    }
    q->next = make_entry(web,uname,pass);
}

int main()
{
  int running = 1;
  int choise;
  while(running)
    {
      printf("============================================\n");
      printf("Welcome to the username and password manager\n");
      printf("============================================\n");
      printf("Press 1 to make a new entry\n");
      printf("Press 2 to view all entries\n");
      printf("Press 3 to view entry by site name\n");
      printf("Press 4 to delete a entry\n");
      printf("Press 5 to exit \n");
      printf("============================================\n");
      scanf("%d",&choise);

      switch(choise)
      {
        case 1:
            entry* e1;
            e1 = (entry*)malloc(sizeof(entry));
            printf("Enter the website name : ");
            scanf("%s",e1->website_name);
            printf("Enter the username : ");
            scanf("%s",e1->username);
            printf("Enter the password : ");
            scanf("%s",e1->password);
            FILE* ptr = fopen("entries.txt","a");
            fprintf(ptr,"%s %s %s\n",e1->website_name,e1->username,e1->password);
            fclose(ptr);
            free(e1);
            break;
        case 2:
            FILE * ptr2 = fopen("entries.txt","r");
            char line[100];
            while(fgets(line,sizeof(line),ptr2))
            {
                printf("%s",line);
            }
            fclose(ptr2);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            running = 0;
            break;
        default:
            running = 0;
            break;
      }
      

    }
  
}
