/*

total = 0
1. for each item given
    2. count times until breaks
    3. add count to total

2. the avg to failure is total/num

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
double get_average_uses_until_failure(int num_sims, double prob_of_failure);
int simulate_uses_until_failure(double prob_of_failure);
double get_random_double(double min, double max);
int simulate_uses_until_failure(double prob_of_failure);

double get_average_uses_until_failure(int num_sims, double prob_of_failure){
    int total = 0;
    for(int sim = 0; sim < num_sims; ++sim){
        total += simulate_uses_until_failure(prob_of_failure);
    }
    return total / (double) num_sims;
}

double get_random_double(double min, double max){
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

/*

*/

int simulate_uses_until_failure(double prob_of_failure){
    int count = 0;
    
    while(get_random_double(0,1)<prob_of_failure){
        count += 1;
    }

    return count;
}

int main(){
    int num_sims;
    double prob_of_failure;
    srand(time(NULL));
    printf("Enter the number of simulation to run: ");
    scanf("%d", &num_sims);

    printf("Enter the odds of failure as decimal");
    scanf("%lf", &prob_of_failure);

    printf("On average you will get %.2lf uses before the item breaks", get_average_uses_until_failure(num_sims,prob_of_failure));
    return 0;
}