#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char x, y, z;
    x = 11, y = 12, z = 23;
    if ((x == y - 1) && !(y < -z))
    {
        printf("Yes!");
    }
}
