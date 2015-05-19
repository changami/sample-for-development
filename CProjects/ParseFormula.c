#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAXIMUM_MEMORY_SIZE = 255;

void omitWhitespace(char *string) {
    char temp[strlen(string)];
    memset(temp, '\n', strlen(string));

    int assignmentIndex = 0;
    for (int i = 0; string[i] != '\n'; ++i) {
        if (string[i] != ' ') {
            temp[assignmentIndex] = string[i];
            assignmentIndex++;
        }
    }

    memset(string, '\n', strlen(string));
    strcpy(string, temp);
}

int isOperator(int c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

// I'll try to implement that in this weekend.
//
//int isParenthesis(int c) {
//    switch (c) {
//        case '(':
//        case ')':
//            return 1;
//        default:
//            return 0;
//    }
//}

int validation(char *string) {
    // 最初の文字が[数字、+、-]以外の場合は 0(false) を返す
    if (!isdigit(string[0]) && string[0] != '+' && string[0] != '-') {
        return 0;
    }

    for (int i = 0; i < MAXIMUM_MEMORY_SIZE; i++) {
        // [数字、四則演算子、スペース、終端文字]以外が含まれていたら 0(false) を返す
        if (!isdigit(string[i]) && !isOperator(string[i]) && string[i] != ' ' && string[i] != '\0') {
            return 0;
        }

        // 最初、または最後の文字が四則演算子の場合は 0(false) を返す
        if (isOperator(string[i]) && string[i + 1] == '\0') {
            return 0;
        }

        // 演算子が並んでいる場合は 0(false) を返す
        if (i != 0 && isOperator(string[i]) && isOperator(string[i - 1])) {
            return 0;
        }

        // 最終文字まで何もなければ 1(true) を返す
        if (string[i] == '\0') {
            return 1;
        }
    }
}

int main() {
    char inputString[MAXIMUM_MEMORY_SIZE];
    printf("Enter your formula. => ");
    fgets(inputString, MAXIMUM_MEMORY_SIZE, stdin);
    inputString[strlen(inputString) - 1] = '\0';

    if (!validation(inputString)) {
        printf("Syntax Error...\n");
        return 0;
    }

    double *numbers;
    char *operators;
    int numbersSize = 0, operatorsSize = 0, doneIndex = 0;
    numbers = (double *) malloc(sizeof(double) * numbersSize);
    operators = (char *) malloc(sizeof(char) * operatorsSize);

    for (int i = 0; i < MAXIMUM_MEMORY_SIZE; i++) {
        if (isdigit(inputString[i]) || inputString[i] == ' ') { //数字がきたとき
            continue;
        } else if (isOperator(inputString[i]) && i != 0 && i != doneIndex) { //演算子がきたとき
            numbers = (double *) realloc(numbers, sizeof(double) * ++numbersSize);
            operators = (char *) realloc(operators, sizeof(char) * ++operatorsSize);

            if (numbers == NULL || operators == NULL) {
                printf("the program cannot ocupy enough memory...\n");
                free(numbers);
                free(operators);
                return -1;
            }

            char temp[MAXIMUM_MEMORY_SIZE];
            memset(temp, '\n', MAXIMUM_MEMORY_SIZE);
            strncpy(temp, inputString + doneIndex, i - doneIndex);
            omitWhitespace(temp);
            numbers[numbersSize - 1] = atoi(temp);

            memset(temp, '\n', MAXIMUM_MEMORY_SIZE);
            strncpy(temp, inputString + i, 1);
            operators[operatorsSize - 1] = temp[0];

            doneIndex = i + 1;
        } else if (inputString[i] == '\0') { //一番最後の数字を取りたいとき
            numbers = (double *) realloc(numbers, sizeof(double) * ++numbersSize);

            char temp[MAXIMUM_MEMORY_SIZE];
            memset(temp, '\n', MAXIMUM_MEMORY_SIZE);
            strncpy(temp, inputString + doneIndex, i - doneIndex);
            omitWhitespace(temp);
            numbers[numbersSize - 1] = atoi(temp);
            break;
        }
    }

    // 掛け算と割り算を先に計算する
    for (int i = 0; i < operatorsSize; ++i) {
        if (operators[i] == '*' || operators[i] == '/') {
            switch (operators[i]) {
                case '*':
                    numbers[i] = numbers[i] * numbers[i + 1];
                    break;
                case '/':
                    if (numbers[i + 1] == 0) {
                        printf("We can't divide by 0.\n");
                        exit(EXIT_FAILURE);
                    }
                    numbers[i] = numbers[i] / numbers[i + 1];
                    break;
                default:
                    break;
            }

            for (int j = i + 1; j + 1 < numbersSize; ++j) {
                numbers[j] = numbers[j + 1];
            }

            for (int k = i; k + 1 < operatorsSize; ++k) {
                operators[k] = operators[k + 1];
            }

            numbersSize--;
            operatorsSize--;
            i--;
        }
    }

    // 足し算と引き算を計算する
    for (int i = 0; i < operatorsSize; ++i) {
        if (operators[i] == '+' || operators[i] == '-') {
            switch (operators[i]) {
                case '+':
                    numbers[i] = numbers[i] + numbers[i + 1];
                    break;
                case '-':
                    numbers[i] = numbers[i] - numbers[i + 1];
                    break;
                default:
                    break;
            }

            for (int j = i + 1; j + 1 < numbersSize; ++j) {
                numbers[j] = numbers[j + 1];
            }

            for (int k = i; k + 1 < operatorsSize; ++k) {
                operators[k] = operators[k + 1];
            }

            numbersSize--;
            operatorsSize--;
            i--;
        }
    }

    printf("The answer is: %lf\n", numbers[0]);

    free(numbers);
    free(operators);
}