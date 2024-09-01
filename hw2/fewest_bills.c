/*
Group: Ian Marwong, Danny Yu

This program asks the user for an amount of money to withdraw,
then outputs the fewest number of bills for each denomination (1, 5, 10, 20, 50, 100)
*/
#include <stdio.h>

/* Function takes the current withdrawal amount and divides it by the specified denomination
 Parameter amount is the remaining amount of money 
 Parameter denomination is what bill type is being calculated*/
int division(int amount, int denomination){
    int total;
    total = amount / denomination;
    return total;
}
/* Function subtracts the amount of money given from the current amount of money
Parameter num1 is the current amount of money
Parameter num2 is the number of bills multiplied by the type of bill*/
int subtract(int num1, int num2){
    int newAmount;
    newAmount = num1 - num2;
    return newAmount;
}

int main(){
    int withdraw;
    int amountLeft;
    printf("Please enter the amount of money you wish to withdraw: ");
    scanf("%d", &withdraw);

    printf("You received %d hundred(s)\n", division(withdraw, 100));
    amountLeft = subtract(withdraw, division(withdraw, 100) * 100);

    printf("You received %d fifty(s)\n", division(amountLeft, 50));
    amountLeft = subtract(amountLeft, division(amountLeft, 50) * 50);

    printf("You received %d twenty(s)\n", division(amountLeft, 20));
    amountLeft = subtract(amountLeft, division(amountLeft, 20) * 20);

    printf("You received %d ten(s)\n", division(amountLeft, 10));
    amountLeft = subtract(amountLeft, division(amountLeft, 10) * 10);

    printf("You received %d five(s)\n", division(amountLeft, 5));
    amountLeft = subtract(amountLeft, division(amountLeft, 5) * 5);

    printf("You received %d one(s)", amountLeft);

    return 0;
}