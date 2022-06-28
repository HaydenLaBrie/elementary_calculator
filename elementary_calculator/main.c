#include <stdio.h>
#include <stdlib.h>

float addition(float, float);
float subtraction(float, float);
float multiplication(float, float);
float division(float, float);

int main(){
    printf("This Program is designed to compute elementary operation on 2 numbers\nThe elementary operations being +,-,*,/\nWhenever you would like to quit please enter !\n\n");
    printf("Enter elementary operation:"); //Output to console for user to see
    char input[32]; //Create a char array of size 32 characters (32 bytes or 256 bits), can only store 255 due to needing the end string character which is '\0'
    fgets(input, sizeof(input), stdin); //get line that user inputs
    char operand1[32]; // char array to store first operand
    int i = 0; //counter int
    while(input[i] != '!'){
        while(input[i] == '0' || input[i] == '.' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
     || input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9' || (i == 0 && input[i] == '-')){ // store into the string array while a number, ., or the first char is a negative
         operand1[i] = input[i];
         i++; //count how many times the while loop has executed
        }
        operand1[i] = '\0'; // The i will be how many interations of the while loop. char array size is always i - 1. thus at i position will be where null terminator needs to be placed in order for it to be a c style string
        while(input[i] == ' '){ //this is used to skip all the spaces. if at position i is a space then go to next and check. if at the next i there is not then at i there must != space
            i++;
        }
        char operator = input[i];
        i++;
        char operand2[32];
        while(input[i] == ' '){
            i++;
        }
        int j = 0;
        while(input[i] == '0' || input[i] == '.' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4'
    || input[i] == '5' || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9' || (j == 0 && input[i] == '-')){
            operand2[j] = input[i];
            i++;
            j++;
        }
        operand2[j] = '\0';
        float op1 = atof(operand1);
        float op2 = atof(operand2);
        if(operator == '+'){
            printf("Result: %f\n", addition(op1, op2));
        }
        else if(operator == '-'){
            printf("Result: %f\n", subtraction(op1, op2));
        }
        else if(operator == '*'){
            printf("Result: %f\n", multiplication(op1, op2));
        }
        else if(operator == '/'){
            printf("Result: %f\n", division(op1, op2));
        }
        else{
            printf("Program can only handle the 4 fundamental operators: +,-,*,/\nPlease try again\n");
        }
        i = 0;
        printf("\nEnter new elementary operation or exit by entering !:"); //Output to console for user to see
        fgets(input, sizeof(input), stdin); //get line that user inputs
    }
    
    return 0;
}

float addition(float a, float b){
    return (a + b);
}

float subtraction(float a, float b){
    return (a - b);
}

float multiplication(float a, float b){
    return (a * b);
}

float division(float a, float b){
    return (a / b);
}
