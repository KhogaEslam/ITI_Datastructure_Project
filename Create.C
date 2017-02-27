#include <stdio.h>
#include<STDLIB.h>
#include<conio.h>
#include<string.h>

void create_name(char* name);

int create_detail(char* name,char* detail);


int main()
{
      char detail[]={"id,int,2\nname,varchar(10),10\ntel,varchar(10),10"};

     int c;

     //char  name[80]={'s','t','u','d','e','n','t','d','t','a','i','l','s','\0'};
     char  name[]={"student\0"};

     if(createTable(name))
     {
	 create_name(name);
	c=create_detail(name,detail);
    }
    else
    {
      //table exists
    }


getch();
return 0;
}

int createTable(char* name)
{
   int retVal = 1;

   FILE* fptr;
   char line[100];

   fptr = fopen("DATABASE.TXT","a+");
   if(fptr)
   {
   strcat(name,"\n");
   while(!feof(fptr) && retVal)
   {
	fgets(line,100,fptr);
	if(!strcmp(line,name))
	{
	 retVal = 0;
	}

   }
   if(retVal)
   {
	fprintf(fptr,"%s",name);
   }
   fclose(fptr);
   }

   return retVal;
}

void create_name(char* name)
{
   FILE *fptr;

 // char txt_n[100];
  char userfile[255];


   sprintf(userfile,"%s.txt", name);

   fptr=fopen(userfile,"w");

  // fprintf(fptr, "%d", 100);

   if(!fptr)
   {

    printf("couldn't open this file");


   }
   else
   {
       printf("done ");

   }
    fclose(fptr);

   // return 0;
}

int create_detail(char* name,char* detail)
{

      FILE *fptr;
      int retval=1;

 // char txt_n[100];
  char userfile[255];
   int i, j,k;



   sprintf(userfile,"%s_.txt", name);

   fptr=fopen(userfile,"w");


  // fprintf(fptr, "%d", 100);

   if(!fptr)
   {

    printf("couldn't open this file");


   }
   else
	  {
	  //for(i=0;i<strlen(detail);i++)
   {

       fprintf(fptr,"%s",detail);
     fprintf(fptr,"\n");

   }

       printf("\nfile details done ");

	  }
    fclose(fptr);



  return retval;
}
