/*
Group: Ian Marwong, Danny Yu
This program decides whether it is better to pay off a loan or to invest for retirement
*/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
double getPosDouble(const char* prompt);
double getValidDouble(const char* prompt);
bool isValidFormat(const int numArgsRead, const int numArgsNeed);
int getPosInt(const char* prompt);
int getValidInt(const char* prompt);
int getIntAtLeast(int min_val, const char* prompt);
double getDoubleAtLeast(double min_val, const char* prompt);
double PayLoan(double amountOwed, double annualInterestRate, double minPayment, double monthlyPayment, double rateOfReturn, int curAge, int retAge);
double MinPay(double amountOwed, double annualInterestRate, double minPayment, double monthlyPayment, double rateOfReturn, int curAge, int retAge);

int main(){
    double amountOwed, annualInterestRate, minPayment, monthlyPayment, rateOfReturn;
    int curAge, retAge;
    amountOwed = getPosDouble("Enter how much you owe in loans: ");
    annualInterestRate = getPosDouble("Enter the annual interest rate of the loans: ");
    minPayment = getPosDouble("Enter your minimum monthly loan payment: ");
    monthlyPayment = getDoubleAtLeast(minPayment,"Enter how much money you will be putting towards loans/retirement each month: ");
    curAge = getPosInt("Enter your current age: ");
    retAge = getIntAtLeast(curAge, "Enter the age you plan to retire at: ");
    rateOfReturn = getPosDouble("Enter your predicted annual rate of return: ");
    double investpay = MinPay(amountOwed, annualInterestRate, minPayment, monthlyPayment, rateOfReturn, curAge, retAge);
    double paydebt = PayLoan(amountOwed, annualInterestRate, minPayment, monthlyPayment, rateOfReturn, curAge, retAge);
    if(investpay > paydebt){
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you paid off your loan before investing.", investpay, paydebt);
    }else if (investpay <= paydebt){
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", monthlyPayment);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.", paydebt, investpay);
    }
    
return 0;
    
}

double getPosDouble(const char* prompt){
  /*
  Function validates for a positive double
  @param prompt is the text shown on the screen telling the user what to input
  @returns a positive double
  */
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= 0));

  return num;
}

double getValidDouble(const char* prompt){
  /*
  Function validates for a double
  @param prompt is the text shown on the screen telling the user what to input
  @returns a double
  */
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num); //waffles\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  /*
  Function validates a given input
  @param numArgsRead is the number of arguments present in the inputted text
  @param numArgsNeed is the number of arguments that should be there
  @returns if the input is in a valid state
  */
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); //45  bob  \n
		if(!isspace(character)){ //found a non whitespace character on the way to the end of the line
			formatIsGood = false;
		}
	}while(character != '\n'); //read characters until the end of the line
  return formatIsGood;
}

int getPosInt(const char* prompt){
  /*
  Function validates for a positive integer
  @param prompt is the text shown on the screen telling the user what to input
  @returns a positive integer
  */
	int num;
  do{
    num = getValidInt(prompt);
  }while(!(num >= 0));

  return num;
}

int getValidInt(const char* prompt){
  /*
  Function validates for a integer
  @param prompt is the text shown on the screen telling the user what to input
  @returns an integer
  */
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num); // waffles 45\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

int getIntAtLeast(int min_val, const char* prompt){
  /*
  Function validates for an integer that is greater than a number
  @param min_val is the number that the integer should be greater than
  @param prompt is the text shown on the screen telling the user what to input
  @returns an integer that is greater than the given number
  */
  int num;
  do{
    num = getValidInt(prompt);
  }while(!(num >= min_val));

  return num;
}
double getDoubleAtLeast(double min_val, const char* prompt){
  /*
  Function validates for a double that is greater than a number
  @param min_val is the number that the double should be greater than
  @param prompt is the text shown on the screen telling the user what to input
  @returns a double that is greater than the given number
  */
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= min_val));

  return num;
}
double PayLoan(double amountOwed, double annualInterestRate, double minPayment, double monthlyPayment, double rateOfReturn, int curAge, int retAge){
    /*
    Function calculates the amount of money one would have if they paid off their loan, then invested.
    @param amountOwed is the amount of the loan
    @param annualInterestRate is the annual interest rate
    @param minPayment is the minimum monthly payment
    @param monthlyPayment is the amount of money being spent in that month
    @param rateOfReturn is the annual return on investment
    @param curAge is the current age
    @param retAge is the age of retirement
    @returns the amount of money one would have if they directly paid the loan
    */
    double monthInterest = annualInterestRate / 12.0;
    double interestDollars;
    double monthROR = rateOfReturn / 12.0;
    double investments;
    

    for(int i = curAge * 12 + 1; i < retAge * 12; ++i){
        interestDollars = amountOwed * monthInterest;
        amountOwed += interestDollars;
        if (amountOwed < monthlyPayment){
            if (amountOwed > 0){
                investments = monthlyPayment-amountOwed;
                amountOwed=0;
            }
            double interestInvest = investments * monthROR;
            investments = investments + interestInvest;
            investments += monthlyPayment;
        }else{
        amountOwed = amountOwed - monthlyPayment;
        }
    }
    interestDollars = amountOwed * monthInterest;
    //amountOwed += interestDollars;
    
    return investments - amountOwed;
}
double MinPay(double amountOwed, double annualInterestRate, double minPayment, double monthlyPayment, double rateOfReturn, int curAge, int retAge){
    /*
    Function calculates the amount of money one would have if they invested then paid their loan.
    @param amountOwed is the amount of the loan
    @param annualInterestRate is the annual interest rate
    @param minPayment is the minimum monthly payment
    @param monthlyPayment is the amount of money being spent in that month
    @param rateOfReturn is the annual return on investment
    @param curAge is the current age
    @param retAge is the age of retirement
    @returns the amount of money one would have if they invested, then paid the loan
    */
    double monthInterest = annualInterestRate / 12.0;
    //double interestDollars;
    double monthROR = rateOfReturn / 12.0;
    double investments;
    double extra;
    for(int i = curAge * 12 + 1; i <= retAge * 12; ++i){
        amountOwed *= (1 + monthInterest);
        investments *= (1 + monthROR);

        if(amountOwed > 0){
            if(amountOwed>minPayment){
                amountOwed -= minPayment;
                investments += (monthlyPayment-minPayment);
            }else{
                extra = minPayment-amountOwed;
                amountOwed = 0;
                investments += (extra + (monthlyPayment-minPayment));
            }
        }else{
            investments += monthlyPayment;
        }
        
    }
    return investments - amountOwed;
}
