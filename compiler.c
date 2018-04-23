#include<stdio.h>

enum State
{
  ID, NUM, RSV, OPR, SEP
};

int isSeparate( char ch )
{
  switch( ch )
  {
  case ' ': case '\n':
  case ',': case ':': case ';':
  case '(': case ')': case '\'':
  case '"': case '&': case '|':
    return 1;
  default:
    return 0;
  }
}

int main()
{
  int i = 0, state;
  char ch, token[256];
  char reserve[5][10] = {"if", "else", "for", "while", "return"};
  FILE *fp;

  fp = fopen("test.txt", "r");

  while( fscanf(fp, "%c", &ch) != EOF )
  {
    token[i++] = ch;

    // first character
    if( ch == 0 )
    {
      if( ch >= '0' && ch <= '9' )
      {
        state = NUM;
      }
    }
    else
    {
      state = ID;
    }

    if( isSeparate( ch ) || isSeparate( token[0] ) )
    {
      token[i] = '\0';
      printf("%s\n", token);
      i = 0;
    }
  }

  return 0;
}
