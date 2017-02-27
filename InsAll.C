#include <stdio.h>
#include <conio.h>

int InsertAllColumns(char * TableName , int TableNameSize , char * Values , int ValuesSize);

int main()
{
  char tablename[] = {"Yoo"};
  int tablenamesize = 3;
  int retval;

  char values[] = {"1,Nada,010999911"};

  retval = InsertAllColumns(tablename, tablenamesize ,values, sizeof(values));

  getch();
  return 0;
}

int InsertAllColumns(char * TableName , int TableNameSize , char * Values  , int ValuesSize)
{
 int ret;
 FILE *fptr;
 int j=0,i;
 char ExtensionWithNullChar [] = {".txt"};

 for(i=TableNameSize;i<TableNameSize+4;i++)
 {
   TableName[i] = ExtensionWithNullChar[j];
   j++;
 }

 TableName[i] = (char)0;

 fptr= fopen(TableName,"a");

 if(!fptr)
 {
   printf("couldn't open the file");
   ret =0;
 }
 else
 {
   ret =1;
   fclose(fptr);
 }

 return ret;
}
