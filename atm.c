#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Functions
void main_Menu();
void check_Balance(float balance);
float money_Deposit(float balance);
float money_Withdraw(float balance);
void menu_Exit();
void error_Message();

//Main Code
int main()
{
    //Local Declarations
    int option,pin;
    float balance = 00.00;
    int choose;
    bool again = true;
    char name[20],passwd[8];
    printf("ENTER USERNAME: ");
    scanf("%s",name);
    printf("ENTER PASSWORD: ");
    scanf("%s",passwd);
    while (pin != 1520)
	{
		printf("ENTER YOUR SECRET PIN NUMBER: ");
		scanf("%d", &pin);
		if (pin != 1520)
		printf("\n!!!!PLEASE ENTER VALID PIN NUMBER!!!!\n\n");
	}

    while (again)
    {
        main_Menu();
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        printf("Your Selection:\t");
        scanf("%d", &option);
        switch (option)
        {
            case 1:
                check_Balance(balance);
                break;
            case 2:
            	balance = money_Deposit(balance);
                break;
            case 3:
                balance = money_Withdraw(balance);
                break;
            case 4:
            	menu_Exit();
                return 0;
            default:
                error_Message();
                break;
        }
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);
        if (choose == 2)
        {
            again = false;
            menu_Exit();
        }
        if(choose!=1 && choose!=2)
        {
            printf("\n!!!!Wrong choice. Please choose valid number!!!!");
            exit(0);
        }

    }
    return 0;
}

//Main Menu
void main_Menu()
{
    printf(" \n\n                Hello!                \n");
    printf("     Welcome to Automated Banking Machine      \n");
    printf("****Please choose one of the options below****\n\n");
    printf("< 1 >  Check Balance\n");
    printf("< 2 >  Deposit\n");
    printf("< 3 >  Withdraw\n");
    printf("< 4 >  Exit\n\n");
}

//Check Balance
void check_Balance(float balance)
{
    printf("\nYou Choose to See your Balance\n");
    printf("\n\nYour Available Balance is: %.2f\n\n", balance);
}

//money deposit
float money_Deposit(float balance)
{
    float deposit;
    printf("\nYou choose to Deposit a money\n");
    printf("\n\nYour Balance is: %.2f\n\n", balance);
    printf("\n\nEnter your amount to Deposit\n");
    scanf("%f", &deposit);
    balance += deposit;
    printf("\n****Your New Balance is: %.2f****\n\n", balance);
    return balance;
}

//money withdraw
float money_Withdraw(float balance)
{
    float withdraw;
    printf("You choose to Withdraw a money\n");
    printf("\n\nYour Balance is: %.2f\n\n", balance);
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);
    if (withdraw < balance)
    {
        balance -= withdraw;
        printf("\nYour withdrawing money is:%.2f\n", withdraw);
        printf("****Your New Balance is: %.2f****\n\n", balance);
    }
    else 
    {
        printf("\n\n !!!!You don't have enough money!!!!\n");
        printf("****Your Balance is: %.2f****\n\n", balance);
    }
    return balance;
}

//exit menu
void menu_Exit()
{
    printf("-----Thank you for using ATM Banking Machine!!!-----\n");
}

//error message
void error_Message()
{
    printf("\n!!!!You selected invalid number!!!!\n");
}
