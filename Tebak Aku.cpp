#include <stdio.h> // <----- Masukin library(ibarat perkakas masseh) buat masukin beberapa fungsi utama input / output (i/o)

int main(){ // <-----  Function utama
    int benih, acak, input; // <----- Inisialisasi variable

    printf("=== Tebak Angka ! ===\n"); // <----- Buat nampilin teks
    printf("Silahkan masukan seed(1,2,...) : "); // <----- Sama aja cuman nyuruh kalian buat input angka
    scanf("%d", &benih); // <----- Meminta input dari kalian

    acak = (11 * benih + 7 + benih) % 26; // <----- Metode untuk mengacak angka (secara sederhana, literaly males buat yang beneran random)

    printf("\nTebak Angka Dimulai !\n"); // <----- Buat nampilin teks[2]

    do {
        printf("Masukan tebakan mu! : "); // <----- Sama aja cuman nyuruh kalian buat input angka[2]
        scanf("%d", &input); // <----- Meminta input dari kalian[2]

        if(acak == input){ // <----- Conditional Function (sok inglis), singkatnya ini buat ngecek kalau inputannya bener apa kaga
            for(int i = 0; i < input; i++){ // <----- Semisal kalau iya, aku bikinin fungsi buat loop kode di kurawal bawah ini
                printf("> Yeay Kamu Benar!!!\n"); // <----- Buat nampilin teks[3]
            } 
        } else { // <----- Semisal ga hoki alias boncos, yaudah jalanin kode di kurawal bawah ini
                printf("> Ups salah\n"); // <----- Buat nampilin teks[3]
                if(acak > input) printf("Kekecilan!\n");
                if(acak < input) printf("Kegedean!\n");
        }
        
    } while (input != acak); // <----- Nah kan udah jalanin kode "do" barusan, disinilah penentuannya
                             //        Semisal kalau input gak sama dengan acak berarti ulangin donya
                             //        Semisal kalau gacor(beruntung) ya ga di ulangin lagi alias lanjut ke kode dibawah ini
    printf("Program selesai, terima kasih telah bermain! Kacawww"); // <----- Ni buat ngasi tau kalo program dah beres, Cihuyy
    // Dah gitu aja yappingnya :v <3 you guys
}
