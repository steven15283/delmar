/*
 * charint.c
 * how C treats integer and character differently
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
  char v = *argv[1];
  printf("%s\n", v);
  printf("%c\n", v);
  return EXIT_SUCCESS;
}
