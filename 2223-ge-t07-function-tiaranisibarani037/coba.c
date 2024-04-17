#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) {
switch(_grade) {
case A:
return "A";
case AB:
return "AB";
case B:
return "B";
case BC:
return "BC";
case C:
return "C";
case D:
return "D";
case E:
return "E";
case T:
return "T";
default:
return "";
}
}

float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
switch(_grade) {
case A:
return 4.0 * _credit;
case AB:
return 3.5 * _credit;
case B:
return 3.0 * _credit;
case BC:
return 2.5 * _credit;
case C:
return 2.0 * _credit;
case D:
return 1.0 * _credit;
case E:
return 0.0;
case T:
return 0.0;
default:
return 0.0;
}
}

void print_course(struct course_t _course)
{
printf("%s|%s|%hu|%s\n", _course.code, _course.name, _course.credit, grade_to_text(_course.passing_grade));
}

void print_student(struct student_t _student)
{
printf("%s|%s|%s|%s\n", _student.id, _student.name, _student.year, _student.study_program);
}

void print_enrollment(struct enrollment_t _enrollment)
{
printf("%s|%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, _enrollment.academic_year, semester_to_text(_enrollment.semester), calculate_performance(_enrollment.grade, _enrollment.course.credit));
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
enum grade_t _passing_grade)
{
struct course_t crs;
}