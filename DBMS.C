/*
About The Code:
*			Description
*			a simulation project for a database engine doing the following functionality:
*			create table, insert into table all values of one record, 
*			select from certain table all values, 
*			update records where certain condition
*			delete from certain table where certain condition through parsing user query to get the required values for processing the previous 
*			mentioned functionalities. 
*			using the text editor in parsing the query from entered from the user.
*			depending on the SQL function entered in the user query, the program dynamically decide the suitable processing.
*/
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<alloc.h>

/*
Function Description:


Input:

Output:

*/
char* textEditor(void);

/*
Function Description:
Delete Record

------------
Declaration
------------
int deleteRecord(char* tableName, char* val, char* colName); 		

Return value 
-------------
on sucsess:
	DeleteRecord return the result value as int.

Example:
delete from students where name=sName;
	=======================================================

*/
int deleteRecord(char* tableName, char* colVal, char* colName);

/*
Function Description:
create_name					
create_detail					

-------------
Declaration
-------------
int create_name(char*name);
int create_detail(char*name,char*detail);
int createTable(char* tblName);
int createAndInsertTable(char* tblName, char* tblDetail);

Return value
--------------
on sucsess:
	create_name return the value as int.
	create_detail return the value as int.

Example:
create table students (id ,name);	
		==============================================

*/
int create_name(char* tblName,  char* tblDetail);

int create_detail(char* tblName,char* tblDetail);

int createTable(char* tblName);

int createAndInsertTable(char* tblName, char* tblDetail);

/*
Function Description:

Insert All columns	in one record			

------------
Declaration
------------
int InsertAllColumns(char * TableName , int TableNameSize , char * Values , int ValuesSize);
 
Return value 
-------------
on sucsess:
	InsertAllcolunms return the result value as int.
Example:
insert into students values(1, studentName);
		===========================================

*/
int InsertAllColumns(char * tableName , char * Values);

/*
Function Description:

select All

-----------
Declaration
-----------
char * selectall(char* table);

Return value 
-------------
on sucsess:
	selectall returns a pointr to string of selected data.
Example:
select * from students;
		===============================================
*/
char* selectAll(char* table);

/*
Function Description:

Update Record

------------
Declaration
------------
int updateRecord(char* tableName, char* colName, char* colVal, char* condCol,char* condVal);

Return value 
-------------
on sucsess:
	updateRecord return the value as int.
Example:
update students set name= SName where name=sNewName;
		=============================================
*/
int updateRecord(char* tableName, char* colName, char* colVal, char* condCol,char* condVal);

/*
Function Description:
Parse Query

===========
Declararion
===========
int parsequery(char*userquery);

Return value 
------------
on sucsess:
	Parse Query return the result values as and handels sql functions.
	=====================================================

*/
int parseQuery(char* userQuery);

/*
Function Description:
Open Help

===========
Declararion
===========
void openHelp();

opens help index for user.

Return value 
------------
on sucsess:
	VOID : Just displays the help window.
	=====================================================
*/
void openHelp();

/*
Function Description:
Results Handeler

===========
Declararion
===========
void resultHandeler(int res);

Handels Result Cases of All Functions

Return value 
------------
on sucsess:
	VOID : Just displays the Resulte Message on screen.
	=====================================================

*/
void resultHandeler(int res);


void resultHandeler(int res)
{
	char option;
	clrscr();
	switch(res)
	{
		case 11:
		{			
			printf("Sorry! Couldn't craete table!\n");			
			getch();
			
			break;
		}
		case 12:
		{
			printf("Table created successfully!\n");
			printf("done! %c %c %c\n",1, 2,3);			
			getch();
			
			break;
		}
		case 13:
		{
			printf("Table already exists!\n");	
			break;
		}
		case 21:
		{
			printf("Data Inserted Correctly\n");
			printf("done! %c %c %c\n",1, 2,3);
			break;
		}
		case 22:
		{
			printf("Sorry! Couldn't Insert Data!\n");
			break;
		}
		case 31:
		{
			printf("Found What you searched for ?\n");
			printf("done! %c %c %c\n",1, 2,3);
			break;
		}
		case 32:
		{
			printf("No Data Found!\n");
			break;
		}
		case 41:
		{
			printf("Updated Successfully!\n");
			printf("done! %c %c %c\n",1, 2,3);
			break;
		}
		case 42:
		{
			printf("Record To Update Not Found!\n");
			break;
		}
		case 43:
		{
			printf("Table Not Found!\n");
			break;
		}
		case 51:
		{
			printf("Deleted Successfully!\n");
			printf("done! %c %c %c\n",1, 2,3);
			break;
		}
		case 52:
		{
			printf("Record To Delete Not Found!\n");
			break;
		}
		case 53:
		{
			printf("Table is Empty!\n");
			break;
		}
		case 54:
		{
			printf("Couldn't Open File!\n");
			break;
		}
		case 61:
		{
			printf("Syntax Error!");
			break;
		}
		
		default:
		{					
			
		}
	}
}

