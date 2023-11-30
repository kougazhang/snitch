#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define defer(fn) __attribute__((cleanup(fn)))

void cleanup_free(void *p)
{
    free(*((void **)p));
}
#define defer_free defer(cleanup_free)

void cleanup_file(FILE **fp)
{
    if (*fp == NULL) {
        return;
    }
    fclose(*fp);
}
#define defer_file defer(cleanup_file)

char *slice(char *s, int start, int end)
{
    int i = 0, n = 0;
    char *res = (char *)malloc(sizeof(char) * (end - start + 1));
    if (res == NULL) {
        printf("malloc failed");
        return NULL;
    }
    for (i = start; i < end; i++) {
        res[n] = s[i];
        n++;
    }
    res[n] = '\0';
    return res;
}

int has_prefix(const char *str, const char *pre)
{
    return strncmp(str, pre, strlen(pre)) == 0;
}

char *join(char **src, int n, char *delimiter)
{
    char *dest = calloc(strlen(*src), sizeof(char));
    int i = 0;
    unsigned long size = 0;

    for (i = 0; i < n; i++) {
        size = sizeof(char) * (strlen(src[i]) + strlen(dest) + strlen(delimiter) + 2);
        dest = realloc(dest, size);
        strcat(dest, src[i]);
        if (i < n - 1) {
            strcat(dest, delimiter);
        }
    }

    return dest;
}

char **split(char *string, char delimiter, int *n)
{
    char *found = NULL;
    char **res = malloc(strlen(string) * sizeof(char *));

    while ((found = strsep(&string, &delimiter)) != NULL) {
        res[*n] = found;
        (*n)++;
    }

    return res;
}

int main()
{
    char *a = "a,b,c";
    int n = 0;
    defer_free char *string = strdup(a);
    char *delimiter = ",";
    defer_free char **res = split(string, ',', &n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    defer_free char *jo = join(res, n, delimiter);
    printf("%s\n", jo);
}