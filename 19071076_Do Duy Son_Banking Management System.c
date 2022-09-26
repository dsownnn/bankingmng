#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int main_exit;
void menu();

struct date{
    int month,day,year;
    };

struct {

    char name[60];
    int accNumber,age;
    char address[60];
    char citizenship[15];
    char phone;
    char accType[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(amount*t*rate/100);
    return (SI);
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

int main()
{
    char pass[10],password[10]="son";
    int i=0;
    printf("\n\n\t\t\t\t*********");
    printf("\n\n\t\t\tBANKING MANAGEMENT SYSTEM");
    printf("\n\n\t\t==========================================");
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(50000000);
            printf(".");
        }
            system("cls");
            menu();
        }

    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}

void menu(void)
{
    int choice;
    system("cls");
    system("color F");
    printf("\n\n\t\t\t\tBANKING MANAGEMENT SYSTEM");
    printf("\n\n\t\t==========================================================");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\t\t1. Create new account\n\t\t2. Update information of existing account\n\t\t3. For transactions\n\t\t4. Check the details of existing account\n\t\t5. Removing existing account\n\t\t6. View accounts list\n\t\t9. Exit\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:newAccount();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:viewList();
        break;
        case 9:close();
        break;
    }

}

void newAccount()
{
    int choice;
    FILE *ptr;

    ptr=fopen("data.txt","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\xB2  CREATE A NEW ACCOUNT  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter the account number:");
    scanf("%d",&check.accNumber);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.accNumber==add.accNumber)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;
            }
    }
    printf("\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    add.accNumber=check.accNumber;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.accType);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter\t1 to go to the main menu\n\t\t\t2 to create another account\n\t\t\t3 to view full list of accounts:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==2)
        newAccount();
    else if(main_exit==3)
        viewList();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("data.txt","r");
    newrec=fopen("cache.txt","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.accNumber);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.accNumber==upd.accNumber)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new phone:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
            /*else if(choice==3)
                {
                printf("Enter the new account name:");
                scanf("%s",&upd.name);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Changes saved!");
                }
                =====dang phat trien=====*/

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("data.txt");
    rename("cache.txt","data.txt");

    if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter\t1 to try again\n\t2 to return to main menu\n\t3 to add a new account\n\t4 to check the account list::");
              scanf("%d",&main_exit);
              system("cls");
                if(main_exit==1)
                    edit();
                else if (main_exit==2)
                    menu();
                else if (main_exit==3)
                    newAccount();
                else if (main_exit==4)
                    viewList();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter\t1 to go to the main menu\n\t2 to edit another account\n\t3 to add a new account\n\t4 to check the account list:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            edit();
        else if (main_exit==3)
            newAccount();
        else if (main_exit==4)
            viewList();
        }
}

