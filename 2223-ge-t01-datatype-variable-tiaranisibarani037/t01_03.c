// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>

int main(int _argc, char **_argv)
{
unsigned int x,y,z, shift1;
scanf("%u", &x);
scanf("%u", &y);
scanf("%u", &z);

printf("%u\n", x<<y);
shift1 = x<<y;
printf("%d", shift1==z);


return 0;
}
