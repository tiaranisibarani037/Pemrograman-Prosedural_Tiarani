// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>

int main(int _argc, char **_argv) {
  int a, b;
scanf("%d", &b);
int hasil[b], maximum, minimum;
float value[a];
float avrgvalue;

for (a = 0; a < b; a++)
{
  scanf("%d", &hasil[a]);
}
maximum = hasil [0]; // inisialisasi varibel maximum
minimum = hasil[0]; // inisialisasi variabel minimum
for (a = 1; a < b; a++)
{
  if (maximum < hasil[a])
  {
    maximum = hasil[a];
  } else if (minimum > hasil[a])
  {
    minimum = hasil[a];
  }
}
for(a = 0; a < b-1; a++){
  value[a] = (float)(hasil[a] + hasil[a+1])/2;
}
avrgvalue = value[0];

for (a = 1; a < b-1; a++){
  if (value[a] < avrgvalue )
  {
    avrgvalue = value [a];
  }
}

printf("%d\n%d\n%.2f", minimum, maximum, avrgvalue);
return 0;
}
