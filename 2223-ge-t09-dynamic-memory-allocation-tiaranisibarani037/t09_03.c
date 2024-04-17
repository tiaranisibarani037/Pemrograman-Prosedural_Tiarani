#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char input[100];
  char *string;
  int index_stdu = 0;
  int index_crs = 0;
  struct student_t *student = malloc(10 * sizeof(struct student_t));
  struct course_t *course = malloc(10 * sizeof(struct course_t));

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
    
    string = strtok(input, "#");
    if (strstr(input, "---") != NULL) {
      break;
      
    } else if (strstr(string, "create-student") != NULL) {
      char id[12];
      char name[40];
      char year[5];
      char study_program[40];
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

    } else if (strstr(string, "print-students") != NULL) {
      print_students(student, index_stdu);

    } else if (strstr(string, "create-course") != NULL) {
      char crs_name[40];
      char crs_code[12];
      unsigned short int crs_credit;
      int crs_passing_grade;

      string = strtok(NULL, "#");
      strcpy(crs_code, string);
      string = strtok(NULL, "#");
      strcpy(crs_name, string);
      string = strtok(NULL, "#");
      crs_credit = atoi(string);
      string = strtok(NULL, "#");
      int nilai;

if (strstr(string, "A") != NULL)
      {
        
        nilai = 8;
      }

      if (strstr(string, "AB") != NULL)
      {
        nilai = 7;
      }

      if (strstr(string, "B") != NULL)
      {
        nilai = 6;
      }

      if (strstr(string, "BC") != NULL)
      {
        nilai = 5;
      }

      if (strstr(string, "C") != NULL)
      {
        nilai = 4;
      }

      if (strstr(string, "D") != NULL)
      {
        nilai = 3;
      }

      if (strstr(string, "E") != NULL)
      {
        nilai = 2;
      }

      if (strstr(string, "T") != NULL)
      {
        nilai = 1;
      }
      
      if (strstr(string, "None") != NULL)
      {
       nilai = 0;
      }
       course[index_crs].passing_grade = nilai;
      crs_passing_grade = nilai;
      course[index_crs] = create_course(crs_code, crs_name, crs_credit, crs_passing_grade);
      index_crs++;

    } else if (strstr(string, "print-courses") != NULL) {
      print_courses(course, index_crs);

    }if (strstr(string, "find-student-by-id") != NULL) {
      char nim[12];
      string = strtok(NULL, "#");
      strcpy(nim, string);
      find_student_by_id(student, index_stdu, nim);

    } else if (strstr(string, "find-course-by-code") != NULL) {
      char kode[12];
      string = strtok(NULL, "#");
      strcpy(kode, string);
      find_course_by_code(course, index_crs, kode);

    }

  }
  return 0;
}
