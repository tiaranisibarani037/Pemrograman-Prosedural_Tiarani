// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include "./libs/todo.h"
#include "./libs/repository.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv) {
    struct Activity_t *activities = malloc(100 * sizeof(struct Activity_t));

    char *data;
    char input[100];
    int id;
    char time[6];
    char description[100];
    int td = 0;

    // Melakukan load initial data
    FILE *file = fopen("storage/todo-repository.txt", "r");
    if (file == NULL) {
        printf("Tidak dapat membuka file.\n");
        return 1;
    }

    while (fgets(input, 100, file) != NULL) {
        data = strtok(input, "|");
        id = atoi(data);
        strcpy(activities[td].time, strtok(NULL, "|"));
        strcpy(activities[td].description, strtok(NULL, "|"));
        strcpy(activities[td].status, strtok(NULL, "|"));

        activities[td].id = id;
        td++;
    }

    fclose(file);

    do {
        fflush(stdin);
        input[0] = '\0';
        int c = 0;
        while (1)
        {
            char x = getchar();
            if (x == '\r')
            {
                continue;
            }
            if (x == '\n')
            {
                break;
            }
            input[c] = x;
            input[++c] = '\0';
        }
        data = strtok(input, "#");
        if (strcmp(data, "---") == 0)
        {
            break;
        }
        if (strcmp(data, "todo-print-all") == 0) {
            todo_print(activities, td);
        } else if (strcmp(data, "todo-add") == 0) {
            int id_td = td + 1;
            data = strtok(NULL, "#");
            strcpy(time, data);
            data = strtok(NULL, "#");
            strcpy(description, data);

            file = fopen("storage/todo-repository.txt", "a+");
            if (file == NULL) {
                printf("Tidak dapat membuka file.\n");
            } else {
                fprintf(file, "%d|%s|%s|none\n", id_td, time, description);
            }
            fclose(file);

            activities[td].id = id_td;
            strcpy(activities[td].time, time);
            strcpy(activities[td].description, description);
            strcpy(activities[td].status, "none\n");
            td++;
        }
    } while (1);

    free(activities);

    return 0;
}
