#include <stdio.h>

int main() {
    FILE *file;
    char data[100];

    printf("Enter data to append: ");
    scanf(" %[^\n]", data);

    file = fopen("student.txt", "a");

    if (file == NULL) {
        printf("Unable to open file.");
        return 1;
    }

    fprintf(file, "\n%s", data);

    fclose(file);

    printf("Data appended successfully.");

    return 0;
}
