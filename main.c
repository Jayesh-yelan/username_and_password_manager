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
    strcpy(temp->website_name,web);
    strcpy(temp->username,uname);
    strcpy(temp->password,pass);
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

void search_and_print_by_sitename(char* web)
{
    entry* p= head;
    int found = 0;
    while(p!=NULL)
    {
        if(strstr(p->website_name,web))
        {
            printf("--------------------------------------------\n");
            printf("%s %s %s\n",p->website_name,p->username,p->password);
            printf("--------------------------------------------\n");
            found = 1;
        }
        p=p->next;
    }
    if(found==0)
    {
        printf("--------------------------------------------\n");
        printf("No match found\n");
        printf("--------------------------------------------\n");
    }
}
void free_list()
{
    while(head!=NULL)
    {
        entry* p = head;
        head = head->next;
        free(p);
    }
}

void del_entry(char * webname)
{
    while(head!=NULL && strcmp(head->website_name,webname)==0)
    {
        entry* r = head;
        head=head->next;
        free(r);
    }
    if(head == NULL)
    {
        return;
    }
    entry* t = head;
    if(t->next==NULL)
    {
        return;
    }
    
    entry* s = head->next;
    while(s!=NULL)
    {
        if(strcmp(s->website_name,webname)==0)
        {
            t->next = s->next;
            free(s);
            s=t->next;
        }
        else{
            t=s;
            s=s->next;
        }
    }
}
void clear_input_buffer()
{
    int c;
    while((c=getchar()) != '\n'&& c!= EOF);
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
      clear_input_buffer();
      switch(choise)
      {
        case 1:
            char f[30];
            char g[40];
            char h[30];
            printf("Enter the website name : ");
            fgets(f,30,stdin);
            f[strcspn(f, "\n")] = '\0';
            printf("Enter the username : ");
            fgets(g,40,stdin);
            g[strcspn(g, "\n")] = '\0';
            printf("Enter the password : ");
            fgets(h,30,stdin);
            h[strcspn(h, "\n")] = '\0';
            FILE* ptr = fopen("entries.txt","a");
            fprintf(ptr,"%s %s %s\n",f,g,h);
            fclose(ptr);
            
            break;
        case 2:
            FILE * ptr2 = fopen("entries.txt","r");
            char line[100];
            while(fgets(line,sizeof(line),ptr2))
            {
                printf("--------------------------------------------\n");
                printf("%s",line);
                printf("--------------------------------------------\n");
            }
            fclose(ptr2);
            break;
        case 3:
            char web[30];
            printf("Enter the website name you want the username and password : ");
            scanf(" %s",web);
            FILE * ptr3 = fopen("entries.txt","r");
            char line1[100];
            char a[30];
            char b[40];
            char c[30];
            
            while(fgets(line1,sizeof(line1),ptr3))
            {
                line1[strcspn(line1, "\n")] = '\0';
                sscanf(line1,"%s %s %s",a,b,c);
                add_entry(a,b,c);
            }
            fclose(ptr3);
            search_and_print_by_sitename(web);
            free_list();
            break;
        case 4:
            char web_del[30];
            printf("Enter the website name you want to delete the entry : ");
            scanf(" %s",web_del);
            FILE * ptr4 = fopen("entries.txt","r");
            char line2[100];
            char d[30];
            char e[40];
            char f[30];

            while (fgets(line2,sizeof(line2),ptr4))     
            {
                line2[strcspn(line2, "\n")] = '\0';
                sscanf(line2,"%s %s %s",d,e,f);
                add_entry(d,e,f);
            }
            fclose(ptr4);
            del_entry(web_del);
            ptr4 = fopen("entries.txt","w");
            entry* u = head;
            while(u!=NULL)
            {
                fprintf(ptr4,"%s %s %s\n",u->website_name,u->username,u->password);
                u=u->next;
            }
            free_list();
            fclose(ptr4);

            
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
