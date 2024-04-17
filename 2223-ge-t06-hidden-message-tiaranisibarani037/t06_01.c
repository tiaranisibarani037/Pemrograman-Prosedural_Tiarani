// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_output(char output[][101], int n, int pjgkarakter) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", output[i]);
    }
}

void combine_strings(char output[][101], int n, int pjgkarakter) {
    for (int j = 0; j < pjgkarakter; j++) {
        for (int i = 0; i < n; i++) {
            if (j < strlen(output[i])) {
                printf("%c", output[i][j]);
            }
        }
    }
    printf("\n");
}

void process_input(long int pjgkarakter, char *input) {
    int jlhkarakterinput = strlen(input);
    if (jlhkarakterinput >= 99) {
        jlhkarakterinput -= 1;
    } else {
        jlhkarakterinput -= 2;
    }

    int n = jlhkarakterinput / pjgkarakter + (jlhkarakterinput % pjgkarakter != 0);
    char output[n][101];

    int j = 0;
    int i = 0;
    while (i < n) {
        while (j < pjgkarakter) {
            if (i * pjgkarakter + j < jlhkarakterinput) {
                output[i][j] = input[i * pjgkarakter + j];
            } else {
                output[i][j] = '#'; 
            }
            j++;
        }
        output[i][pjgkarakter] = '\0';
        j = 0;
        i++;
    }

    print_output(output, n, pjgkarakter);
    combine_strings(output, n, pjgkarakter);
}

int main(int argc, char *argv[]) {
    long int pjgkarakter = strtol(argv[1], NULL, 10);
    char input[101];
    fgets(input, 101, stdin);
    process_input(pjgkarakter, input);
    return 0;
}