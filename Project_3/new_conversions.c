#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>


char ConversionChecker(char conversionType) {
    conversionType = tolower(conversionType);
    return conversionType;
}


double Celsius(double inputTemp, char inputTempUnit) {

    double celsius;
    if (inputTempUnit == 'F'|| inputTempUnit == 'f') {
        celsius = (inputTemp - 32) * (5.0/9.0);
        return celsius;
    }
    else if (inputTempUnit == 'K'|| inputTempUnit == 'k') {
        celsius = inputTemp - 273.15;
        return celsius;
    }
    else {
        return 9000;
    }
}


double TempConverter(double inputTemp, char inputTempUnit, char outputTempUnit) {

    double celsius;
    double fahr;
    double kelvin;

    if (inputTempUnit == 'F' || inputTempUnit == 'K'||inputTempUnit == 'f' || inputTempUnit == 'k') {
        celsius = Celsius(inputTemp, inputTempUnit);
    }
    else if (inputTempUnit == 'C' || inputTempUnit == 'c') {
        celsius = inputTemp;
    }
    if (outputTempUnit == 'C' || outputTempUnit == 'c') {

        return celsius;
    }
    else if (outputTempUnit == 'F' || outputTempUnit == 'f') {
        fahr = celsius * 9.0 / 5.0 + 32;
        return fahr;
    }
    else if (outputTempUnit == 'K' || outputTempUnit == 'k' ) {
        kelvin = celsius + 273.15;
        return kelvin;
    }else{
        printf("%c is not a valid temperature type. Ending program.", toupper(outputTempUnit));
        exit(0);
    }
    return 23049;
}


double Yards(double inputDist, char inputDistUnit) {
    double yards;
    if (inputDistUnit == 'I') {
        yards = inputDist / 36.0;
        return yards;
    }
    else if (inputDistUnit == 'F') {
        yards = inputDist / 3.0;
        return yards;
    }
    else if (inputDistUnit == 'M') {
        yards = inputDist * 1760;
        return yards;
    }
    else{

        return 9000;
    }
}

double DistConverter(double inputDist, char inputDistUnit, char outputDistUnit) {

    double inches;
    double feet;
    double yards;
    double miles;

    if (inputDistUnit == 'I' || inputDistUnit == 'F' || inputDistUnit == 'M') {
        yards = Yards(inputDist, inputDistUnit);
    }
    else if (inputDistUnit == 'Y') {
        yards = inputDist;
    }
    if (outputDistUnit == 'Y') {

        return yards;
    }
    else if (outputDistUnit == 'I') {
        inches = yards * 36;
        return inches;
    }
    else if (outputDistUnit == 'F') {
        feet = yards * 3;
        return feet;
    }
    else if (outputDistUnit == 'M') {
        miles = yards / 1760.0;
        return miles;
    }else{
        printf("%c is not a valid distance type. Ending program.", toupper(outputDistUnit));
        exit(0);
    }
    return 12345;

}





bool isValidFormat(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line) {
	 bool format_is_correct = num_args_read == num_args_needed;
	 if(should_be_last_value_on_line){
		char should_be_newline = '?';
		scanf("%c", &should_be_newline);
		format_is_correct = format_is_correct && should_be_newline == '\n';
	 }
	 return format_is_correct;
 }



char getValidChar(const bool isLastElementOnLine) {
  const int numArgsNeeded = 1;
  int numArgsRead;
  char theCharacter;

  numArgsRead = scanf(" %c", &theCharacter);
  if (isValidFormat(numArgsNeeded, numArgsRead, isLastElementOnLine)) {
    return theCharacter;
  } else {
    printf("Format Error\n");
    exit(0);
  }
}



int main() {
    char conversionType;
    double inputTemp;
    char inputTempUnit;
    char outputTempUnit;
    double outputTemp;
    double inputDist;
    char inputDistUnit;
    double outputDist;
    char outputDistUnit;

    char num1;
    int num_args_read;
    char should_be_newline ='?';
    int new_num_args_read;
    char new_should_be_new_line = '$';

    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");

    num_args_read = scanf("%c", &num1);
    scanf("%c", &should_be_newline);

    if(num_args_read == 1 && should_be_newline == '\n'){
        conversionType = num1;
        //TEMP
        if (conversionType == 't' || conversionType == 'T') {

        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        new_num_args_read = scanf("%lf %c", &inputTemp, &inputTempUnit);
        scanf("%c", &new_should_be_new_line);
        if(new_num_args_read == 2 && new_should_be_new_line == '\n'){
            inputTempUnit = toupper(inputTempUnit);

            if (inputTempUnit == 'F' || inputTempUnit == 'C' || inputTempUnit == 'K') {

                printf("Enter the new unit type (F, C, or K): ");
                new_num_args_read = scanf(" %c", &outputTempUnit);
                scanf("%c", &new_should_be_new_line);
                if(new_num_args_read == 1 && new_should_be_new_line == '\n'){

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
            new_num_args_read = scanf("%lf %c", &inputDist, &inputDistUnit);
            scanf("%c", &new_should_be_new_line);
            if(new_num_args_read == 2 && new_should_be_new_line == '\n'){
                inputDistUnit = toupper(inputDistUnit);

                if (inputDistUnit == 'I' || inputDistUnit == 'F' || inputDistUnit == 'Y' || inputDistUnit == 'M') {
                    printf("Enter the new unit type (I,F,Y,M): ");
                    new_num_args_read = scanf(" %c", &outputDistUnit);
                    scanf("%c", &new_should_be_new_line);
                    if(new_num_args_read == 1 && new_should_be_new_line == '\n'){
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
