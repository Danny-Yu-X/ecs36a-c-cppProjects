//Array
//need null to have string
#include<stdbool.h>
//Any and all checks
bool all(bool values[], int len){
    for(int i =0; i<len; ++i){
        if(values[i]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

bool any(bool values[], int len){
    for(int i=0; i<len; ++i){
        if(values[i]){
            return true;
        }
    }
    return false;
}

//Mulitdimensional array
// type name [dim1size][dim2size][dim3size]

#include<stdio.h>
#include<stdlib.h>
void sort(int nums[], int len){
    for (int i =0;i<len;++i){
        int smallest_index = find_index_of_min(nums,len);
        swap(nums, smallest_index, i);
    }
}
int find_index_of_min(int ar[], int size){
    int smallest_index = 0;
    for(int i = 1; i<size; ++i){
        if(ar[i]<ar[smallest_index]){
            smallest_index = i;
        }
    }
    return smallest_index;
}
void swap(int ar[], int pos1, int pos2){
    int temp = ar[pos1];
    ar[pos1]=ar[pos2];
    ar[pos2]=temp;

}
void fill_with_random(int nums[], int len, int min, int max){
    for (int i = 0;i<len;++i){
        nums[i] = get_random_number_between(min,max);
    }
}
int get_random_number_between(int min, int max){
    return min + rand()%(max-min+1);
}
void print_ar(int ar[], int len){
    for(int i = 0; i<len;++i){
        printf("%d", ar[i]);
    }
}
int main(){
    int nums[10];
    int len = 10;
    srand(50);

    fill_with_random(nums, len, -100, 100);
    print_ar(nums, len);
    
    sort(nums, len);
    print_ar(nums,len);
}

/* gbd
compile with -g

gbd --tui exe_name
run args


conditional breakpoint
watch
*/



Prob();

int* p;
//ValueAt() removes a pointer *
//AddressOf() adds a pointer &