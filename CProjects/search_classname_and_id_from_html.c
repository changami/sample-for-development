#include <stdio.h>

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

    int fileChar, idIndex = 0, classIndex = 0;
    char *id = "id=\"";
    char *class = "class=\"";
    const int idLength = 4, classLength = 7;

    while ((fileChar = fgetc(file)) != EOF) {
        if (fileChar == '<') {
            while ((fileChar = fgetc(file)) != EOF) {
                if (fileChar == '>' || (fileChar == '\"' && (idIndex == idLength || classIndex == classLength))) {
                    if (idIndex == idLength || classIndex == classLength) printf("\n");
                    break;
                }
                // Only the contents of inside < > come here.
                if (idIndex == idLength) {
                    printf("%c", fileChar);
                }
                if (classIndex == classLength) {
                    printf("%c", fileChar);
                }
                if (fileChar == id[idIndex]) idIndex++;
                if (fileChar == class[classIndex]) classIndex++;
            }
            idIndex = 0;
            classIndex = 0;
        }
    }

    fclose(file);
    return 0;
}