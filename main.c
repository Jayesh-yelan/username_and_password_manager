#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
      printf("Press 4 to delete a entry\n);
      printf("Press 5 to exit \n);
      printf("============================================\n");
      scanf("%d",&choise);

      switch(choise)
      {
        case 1:
          break;
        case 2:
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
