// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    long int pjgkarakter;
    pjgkarakter = strtol(argv[1], NULL, 10); // konversi argumen pertama ke long int

    char str[101];
    fgets(str, 101, stdin);
    int jlhkarakterinput;

    if (strlen(str) >= 99) {
        jlhkarakterinput = strlen(str) - 1; // hitung panjang masukan, dikurangi 1 karena newline
    }   
    else {
        jlhkarakterinput = strlen(str) - 2; // hitung panjang masukan, dikurangi 2 karena newline
    }
    int n = jlhkarakterinput / pjgkarakter + (jlhkarakterinput % pjgkarakter != 0);
    char output[n][pjgkarakter+1];

    int j = 0;
    int i = 0;
    while (i < n) {
        while (j < pjgkarakter) {
            if (i * pjgkarakter + j < jlhkarakterinput) {
                output[i][j] = str[i * pjgkarakter + j];
            } else {
                output[i][j] = '#'; 
            }
            j++;
        }
        output[i][pjgkarakter] = '\0';
        printf("%s\n", output[i]);
        j = 0;
        i++;
    }
    // Hidden message --> menggabungkan string menjadi satu
            // int j = 0; akan tetapi sudah di declare pada global scope
        do {
             int i = 0;
        do {
        if (j < strlen(output[i])) {
            printf("%c", output[i][j]);
        }
        i++;
    } while (i < n);
    j++;
} while (j < pjgkarakter);

    printf("\n");
    
    return 0;
}
