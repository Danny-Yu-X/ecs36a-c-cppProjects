/*
Group: Ian Marwong, Danny Yu
Program calculates a final percentage based on wanted grade, current grade, and weight of final
*/

#include <stdio.h>
// Function calculates the final percentage
// Parameter percentNeeded is the percent needed to get the grade the user wants
// Parameter currentPercent is the current grade the user has
// Parameter finalWeight is the weight of the final
double FinalPercent(double percentNeeded, double currentPercent, double finalWeight){
    double miscWeight = 100 - finalWeight;
    
    double notFinalGrade = currentPercent * (miscWeight/100);
    
    double finalCat = percentNeeded - notFinalGrade;
    
    double finalPercent = finalCat / (finalWeight / 100);

    return finalPercent;
}
int main(){

    char gradeWanted;
    printf("Enter the grade you want in the class: ");
    scanf("%c", &gradeWanted);

    double percentNeeded;
    printf("Enter the percent you need to get that grade: ");
    scanf("%lf", &percentNeeded);

    double currentPercent;
    printf("Enter your current percent in the class: ");
    scanf("%lf", &currentPercent);

    double finalWeight;
    printf("Enter the weight of the final: ");
    scanf("%lf", &finalWeight);

    double finalPercent = FinalPercent(percentNeeded, currentPercent, finalWeight);
    
    printf("You need to get at least %.2lf%% on the final to get a %c in the class.", finalPercent, gradeWanted);
    return 0;
}