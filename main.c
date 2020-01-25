#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include <time.h>
#define size 130

typedef struct
{
    char id[10];
    char f_name[10];
    char l_name[10];
    char p_number[15];
    char b_group[3];
    char section[2];
    int tk;


} person;


person array[size];
int taka=0;
int top=0;
int taka_khoroch=0;
void entry();
void display();

void save_to_file();
void read_from_file();
int search();
void delet();
int src(char x[]);
void payment();

int main()
{
    read_from_file();
    int x;
    int ab;
    time_t t;
    time(&t);
    int f;

    while(1)
    {
        puts("                                         :::::::::::::DURJOY FOUNDATION::::::::::::::");
        puts("                                         ::::::::University Of Global Village::::::::");
        puts("                                         Department of Computer Science & Engineering");
        puts("                                         ::::::::::::Powered by 4th batch::::::::::::");
        puts("                                         ::::::Developed by Khandaker Zoad Pial::::::");

        printf("\n\n\n\n\n");
        printf(" Time & Date: %s\n",ctime(&t));
        printf(" Current Balance: %d BDT\n",taka);
        puts(" ----------------------------------------");

        puts(" |   1.Add New Member                   |");
        puts(" |   2.Display All Members              |");
        puts(" |   3.Search A Member                  |");
        puts(" |   4.Delete A Member                  |");
        puts(" |   5.Payment                          |");
        puts(" |   6.Taka Khoroch                     |");
        puts(" |   7.Exit                             |");
        printf(" |   Choose your action:                |\n");
        puts(" ----------------------------------------");

        scanf("%d",&x);
        switch(x)
        {
        case 1:
            entry();
            save_to_file();
            clear();
            break;
        case 2:
            display();
            clear();

            break;
        case 3:
            ab=search();
            printf(" ------------------------------\n");
            printf(" |  Search Result             |\n");
            printf(" ------------------------------\n");

            printf(" ----------------------------------\n");
            printf(" |  Student ID  :%s\n",array[ab].id);

            printf(" |  Name        :%s %s\n",array[ab].f_name,array[ab].l_name);
            printf(" |  Phone Number:%s\n",array[ab].p_number);
            printf(" |  Blood Group :%s\n",array[ab].b_group);
            printf(" |  Section     :%s\n",array[ab].section);
            printf(" |  Total Paid  :%d\n",array[ab].tk);
            printf(" -----------------------------------\n");
            clear();

            break;
        case 4:
            delet();
            save_to_file();
            clear();
            break;
        case 5:
            payment();
            save_to_file();
            clear();
            break;
        case 6:
            printf("Enter amount:");
            scanf("%d",&f);
            taka=taka-f;
            save_to_file();
            clear();

            break;

        case 7:
            exit(1);
            break;
            break;
        default:
            puts("");

        }

    }



}



void entry()
{

    person c;


    printf("Enter Student ID:");
    scanf("%s",c.id);


    printf("Enter First Name:");
    scanf("%s",c.f_name);

    printf("Enter Last Name:");
    scanf("%s",c.l_name);

    printf("Enter Phone Number:");
    scanf("%s",c.p_number);

    printf("Enter Blood Group:");
    scanf("%s",c.b_group);


    printf("Enter Section:");
    scanf("%s",c.section);
    c.tk=1;

    array[top]=c;
    top++;
}
void display()
{
    int i;
    printf("------------------------------\n");
    for(i=0; i<top; i++)
    {
        printf("|  Student ID  :%s\n",array[i].id);

        printf("|  Name        :%s %s\n",array[i].f_name,array[i].l_name);
        printf("|  Phone Number:%s\n",array[i].p_number);
        printf("|  Blood Group :%s\n",array[i].b_group);
        printf("|  Section     :%s\n",array[i].section);
        printf("|  Total Paid  :%d\n",array[i].tk);
        printf("------------------------------\n");
    }
    printf("\n\n\n");

}

void save_to_file()
{
    FILE *fp;
    if((fp=fopen("durjoy.db","wb"))==NULL)
    {
        puts("Error: Can't create the database");
        return;

    }
    if(fwrite(&top,sizeof(top),1,fp)!=1)
    {

        puts("Error : Can't save data");
        return;
    }
    if(fwrite(&taka,sizeof(taka),1,fp)!=1)
    {

        puts("Error : Can't save data");
        return;
    }
    if(fwrite(array,sizeof(array),1,fp)!=1)
    {
        puts("Error : Can't save data");
        return;
    }
}
void read_from_file()
{
    FILE *fp;
    if((fp=fopen("durjoy.db","rb"))==NULL)
    {

        puts("Error: Can't read data!");
        return;
    }
    if(fread(&top,sizeof(top),1,fp)!=1)
    {
        puts("Error: Can't read data!");
        return;

    }
    if(fread(&taka,sizeof(taka),1,fp)!=1)
    {
        puts("Error: Can't read data!");
        return;

    }
    if(fread(array,sizeof(array),1,fp)!=1)
    {
       // puts("Error: Can't read data!1");
        return;
    }

}
int search()
{
    int i,flag=0;
    char a[10];
    printf("Enter ID:");
    scanf("%s",a);
    for(i=0; i<top; i++)
    {

        if(strcmp(array[i].id,a)==0)
        {

            flag=1;
            break;
        }
    }
    if(flag!=1)
    {
        printf("No Data Found!!\n");
        return;
    }
    return i;


}
void clear()
{

    system("PAUSE");
    system("CLS");
}
void delet()
{
    int temp;
    temp=search();
    int i;
    for(i=temp; i<top; i++)
    {
        array[i]=array[i+1];
    }
    top--;
}
int src(char x[])
{
    int i,flag=0;

    for(i=0; i<top; i++)
    {

        if(strcmp(array[i].id,x)==0)
        {

            flag=1;
            break;
        }
    }
    if(flag==1)
    {

        return 1;
    }
    else
    {
        return 0;
    }


}
void payment()
{
    char x[10];
    printf("Enter ID:");
    scanf("%s",x);
    int flg=src(x);
    int n,temp;
    if(flg>0)
    {
        n=search();
        printf("Enter Amount: ");
        scanf("%d",&temp);

        array[n].tk=array[n].tk+temp;
        taka=taka+temp;
        printf("Money Added\n!!");

    }
}