/*The Code*/

void openHelp()
{
	FILE *fHelp = NULL;
	char line[81] = {0};
	char ch;
	clrscr();
	
	clrscr();
	
	printf("Welcome to DBMS Help %c Page %c %c\n",3,1,2);
	
	fHelp = fopen("Help.txt","r");
	
	if(fHelp)
	{
		while(!feof(fHelp))
		{
			fgets(line,81,fHelp);
			printf("%s",line);
		}
	}
	printf("You can press ESC to Exit Help Page\n");
	ch = getch();
	if(ch == 27)
	{
		printf("Do You Want to Query Any thing else \? \(Y/N\)\?\n");
		ch = getch();
		if(ch == 'n' || ch == 'N')
			exit(0);
	}
}

int parseQuery(char* userQuery)
{
    char *line = NULL;
    char *sqlfn = NULL;	//sqlfunction
    char *tableName = NULL;
    char *tableCols = NULL;	//userinput table columns

    int res = 0, x=0, i, lineCounter =0, marker = 0;
	
    char *usertemp=NULL;
    char *wheretmp=NULL;
    char *colName=NULL;    //for delete fn
    char *colValue=NULL;
    char *whereColName=NULL;    //for update fn
    char *whereColValue=NULL;
	
    char *ptr=NULL;
    free(usertemp);
    usertemp = (char*) malloc(strlen(userQuery)*sizeof(char) + 1);
    memset(usertemp,0,sizeof(usertemp));
    strcpy(usertemp,userQuery);
    sqlfn=strtok(usertemp," ");   //function
	//cases 1-create 2-insert 3-selete 4-update 5-delete
    if(!strcmp(sqlfn,"create"))
    {
		x = 1;
		tableName=strtok(NULL," () ");        //tableName
		tableName=strtok(NULL," () ");       //for parsing create
		tableCols=strtok(NULL,"()");		//for all columns
		res = createAndInsertTable(tableName, tableCols);
		if(res == 1)
		{
			//printf("couldn't craete table!");
			res = 11;
		}
		else if(res == 2)
		{
			//printf("Table created successfully %c %c %c",1,2,3);
			res = 12;
		}
		else
		{
			//printf("table already exists!");
			res = 13;
		}
    }
    else if(!strcmp(sqlfn,"insert"))
    {
		x = 2;
		tableName=strtok(NULL," () ");
		tableName=strtok(NULL," () ");
		tableCols= strtok(NULL," () ");
		//tableCols=strtok(NULL," () ");
		
		res = InsertAllColumns(tableName ,tableCols);
		if(res)
		{
			//printf("Inserted");
			res = 21;
		}
		else
		{
			res = 22;
		}
    }
	else if(!strcmp(sqlfn,"select"))
    {
		x = 3;
		tableName=strtok(NULL," ");        //tableName
		tableName=strtok(NULL," ");
        tableName=strtok(NULL," ;");
		
		ptr = selectAll(tableName);
		  if (ptr)
		  {
			clrscr();
			printf("\nAll Data found in table %s is :\n");
			//line = strtok(ptr,"\n");
			printf("Columns:\n");
			//printf("%s\n",line);
			
			for(i = 0 ; i< strlen(ptr) ; i++)
			{
				if(ptr[i] == '\n') 
					lineCounter++;
				
				if(lineCounter == 0)
                    printf("%c",ptr[i]);
			}
			printf("\n");
			for(i = 0 ; i< strlen(ptr) && marker == 0 ; i++)
			{
				if(ptr[i] == '\n') 
					marker++;							
			}
			
			lineCounter--;
			printf("Found %d Rows of Data:\n",lineCounter);
			for(i ; i< strlen(ptr) ; i++)
			{
				if(lineCounter > 0)
                    printf("%c",ptr[i]);
			}						
			//printf("%s\n",ptr);
			//puts(ptr);
			getch();
			free(ptr);
			res = 31;
		  }
		  else
		  {				
				//printf("Table Not Found or Empty!");
				res = 32;
		  }
    }
	else if(!strcmp(sqlfn,"update"))
    {
		x = 4;
		tableName=strtok(NULL," = ");        //tableName
		colName=strtok(NULL," = ");
		colName=strtok(NULL," = ");		   // for parsing update
		colValue=strtok(NULL," = ");
		whereColName = strtok(NULL," = ");
		whereColName = strtok(NULL," = ");
		whereColValue = strtok(NULL," = ;");
		
		res = updateRecord(tableName, colName, colValue, whereColName, whereColValue);

		if(res == 2)
		{
			//printf("Updated !");
			res = 41;
		}
		else if(res == 1)
		{
			//printf("Record Not Found!");
			res = 42;
		}
		else
		{
			//printf("Couldn't Open File!");
			res = 43;
		}
    }
    else if(!strcmp(sqlfn,"delete"))
    {
		x = 5;
		tableName=strtok(NULL," = ");        //tableName
		tableName=strtok(NULL," = ");
		colName=strtok(NULL," = ");
		colName=strtok(NULL," ");		   // for parsing delete
		colValue=strtok(NULL," = ;");
		
		res = deleteRecord(tableName, colValue, colName);

		if(res == 3)
		{
			//printf("Deleted !");
			res = 51;
		}
		else if(res == 2)
		{
			//printf("Record Not Found!");
			res = 52;
		}
		else if(res == 1)
		{
			//printf("No Data Found");
			res = 53;
		}
		else
		{
			//printf("Couldn't Open File!");
			res = 54;
		}
    }
	else
	{
		x = 0;
		res = 61;
	}
	
	return res;
}

