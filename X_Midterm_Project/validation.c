#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "validation.h"

bool isValidFormatExit(const int num_args_needed, const int num_args_read, bool should_be_last_value_on_line) {
	 bool format_is_correct = num_args_read == num_args_needed;
	 if(should_be_last_value_on_line){
		char should_be_newline = '?';
		scanf("%c", &should_be_newline);
		format_is_correct = format_is_correct && should_be_newline == '\n';
	 }
	 return format_is_correct;
 }

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
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
