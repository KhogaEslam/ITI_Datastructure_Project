#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200


int selectColumns(char* tableName, char* colNames,char* colValues);

int main()
{
	char tableName[13] = {"STUDENTS.TXT\0"};
	char * colNames = {"id,abc\0"};
	char * colValues={"2,1000\0"};

	int res;
	clrscr();

	res = selectColumns(tableName, colNames, colValues);
	getch();

	return 0;
}

int selectColumns(char* tableName, char* colNames,char* colValues)
{
	char buffer[500];
	int retVal=0;
	FILE * pFile;
	char * line;
	char * templine;
	char* tok;
	char *tempColNames;
	int * ar;
	char * col;
	int columnCount =0;

	char * isExistCol;
	int found;
	char * tokparam;
	int i;
	int k;
	int r;
	char * tableCol;
	char ch;
	char * wordusercol;

	int z=0;
	int subi=0;

	int rro;
	int c=0;

	char array[MAX];
	char word[MAX];
	char in = '0';

	//for insert;
	int q;//for for loop
	int w; //for array of places
	char * part;
	char * sub;





	//i need to know how many columns and their numbers in select col
	free(tempColNames);
	tempColNames = malloc(sizeof(colNames));
	strcpy(tempColNames,colNames);

	col = strtok(tempColNames,",");
	//if(col != NULL)
	printf("%s", col);

	while(col != NULL)
	{
	  col = strtok(NULL,",");
	  if(col != NULL)
	  printf("\t%s\t", col);
	  columnCount++;
	}

	ar = malloc(columnCount*sizeof(int));

	free(tempColNames);
	tempColNames = malloc(sizeof(colNames));
	strcpy(tempColNames,colNames);

	col = strtok(tempColNames,",");
	col[sizeof(col)]=(char)0;


	//open file
	pFile = fopen(tableName,"r");
	fgets(line, 81, pFile);

	//check first if the first column word exists in the table header
	if(strstr(line,col))
	{

	  free(tempColNames);
	  tempColNames = malloc(sizeof(colNames));
	  strcpy(tempColNames,colNames);
	  tempColNames[strlen(tempColNames)] = (char)0;


	  while(tempColNames[z] != NULL)
	  {

	    ch = tempColNames[z];
	    if(ch == ',')
	    {
	       wordusercol[subi] = (char)0;
	       subi=0;

	       tableCol = strtok(line,",");

	       k=0; // for looping words of columns
	       i=0;// for putting into array

	       while(tableCol != NULL)
	       {
			if(strcmp(wordusercol,tableCol) == 0)
			{
				ar[i] = k;
				i++;
			}
			k++;

			tableCol = strtok(NULL,",");
	       }

	       fseek(pFile, 0, SEEK_SET);
	       tableCol = strtok(line,",");

	    }
	    else
	    {
	       wordusercol[subi] = ch;
	       subi ++;
	    }
	    wordusercol[subi] = (char)0;
	    z++;
	  }//end of while


	  k=0;

	  fseek(pFile, 0, SEEK_SET);
	  fgets(line, 81, pFile);
	  line[strlen(line)-1]  = (char)0;
	  tableCol = strtok(line,",");

	  while(tableCol != NULL)
	  {
			if(strcmp(wordusercol,tableCol) == 0)
			{
				ar[i] = k;
				i++;
			}
			k++;

			tableCol = strtok(NULL,",");
	  }
	}

	retVal =1;
	//Now it is time to print the columns
	fclose(pFile);

	pFile = fopen(tableName,"a+");
	if(pFile)
	{
	  //fprintf(pFile,"%s",colValues);
	  //fputs("nadah",pFile);
	   //strcpy(sub,part);
	   part = strtok(colValues,",");
	   w=0;

	   ///////

	   sub = (char *)malloc(sizeof(part));

	   memset(sub,0,255);
	   /////////


	   //strcpy(part,"\0");
	   while(part != NULL)
	   {
	     for(q=0;q<= columnCount;q++)
	     {
	       if(q==ar[w])
	       {
		 strcat(sub,part);
		 strcat(sub,",");
		 w++;
		 part = strtok(NULL,",");
	       }
	       else
	       {
		 strcat(sub,",");
	       }

	     }

	   }

	   sub[strlen(sub)] = (char)0;
	   fprintf(pFile,"\n%s",sub);

	}
	fclose(pFile);
	return retVal;

}