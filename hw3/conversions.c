/*
Group: Ian Marwong, Danny Yu

Program performs temperature and distance conversions

*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

double Celsius(double inputTemp, char inputTempUnit);
double TempConverter(double inputTemp, char inputTempUnit, char outputTempUnit);
double Yards(double inputDist, char inputDistUnit);
double DistConverter(double inputDist, char inputDistUnit, char outputDistUnit);
bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line);

double Celsius(double inputTemp, char inputTempUnit) {
    /*
    Converts Kelvin and Fahrenheit to Celsius
    @param inputTemp: the number that we are converting from
    @param inputTempUnit: the unit that we are converting from
    @returns: the value in celsius or 9000 as an error number
    */
    double celsius;
    if (inputTempUnit == 'F'|| inputTempUnit == 'f') {
        celsius = (inputTemp - 32) * (5.0/9.0);
        return celsius;
    }else if (inputTempUnit == 'K'|| inputTempUnit == 'k') {
        celsius = inputTemp - 273.15;
        return celsius;
    }else {
        return 9000;
    }
}


double TempConverter(double inputTemp, char inputTempUnit, char outputTempUnit) {
    /*
    Converts temperature into other units
    @param inputTemp: the temperature that we are converting from
    @param inputTempUnit: the unit that we are converting from
    @param outputTempUnit: the unit we are looking to convert to
    @returns: the value of the temperature in the desired units or error message if invalid temperature type
    */
    double celsius;
    double fahr;
    double kelvin;
    if (inputTempUnit == 'F' || inputTempUnit == 'K'||inputTempUnit == 'f' || inputTempUnit == 'k') {
        celsius = Celsius(inputTemp, inputTempUnit);
    }else if (inputTempUnit == 'C' || inputTempUnit == 'c') {
        celsius = inputTemp;
    }
    if (outputTempUnit == 'C' || outputTempUnit == 'c') {

        return celsius;
    }else if (outputTempUnit == 'F' || outputTempUnit == 'f') {
        fahr = celsius * 9.0 / 5.0 + 32;
        return fahr;
    }else if (outputTempUnit == 'K' || outputTempUnit == 'k' ) {
        kelvin = celsius + 273.15;
        return kelvin;
    }else{
        printf("%c is not a valid temperature type. Ending program.", toupper(outputTempUnit));
        exit(0);
    }
}


double Yards(double inputDist, char inputDistUnit) {
    /*
    Converts Miles, Feet, and Inches to Yards
    @param inputDist: the number that we are converting from
    @param inputDistUnit: the unit that we are converting from
    @returns: the value in yards or 9000 as an error number
    */
    double yards;
    if (inputDistUnit == 'I') {
        yards = inputDist / 36.0;
        return yards;
    }else if (inputDistUnit == 'F') {
        yards = inputDist / 3.0;
        return yards;
    }else if (inputDistUnit == 'M') {
        yards = inputDist * 1760;
        return yards;
    }else{
        return 9000;
    }
}

double DistConverter(double inputDist, char inputDistUnit, char outputDistUnit) {
    /*
    Converts distance into other units
    @param inputDist: the distance that we are converting from
    @param inputDistUnit: the unit that we are converting from
    @param outputDistUnit: the unit we are looking to convert to
    @returns: the value of the distance in the desired units or error message if invalid temperature type
    */
    double inches;
    double feet;
    double yards;
    double miles;
    if (inputDistUnit == 'I' || inputDistUnit == 'F' || inputDistUnit == 'M') {
        yards = Yards(inputDist, inputDistUnit);
    }else if (inputDistUnit == 'Y') {
        yards = inputDist;
    }
    if (outputDistUnit == 'Y') {
        return yards;
    }else if (outputDistUnit == 'I') {
        inches = yards * 36;
        return inches;
    }else if (outputDistUnit == 'F') {
        feet = yards * 3;
        return feet;
    }else if (outputDistUnit == 'M') {
        miles = yards / 1760.0;
        return miles;
    }else{
        printf("%c is not a valid distance type. Ending program.", toupper(outputDistUnit));
        exit(0);
    }
}


bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line) {
    /*
    Checks to make sure user input in formatted properly
    @param num_args_needed: the number of arguments that should be present
    @param num_args_read: the number of arguments that was given by the user
    @param should_be_the_last_value_on_line: checks to see if last value on line should be new line
    @returns: whether the format is valid or not
    */
	 bool format_is_correct = num_args_read == num_args_needed;
	 if(should_be_last_value_on_line){
		char should_be_newline = '?';
		scanf("%c", &should_be_newline);
		format_is_correct = format_is_correct && should_be_newline == '\n';
	 }
	 return format_is_correct;
 }


int main() {
    char conversionType, inputTempUnit, outputTempUnit, inputDistUnit, outputDistUnit;
    double inputTemp, outputTemp, inputDist, outputDist;
    int num_args_read;

    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");

    num_args_read = scanf("%c", &conversionType);

    if(isValidFormat(1, num_args_read, true)){
        //TEMP
        if (conversionType == 't' || conversionType == 'T') {
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        num_args_read = scanf("%lf %c", &inputTemp, &inputTempUnit);
        if(isValidFormat(2, num_args_read, true)){
            inputTempUnit = toupper(inputTempUnit);
            if (inputTempUnit == 'F' || inputTempUnit == 'C' || inputTempUnit == 'K') {
                printf("Enter the new unit type (F, C, or K): ");
                num_args_read = scanf(" %c", &outputTempUnit);
                if(isValidFormat(1, num_args_read, true)){
                    outputTemp = TempConverter(inputTemp, inputTempUnit, outputTempUnit);
                    printf("%.2lf%c is %.2lf%c", inputTemp, inputTempUnit, outputTemp, toupper(outputTempUnit));
                }else{
                    printf("Invalid formatting. Ending program.");
                    exit(0);
                }
            }else {
                printf("%c is not a valid temperature type. Ending program.", inputTempUnit);
            }
        }else {
            printf("Invalid formatting. Ending program.");
            exit(0);
        }
    }else if (conversionType == 'd' || conversionType == 'D') { //DIST
            printf("Enter the distance followed by its suffix (I,F,Y,M): ");
            num_args_read = scanf("%lf %c", &inputDist, &inputDistUnit);
            if(isValidFormat(2, num_args_read, true)){
                inputDistUnit = toupper(inputDistUnit);
                if (inputDistUnit == 'I' || inputDistUnit == 'F' || inputDistUnit == 'Y' || inputDistUnit == 'M') {
                    printf("Enter the new unit type (I,F,Y,M): ");
                    num_args_read = scanf(" %c", &outputDistUnit);
                    if(isValidFormat(1, num_args_read, true)){
                        outputDistUnit = toupper(outputDistUnit);

                        outputDist = DistConverter(inputDist, inputDistUnit, outputDistUnit);
                        printf("%.2lf%c is %.2lf%c", inputDist, inputDistUnit, outputDist, outputDistUnit);
                    }else{
                        printf("Invalid formatting. Ending program.");
                        exit(0);
                    }
                }else {
                    printf("%c is not a valid distance type. Ending program.", inputDistUnit);
                    exit(0);
                }
            }else {
                printf("Invalid formatting. Ending program.");
                exit(0);
            }    
        }else{
            printf("Unknown conversion type %c chosen. Ending program.", toupper(conversionType));
        }
  }else{
    printf("Invalid formatting. Ending program.");
    exit(0);
  }
    return 0;
}