int updateRecord(char* tableName, char* colName, char* colVal, char* condCol,char* condVal)
{
	int retVal = 0;

	FILE* pFile=NULL;

	char line[81] = {0};
	char updatedLine[81]={0};

	char* buffer=NULL;
	char* ptr=NULL;
	char* loc=NULL;

	int i=0, j=0, k=0, pos;
	int countComma = 0, commaTN=0, counter=0;
	int cKeep=0;
	int cc = 0;

	//buffer = ptr = loc = NULL;

	 char userFile[8] = {0};

	buffer = (char*) malloc(1000 * sizeof(char));
	memset(buffer, 0 , 1000 * sizeof(char));

	ptr = buffer;
	
	sprintf(userFile,"%s.txt", tableName);
	
	//open file
	pFile = fopen(userFile,"r");

	if(pFile)
	{

		if(!feof(pFile)&&fgets(line, 81, pFile))
		//reading first line - record attributes
		{
			//put line in buffer
			strcpy(ptr, line);
			ptr += strlen(line);

			for(i ; i<strlen(line) ; i++)
			{
				if(line[i] == ',')
				commaTN++;
			}

			i = 0;

			loc = strstr(line,colName);
		}
		if(loc)
		{
			pos = loc - line;
			cKeep = 0;
			for(i= pos ; i>=0 ; i--)
				if(line[i] == ',')
					cKeep++;
			retVal = 1; 
			while(!feof(pFile))
			{
				counter =  cKeep;
				countComma = cKeep;				
				i = 0;

				fgets(line, 81, pFile);
				if(strstr(line,condVal))
				{
					if(countComma == commaTN)
					{
						for(i ; countComma ; i++)
						{
							updatedLine[i] = line[i];
							if(line[i] == ',')
							countComma--;
						}
						j = i + strlen(colVal);
						
						for(i ; i<j ; i++)
						{
							 updatedLine[i] = colVal[k];
							 k++;
						}					
					}
					else if(countComma>0)
					{						
						i=0;
						for(i ; countComma ; i++)
						{//Copy First parts
							updatedLine[i] = line[i];
							if(line[i] == ',')
								countComma--;
						}					
						j=0;
						for(i ; j<strlen(colVal) ; i++)
						{//copy new value
							updatedLine[i] = colVal[j];
							j++;
						}
						if(counter < commaTN)
						{//if there is still parts to copy
							updatedLine[i++] = ',';
							for(k = 0; counter+1; k++)
							{
								if(line[k] == ',')
								counter--;
							}
							line[strlen(line)+1] = 0;
							for(k ; line[k] ; k++)
							{
								updatedLine[i] = line[k];
								i++;
							}
						}
						retVal = 2; 
					}
					else
					{//No commas (first part to update)
						i = 0;
						retVal = 2;
						while(line[i] != ',' )
							i++;
						cc = 0;
						
						for(cc = 0; cc< strlen(colVal) ; cc++)
							updatedLine[cc] = colVal[cc];
						//updatedLine[cc++] = ',';
						line[strlen(line)+1] = 0;
						
						for(i ; line[i] ; i++)
						{
							updatedLine[cc] = line[i];
							cc++;
						}	
						//updatedLine[cc++] = '\n';
						//updatedLine[cc++] = 0;
					}
					//put line in buffer
					strcpy(ptr, updatedLine);
					ptr += strlen(updatedLine);
					/*strcpy(ptr,"\n");
					ptr+=1;*/	
					retVal = 2; 					
				}
				else
				{
					//put line in buffer
					strcpy(ptr, line);
					ptr += strlen(line);		
				}			
				strcpy(line,NULL);
				strcpy(updatedLine,NULL);
			}
		}
		loc = NULL;

		if(pFile) fclose(pFile);

		strcpy(userFile,NULL);
                sprintf(userFile,"%s.txt",tableName);

		pFile = fopen(userFile,"w");

		if(pFile)
		{
			fprintf(pFile, "%s", buffer);
		}
		if(pFile) fclose(pFile);

		//free(ptr);
		free(buffer);
	}
	
	return retVal;
}

