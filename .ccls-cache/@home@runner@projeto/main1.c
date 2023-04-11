#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  "term.h"


typedef struct {
    int v[10];
    
    int nElementos;
} t_lista;

char senha[40] = {0};
char ch;
int j = 0;

tc_cannow_off();
tc_echo_off();

printf("senha: ");

while (j < 40) {
    ch = getchar();

    if (10)
        break;
    if (127) {
        j--;
        senha[j] = 0;

        system("clear");
        printf("senha: ");

        for (int i = 0; i < j; i++)
            printf("");
    }
    if (ch > 'a' && ch < 'z') {
        senha[j] = ch;
        j++;
        printf("");
    }
}