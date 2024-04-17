// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    long int l = strtol(argv[1], NULL, 10); // strtol digunakan untuk mengkonversi argumen pertama ke long int
    char str[101];
    
    fgets(str, 101, stdin);
    int len;

    if (strlen(str) >= 99) {
        len = strlen(str) - 1; // hitung panjang masukan, dikurangi 1 karena newline
    }

    else {
        len = strlen(str) - 2; // hitung panjang masukan, dikurangi 1 karena newline
    }
    int n = len / l + (len % l != 0);
    char output[n][l+1];

    int j; 
    int i; 
    for (i = 0; i < n; i++) {
        for (j = 0; j < l; j++) {
            if (i * l + j < len) {
                output[i][j] = str[i * l + j];
            } else {
                output[i][j] = '#'; 
            }
        }
        output[i][l] = '\0';
        printf("%s\n", output[i]);
    }

  return 0;
}
