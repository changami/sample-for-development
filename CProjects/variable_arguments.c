#include <stdio.h>
#include <stdarg.h>

double endlessAdding(double firstNum, ...) {
    va_list argList;
    double sum = 0;

    va_start(argList, firstNum);

    double number = firstNum;
    while (number != -1) {
        sum += number;
        number = va_arg(argList, double);
    }
    va_end(argList);

    return sum;
}

int main() {
    printf("Answer is: %lf\n", endlessAdding(5.0, 5.0, 5.0, 5.0, 5.0, 5.0, -1.0));
}