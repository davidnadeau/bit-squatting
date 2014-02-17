#include <stdio.h>

#define MAXLENGTH 100
#define BYTE 7 

int getaddress(char address[]);
int flipbit(int n, int k);

main() {
    int word_length, flip_count;
    char address[MAXLENGTH];
    
    word_length = getaddress(address);     
    flip_count = word_length * BYTE;
    char flipped_address[flip_count][word_length+1];
    
    //fill array with original address;
    int i,j; 
    for (i = 0; i < flip_count; ++i) {
        for (j = 0; j < word_length; ++j)
            flipped_address[i][j] = address[j];
        flipped_address[i][word_length] = '\0';
    }

    //first char 7 times, sec char 7 times, ...
    int k;
    k = 0;
    for (i = 0; i < word_length; ++i) {
        for (j = 1; j < BYTE; ++j) {
            flipped_address[k][i] = flipbit(address[i], j);
            printf("%s\n",flipped_address[k]);
            ++k;
        }
    }   
    printf("%s\n",flipped_address[k]);
}

/* get word from console, return word len*/
int getaddress(char address[]) {
    int c, len; 
    len=0;
    while ((c = getchar()) != '\n') {
       address[len] = c;
       ++len;
    }
    return len;
}

int flipbit(int n, int k) {
    return n ^ (1 << k);
}
