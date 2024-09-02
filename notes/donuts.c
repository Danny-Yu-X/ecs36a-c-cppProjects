
/*
1. Get the number of people in class
2. Get the number of donuts we brought
3. Figure out how many donuts each classmate gets: donuts / classmate
4. Fins the remainder and keep donuts for ourselves
*/

#include <stdio.h>


int main(){
    int num_classmates, num_donuts;
    int donuts_per_classmates, donuts_for_me;

    printf("Enter how many people are in class today: ");
    scanf(" %d", &num_classmates);

    printf("Enter the number of donuts you brought: ");
    scanf(" %d", &num_donuts);

    // +1 is for me cause I want to eat donuts to
    donuts_per_classmates = num_donuts / (num_classmates +1);
    int leftover_donuts = num_donuts % (num_classmates +1);
    donuts_for_me = donuts_per_classmates + leftover_donuts;

    printf("Give everyone %d donuts and keep %d donuts for yourself\n", donuts_per_classmates, donuts_for_me);


    return 0;
}