#include <stdlib.h>
#include <math.h>

#include "colorUtils.h"

int max(int a, int b, int c) {
  return (a > b) ? (a > c ? a : c) : (b > c ? b: c);
}

int min(int a, int b, int c) {
  return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int toGrayScale(int *r, int *g, int *b, Mode mode)
{
  //TODO: implement
  int userCmd;
  char inLoop = y;

  printf ("Would you like to use the Average (1), Lighness (2), or Luminosity (3) method?\n)");
  scanf("%d\n", userCmd);

  while (inLoop == y)
  {
    if (userCmd == 1)
    {
      return (r + g + b) / 3;
      inLoop = "n";
    }
    else if (userCmd == 2)
    {
      return (min (r, g, b) + max (r, g, b)) / 2;
      inLoop = "n";
    }
    else if (userCmd == 3)
    {
      return (0.21 * r) + (0.72 * g) + (0.07 * b);
      inLoop = "n";
    }
    else
    {
      printf("Please input a valid number\n", );
    }
  }
}

int toSepia(int *r, int *g, int *b) {
  //TODO: implement
}
