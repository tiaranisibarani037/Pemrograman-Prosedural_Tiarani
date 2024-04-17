// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include "repository.h"
#include "todo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief implement your prototyped functions mentioned in the todo.h.
 *
 */


void todo_print(struct Activity_t *_activities, int numActivities) {
    for (int i = 0; i < numActivities; i++) {
        printf("%d|%s|%s|%s", _activities[i].id, _activities[i].time, _activities[i].description, _activities[i].status);
    }
}
