#include "dorm.h"
#include <stdio.h>
#include <string.h>

struct dorm_t create_dorm(char *_name, unsigned short _capacity, enum gender_t _gender) {
    struct dorm_t d;
    strcpy(d.name, _name);
    d.capacity = _capacity;
    d.gender = _gender;
    d.residents_num = 0;
    return d;
}

void print_dorm_detail(struct dorm_t *_dorm, int count) {
    int w = 0;
    while (w < count) {
        if (_dorm[w].gender == GENDER_MALE) {
            printf("%s|%d|male|%d\n", _dorm[w].name, _dorm[w].capacity, _dorm[w].residents_num);
        } else if (_dorm[w].gender == GENDER_FEMALE) {
            printf("%s|%d|female|%d\n", _dorm[w].name, _dorm[w].capacity, _dorm[w].residents_num);
        }
        w++;
    }
}

void print_dorm(struct dorm_t *_dorm, int count) {
    for (int w = 0; w < count; w++) {
        if (_dorm[w].gender == GENDER_MALE) {
            printf("%s|%d|male\n", _dorm[w].name, _dorm[w].capacity);
        } else if (_dorm[w].gender == GENDER_FEMALE) {
            printf("%s|%d|female\n", _dorm[w].name, _dorm[w].capacity);
        }
    }
}

