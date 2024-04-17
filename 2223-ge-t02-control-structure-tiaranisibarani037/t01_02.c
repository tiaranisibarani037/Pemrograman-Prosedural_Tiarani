// 12S22004 - Bethania Hasibuan
// 12S22037 - Tiarani Sibarani

#include <stdio.h>

int main(int _argc, char **_argv) {
    // membeli donat max 3 buah
    // untuk melayani 1 transaksi membutuhkan waktu 3 menit

    int Donatbutet = 0;
    int pesananUcok = 0;

    scanf("%d %d", &pesananUcok, &Donatbutet);

    int banyakAntrianButet = 0;
    int banyakAntrianUcok = 0;

    // if (pesananUcok > 3) {
    //     banyakAntrianUcok = (pesananUcok / 3) + 2;
    // }

    // else {
    //     banyakAntrianUcok = pesananUcok;
    // }

    // if (Donatbutet > 3) {
    //     banyakAntrianButet = (Donatbutet / 3) + 2;
    // }

    // else {
    //     banyakAntrianButet = Donatbutet;
    // }

    int banyakAntrian = ((pesananUcok / 3) + 1) + ((Donatbutet / 3) + 1);
    int nextUcok = 1;
    int nextButet = 0;

    for (int i = 0; i < banyakAntrian; i++) {
        if (nextUcok == 1) {
            if (!(Donatbutet < 1)) { // next si butet
                nextUcok--;
                nextButet++;
            }

            if (pesananUcok >= 1 && !(nextButet < 1)) {
                banyakAntrianUcok++;
                banyakAntrianButet++;
                pesananUcok = pesananUcok - 3;
                continue;
            }

            else if (pesananUcok != 0) {
                banyakAntrianUcok++;
                pesananUcok = pesananUcok - 3;
                continue;
            }
            
        }

        if (nextButet == 1) {
            if (!(pesananUcok < 1)) { // next si butet
                nextUcok++;
                nextButet--;
            }

            if (Donatbutet >= 1 && !(nextUcok < 1)) {
                banyakAntrianUcok++;
                banyakAntrianButet++;
                Donatbutet = Donatbutet - 3;
                continue;
            }

            else if (!(Donatbutet < 1)) {
                banyakAntrianButet++;
                Donatbutet = Donatbutet - 3;
                continue;
            }
        }
        
    }

    printf("%d\n", banyakAntrianUcok * 3);
    printf("%d\n", banyakAntrianButet * 3);
    printf("%d\n", (banyakAntrianButet * 3) + (banyakAntrianUcok*3));

    return 0;
}