char * selectAll(char* tableName)
{
	char* ptr = NULL;
	char* line[81] = {0};
	int string_size;

	FILE *fptr=NULL;
	
	char userFile[8] = {0};
	
	sprintf(userFile,"%s.txt", tableName);

	fptr = fopen(userFile,"r");
	if(fptr)
	{		
	   // Seek the last byte of the file
	   fseek(fptr, 0, SEEK_END);
	   // Offset from the first to the last byte, or in other words, filesize
	   string_size = ftell(fptr);
	   // go back to the start of the file
	   rewind(fptr);

	   // Allocate a string that can hold it all
	   ptr = (char*) malloc(sizeof(char) * (string_size + 1) );
	   memset(ptr,0,sizeof(ptr));
	   // Read it all in one operation
	   while(!feof(fptr))
	   {
           strcpy(line,NULL);
		   fgets(line,81,fptr);
		   strcat(ptr,line);
			// fread doesn't set it so put a \0 in the last position
			// and buffer is now officially a string
			//ptr[string_size] = '\0';

			/* nada commented
			if (string_size != read_size)
			{
			   // Something went wrong, throw away the memory and set
			   // the buffer to NULL
			   free(buffer);
			   buffer = NULL;
			} */
	   }
	   if(fptr) fclose(fptr);
	  }
	  else
	  {
	    //printf("\nCould not open file\n");
	  }
	  if(fptr) fclose(fptr);
	  return ptr;
}

int InsertAllColumns(char * tableName , char * Values )
{
 int ret;
 FILE *fptr=NULL;
 int i;
 
 
 /*char ExtensionWithNullChar [] = {".txt"};

 for(i=tableNameSize;i<tableNameSize+4;i++)
 {
   tableName[i] = ExtensionWithNullChar[j];
   j++;
 }

 tableName[i] = (char)0;*/
 
    char userFile[9] = {0};

 sprintf(userFile,"%s.txt", tableName);
 
 fptr= fopen(userFile,"a");

 if(!fptr)
 {
   //printf("couldn't open the file");
   ret =0;
 }
 else
 {
   ret =1;
   strcat(Values,"\n");
   fprintf(fptr,Values);
   if(fptr) fclose(fptr);
 }

 return ret;
}


int createAndInsertTable(char* tblName, char* tblDetail)
{
	int res = 1;
	res = createTable(tblName);
	if (res == 2)
	{
		res = create_name(tblName, tblDetail);
		//res = create_detail(tblName, tblDetail);
	}
	return res;
}

