#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main(int argc, char **argv)
{
  FILE *p;
  long fsize, i = 0;
  char *contents, c;

  p = fopen(argv[1], "r");
  if(p == NULL) { printf("Failed to open file.\n"); return 0; }
  fseek(p, 0, SEEK_END);
  fsize = ftell(p);
  fseek(p, 0, SEEK_SET);
  contents = malloc(fsize);

  while ((c = fgetc(p)) != EOF) contents[i++] = c;
  contents[i] = '\0';
  fclose(p);

  for(i = 0; contents[i] != '\0'; i++) {
    long j;
    if(contents[i] == '\n' && !isspace(contents[i - 1]) && !isspace(contents[i + 1]))
      contents[i] = ' ';
    else if(contents[i] == '\n' && contents[i - 1] == ' ' && !isspace(contents[i + 1])) {
      for(j = i + 1; contents[j] != '\0'; j++) contents[j - 1] = contents[j];
      contents[j - 1] = '\0';
    }
  }

  p = fopen(argv[1], "w"); i = 0;
  while ((c = contents[i++]) != '\0') fputc(c, p);

  free(contents); contents = NULL;
  fclose(p); p = NULL;

  return 0;
}
