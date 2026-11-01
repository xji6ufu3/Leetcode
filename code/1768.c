#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int debug_on;   // set by DEBUG=1 in Linux, or set -dbg in Windows

#define dbg(...) do { if (debug_on) fprintf(stderr, "[debug] " __VA_ARGS__); } while (0)

char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1), len2 = strlen(word2);

    char *ret = malloc(len1 + len2 + 1);
    if(!ret) return NULL;

    int minlen = len1 > len2 ? len2 : len1;
    for(int i = 0; i < minlen; ++i){
        ret[2 * i] = word1[i];
        ret[2 * i + 1] = word2[i];
    }

    strcpy(ret + 2*minlen, (len1 > len2 ? word1 : word2) + minlen);

    return ret;
}

int main(int argc, char **argv){
    // debug_on = getenv("DEBUG") != NULL;
    debug_on = (argc > 1 && strcmp(argv[1], "-dbg") == 0);

    char word1[105], word2[105];

    printf("word1: ");
    scanf("%s", word1);
    printf("word2: ");
    scanf("%s", word2);

    // if (debug_on){
    //     fprintf(stderr, "word1=%s word2=%s\n", word1, word2);
    // }

    dbg("word1=%s word2=%s\n", word1, word2);

    char *ret = mergeAlternately(word1, word2);
    if(!ret){
        fprintf(stderr, "malloc faild\n");
        return 1;
    }

    printf("answer: %s\n", ret);
    free(ret);

    return 0;
}