#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
char * selectall(char* table);


int main()
{
	  char * ptr;
	  ptr = selectall("students\0");
	  if (ptr)
	  {
		puts(ptr);
		free(ptr);
	  }
	  getch();
	  return 0;
}
char * selectall(char* table)
{
	char* ptr = NULL;
	int string_size,read_size;

	FILE *fptr;
	char str[10];
	int c;
	strcat(table,".txt");

	fptr = fopen(table,"r");
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

	   // Read it all in one operation
	   read_size = fread(ptr, sizeof(char), string_size, fptr);

	    // fread doesn't set it so put a \0 in the last position
	    // and buffer is now officially a string
	    ptr[string_size] = '\0';

	    /* nada commented
	    if (string_size != read_size)
	    {
		   // Something went wrong, throw away the memory and set
		   // the buffer to NULL
		   free(buffer);
		   buffer = NULL;
	    } */

	  }
	  else
	  {
	    printf("\nCould not open file\n");
	  }
	  fclose(fptr);
	  return ptr;
}