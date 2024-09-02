// Recursion

/*
define problem
base case (do nothing)
shrink problem (get closer to base case)
recursive case
Combine Results (add shrink to recursive)
*/
#include <stdbool.h>

void washDishes(Dish* dishes, int num_dishes){
    if(num_dishes ==0){
        printf("Done");
    }else{
        dishes[0].status = clean;
        washDishes(dishes + 1,num_dishes -1);
    }
}

int recSum(int* numbers, int length){
    if(length == 0){
        return 0;
    }else{
        int sum_rest = recSum(numbers +1, length -1);
        return numbers[0] + sum_rest;
    }
}

int main(){
    int nums[] = {1, 2, 3, 4, 5};
    int len = 5;
    printf("%d\n", recSum(nums, len));
    return 0;
}


//Two strings are equal to each other
//hello, hi
//base: empty means equal
//base: if first letter are different, not equal
//shrink: remove first character
// recursive: check the remaining


bool are_str_equal(char* str1, char* str2){
    if(str1 == '\0' && str2 == '\0'){
        return true;
    }else if (str1[1] != str2[1]){
        return false;
    }else{
        return are_str_equal(str1+1, str2+1);
    }
}

/*
prob: list all premutations
base: empty list
shrink: take out first value
recursion: find rest
*/
/*
prob: find index for array
base: empty
Base: middle value
recursive: if value we look for is less than middle, first half, otherwise look second half
*/

int bin_search(int to_find, int* values, int len){
    if(len==0){
        return -1;
    }

    int midpoint = len/2;
    int midvalue = values[midpoint];

    if(midvalue == to_find){
        return midpoint;
    }else if(to_find < midvalue){
        return bin_search(to_find, values, len/2);
    }else{
        int left_side_len = midpoint;
        int right_side_len = len - left_side_len -1;
        return bin_search(to_find, values + midpoint+1, right_side_len);
    }
}

