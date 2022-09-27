
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

static int x=1;                        //It has been used for x-cursor co-ordinate.
#define pos gotoxy(33,x++)             //For cursor movement.
#define ln printf("..............................................");
//.............................................................................................................................................................
COORD coord= {0,0};
void gotoxy(int x, int y);
void gotoxy(int x, int y)       //Function to set the cursor position
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void delay(unsigned int mseconds)           //function for delay
{
    clock_t goal=mseconds+clock();
    while(goal>clock());
}
//.............................................................................................................................................................
void sett();       //Sets time limit for typing.
int t=30;
int c=0;

char name[15];
void getscore(int score,int speed, int level);
void start();       //To start the typing practice
void scorecard();   //To update high score
void About_me();
void help();

//main function
int main()
{
    int ch;
    time_t t;
    time(&t);

x=1;
system("cls");
pos;
printf("WELCOME TO TYPING TUTOR");pos;
printf("%s",ctime(&t));
pos;
ln pos;
if(c==0)
   {
    printf("Enter user name:");
    gets(name);
   }
   c++;
pos; ln pos;

printf("MAIN MENU");pos;
ln pos;
printf("1.Start Practice");
pos;
printf("2.Scorecard");
pos;
printf("3.Set the time limit");
pos;
printf("4.Help");
pos;
printf("5.About Project");
pos;
printf("6.Exit");
pos;
printf("Enter your choice::");
scanf("%d",&ch);
pos;
switch(ch)
{
    case 1:start(); break;
    case 2:scorecard(); break;
    case 3:sett(); main();
    case 4:help(); break;
    case 5:About_me(); break;
    case 6:system("cls");gotoxy(17,10);
           printf("This project has been prepared by Ankur Kumar and Adarsh Keshari of Group 6. Thanks");
           delay(1000);
           exit(1);
    default:main();
}
getch();
}
//.......End of Main Function........

//Start Practice.
void start()
{
int score=0,level=1,mode=100,count=0;
clock_t begin;int time_spent,speed;
int r,letter,ch;
delay(500);

system("cls");
srand(time(NULL));     //Initializes random function and seed with time.
x=2;
pos;
printf("Select the level to practice.");pos;
ln pos;
printf("1.LEVEL 1");
pos;
printf("2.LEVEL 2");
pos;
printf("3.LEVEL 3");
pos;
printf("4.Go back to Main Menu");
pos;
scanf("%d",&level);
if(level==4)
    main();
else
    {
        if(level==1)                //For uppercase alphabet
            mode=65;
        if(level==2)                //For lowercase alphabet
            mode=97;
        if(level==3)                 //For mixed case
            mode=120;
      begin=clock();
          while(1)
            {
             system("cls");
             time_spent= (int) (clock()-begin)/CLOCKS_PER_SEC;

             if(time_spent>=t)
            break;
            r=rand()%1000;
            r=r%26+mode;
            gotoxy(20,8);
            printf("Type the following character");
            gotoxy(36,11);
            printf("%c",r);      //Prints random character
            letter=getch();

            if(letter!=r)
                break;
            else
                {
                  count++;
                  score=score+10;
                  gotoxy(28,9);
                  printf("score=%d",score);      //Prints score
                  gotoxy(37,9);
                  printf("Time_spent=%d sec",time_spent);    //Prints time spent during typing practice


if(level==1)
                    delay(400);
                  if(level==2)
                    delay(200);
                  if(level==3)
                    delay(100);
                }     //End of else loop
             }        //End of while loop
gotoxy(26,x);
delay(400);
++x;
pos;
speed= (count*60)/time_spent;
if(time_spent<t-1)
    printf("You made a mistake.");
else
    printf("Time is up!");
pos;

if((speed>=40)&&(speed<=50))
   {
    printf("Good work! Keep it up.");pos;
    printf("You got Silver medal.");
   }
else
    if(speed>50)
      {
        printf("Nice work! You got Gold medal.");
      }
    else
    printf("Sorry no medal! You need practice.....");

    pos;

    printf("Total score is::%d",score);pos;
    printf("Your net speed=%d letter per minute",speed);
    getscore(score,speed,level);        //Saves data to file
    ++x;
    pos;
    printf("1.Try Again");pos;
    printf("2.Main Menu");pos;
    printf("3.Exit");pos;
    printf("Enter your choice::");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:start();break;      //Recursive call
        case 2:main();break;
        case 3:system("cls");gotoxy(17,10);
                printf("This project has been prepared by ANKUR KUMAR and ADARSH KESHARI.");
                delay(1000);exit(1);
        default:pos;printf("WRONG CHOICE!");pos;
             main();
    }
    }
}
// End of start practice function.

// sett function starts
void sett()    //Set time limit.
{
    int ch;
    system("cls");
    x=5;
    pos;
    printf("Set the time limit for practice in minute::");
    pos;
    ln pos;
    printf("Press 0 for half minute");pos;
    printf("Press 1 for one minute");pos;
    printf("Press 2 for two minutes");pos;
    scanf("%d",&ch);
    switch(ch)
    {
      case 0:t=30;break;
      case 1:t=60;break;
      case 2:t=120;break;
      default:main();
    }
}
//sett function ends

//....................................................
void help()
{
    system("cls");
    gotoxy(7,5);
    printf("GUIDE FOR THE TYPING TUTOR");gotoxy(7,6);
    printf("A.Enter your name.");gotoxy(7,7);
    printf("B.Set the time limit under option 3 in Main Menu(default time limit is 30 seconds.)");gotoxy(7,8);
    printf("C.Select the level and get started.");gotoxy(7,9);
    printf("D.Characters are displayed and you have to type them as fast as you can.");gotoxy(7,10);
    printf("E.Avoid incorrect typing.");
    getch();main();
}
void About_me()
{
    system("cls");
    gotoxy(0,4);
    printf("This project of typing tutor has been prepared by ANKUR KUMAR and ADARSH KESHARI of IT 2nd Year of batch 2021-2022.\n");
    printf("This project will help you in improving your typing speed and accuracy.\n");
    printf("Good Luck!");
        getch();
        main();
}
//....................................................................
void getscore(int score,int speed,int level)
{
    FILE *fp;
    fp=fopen("file.txt","a");
    pos;
    if(fp==NULL)
    printf("Error in opening file.");
    fprintf(fp,"\nName=%s;  Score=%d  Speed=%d  Level=%d",name,score,speed,level);
    fclose(fp);
    pos;
    printf("Scorecard updated");
}
void scorecard()
{
    int ch;
    FILE *fp;
    system("cls");
    x=3;
    printf("\t\t\t....The scores are...\n");
    fp=fopen("file.txt","r");
    while((ch=fgetc(fp))!=EOF)
    {
        printf("%c",ch);
    }
    getch();
    main();
}
