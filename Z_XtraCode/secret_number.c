/*
1. pick secret num
2. until user's guess is the secret number
    2.1 ask user for guess
    2.2 if closer than previous guess, tell them
    2.3 if farther than previous guess, tell them
    2.4 but if guess is just as far as previous guess, tell them
3. say they won

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
void secret_number_game(const int secret_number);
bool is_closer(int new, int old, int target);
bool is_farther(int new, int old, int target);
bool is_same_distance(int new, int old, int target);

void secret_number_game(const int secret_number){
    int user_guess, previous_guess;

    printf("Guess a number between 1 - 100: ");
        scanf("%d", &user_guess);

        previous_guess = user_guess;

    while(user_guess != secret_number){
        printf("Guess a number between 1 - 100: ");
        scanf("%d", &user_guess);
        if(user_guess == secret_number){
            break;
        }
        if(is_closer(user_guess, previous_guess, secret_number)){
            printf("Your guess of %d is closer than your last guess of %d\n", user_guess, previous_guess);
        }else if(is_farther(user_guess, previous_guess, secret_number)){
            printf("Your guess of %d is farther than your last guess of %d\n", user_guess, previous_guess);
        }else if(is_same_distance(user_guess, previous_guess, secret_number)){
            printf("Your guess of %d is just as far than your last guess of %d\n", user_guess, previous_guess);
        }
        previous_guess = user_guess;
    }

    printf("You guessed my secret number of %d", secret_number);
}

bool is_closer(int new, int old, int target){
    /*
    Checks if new is closer to the target than old
    @param new: the new guess
    @param old: the old guess
    @param target: the value we are looking to find
    @returns: true if new is closer to target than old
    */
   return abs(target - new) < abs(target - old);
}
bool is_farther(int new, int old, int target){
    /*
    Checks if new is farther to the target than old
    @param new: the new guess
    @param old: the old guess
    @param target: the value we are looking to find
    @returns: true if new is farther to target than old
    */
   return abs(target - new) > abs(target - old);
}
bool is_same_distance(int new, int old, int target){
    /*
    Checks if new is the same distance to the target than old
    @param new: the new guess
    @param old: the old guess
    @param target: the value we are looking to find
    @returns: true if new is same distance to target than old
    */
   return abs(target - new) == abs(target - old);
}

int get_random_number_between(int min, int max){
    /*
    Generate a random value between [min, max] inclusive
    @param min: the min num that can be genreated
    @param max: the max num that can be generated
    @return: a random value between[min,max]
    */
   int range = max - min + 1;

   return min + rand() % range;
}

double get_random_double_between(double min, double max){
    /*
    Generate a random value between [min, max] inclusive
    @param min: the min num that can be genreated
    @param max: the max num that can be generated
    @return: a random value between[min,max]
    */
   double range = max - min;
   double percent_range_traveled = ((double)rand()) / RAND_MAX;

   return min + range * percent_range_traveled;
}
int main(){
    srand(time(NULL));
    const int secret_number = get_random_number_between(1,100);
    secret_number_game(secret_number);
    return 0;
}