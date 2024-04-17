#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char input[100];
  char *string;
  
  int index_stdu = 0;
  struct student_t *student = malloc(10 * sizeof(struct student_t));

  while (1) {
    input[0] = '\0';
    int c = 0;

    while (1) {
      char x = getchar();
      if (x == '\r') {
        continue;
      }
      if (x == '\n') {
        break;
      }
      input[c] = x;
      input[++c] = '\0';
    }

    if (strcmp(input, "---") == 0) {
      break;
    } else if (strstr(input, "create-student") != NULL) {
      char id[12];
      char name[40];
      char year[5];
      char study_program[40];

      string = strtok(input, "#");
      string = strtok(NULL, "#");
      strcpy(id, string);
      string = strtok(NULL, "#");
      strcpy(name, string);
      string = strtok(NULL, "#");
      strcpy(year, string);
      string = strtok(NULL, "#");
      strcpy(study_program, string);

      student[index_stdu] = create_student(id, name, year, study_program);
      index_stdu++;
      
    } else if (strstr(input, "print-student") != NULL) {
      print_students(student, index_stdu);
    }
  }

  return 0;
}
