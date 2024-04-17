// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libs/dorm.h"
#include "libs/student.h"

int main(int _argc, char **_argv)
{
    // Declare Struct
    struct dorm_t *dorms = malloc(100 * sizeof(struct dorm_t));
    struct student_t *students = malloc(100 * sizeof(struct student_t));

    // Student
    char input[100];
    char id[12];
    char student_name[40];
    char year[5];

    // Dorm
    char dorm_name[40];
    unsigned short capacity;

    // For Algoritma use
    char *data;
    int idx_s, idx_d;
    int std = 0, dr = 0;

    // File handling

    // Dorm File
    // fdrm = variabel file dorm
    // path name file = storage/dorm-repository.txt

    FILE *fdrm;
    fdrm = fopen("storage/dorm-repository.txt", "r");
    if (fdrm == NULL)
    {
        printf("File not found\n");
    }
    while (fgets(input, 100, fdrm) != NULL)
    {
        data = strtok(input, "|");
        strcpy(dorms[dr].name, data);
        data = strtok(NULL, "|");
        capacity = atoi(data);
        dorms[dr].capacity = capacity;
        dorms[dr].residents_num = 0;
        data = strtok(NULL, "|");
        if (strcmp(data, "male") == 0)
        {
            dorms[dr].gender = GENDER_MALE;
        }
        else if (strcmp(data, "female") == 0)
        {
            dorms[dr].gender = GENDER_FEMALE;
        }
        dr++;
        
    }
    fclose(fdrm);

    // Student File
    FILE *fstd;
    fstd = fopen("storage/student-repository.txt", "r");
    if (fstd == NULL)
    {
        printf("File not found\n");
    }
    while (fgets(input, 100, fstd) != NULL)
    {
        data = strtok(input, "|");
        strcpy(students[std].id, data);
        data = strtok(NULL, "|");
        strcpy(students[std].name, data);
        data = strtok(NULL, "|");
        strcpy(students[std].year, data);
        data = strtok(NULL, "|");
        if (strcmp(data, "male") == 0)
        {
            students[std].gender = GENDER_MALE;
        }
        else if (strcmp(data, "female\n") == 0)
        {
            students[std].gender = GENDER_FEMALE;
        }
        std++;

    }
    fclose(fstd);

       // Algorithm start here
    do
    {
        fflush(stdin);
        input[0] = '\0';
        int c = 0;
        while (1)
        {
            char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            input[c] = x;
            input[++c] = '\0';
        }
        data = strtok(input, "#");
        if (strcmp(data, "---") == 0)
        {
            break;
        }
        else if (strcmp(data, "student-print-all") == 0)
        {
            print_student(students, std);
        }
        else if (strcmp(data, "student-print-all-detail") == 0)
        {
            print_student_detail(students, std);
        }
        else if (strcmp(data, "student-add") == 0)
        {
            data = strtok(NULL, "#");
            strcpy(id, data);
            data = strtok(NULL, "#");
            strcpy(student_name, data);
            data = strtok(NULL, "#");
            strcpy(year, data);
            data = strtok(NULL, "#");
            students[std] = create_student(id, student_name, year, data);
            std++;

            fstd = fopen("./storage/student-repository.txt", "a");
            if (fstd == NULL)
            {
                printf("File not found\n");
            }else{
                fprintf(fstd, "%s|%s|%s|%s\n", id, student_name, year, data);
            }
            fclose(fstd);
            
        }
        else if (strcmp(data, "dorm-print-all") == 0)
        {
            print_dorm(dorms, dr);
        }
        else if (strcmp(data, "dorm-print-all-detail") == 0)
        {
            print_dorm_detail(dorms, dr);
        }
        else if (strcmp(input, "dorm-add") == 0)
        {
            data = strtok(NULL, "#");
            strcpy(dorm_name, data);
            data = strtok(NULL, "#");
            capacity = atoi(data);
            data = strtok(NULL, "#");
            dorms[dr] = create_dorm(dorm_name, capacity, data);
            dr++;

            fdrm = fopen("./storage/dorm-repository.txt", "a");
            if (fdrm == NULL)
            {
                printf("File not found\n");
            }else{
                fprintf(fdrm, "%s|%d|%s\n", dorm_name, capacity, data);
            }
            fclose(fdrm);
            
        }
        else if (strcmp(data, "assign-student") == 0)
        {
            char *id = strtok(NULL, "#");
            char *dorm_name = strtok(NULL, "#");

            idx_s = findStudentIndex(id, students, std);
            idx_d = findDormIndex(dorm_name, dorms, dr);

            assign_student(students, dorms, idx_d, idx_s);
        }
        
    } while (1);
    
    return 0;
}
