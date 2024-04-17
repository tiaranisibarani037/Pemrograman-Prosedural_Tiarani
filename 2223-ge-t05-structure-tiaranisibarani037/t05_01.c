// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>
#include <string.h>

struct kata_t {
  char eng[21];
  char ind[81];
};

int main(int _argc, char **_argv) {
  struct kata_t dict[5];
  int size = 0;
  char command[10];

  while (1) {
    scanf("%s", command);

    if (strcmp(command, "register") == 0) {
      if(size < 5) {
        scanf("%s %[^\n]", dict[size].eng, dict[size].ind);
        size++;
      }
    } else if (strcmp(command, "find") == 0) {
      char eng[21];
      scanf("%s", eng);

      for (int i = 0; i < size; i++) {
        if(strcmp(dict[i].eng, eng) == 0) {
          printf("%s#%s\n", dict[i].eng, dict[i].ind);
          break;
        }
      }
    } else if (strcmp(command, "---") == 0) {
      break;
    }
  }

    return 0;
}
