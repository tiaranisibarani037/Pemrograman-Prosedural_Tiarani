    // 12S22004 - Bethania Hasibuan
    // 12S22037 - Tiarani Sibarani

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main(int argc, char *argv[]) {
        long int panjangkarakter = strtol(argv[1], NULL, 10); 
        // strtol digunakan untuk mengkonversi argumen pertama ke long int dan disimpan dalam variabel panjangkarakter

        char input[101];
        // 101 karena karakter 100 ditambah dengan null
        fgets(input, 101, stdin);
        int jumlahkarakterinput; 
        
        // batasnya menampung mulai dari 99 karakter
        if (strlen(input) >= 99) {
            // hitung panjang masukan, dikurangi 1 karakter sudah lebih dari 99
            jumlahkarakterinput = strlen(input) - 1; 
        } else {
            // hitung panjang masukan, dikurangi 2 jika karakter kurang dari 99
            jumlahkarakterinput = strlen(input) - 2; 
        }
        int barisdibutuhkan = jumlahkarakterinput / panjangkarakter + (jumlahkarakterinput % panjangkarakter != 0);
        char output[barisdibutuhkan][panjangkarakter+1];

        int j = 0;
        int i = 0;
        while (i < barisdibutuhkan) {
            while (j < panjangkarakter) {
                if (i * panjangkarakter + j < jumlahkarakterinput) {
                    output[i][j] = input[i * panjangkarakter + j];
                } else {
                    output[i][j] = '#'; 
                }
            }
            output[i][panjangkarakter] = '\0';
            printf("%s\n", output[i]);
            j++;
            i++;
        }
        
    return 0;
    }