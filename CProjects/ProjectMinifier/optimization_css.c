#include <stdio.h>

#define READING_MODE "r+"
#define CREATING_MODE "w+"

int execOptimizationCSS(char *HTMLFilePath, char *CSSFilePath, char *newCSSFilePathToCreate) {
    FILE *htmlOrg, *cssOrg, *cssNew;
    htmlOrg = fopen(HTMLFilePath, READING_MODE);
    cssOrg = fopen(CSSFilePath, READING_MODE);
    cssNew = fopen(newCSSFilePathToCreate, CREATING_MODE);
    if (htmlOrg == NULL || cssOrg == NULL || cssNew == NULL) {
        printf("The files couldn't open...\n");
        return -1;
    }

    // ------- Loop -------
    // Cursor moves to first in HTML
    // Find a class/id/tag name in CSS
    // Check whether those are used in HTML
    //     (If those are used in HTML,)
    //     Extract the target block from CSS
    //     Write the target block to new CSS file
    // ------- End --------

    fclose(htmlOrg);
    fclose(cssOrg);
    fclose(cssNew);

    return 0;
}