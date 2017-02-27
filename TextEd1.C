#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

void PrintString(char* str, int x);
void EditString(char* str, int x);
void EmptyString(char* str);

int main()
{
 char st[101] = {"Enter Your Text Here! \(100 Char Maximum\)"};
 int i, x=1, y=1, tag=1, flag=1, toggleMode=1;
 char ch = 0 ,temp=0;
 int strln=0;

 //char* ptr=st;

 clrscr();

 puts(st);

 do
 {
  gotoxy(x,y);
  ch = getch();
  clrscr();
  if(flag)
  {
   for(i=0 ; i<101 ; i++)
   st[i] =' ';
   st[101]=0;
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
     if(x<100) x++;
     else x=1;

    break;

    case 75: //left arrow
     if(x>1) x--;
     else x=100;

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
      for(i=x ; i<101 ; i++)
      {
       st[i] = st[i+1];
      }

     }//if Toggle Mode is On, insert mode Delete letter after current pos
     else
     {
      for(i=x ; i<101 ; i++)
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
       for(i=x ; i<101 ; i++)
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
      gotoxy(1,5);
      printf("You Entered This Text:");

      gotoxy(1,7);
      textattr(0x42);
      cprintf("%s",st);
      textattr(0x07);
      gotoxy(x,y);

     break;

    } //Normal ch SWITCH end
   }
   //ELSE ch != 0 end

   else //getting Normal character
   {

    if(x<101 && isprint(ch))
    {
     if(toggleMode)
     {

      if(st[100] == 32)
      {
	for(i=100 ; i>=x ; i--)
	{
	 st[i] = st[i-1];
	}
	st[i] = ch;
	if(x<100) x++;
      }
      else
      {
       //st[x-1] = ch;
      }

     }
     else
     {
      st[x-1] = ch;
      if(x<100) x++;
     }

     clrscr();
     puts(st);
     gotoxy(x,y);
    }
   }
  }
  strln = strlen(st);
  i = ch;
  //PrintString(); // Print String After Editting
 }
 while(tag);

 return 0;
}