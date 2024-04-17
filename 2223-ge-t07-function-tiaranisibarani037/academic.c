// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) 
{ 
        switch(_grade)
    {
        case GRADE_A:
            return "A";
            break;
        case GRADE_AB:
            return "AB";
            break;
        case GRADE_B:
            return "B";
            break;
        case GRADE_BC:
            return "BC";
            break;
        case GRADE_C:
            return "C";
            break;
        case GRADE_D:
            return "D";
            break;
        case GRADE_E:
            return "E";
            break;
        case GRADE_T:
            return "T";
            break;
        default:
            return "None";
    }
}

float calculate_performance(enum grade_t _grade, unsigned short _credit)
{
    if (_grade == GRADE_A) {
        return 4.0 * _credit;
    } else if (_grade == GRADE_AB) {
        return 3.5 * _credit;
    } else if (_grade == GRADE_B) {
        return 3.0 * _credit;
    } else if (_grade == GRADE_BC) {
        return 2.5 * _credit;
    } else if (_grade == GRADE_C) {
        return 2.0 * _credit;
    } else if (_grade == GRADE_D) {
        return 1.0 * _credit;
    } else if (_grade == GRADE_E) {
        return 0.5;
    } else if (_grade == GRADE_T) {
        return 0.0;
    } else {
        return 0.0;
    }
}

void print_course(struct course_t _course)
{
    char *grade1 = grade_to_text(_course.passing_grade);
    printf("%s|%s|", _course.code, _course.name);
    printf("%hu|%s\n", _course.credit, grade1);
}

void print_student(struct student_t _student)
{
    printf("%s|%s|", _student.id, _student.name);
    printf("%s|%s\n",  _student.year, _student.study_program);
}

void print_enrollment(struct enrollment_t _enrollment)
{
    char *grade = grade_to_text(_enrollment.grade);
    float performance = calculate_performance(_enrollment.grade, _enrollment.course.credit);
    printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, grade, performance);
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade)
{
  struct course_t crs;
  strcpy(crs.name, _name);
  strcpy(crs.code, _code);
  crs.credit = _credit;
  crs.passing_grade = _passing_grade;

  return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program)
{
  struct student_t std;
  strcpy(std.id, _id);
  strcpy(std.name, _name);
  strcpy(std.year, _year);
  strcpy(std.study_program, _study_program);
  
  return std;
}

struct enrollment_t create_enrollment(struct course_t _course, struct student_t _student, char *_year, enum semester_t _semester)
{
    struct enrollment_t emt;
    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;
    
    return emt;
}
