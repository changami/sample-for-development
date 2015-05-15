#include <stdio.h>
#include <ctype.h>

int main() {
    char *filePath = ""; // Please set the path of the file
    char *openMode = "r";

    FILE *file;
    file = fopen(filePath, openMode);

    if (file == NULL) {
        printf("The program couldn't open the file...\n\n");
    }
    // Cursor moves to first
    rewind(file);

    int fileChar, idIndex = 0, classIndex = 0, previousChar = 0;
    char *id = "id=\"";
    char *class = "class=\"";
    const int idLength = 4, classLength = 7;

    while ((fileChar = fgetc(file)) != EOF) {
        if (fileChar == '<') {
            while ((fileChar = fgetc(file)) != EOF) {
                if (fileChar == '>' || (fileChar == '\"' && (idIndex == idLength || classIndex == classLength))) {
                    if (idIndex == idLength || classIndex == classLength) printf("\n");
                    idIndex = 0;
                    classIndex = 0;
                    break;
                }
                if (classIndex == classLength && fileChar == ' ' && isalnum(previousChar)) {
                    // for several class names
                    printf("\n");
                    previousChar = fileChar;
                } else if(fileChar == ' '){
                    // for skip TODO: Think more cool solution
                }
                // Only the contents of inside < > come here.
                else if (idIndex == idLength) {
                    printf("%c", fileChar);
                } else if (classIndex == classLength) {
                    printf("%c", fileChar);
                    previousChar = fileChar;
                } else if (fileChar == id[idIndex]) {
                    idIndex++;
                } else if (fileChar == class[classIndex]) {
                    classIndex++;
                    previousChar = fileChar;
                } else {
                    idIndex = 0;
                    classIndex = 0;
                    previousChar = 0;
                }
            }
        }
    }

    fclose(file);
    return 0;
}