int createTable(char* tblName)
{
   int retVal = 1;

   FILE* fptr=NULL;
   char line[100];
   char temp[10];

   fptr = fopen("DATABASE.TXT","a+");
   if(fptr)
   {
	   strcat(temp,tblName);
	   strcat(temp,"\n");
	   while(!feof(fptr) && retVal)
	   {
			fgets(line,100,fptr);
			if(!strcmp(line,temp))
			{
				//if exits
				retVal = 0;
			}
	   }
	   if(retVal)
	   {
			fprintf(fptr,"%s",tblName);
			fprintf(fptr,"\n");
			retVal = 2;
	   }
	   if(fptr) fclose(fptr);
   }

   return retVal;
}

int create_name(char* tblName, char* tblDetail)
{
	int retVal = 0;
   FILE *fptr=NULL;
   char userFile[9] = {0};

   sprintf(userFile,"%s.txt", tblName);

   fptr = fopen(userFile,"w");

   if(fptr)
   {
	   fprintf(fptr,"%s",tblDetail);
	   fprintf(fptr,"\n");
       //printf("done ");
	   
	   if(fptr) fclose(fptr);
	   retVal = 2;
   }
   else
   {
	   //printf("couldn't open this file");
	   retVal = 1;
   }
   
   if(fptr) fclose(fptr);
    
	return retVal;
}

int create_detail(char* tblName, char* tblDetail)
{
   int retval=1;
   FILE *fptr=NULL;
   char userFile[9] = {0};

   sprintf(userFile,"%s_.txt", tblName);

   fptr = fopen(userFile,"w");

   if(fptr)
   {
	   fprintf(fptr,"%s",tblDetail);
	   fprintf(fptr,"\n");
       //printf("done ");
	   
	   if(fptr) fclose(fptr);
   }
   else
   {
	   //printf("couldn't open this file");
   }
   
   if(fptr) fclose(fptr);	
   return retval;
}

int deleteRecord(char* tableName, char* colVal, char* colName)
{
	int retVal = 0;

	FILE* pFile=NULL;
	
	char line[81] = {0};
	char tmpLine[81] = {0};

	char* buffer=NULL;
	char* ptr=NULL;
	char* loc=NULL;

	int i, pos, countComma = 0, counter;
	char userFile[8] = {0};

	buffer = ptr = loc = NULL;

	buffer = (char*) malloc(1590 * sizeof(char));
	memset(buffer, 0 , 1590 * sizeof(char));

	ptr = buffer;



	sprintf(userFile,"%s.txt", tableName);

	//open file
	pFile = fopen(userFile,"r");

	if(pFile)
	{

		if(!feof(pFile)&&fgets(line, 81, pFile))
		//reading first line - record attributes
		{
			//put line in buffer
			strcpy(ptr, line);
			ptr += strlen(line);

			loc = strstr(line,colName);

			if(loc)
			{
				pos = loc - line;
				
				for(i= pos ; i>=0 ; i--)
				if(line[i] == ',')
				countComma++;
            }//else attribute not found
			 
			loc = NULL;
			
			retVal = 2;
		}

		while(!feof(pFile))
		{	
			counter = countComma;

			fgets(line, 81, pFile);

			strcpy(tmpLine,line);

			loc = strtok(tmpLine,",\0");

			while(loc && counter)
			{
				loc = strtok(NULL,",\0");
				counter--;
			}

			if(!strcmp(loc,colVal))
			{	
				//add counter number of rows deleted
				retVal = 3;
			}
			else
			{
				//put line in buffer
				strcpy(ptr, line);
				ptr += strlen(line);				
			}
			
			strcpy(line,NULL);
		}

		if(pFile) fclose(pFile);

		strcpy(userFile,NULL);
		sprintf(userFile,"%s.txt",tableName);

		pFile = fopen(userFile,"w");
		if(pFile)
		{
			fprintf(pFile, "%s", buffer);
		}
		if(pFile) fclose(pFile);

		//free(ptr);
		free(buffer);
	}
	return retVal;
}
                    
