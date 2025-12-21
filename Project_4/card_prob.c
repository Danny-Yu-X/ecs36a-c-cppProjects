/*
Group: Ian Marwong, Danny Yu
Program calculates the probability of drawing a certain card.
*/
#include <stdio.h>

double CalcProb(int deckSize, int copiesNeeded, int initialHandSize, int mulliganSize, int turnToDrawBy);
double CalcInitDrawProb(int deckSize, int copiesNeeded, int initialHandSize);
double CalculateMulliganProbability(int deckSize, int copiesNeeded, int mulliganSize, int initialHandSize);
double CalculateDrawProbability(int deckSize, int copiesNeeded, int initialHandSize, int turnToDrawBy);

double CalcInitDrawProb(int deckSize, int copiesNeeded, int initialHandSize){
    /*
    Function calculates the probability of not drawing the chosen card during the initial draw
    @param deckSize is the size of the deck
    @param copiesNeeded is the number of the certain card that is in the deck
    @param initialHandSize is the amount of cards that you have at first
    @returns the probability of not drawing a chosen card
    */
    double probNotDrawn = 1.0;
    for (int i = 0; i < initialHandSize; ++i) {
        probNotDrawn *= (double)(deckSize - copiesNeeded - i) / (deckSize - i);
    }
    //printf("CalcInitDrawProb %lf",probNotDrawn);
    return probNotDrawn;
}

double CalculateMulliganProbability(int deckSize, int copiesNeeded, int mulliganSize, int initialHandSize) {
    /*
    Function calculates the probability of not drawing the chosen card during the mulligan
    @param deckSize is the size of the deck
    @param copiesNeeded is the number of the certain card that is in the deck
    @param mulliganSize is the number of cards being drawn during the mulligan
    @param initialHandSize is the the amount of cards that you have at first
    @returns the probability of of not drawing a chosen card
    */
    double probNotDrawn = 1.0;
    for (int i = 0; i < mulliganSize; ++i) {
        probNotDrawn *= (double)(deckSize - initialHandSize - copiesNeeded - i) / (deckSize - initialHandSize - i);
    }
    //printf("CalcMullProb %lf",probNotDrawn);
    return probNotDrawn;
}

double CalculateDrawProbability(int deckSize, int copiesNeeded, int initialHandSize, int turnToDrawBy) {
    /*
    Function calculates the probability of not drawing the chosen card during the drawing phase
    @param deckSize is the size of the deck
    @param copiesNeeded is the number of the certain card that is in the deck
    @param initialHandSize is the the amount of cards that you have at first
    @param turnToDrawBy is the number of turns that you have to draw the chosen card
    @returns the probability of of not drawing a chosen card
    */
    double probNotDrawn = 1.0;
    for (int i = 0; i < turnToDrawBy; ++i) {
        probNotDrawn *= (double)(deckSize - initialHandSize - copiesNeeded - i) / (deckSize - initialHandSize - i);
    }
   // printf("CalcDrawProb %lf",probNotDrawn);
    return probNotDrawn;
}

double CalcProb(int deckSize, int copiesNeeded, int initialHandSize, int mulliganSize, int turnToDrawBy){
    /*
    Function calculates the probability of not drawing the chosen card during the game
    @param deckSize is the size of the deck
    @param copiesNeeded is the number of the certain card that is in the deck
    @param initialHandSize is the the amount of cards that you have at first
    @param mulliganSize is the number of cards drawn during the mulligan
    @param turnToDrawBy is the number of turns you have to draw the card
    @returns the probability of of not drawing a chosen card
    */
    double initialDrawProb = CalcInitDrawProb(deckSize, copiesNeeded, initialHandSize);
    double mulliganProb = CalculateMulliganProbability(deckSize, copiesNeeded, mulliganSize, initialHandSize);
    double drawProb = CalculateDrawProbability(deckSize, copiesNeeded, initialHandSize, turnToDrawBy);
    double totalProbNotDrawn = initialDrawProb * mulliganProb * drawProb;
    //printf("CalcProb %lf",totalProbNotDrawn);
    return 1.0 - totalProbNotDrawn;
}

int main(){
    int deckSize, copiesNeeded, initialHandSize, mulliganSize, turnToDrawBy;
    double prob;
    printf("Enter how many total cards there are in the deck: ");
    scanf("%d", &deckSize);
    printf("Enter how many copies of the card that you are looking for are in the deck: ");
    scanf("%d", &copiesNeeded);
    printf("Enter your initial hand size: ");
    scanf("%d", &initialHandSize);
    printf("Enter how many cards you are mulliganing: ");
    scanf("%d", &mulliganSize);
    printf("Enter what turn you want to draw the card by: ");
    scanf("%d", &turnToDrawBy);

    prob = CalcProb(deckSize, copiesNeeded, initialHandSize, mulliganSize, turnToDrawBy);
    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf", turnToDrawBy, mulliganSize, prob);
    return 0;
}