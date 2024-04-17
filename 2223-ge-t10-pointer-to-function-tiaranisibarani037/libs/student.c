#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct student_t create_student(char *_id, char *_name, char *_year,enum gender_t _gender){
    struct student_t s;
    strcpy(s.id, _id);
    strcpy(s.name, _name);
    strcpy(s.year, _year);
    s.gender = _gender;
    s.dorm = NULL;
    return s;
}

void print_student(struct student_t *_student, int count){
    for (int w = 0; w < count; w++)
    {
        if (_student[w].gender == GENDER_MALE){
            printf("%s|%s|%s|male\n", _student[w].id, _student[w].name, _student[w].year);
        } else if (_student[w].gender == GENDER_FEMALE){
            printf("%s|%s|%s|female\n", _student[w].id, _student[w].name, _student[w].year);
        }
    }
}

void print_student_detail(struct student_t *_student, int count){
    for (int w = 0; w < count; w++)
    {
        if (_student[w].dorm == NULL){
            if (_student[w].gender == GENDER_MALE){
                printf("%s|%s|%s|male|unassigned\n", _student[w].id, _student[w].name, _student[w].year);
            } else if (_student[w].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|unassigned\n", _student[w].id, _student[w].name, _student[w].year);
            }
        } else {
            if (_student[w].gender == GENDER_MALE){
                printf("%s|%s|%s|male|%s\n", _student[w].id, _student[w].name, _student[w].year, (*_student[w].dorm).name);
            } else if (_student[w].gender == GENDER_FEMALE){
                printf("%s|%s|%s|female|%s\n", _student[w].id, _student[w].name, _student[w].year,(*_student[w].dorm).name);
            }
        }
    }
}

void assign_student(struct student_t *_student,struct dorm_t *_dorm, char *id, char *dorm_name){
    if ((*_dorm).residents_num < (*_dorm).capacity){
        if ((*_student).gender == (*_dorm).gender){
            (*_student).dorm = _dorm;
            (*_dorm).residents_num++;
        }
    }
}

void move_student(struct student_t *_student, struct dorm_t *_dorm, struct dorm_t *old_dorm, char *id, char *dorm_name){
    if ((*_dorm).residents_num < (*_dorm).capacity){
        if ((*_student).gender == (*_dorm).gender){
            (*_student).dorm = _dorm;
            (*_dorm).residents_num++;
            (*old_dorm).residents_num--;
        }
    }
}