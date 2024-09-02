#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  /*
  checks to see if input is in correct form
  @param numArgsRead is the number of arguments read
  @param numArgsNeed is the number of argunments needed
  @returns if the format is good
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