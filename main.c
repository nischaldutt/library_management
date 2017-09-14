#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<windows.h>

char categories[][15]={"Computer","Electronics","Electrical","Civil","Mechanical","Architecture"};
void mainmenu(void);
void password();
int t(void);
void addbooks(void);
void deletebooks(void);
void viewbooks(void);
void returnfunc(void);
int getdata();
int checkid(int);
FILE *fp,*ft;//globals file that can be accessed anywhere in the program
int s;
char findbook;
struct books
{
    int id;
    char name[20];
    char author[10];
    int price;
    int count;
    int racno;
    char *cat;
};
struct books a;
COORD coord ={0,0}; //sets coordinates to (0,0).
void gotoxy(int x, int y) //function used to manipulate the user prompt on the screen.
{
    coord.X=x; coord.Y=y; //x and y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds) //function used to delay our execution in milliseconds.
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int main()
{
    password();
    return 0;
}
char Password[10]={"library"};
void password(void)
{
    system("cls"); //function clears the screen.
    char d[25]={" Password Protected"};
    char ch,pass[10];
    int j=0,i=0;
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
        delay(50);
        printf("*");
    }
    for(j=0;j<20;j++)
    {
        delay(50);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        delay(50);
        printf("*");
    }
    gotoxy(15,7);
    printf("Enter Password- ");
    while(ch!=13)
        {ch=getch();
    if(ch!=13 && ch !=8)
    {
        putch('*');
        pass[i]=ch;
        i++;
    }
        }
pass[i]='\0';
if(strcmp(pass,Password)==0)
{
    gotoxy(15,9);
    printf("Password Matched");
    gotoxy(17,10);
    printf("Press any key to continue..");
    getch();
    mainmenu();
}
else
{
    gotoxy(15,16);
    printf("Wrong Password !!!");
    getch();
    password();
}
}
int t(void) //function displays date and time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}
void mainmenu()
{
    system("cls");
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1. Add Book");

    gotoxy(20,7);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2. Delete Book");

    gotoxy(20,9);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3. Available Books");

    gotoxy(20,11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4. Close Application");

    gotoxy(20,13
           );
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,20);
	t();
    gotoxy(20,21);
    printf("Enter the choice:");
    switch(getch())
    {
    case '1':
        addbooks();
        break;
    case '2':
        deletebooks();
        break;
    case '3':
        viewbooks();
        break;
    case '4':
        {
        system("cls");
        gotoxy(16,3);
        printf("Programmed by----->");
        gotoxy(40,3);
        printf("Nischal Dutt");
        gotoxy(16,5);
        printf("e-mail: nischaldutt01@gmail.com         Mobile: 9779806407");
        gotoxy(10,17);
        printf("Exiting in 3 second");
        delay(3000);
        exit(0);
        }
    default:
    {
        system("cls");
        gotoxy(15,10);
        printf("Wrong Choice !!!");
        if(getch())
        mainmenu();
    }
    }
}
void addbooks(void)
{
    system("cls");
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CATEGORIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 1. Computer");

    gotoxy(20,7);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 2. Electronics");

    gotoxy(20,9);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 3. Digital");

    gotoxy(20,11);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 4. Automation");

    gotoxy(20,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 5. Artificial Intelligence");

    gotoxy(20,15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 6. Architecture");

    gotoxy(20,17);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2 7. Back to Main Menu");
    gotoxy(20,19);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,20);
	printf("Enter your choice: ");
	scanf("%d",&s);
	if(s==7)
	mainmenu();
	system("cls");
	fp=fopen("test.txt","a+");
    if(getdata()==1)
    {
        a.cat=categories[s-1];
        fseek(fp,0,SEEK_END); //fseek() position the file pointer to the end of the file.
        fwrite(&a,sizeof(a),1,fp); //function writes the data of the given book to the file.
        fclose(fp);
        gotoxy(20,22);
        printf("Data Successfully Saved...!!");
        gotoxy(20,24);
        printf("Save more Books? (y/n) ");
        if(getch()=='n')
            mainmenu();
        else
            system("cls");
            addbooks();
    }
}
void deletebooks(void)
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(10,5);
        printf("Enter the Book ID to delete");
        scanf("%d",&d);
        fp=fopen("test.txt","r+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                gotoxy(10,7);
                printf("The Book Record is Available..");
                gotoxy(10,10);
                printf("Book Name: %s",a.name);
                gotoxy(10,12);
                printf("Book's Author: %s",a.author);
                findbook='t';
            }
        }
            if(findbook!='t')
            {
                gotoxy(10,10);
                printf("No record is found modify the search");
                if(getch())
                mainmenu();
            }
            if(findbook=='t')
            {
                gotoxy(10,9);
                printf("Do you want to Delete the Book's Record? (y/n) ");
                if(getch()=='y')
                {
                    ft=fopen("temp.txt","w+"); //temporary file
                    rewind(fp);
                    while(fread(&a,sizeof(a),1,fp)==1) //read the original file
                    {
                        if(a.id!=d)
                        {
                            fseek(ft,0,SEEK_CUR);
                            fwrite(&a,sizeof(a),1,ft); //write all data to temporary file except what we want to delete
                        }
                    }
                    fclose(ft);
                    fclose(fp);
                    remove("test.txt"); //delete the original file
                    rename("temp.txt","test.txt"); //copy all data from temporary file to original file except that what we want to delete
                    fp=fopen("test.dat","r+");
                    if(findbook=='t')
                    {
                        gotoxy(10,10);
                        printf("The record is sucessfully deleted");
                        gotoxy(10,11);
                        printf("Delete another record?(Y/N)");
                    }
                }
                else
                    mainmenu();
                    fflush(stdin);
                    another=getch();
            }
    }
    gotoxy(10,15);
    mainmenu();
}
int getdata()
{
    int t;
    gotoxy(20,3);printf("Enter the Information Below");
    gotoxy(20,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CATEGORIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,6);
    printf("Category- ");
    gotoxy(30,6);
    printf("%s",categories[s-1]);
    gotoxy(20,7);
    printf("Book ID: ");
    gotoxy(30,7);
    scanf("%d",&t);
    if(checkid(t)==0)
    {
        gotoxy(20,8);
        printf("The book is already present !");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(20,8);
    printf("Book Name: ");
    gotoxy(30,8);
    scanf("%s",a.name);
    gotoxy(20,9);
    printf("Author: ");
    gotoxy(30,9);
    scanf("%s",a.author);
    gotoxy(20,10);
    printf("Price: ");
    gotoxy(30,10);
    scanf("%d",&a.price);
    gotoxy(20,11);
    printf("Count: ");
    gotoxy(30,11);
    scanf("%d",&a.count);
    gotoxy(20,12);
    printf("Rack No. ");
    gotoxy(30,12);
    scanf("%d",&a.racno);
    return 1;
}
int checkid(int t) //checks the id of the book.
{
    rewind(fp); //positions the file pointer to the starting location
    while(fread(&a,sizeof(a),1,fp)==1)//fread function reads the data from the file.
    if(a.id==t)
    return 0; //book is already present
    return 1; //new book
}
void viewbooks(void) //displays the list of all available books
{
    int i=0,j=0;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;
    fp=fopen("test.txt","r");
    while(fread(&a,sizeof(a),1,fp))
    {
        gotoxy(3,j);
        printf("%s",a.cat);
        gotoxy(16,j);
        printf("%d",a.id);
        gotoxy(22,j);
        printf("%s",a.name);
        gotoxy(36,j);
        printf("%s",a.author);
        gotoxy(50,j);
        printf("%d",a.count);
        gotoxy(57,j);
        printf("%d",a.price);
        gotoxy(69,j);
        printf("%d",a.racno);
        j++;
        i=i+a.count;
    }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
}
void returnfunc(void) //returns the control to main menu
{
    printf("PressEnter return to Main Menu");
    a:
    if(getch()==13) // ascii  value of carriage return is 13
        mainmenu();
    else
        goto a;
}
