#ifndef __SNICH__STRING__
#define __SNICH__STRING__


char** split(char *string, char delimitor, int *n);
void split_free(char **res, int size);
char *join(char **src, int size, char delimiter);
char *slice(char *s, int start, int end);

#endif