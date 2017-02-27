#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
   // char *userquery="create table students (id int 2,name varchar 20)"; //input
   // char *userquery="insert into students values(1,'nada')";
   // char *userquery= "delete from students where name = 'salma' ";
     // char *userquery="select *from students";
     char userquery[]={"update students set name = 'salma' where id = 1"};
    char *sqlfn;	//sqlfunction
    char *tablename;
    char *tablecols;	//userinput table columns

    int x; //switch cases 1-create 2-insert 3-selete 4-update 5-delete
    char *usertemp;
    char *wheretmp;
    char *colname;    //for delete fn
    char *colvalue;
    char *wherecolname;    //for update fn
    char *wherecolvalue;
    const char where[] = {"where\0"};

    strcpy(usertemp,userquery);
    sqlfn=strtok(usertemp," ");   //function

    if(strcmp(sqlfn,"create")==0)
    {
	x=1;
    }
    else if(strcmp(sqlfn,"insert")==0)
    {
	x=2;
    }
    else if(strcmp(sqlfn,"select")==0)
    {
	x=3;
    }
    else if(strcmp(sqlfn,"update")==0)
    {
	x=4;
    }
    else if(strcmp(sqlfn,"delete")==0)
    {
	x=5;
    }
    switch(x)
    {
	case 1:

	{
	  tablename=strtok(NULL," () ");        //tablename
	  tablename=strtok(NULL," () ");       //for parsing create
      /*
   // tablename=strtok(usertemp,"create table ");
	 tablecols=strtok(usertemp," () ");
	 tablecols=strtok(NULL," () ");
	 tablecols=strtok(tablecols," () "); */ //id int 2,name varchar 20
    //end of block of parsing create statement
	 break;
	}
	case 2:
	{

	   tablename=strtok(NULL," () ");
	   tablename=strtok(NULL," () ");

	   tablecols= strtok(NULL," () ");
	   tablecols=strtok(NULL," () ");

	 break;
	}
	case 3:
	{      tablename=strtok(NULL," ");        //tablename
	       tablename=strtok(NULL," ");


	 break;
	}
	case 4:
	{
	   tablename=strtok(NULL," = ");        //tablename
    //tablename=strtok(NULL," = ");
	  colname=strtok(NULL," = ");
	  colname=strtok(NULL," = ");		   // for parsing update
	  colvalue=strtok(NULL," = ");

    //colvalue=strtok(NULL," = ");
	 wherecolname = strtok(NULL," = ");
	 wherecolname = strtok(NULL," = ");
	 wherecolvalue = strtok(NULL," = ");

	 break;
	}
	case 5:
	{
	   tablename=strtok(NULL," = ");        //tablename
	   tablename=strtok(NULL," = ");
	   colname=strtok(NULL," = ");
	   colname=strtok(NULL," ");		   // for parsing delete
	   colvalue=strtok(NULL," = ");


	 break;
	}
    }
    //salma code for parsing create statement after getting sql function
   /*
    tablename=strtok(NULL," () ");        //tablename
    tablename=strtok(NULL," () ");       //for parsing create

   // tablename=strtok(usertemp,"create table ");
    tablecols=strtok(usertemp," () ");
    tablecols=strtok(NULL," () ");
    tablecols=strtok(tablecols," () "); */ //id int 2,name varchar 20
    //end of block of parsing create statement

    /*
     tablename=strtok(NULL," () ");
     tablename=strtok(NULL," () ");

     tablecols= strtok(NULL," () ");
     tablecols=strtok(NULL," () ");
				    */	//for parsing insert
    /*
     tablecols=strtok(usertemp,"(");
     tablecols=strtok(NULL,"(");
     tablecols=strtok(tablecols,")"); */

   /*

    tablename=strtok(NULL," = ");        //tablename
    tablename=strtok(NULL," = ");
    colname=strtok(NULL," = ");
    colname=strtok(NULL," ");		   // for parsing delete
    colvalue=strtok(NULL," = ");       */




   /*


    //parsing select statement

    tablename=strtok(NULL," ");        //tablename
    tablename=strtok(NULL," ");
   // end of block of parsing select statement    */
   /*
    tablename=strtok(NULL," = ");        //tablename
    //tablename=strtok(NULL," = ");
    colname=strtok(NULL," = ");
    colname=strtok(NULL," = ");		   // for parsing update
    colvalue=strtok(NULL," = ");

    //colvalue=strtok(NULL," = ");
    wherecolname = strtok(NULL," = ");
    wherecolname = strtok(NULL," = ");
    wherecolvalue = strtok(NULL," = ");   */







   //parsing update statement
    /*

    tablename=strtok(NULL," = ");      //table name


    //strcpy(usertemp,userquery);

    strtok(NULL," == ");
    strtok(NULL," == ");
    strtok(NULL," == ");
    //colname = strtok(NULL," = ");

    colname=strtok(NULL," == ");

    colvalue=strtok(NULL," == ");




    wherecolname = strtok(NULL," = ");
    wherecolname = strtok(NULL," = ");
    wherecolname = strtok(NULL," = ");
    wherecolname = strtok(NULL," = ");
    wherecolname = strtok(NULL," = ");
   wherecolname = strtok(NULL,"= =");
   wherecolvalue = strtok(NULL,"= =");
    //wherecolname                      */

getch();
return 0;
}


 /*

void parserselect(char * tablenamesalma)
{

    tablename=strtok(NULL," ");        //tablename
    tablename=strtok(NULL," ");

}*/
