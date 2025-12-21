#include <stdio.h>
#include <stdlib.h>

int* merge(int* sorted1, int len1, int* sorted2, int len2){
    /*
    1. make answer array
    2. go through elements in sorted1 and sorted2 until go through all
        if current sorted1 < sorted2, add sorted1 to answer, move to next value in sorted1
        otherwise, sorted2 gets added and moved
    3. copy remaining elements from sorted1 and sorted2 to the end
    */

   int* answer = (int*)malloc((len1+len2)*sizeof(int));

   int i, j;
   int answer_index;
    for(i=0, j=0, answer_index = 0; i<len1 && j<len2; ++answer_index){
        if(sorted1[i]<sorted2[j]){
            answer[answer_index]= sorted1[i];
            ++i;
        }else{
            answer[answer_index]= sorted2[j];
            ++j;
        }
    }
    for(;i<len1; ++i, ++answer_index){
        answer[answer_index]=sorted1[i];
    }
    for(;j<len2; ++j, ++answer_index){
        answer[answer_index]=sorted2[j];
    }
}

/*
prob: sort array
shrink: split left/right
recursion: sort left and right
combine: left/right
*/
int* merge_sort(int* values, int len){
    if(len==0){
        return NULL;

    }else if(len ==1){
        int* answer = (int*)malloc(len*sizeof(int));
        answer[0]=values[0];
    }else{
        int midpoint = len/2;
        int* left = values;
        int* right = values + midpoint;

        int* sortedleft = merge_sort(left, midpoint);
        int* sortedright = merge_sort(right, len-midpoint);

        int* answer = merge(sortedleft, midpoint, sortedright, len-midpoint);
        if(sortedleft != NULL){
            free(sortedleft);
        }
        if(sortedright != NULL){
            free(sortedright);
        }

        return answer;
    }

}