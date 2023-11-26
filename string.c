#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void split_free(char **res, int size)
{
    if (res == NULL) {
        return;
    }

    for (int i = 0; i < size; i++) {
        free(res[i]);
    }
    free(res);
}

char **split(char *string, char delimiter, int *n)
{
    int len = strlen(string);
    int i = 0, last = 0;
    char **res = NULL;
    char **temp = NULL;

    for (i = 0; i < len; i++) {
        if (delimiter == string[i]) {
            temp = (char **)realloc(res, sizeof(char *) * (*n + 1));
            if (temp == NULL) {
                printf("realloc failed");
                split_free(res, *n); // Free memory before returning NULL
                return NULL;
            }
            res = temp;
            res[*n] = slice(string, last, i);
            if (res[*n] == NULL) {
                split_free(res, *n); // Free memory before returning NULL
                return NULL;
            }
            (*n)++;
            last = i + 1;
        }
    }

    temp = (char **)realloc(res, sizeof(char *) * (*n + 1));
    if (temp == NULL) {
        printf("realloc failed");
        split_free(res, *n); // Free memory before returning NULL
        return NULL;
    }
    res = temp;
    res[*n] = slice(string, last, i);
    if (res[*n] == NULL) {
        split_free(res, *n); // Free memory before returning NULL
        return NULL;
    }
    (*n)++;
    return res;
}

int _append(char *src, int src_size, char *dest, int dest_size)
{
    int i = 0;
    for (i = 0; i < src_size; i++) {
        dest[dest_size] = src[i];
        dest_size++;
    }
    return dest_size;
}

char *join(char **src, int size, char delimiter)
{
    char *dest = NULL;
    int i = 0, len = 0, existed = 0;
    for (i = 0; i < size; i++) {
        len = strlen(src[i]);
        dest = realloc(dest, sizeof(char) * (existed + len + 1));
        existed = _append(src[i], len, dest, existed);
        if (i < size - 1) {
            dest[existed] = delimiter;
            existed = existed + 1;
        }
    }
    dest[existed] = '\0';

    return dest;
}

int has_prefix(const char *str, const char *pre)
{
    return strncmp(str, pre, strlen(pre)) == 0;
}