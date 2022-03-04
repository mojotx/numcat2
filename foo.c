#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define BLK "\e[1;30m"
#define OFF "\e[0m"

int main(){
    uint32_t data[50];
    setlocale(LC_NUMERIC, "");

    uint32_t max = 100;

    for (size_t i=0; i<sizeof(data)/sizeof(data[0]); i++) {

        if (i > 0 && i%2 ) {
            max *= 2;
        }
        data[i] = arc4random_uniform(max);

        uint32_t digits = (uint32_t)(log10( (double)(max)))+1;
        printf("data[%lu] = " BLK "%'u" OFF ", log=" BLK "%u" OFF " max=%u\n", i, data[i], digits, max-1);
    }
    return EXIT_SUCCESS;
}
