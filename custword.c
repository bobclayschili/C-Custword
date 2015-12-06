/* custword.c - user customized password system for Personal Computers *
 * by Sean Clay     Date: 06/01/1991      Version: 1.0                 */

 #include <stdio.h>
 #include <dos.h>

 int cbrk();
 int beg();
 int box(int, int, int, int);

 main(int argc, char *argv[])
 {
	FILE *fptr;
	char password[40];
	char string[81];

	if(argc != 2)
	  {printf("ERROR! Missing password argument."); exit();}

	if( (fptr=fopen("screen.txt","r"))==NULL )
	  {printf("ERROR! Missing 'screen.txt' file."); exit();}

	clrscr();
	ctrlbrk(cbrk);

	while( fgets(string,80,fptr) != NULL )
	  printf("%s", string);

	fclose(fptr);

	while( strcmp(password,argv[1]) )
	{
	gotoxy(20,20);
	printf("                     ");
	gotoxy(20,20);
	gets(password);
	}

	beg();

 }

 cbrk() 	/* handle any ctrl-c or break attempts! */
 {
	gotoxy(20,20);
   	printf("                     ");
	gotoxy(20,20);
	return 1;
 }

beg()      	/* beg for money for this program */
{
	clrscr();
	box(5,1,75,4);
	gotoxy(26,2);
	printf("CUSTWORD - Custom Password Utility");
	gotoxy(28,3);
	printf("Copyright 1991 - CLAYCO");
	gotoxy(10,7);
	printf("You may copy this program and share it with your friends.");
	gotoxy(10,8);
	printf("If you make use of this software, you are expected to");
	gotoxy(10,9);
	printf("pay a one time registration fee.  Please send $15 to:");
	gotoxy(30,11);
	printf("       CLAYCO");
	gotoxy(30,12);
	printf(" 2572 Yucca Mesa Road");
	gotoxy(30,13);
	printf("Yucca Valley, Ca. 92284");
	gotoxy(30,14);
	printf("   (619) 365-9385");
	box(10,17,70,21);
	gotoxy(13,18);
	printf("Upon receipt of your registration fee, you will receive");
	gotoxy(13,19);
	printf("a diskette with the latest version of this software");
	gotoxy(13,20);
	printf("and notice of future updates.");
	gotoxy(0,23);
} /* end beg */

/* box.c - draws a box per users request */
box(x1,y1,x2,y2)
  int x1,y1,x2,y2;
  {
  int i;
  gotoxy(x1,y1);
  printf("\xC9");
  gotoxy(x1,y2);
  printf("\xC8");
  for (i=x1+1; i<x2; i++)
    {
    gotoxy(i,y1);
    printf("\xCD");
    gotoxy(i,y2);
    printf("\xCD");
    }
  gotoxy(x2,y1);
  printf("\xBB");
  gotoxy(x2,y2);
  printf("\xBC");
  for (i=y1+1; i<y2; i++)
    {
    gotoxy(x1,i);
    printf("\xBA");
    gotoxy(x2,i);
    printf("\xBA");
    }
  } /* end box */