void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("data.txt","r");
    newrec=fopen("cache.txt","w");

        printf("Enter the account no. of the customer and 0 if there is no value:");
    scanf("%d",&transaction.accNumber);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.accNumber==transaction.accNumber)
            {   test=1;
                if(strcmpi(add.accType,"fixed1")==0||strcmpi(add.accType,"fixed2")==0||strcmpi(add.accType,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("data.txt");
   rename("cache.txt","data.txt");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter\t1 to go to the main menu\n\t2 to transact again:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            transact();
   }

}

void see(void)
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("data.txt","r");
    printf("Do you want to check by\n1. Account no\n2. Citizen ID No.\n3. Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.accNumber);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(add.accNumber==check.accNumber)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizen ID No.:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.accType,"fixed1")==0)
                    {
                        time=1.0;
                        rate=5;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);

                    }
                else if(strcmpi(add.accType,"fixed2")==0)
                    {
                        time=2.0;
                        rate=6;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%.2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.accType,"fixed3")==0)
                    {
                        time=3.0;
                        rate=7;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%.2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.accType,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=5;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%.2f as interest on the %d of every month",add.name,intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.accType,"current")==0)
                    {
                        printf("\n\%s will get no interest\a\a",add.name);
                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the citizen ID no.:");
        scanf("%s",&check.citizenship);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
        {
            if(strcmpi(add.citizenship,check.citizenship)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizen ID No.:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.accType,"fixed1")==0)
                    {
                        time=1.0;
                        rate=5;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);

                    }
                else if(strcmpi(add.accType,"fixed2")==0)
                    {
                        time=2.0;
                        rate=6;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%.2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                    }
                else if(strcmpi(add.accType,"fixed3")==0)
                    {
                        time=3.0;
                        rate=7;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%.2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                    }
                 else if(strcmpi(add.accType,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=5;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\n%s will get $%.2f as interest on the %d of every month",add.name,intrst,add.deposit.day);

                     }
                 else if(strcmpi(add.accType,"current")==0)
                    {
                        printf("\n\%s will get no interest\a\a",add.name);
                     }

            }
        }
    }
        else if (choice==3)
        {   printf("Enter the name:");
            scanf("%s",&check.name);
            while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
            {
                if(strcmpi(add.name,check.name)==0)
                {   system("cls");
                    test=1;
                    printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                    add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    if(strcmpi(add.accType,"fixed1")==0)
                        {
                            time=1.0;
                            rate=5;
                            intrst=interest(time,add.amt,rate);
                            printf("\n\n%s will get $%.2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                        }
                    else if(strcmpi(add.accType,"fixed2")==0)
                        {
                            time=2.0;
                            rate=6;
                            intrst=interest(time,add.amt,rate);
                            printf("\n\n%s will get $%.2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                        }
                    else if(strcmpi(add.accType,"fixed3")==0)
                        {
                            time=3.0;
                            rate=7;
                            intrst=interest(time,add.amt,rate);
                            printf("\n\n%s will get $%.2f as interest on %d/%d/%d",add.name,intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                        }
                     else if(strcmpi(add.accType,"saving")==0)
                        {
                            time=(1.0/12.0);
                            rate=5;
                            intrst=interest(time,add.amt,rate);
                            printf("\n\n%s will get $%.2f as interest on %d of every month",add.name,intrst,add.deposit.day);

                         }
                     else if(strcmpi(add.accType,"current")==0)
                        {
                            printf("\n\n%s will get no interest\a\a",add.name);

                         }

                }

            }
        }

    fclose(ptr);
        if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter\t1 to return to main menu\n\t2 to try again\n\t0 to exit the program:");
              scanf("%d",&main_exit);
              system("cls");
                if (main_exit==0)
                    close();
                else if (main_exit==1)
                    menu();
                else if(main_exit==2)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }

        else
        {printf("\nEnter\t1 to go to the main menu\n\t2 to check another account\n\t0 to exit the program:");
        scanf("%d",&main_exit);
              system("cls");
                if (main_exit==0)
                    close();
                else if (main_exit==1)
                    menu();
                else if(main_exit==2)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }

}

void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("data.txt","r");
    newrec=fopen("cache.txt","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.accNumber);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.accNumber!=rem.accNumber)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.accNumber,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.accType,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("data.txt");
   rename("cache.txt","data.txt");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter\t1 to try again\n\t2 to return to main menu\n\t0 to exit the program:");
              scanf("%d",&main_exit);

                 if (main_exit==2)
                    menu();
                else if (main_exit==1)
                    erase();
                else if(main_exit==0)
                    close();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter\t1 to go to the main menu\n\t2 to erase another account:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            erase();
        }

}

void viewList()
{
    FILE *view;
    view=fopen("data.txt","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\tACC. TYPE\t\tAMOUNT\t\t\t   ADDRESS\t\tCITIZEN ID No.\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.accNumber,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.accType,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
       {
           printf("\n%6d\t%12s\t\t%s\t\t\t%.03f\t\t%10s\t\t%s",add.accNumber,add.name,add.accType,add.amt,add.address,add.citizenship);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    viewList_invalid:
     printf("\n\nEnter\t1 to go to the main menu\n\t2 to edit the information\n\t3 to see the account detail:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==2)
            edit();
        else if(main_exit==3)
            see();
        else
        {
            printf("\nInvalid!\a");
            goto viewList_invalid;
        }
}

void close(void)
{
    printf("\n\n\n\nBanking Management System");
    printf("\n==========================================\nClosing");
    for(i=0;i<=6;i++)
        {
            fordelay(50000000);
            printf(".");
        }
}
