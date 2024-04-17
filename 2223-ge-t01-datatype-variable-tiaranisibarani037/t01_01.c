// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>

int main(int _argc, char **_argv)
{
  int num;
  scanf("%d", &num);

  char b;
  scanf(" %c ", &b);

  int boolean;
  scanf("%d", &boolean);
  
  unsigned short numerik;
  scanf("%hu", &numerik);

  float flot;
  scanf("%f", &flot);

  printf("%d\n", num);
  printf("%c\n", b);
  printf("%d\n", boolean);
  printf("%hu\n", numerik);
  printf("%.2f\n", flot);

return 0;
}