/*
Group: Ian Marwong, Danny Yu
Program calculates the roots for a given qudratic equation
*/

#include <stdio.h>
#include <math.h>
/*Function checks the number of real soulutions
Parameter a is the coefficient of the leading term of the equation (ax^2)
Parameter b is the coefficient of the second term of the equation (bx)
Parameter c is the constant of the equation (c)
Function returns the number of real solutions (0,1,2)*/
int IsReal(double a, double b, double c){
    if(pow(b, 2)- 4 * a * c > 0){
        return 2;
    }else if(pow(b, 2)- 4 * a * c == 0){
        return 1;
    }else{
        return 0;
    }
}
/*Function calculates the root using the positive square root of the quadratic formula
Parameter a is the coefficient of the leading term of the equation (ax^2)
Parameter b is the coefficient of the second term of the equation (bx)
Parameter c is the constant of the equation (c)
Function returns a real solution
*/
double PosEquation(double a, double b, double c){
    double ans = (-b + sqrt((pow(b,2) - 4 * a * c)))/(2 * a);
    return ans;
}
/*Function calculates the root using the negative square root of the quadratic formula
Parameter a is the coefficient of the leading term of the equation (ax^2)
Parameter b is the coefficient of the second term of the equation (bx)
Parameter c is the constant of the equation (c)
Function returns a real solution
*/
double NegEquation(double a, double b, double c){
    double ans = (-b - sqrt((pow(b,2) - 4 * a * c)))/(2 * a);
    return ans;
}
int main(){
    double a, b, c;
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);

    if (IsReal(a, b, c) == 2){
        printf("There are %d real solutions", IsReal(a, b, c));
        printf("\nSolution 1: %.2lf", PosEquation(a, b, c));
        printf("\nSolution 2: %.2lf", NegEquation(a, b, c));
    }else if (IsReal(a, b, c) == 1){
        printf("There is one real solution: %.2lf", PosEquation(a, b, c));
    }else{
        printf("There are no real solutions");
    }

    return 0;
}
