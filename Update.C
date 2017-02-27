#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int updateRecord(char* tableName, char* val, char* colName,int colu,char* newd);

int main()
{
	char tableName[11] = {"Test.txt\0"};
	char val[11] = {"aaa\0"};
	char colName[11] = {"abc\0"};
	int colu=2;
	char newd[]="aaaa\0";
	int res;

	clrscr();


	res = updateRecord(tableName, val, colName,colu,newd);

	if(res == 2)
	{
		printf("Updated !");
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

int updateRecord(char* tableName, char* val, char* colName,int colu,char* newd)
{
	int retVal = 0;

	FILE* pFile;

	char line[81] = {0};
	char tmpLine[81] = {0};
	char updatedLine[81]={0};

	char* buffer;
	char* ptr;
	char* loc;

	int i=0, j=0, k=0, pos, countComma = 0, commaTN=0, commaKeeper, counter;

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

			for(i ; i<strlen(line) ; i++)
			{
				if(line[i] == ',')
				commaTN++;
			}

			i = 0;

			loc = strstr(line,colName);

		if(loc)
		{
				pos = loc - line;

				for(i= pos ; i>=0 ; i--)
				if(line[i] == ',')
				countComma++;

				counter = commaKeeper = countComma;
			//else attribute not found

			//loc = NULL;  to be moved


		while(!feof(pFile))
		{
			retVal = 1;
			i = 0;

			fgets(line, 81, pFile);

			if(countComma == commaTN)
			{
				for(i ; countComma ; i++)
				{
					updatedLine[i] = line[i];
					if(line[i] == ',')
					countComma--;

				}
				j = i + strlen(val);
				for(i ; i<j ; i++)
				{
				     updatedLine[i] = val[k];
				     k++;
				}
				updatedLine[i] = 0;

			}
			else if(countComma)
			{
			       retVal = 2;
			       i=0;
			       for(i ; countComma ; i++)
			       {
				     updatedLine[i] = line[i];
				     if(line[i] == ',')
				     countComma--;
			       }
			       //l = strlen(val);
			       j=0;
			       for(i ; j<strlen(val) ; i++)
			       {
				updatedLine[i] = val[j];
				j++;
			       }

			       if(counter+1 < commaTN)
			       {
					updatedLine[i] = ',';
					i++;
					for(k ; counter+1; k++)
					{
						if(line[k] == ',')
						 counter--;
					}
					for(k ; k<strlen(line) ; k++)
					{
					  updatedLine[i] = line[k];
					  i++;
					}
					updatedLine[i] = 0;
			       }


			}
			else
			{
				i = 0;
				retVal = 2;
				while(line[i] != ',' )
				i++;

				counter = 0;
				//while(val[counter])
				updatedLine[counter] = val[counter];

				for(i ; i < strlen(line) && line[i] ; i++)
				{
					updatedLine[counter] = line[i-1];

				}
				line[i] = 0;
			}

				//put line in buffer
				strcpy(ptr, updatedLine);
				ptr += strlen(line);
		}
		loc = NULL;
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