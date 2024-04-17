#include "student.h"
#include "gender.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_student(struct student_t* _student, int count) {
    for (int w = 0; w < count; w++) {
        printf("%s|%s|%s|", _student[w].id, _student[w].name, _student[w].year);
        char* gender_text = gender_to_text(_student[w].gender);
        printf("%s\n", gender_text);
    }
}

void print_student_detail(struct student_t* _student, int count) {
    for (int w = 0; w < count; w++) {
        printf("%s|%s|%s|", _student[w].id, _student[w].name, _student[w].year);

        if (_student[w].dorm == NULL) {
            printf("%s|unassigned\n", gender_to_text(_student[w].gender));
        } else {
            printf("%s|%s\n", gender_to_text(_student[w].gender), _student[w].dorm->name);
        }
    }
}

void assign_student(struct student_t *_student, struct dorm_t *_dorm, int idd, int ids)
{
    if (_dorm[idd].capacity > _dorm[idd].residents_num)
    {
        if (_student[ids].gender == _dorm[idd].gender)
        {
            _student[ids].dorm = &_dorm[idd];

            _dorm[idd].residents_num++;
        }
    }
}

int findStudentIndex(char* id, struct student_t *_student, int std) {
    int idx_s = 0;
    for (int i = std; i >= 0; i--) {
        if (strcmp(_student[i].id, id) == 0) {
            idx_s = i;
        }
    }
    return idx_s;
}
