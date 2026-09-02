#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int lines = 0;

    file = fopen("student.txt", "r");

    if (file == NULL) {
        printf("File not found.");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    fclose(file);

    printf("Number of lines = %d", lines);

    return 0;
}
