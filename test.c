#include <stdio.h>
#include <libc.h>
#include <string.h>
#include "string.h"

int main()
{
    char string[] = "a,b,c";
    char delimiter = ',';
    int size = 0;
    char **res = split(string, delimiter, &size);
    if (!res) {
        return -1;
    }

    char *joined = join(res, size, delimiter);
    printf("%s\n", joined);
    printf("%d\n", strcmp(string, joined));
    split_free(res, size);
    free(joined);
    return 0;
}