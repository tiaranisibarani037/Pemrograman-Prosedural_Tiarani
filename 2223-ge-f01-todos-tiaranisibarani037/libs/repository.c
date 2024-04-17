// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include "repository.h"
#include "todo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief implement your prototyped functions mentioned in the repository.h.
 *
 */

void todoact(struct Activity_t *_todo, int *_id, char *_time, char *_description, char *_status) {
    _todo->id = *_id;
    strcpy(_todo->time, _time);
    strcpy(_todo->description, _description);
    strcpy(_todo->status, _status);
}