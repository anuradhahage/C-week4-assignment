#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float marks;
};

int main() {
    struct Student s, readStudent;
    FILE *file;

    printf("Enter student name: ");
    scanf("%s", s.name);

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter marks: ");
    scanf("%f", &s.marks);

    // Write data to file
    file = fopen("student.txt", "w");

    if (file == NULL) {
        printf("Unable to open file.");
        return 1;
    }

    fprintf(file, "%s %d %.2f", s.name, s.age, s.marks);
    fclose(file);

    // Read data from file
    file = fopen("student.txt", "r");

    if (file == NULL) {
        printf("Unable to open file.");
        return 1;
    }

    fscanf(file, "%s %d %f",
           readStudent.name,
           &readStudent.age,
           &readStudent.marks);

    fclose(file);

    printf("\n--- Data Read From File ---\n");
    printf("Name: %s\n", readStudent.name);
    printf("Age: %d\n", readStudent.age);
    printf("Marks: %.2f\n", readStudent.marks);

    return 0;
}
