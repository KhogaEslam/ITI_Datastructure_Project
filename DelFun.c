#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int deleteRecord(char* tableName, char* val, char* colName);

int main()
{
	char tableName[11] = {"Test.txt\0"};
	char val[11] = {"aaa\0"};
	char colName[11] = {"abc\0"};

	int res;

	clrscr();


	res = deleteRecord(tableName, val, colName);

	if(res == 2)
	{
		printf("Deleted !");
	}
	else if(res == 1)
	{
		printf("Record Not Found!");
	}
	else
	{
		printf("Couldn't Open File!");
	}


	getch();

	return 0;
}

int deleteRecord(char* tableName, char* val, char* colName)
{
	int retVal = 0;

	FILE* pFile;
	
	char line[81] = {0};
	char tmpLine[81] = {0};

	char* buffer;
	char* ptr;
	char* loc;

	int i, pos, countComma = 0, counter;

	buffer = ptr = loc = NULL;



	buffer = (char*) malloc(1000 * sizeof(char));
	memset(buffer, 0 , 1000 * sizeof(char));

	ptr = buffer;


	//open file
	pFile = fopen(tableName,"r");

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
		}

		while(!feof(pFile))
		{
			retVal = 1;
			
			counter = countComma;

			fgets(line, 81, pFile);

			strcpy(tmpLine,line);

			loc = strtok(tmpLine,",\0");

			while(loc && counter)
			{
				loc = strtok(NULL,",\0");
				counter--;
			}

			if(!strcmp(loc,val))
			{
				retVal = 2;
				//add counter number of rows deleted
			}
			else
			{
				//put line in buffer
				strcpy(ptr, line);
				ptr += strlen(line);
			}
		}

		fclose(pFile);

		pFile = fopen(tableName,"w");
		if(pFile)
		{
			fprintf(pFile, "%s", buffer);
		}
		fclose(pFile);

		//free(ptr);
		free(buffer);
	}


	return retVal;
}