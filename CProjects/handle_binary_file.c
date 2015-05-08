#include <stdio.h>

struct student {
    char *name;
    int age;
};

int main() {
    struct student sampleStudent;
    sampleStudent.name = "Sample";
    sampleStudent.age = 100;

    char *filePath = ""; // Please set the path of the file
    char *openMode = "wb+";

    FILE *file;
    file = fopen(filePath, openMode);
    if (file == NULL) {
        printf("The program couldn't open the file...\n\n");

    }
    // write to file
    fwrite(&sampleStudent, sizeof(struct student), 1, file);
    // read from file
    fseek(file, 0L, SEEK_SET);
    struct student readStudent;
    fread(&readStudent, sizeof(struct student), 1, file);

    fclose(file);

    printf("name: %s\nage: %d\n\n", readStudent.name, readStudent.age);
    return 0;
}