#include<stdlib.h>
#include<stdio.h>

//declared variables
char card_num [] = "1234123412341234";
char password [] = "pASSword#0";
char ID [] = "12345678";
char first_name [] = "Yejun";
char last_name [] = "Choi";
int day = 7;
int month = 12;
int year = 1972;
int cheqAccNum = 111111;
int savAccNum = 222222;
int tfsaAccNum = 333333;
float cheqbal = 0.0;
float savbal = 0.0;
float tfsabal = 0.0;
//Function prints out all user information
void displayUserInfo(void) {
    printf("Customer Information \n");
    printf("Card Number : %s \n", card_num);
    printf("Customer ID : %s \n", ID);
    printf("Name: %s %s \n", first_name, last_name);
    printf("Birthdate: %d/%d/%d \n", month, day, year);
}

//Displays the each accounts status
void accountStatus(void) {
    printf("Account Status: \n");
    printf("Chequing: %d, $%.2f \n", cheqAccNum, cheqbal);
    printf("Savings: %d, $%.2f \n", savAccNum, savbal);
    printf("TFSA: %d, $%.2f \n", tfsaAccNum, tfsabal);
}

//Function compares each aray character the user inputed values to the correct values for user card number and password
int stringCompare(char a[], char b[]) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

//Authenticator Function
int userAuthenticator(void) {
    char card_enter[17];
    char pass_enter[11];
    int tries = 0;
    //After 3 tries, if user's input does not match the correct value, it exists
    while (tries < 3) {
        printf("Enter card number: \n");
        scanf("%16s", card_enter);
        printf("Enter password: \n");
        scanf("%10s", pass_enter);

        //Calls the function above to compare the arays
        if (stringCompare(card_num, card_enter) && stringCompare(password, pass_enter)) {
            return 1;
        }

        printf("Incorrect please try again. \n");
        tries++;
    }
    return 0;
}

//The function for the menu
char userOption(void)
{
    char option=0;
    printf("Please enter your choice\n"
           "1-Withdraw\n"
           "2-Deposit\n"
           "3-Transfer Money\n"
           "4-Exit\n");
    scanf(" %c", &option);
    return option;
}

//Withdraw function
void withDraw(void){
    double amount = 0.0;
    int account;
    int repeat;
    //while loop
    do{
        printf("Enter amount to withdraw: \n");
        scanf("%lf", &amount);

        printf(
            "Please select an account to withdraw from:\n"
            "1 Chequing\n"
            "2 Savings\n"
            "3 TFSA\n");
        scanf("%d", &account);

        if (account == 1){
            if (amount > cheqbal) {
                printf("Not enough funds in the account \n");
            }
            else {
            cheqbal -= amount;
            printf("The Updated Chequings account: $%.2f \n", cheqbal);
            }
        }

        else if (account == 2){
            if (amount > savbal) {
                printf("Not enough funds in the account \n");
            }
            else {
            savbal -= amount;
            printf("The Updated Savings account: $%.2f \n", savbal);
            }
        }

        else if (account == 3){
            if (amount > tfsabal) {
                printf("Not enough funds in the account \n");
            }
            else {
            tfsabal -= amount;
            printf("The Updated TFSA account: $%.2f \n", tfsabal);
            }
        }

        else {
            printf("Invalid account selection.\n");
        }
        printf("Do you want to continue withdrawing?:\n" "1 Yes\n" "2 No\n");
        scanf("%d", &repeat);
    }
    while (repeat ==1);
    return;
}

//Deposit function
void deposit(void) {
    double amount = 0.0;
    int account;
    int repeat;
    do {
        printf("Enter amount to deposit: ");
        scanf("%lf", &amount);

        printf(
            "Please select an account to deposit from:\n"
            "1 Chequing\n"
            "2 Savings\n"
            "3 TFSA\n");

        scanf("%d", &account);
        if (account == 1) {
            cheqbal += amount;
            printf("The Updated Chequings account: $%.2f\n", cheqbal);
        }

        else if (account == 2) {
            savbal += amount;
            printf("The Updated Savings account: $%.2f\n", savbal);
        }

        else if (account == 3) {
            tfsabal += amount;
            printf("The Updated TFSA account: $%.2f\n", tfsabal);
        }
        else {
            printf("Invalid account selection.\n");
        }
        printf("New Chequing balance: $%.2f\n", cheqbal);
        printf("New Savings balance:  $%.2f\n", savbal);
        printf("New TFSA balance:     $%.2f\n", tfsabal);

        printf("Do you want to continue depositing?:\n" "1 Yes\n" "2 No\n"); scanf("%d", &repeat);
    }
    while (repeat == 1);
    return;
}

//Transfer function
void transfer(void) {
    double amount = 0.0;
    int to;
    int from;
    int repeat;

    do{
        printf("Enter amount to transfer: \n");
        scanf("%lf", &amount);

        printf("From what account do you want to transfer money?: \n");
        printf("1 Chequing\n" "2 Savings\n" "3 TFSA\n");
        scanf("%d", &from);
        printf("To what account do you want to transfer money?: \n");
        printf("1 Chequing\n" "2 Savings\n" "3 TFSA\n");
        scanf("%d", &to);

        if ((from == 1 && amount > cheqbal) || (from == 2 && amount > savbal)  ||(from == 3 && amount > tfsabal)) {
            printf("Not Enough Funds\n");
        }
        else {
            //subtracting
            if (from == 1)
                cheqbal -= amount;
            else if (from == 2)
                savbal -= amount;
            else if (from == 3)
                tfsabal -= amount;
            else
            printf("Invalid account selection.\n");

            //adding
            if (to == 1)
                cheqbal += amount;
            else if (to == 2)
                savbal += amount;
            else if (to == 3)
                tfsabal += amount;
            else
            printf("Invalid account selection.\n");

        }
    printf("Do you want to continue transferring?:\n" "1 Yes\n" "2 No\n"); scanf("%d", &repeat);
    }
    while (repeat == 1);
    return;
}

int main(void)
{
    int auth = userAuthenticator();
    if (auth == 0) {
        // auth == 0 means authentication failed
        printf("Username or Password incorrect\n");
        return EXIT_FAILURE;
    }

    displayUserInfo();
    accountStatus();

    char usrOpt=0;
    while(1)
    {
        usrOpt=userOption();

        switch(usrOpt)
        {
        case '1':
            withDraw();
            break;
        case '2':
            deposit();
            break;
        case '3':
            transfer();
            break;
        case '4':
            break;
        default:
            printf("Incorrect option is selected.\n please try again\n");
        }
        if (usrOpt=='4') break;
    }
    return EXIT_SUCCESS;
}