char* textEditor(void)
{             
 char st[160] = {"Enter Your Query Here! \(Type Help For HELP Page - Or Exit to Close Program\)\0"};
 int i, x=1, y=1, tag=1, flag=1, toggleMode=1;
 char ch = 0;

 clrscr();

 puts(st);

 do
 {
  gotoxy(x,y);
  ch = getch();
  clrscr();
  if(flag)
  {
   for(i=0 ; i<160 ; i++)
   st[i] =' ';
   st[160]=0;
   flag = 0;
  }
  puts(st);
  //PrintString(); // Function to display string

  if(ch == 0)
  {

   ch = getch();

   switch(ch)
   {
    case 77: //right arrow
     if(x<159) x++;
     else x=1;

    break;

    case 75: //left arrow
     if(x>1) x--;
     else x=159;

    break;

    case 80: //down arrow
    break;

    case 72: //up arrow
    break;

    case 71: //Home btn
     x=1;

    break;

    case 79: //End btn
     x=strlen(st);

    break;

    case 83: //Del btn
     if(toggleMode)
     {
      for(i=x ; i<160 ; i++)
      {
       st[i] = st[i+1];
      }

     }//if Toggle Mode is On, insert mode Delete letter after current pos
     else
     {
      for(i=x ; i<160 ; i++)
      {
       st[i-1] = st[i];
      }
     }//Toggle Mode is Off, replace mode Delete letter at current position

     clrscr();
     puts(st);

    break;

    case 82: //Toggle Insert Mode to shift characters or to overrite it.
     if(toggleMode) toggleMode =0;
     else toggleMode = 1;


    break;

   } //Extended ch SWITCH end

  } //IF ch == 0 end

  else
  {
   if(ch == 27 || ch == 8 || ch == 13)
   {
    switch(ch)
    {
     case 27: //Esc btn

      tag=0;

     break;

     case 8: //Backspace btn
      if(x>1)
      {
       for(i=x ; i<160 ; i++)
       {

	st[i-2] = st[i-1];
       }
       x--;
      }
      clrscr();
      puts(st);
      gotoxy(x,y);

     break;

     case 13: //Enter btn
	  tag = 0;
      gotoxy(1,10);
      printf("You Entered This Query:");

      gotoxy(1,12);
      textattr(0x42);
      cprintf("%s",st);
      textattr(0x07);
	  gotoxy(5,15);
	  printf("Press Any Key to continue...");
      gotoxy(x,y);
	  getch();

     break;

    } //Normal ch SWITCH end
   }
   //ELSE ch != 0 end

   else //getting Normal character
   {

    if(x<160 && isprint(ch))
    {
     if(toggleMode)
     {

      if(st[159] == 32)
      {
	for(i=159 ; i>=x ; i--)
	{
	 st[i] = st[i-1];
	}
	st[i] = ch;
	if(x<159) x++;
      }
      else
      {
       //st[x-1] = ch;
      }

     }
     else
     {
      st[x-1] = ch;
      if(x<159) x++;
     }

     clrscr();
     puts(st);
     gotoxy(x,y);
    }
   }
  }
  //strln = strlen(st);
  i = ch;
  //PrintString(); // Print String After Editting
 }
 while(tag);


 i = 160 ;
 while(st[i] ==' ' || st[i] == 0)
 {
	st[i]=0;
	i--;
 }

 flushall();

 return st;
}

int main()
{
	char* ptr=NULL;
	int flag = 1, res = 0;
	char option=0;

	clrscr();
	while(flag)
	{
		ptr = textEditor();

		strlwr(ptr);
		
		if(strstr(ptr,"create") || strstr(ptr,"insert") || strstr(ptr,"update") || strstr(ptr,"delete") || strstr(ptr,"select"))
		{
			res = parseQuery(ptr);			
			resultHandeler(res);

			printf("Do You Want to Query Any thing else \? \(Y/N\)\?\n");
			option = getch();
			if(option == 'n' || option == 'N')
				flag = 0;
		}

		else if(!strcmp(ptr,"help"))
		{
			openHelp();
			clrscr();
		}
		else if(!strcmp(ptr,"exit"))
		{
			flag = 0;
		}
		else
		{
			clrscr();
			printf("Syntax Error, Wrong Input %c\n",19);
			flushall();
			printf("Do You Want to Query Any thing else \? \(Y/N\)\?");
			option = getch();
			if(option == 'n' || option == 'N')
			{
				flag = 0;
			}
		}

	}
    return 0;
}