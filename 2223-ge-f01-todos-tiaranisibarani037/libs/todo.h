// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#ifndef TODO_H
#define TODO_H

struct Activity_t
{
    int id;
    char time[6];
    char description[100];
    char status[10];
};

void todoact(struct Activity_t *_activities, int *_id, char *_time, char *_description, char *_status);
void todo_print(struct Activity_t* _activities, int numActivities);
#endif
