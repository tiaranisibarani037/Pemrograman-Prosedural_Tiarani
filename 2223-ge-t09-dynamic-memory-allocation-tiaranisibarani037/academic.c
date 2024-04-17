// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

char *grade_to_text(enum grade_t _grade) {
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

void print_course(struct course_t _course) {
    char *grade1 = grade_to_text(_course.passing_grade);
    printf("%s|%s|", _course.code, _course.name);
    printf("%hu|%s\n", _course.credit, grade_to_text(_course.passing_grade));
}

void print_courses(struct course_t *_courses, unsigned short int _course_size)
{
    int i = 0;
    while (i < _course_size) {
    printf("%s|%s|", _courses[i].code, _courses[i].name);
    printf("%hu|%s\n", _courses[i].credit, grade_to_text(_courses[i].passing_grade));
    i++;
    }
}

void print_student(struct student_t _student)
{
    printf("%s|%s|", _student.id, _student.name);
    printf("%s|%s|%.2f\n",  _student.year, _student.study_program, _student.gpa);
}

void print_students(struct student_t *_students,
                    unsigned short int _student_size)
{
    int i = 0;
    while (i < _student_size) {
    printf("%s|%s|", _students[i].id, _students[i].name);
    printf("%s|%s|%.2f\n",  _students[i].year, _students[i].study_program, _students[i].gpa);
    i++;
    }

}

void print_enrollment(struct enrollment_t _enrollment)
{
    char *grade = grade_to_text(_enrollment.grade);
    float performance = calculate_performance(_enrollment.grade, _enrollment.course.credit);
    printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, grade, performance);
}

void print_enrollments(struct enrollment_t *_enrollments,
                       unsigned short int _enrollment_size)
{
    int i = 0;
        while (i < _enrollment_size) {
            char *grade = grade_to_text(_enrollments[i].grade);
            float performance = calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);

            printf("%s|%s|%s|%.2f\n", _enrollments[i].course.code, _enrollments[i].student.id, grade, performance);

            i++;
        }
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
    std.gpa = 0.00;
    return std;
}

struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester)
{
    struct enrollment_t emt;
    emt.course = _course;
    emt.student = _student;
    strcpy(emt.year, _year);
    emt.semester = _semester;
    return emt;
}

void calculate_gpa(struct student_t *_student,
                   struct enrollment_t *_enrollments,
                   unsigned short int _enrollment_size)
{
    float total_performance = 0.00;
        float total_credit = 0.00;
        int i = 0;

            do {
                float performance = calculate_performance(_enrollments[i].grade, _enrollments[i].course.credit);
                total_performance += performance;
                total_credit += _enrollments[i].course.credit;
                i++;
                } while (i < _enrollment_size);

        float gpa = total_performance / total_credit;
        _student->gpa = gpa;
}

void set_enrollment_grade(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollments,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade)
{
    int a = 0;
        while(a < _enrollment_size)
        {
            if(strcmp(_enrollments[a].course.code, _course.code)==0 && strcmp(_enrollments[a].student.id, _student.id)==0)
        {
              _enrollments[a].grade = _grade;
        }
            a++;
        }
}

struct student_t find_student_by_id(struct student_t *_students,
                                    unsigned short int _student_size,
                                    char *_id)
{
    struct student_t std;
        int i = 0;
    while (i < _student_size) {
        if (strcmp(_students[i].id, _id) == 0) {
            print_student(_students[i]);
        }
        i++;
    }

    return std;
}
struct course_t find_course_by_code(struct course_t *_courses,
                                    unsigned short int _course_size,
                                    char *_code)
{
    struct course_t crs;
        int i = 0;
    while (i < _course_size) {
        if (strcmp(_courses[i].code, _code) == 0) {
            print_course(_courses[i]);
        }   
        i++;
    }
    
    return crs;
}
