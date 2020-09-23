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
  int red;
  int green;
  int blue;

  r = &red;
  g = &green;
  b = &blue;

  if (mode == 0)
  {
    return (red + green + blue) / 3;
  }
  else if (mode == 1)
  {
    return (min (red, green, blue) + max (red, green, blue)) / 2;
  }
  else if (mode == 2)
  {
    return (0.21 * red) + (0.72 * green) + (0.07 * blue);
  }
  else
  {
    printf("Please input a valid number\n", );
  }
}
/**
int toSepia(int *r, int *g, int *b)
{
  //TODO: implement

}
*/
