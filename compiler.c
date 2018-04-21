#include<stdio.h>

int main()
{
  int id = 0;
  char ch, token[256];
  FILE *fp;

  fp = fopen("test.txt", "r");

  while( fscanf(fp, "%c", &ch) != EOF )
  {
    if( ch != ' ' && ch != '\n' )
    {
      token[id++] = ch;
    }
    else 
    {
      token[id] = '\0';
      printf("%s\n", token);
      id = 0;
    }
  }

  return 0;
}
