#include "dorm.h"
#include "gender.h"
#include <stdio.h>
#include <string.h>

void print_dorm(struct dorm_t* _dorm, int count) {
    for (int w = 0; w < count; w++) {
        printf("%s|%d|", _dorm[w].name, _dorm[w].capacity);
        printf("%s\n", gender_to_text(_dorm[w].gender));
    }
}

void print_dorm_detail(struct dorm_t* _dorm, int count) {
    int w = 0;
    while (w < count) {
        printf("%s|%d|", _dorm[w].name, _dorm[w].capacity);
        printf("%s|%d\n", gender_to_text(_dorm[w].gender), _dorm[w].residents_num);
        w++;
    }
}

int findDormIndex(char* dorm_name, struct dorm_t *_dorm, int num_dorms) {
    int idx_d = 0;
    for (int i = num_dorms; i >= 0; i--) {
        if (strcmp(_dorm[i].name, dorm_name) == 0) {
            idx_d = i;
        }
    }
    
    return idx_d;
}
