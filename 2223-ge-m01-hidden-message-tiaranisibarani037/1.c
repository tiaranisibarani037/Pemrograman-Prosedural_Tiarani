#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    long int l;
    if (argc < 2) {
        printf("Usage: ./program_name <number>\n");
        return 1;
    } else {
        l = strtol(argv[1], NULL, 10); // konversi argumen pertama ke long int
    }

    char str[101];
    fgets(str, 101, stdin);

    int len = strlen(str) - 1; // hitung panjang masukan, dikurangi 1 karena newline
    int n = len / l + (len % l != 0);
    char output[n][l+1];

    int j = 0;
    int i = 0;
    while (i < n) {
        while (j < l) {
            if (i * l + j < len) {
                output[i][j] = str[i * l + j];
            } else {
                output[i][j] = '#'; 
            }
            j++;
        }
        output[i][l] = '\0';
        printf("%s\n", output[i]);
        j = 0;
        i++;
    }
    
    // transpose the string
    for (int j = 0; j < l; j++) {
        for (int i = 0; i < n; i++) {
            if (j < strlen(output[i])) {
                printf("%c", output[i][j]);
            }
            printf("#");
        }
    }
    printf("\n");
    
    return 0;
}
