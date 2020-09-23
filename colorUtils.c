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
  //TODO: check


  //Error Tests
  if (r == NULL || g == NULL || b == NULL)
  {
    return (NULL_ERROR);
  }

  if (*r > 255 || *g > 255 || *b > 255)
  {
    return (ESCEEDS_VAL_ERROR);
  }

  if (*r < 0 || *g < 0 || *b < 0)
  {
    return (NEGATIVE_VAL_ERROR);
  }

  if (mode > 4)
  {
    return (NO_MODE_ERROR);
  }

  //Non-Error Code
  if (mode == 0)
  {
    *r = (*r + *g + *b) / 3;
    *g = *r;
    *b = *r;
  }
  else if (mode == 1)
  {
    *r = (min (*r, *g, *b) + max (*r, *g, *b)) / 2;
    *g = *r;
    *b = *r;
  }
  else if (mode == 2)
  {
    *r = (0.21 * *r) + (0.72 * *g) + (0.07 * *b);
    *b = *r;
    *g = *r;
  }

  return (NO_ERROR);
}

int toSepia(int *r, int *g, int *b)
{
  //TODO: test

  //Error Tests
  if (r == NULL || g == NULL || b == NULL)
  {
    return (NULL_ERROR);
  }

  if (*r > 255 || *g > 255 || *b > 255)
  {
    return (ESCEEDS_VAL_ERROR);
  }

  if (*r < 0 || *g < 0 || *b < 0)
  {
    return (NEGATIVE_VAL_ERROR);
  }

  //Non-Error Code
  *r = (0.393 * *r) + (0.769 * *g) + (0.189 * *b);

  *g = (0.349 * *r) + (0.686 * *g) + (0.168 * *b);

  *b = (0.272 * *r) + (0.534 * *g) + (0.131 * *b);

  //Check for Sepia Color vals > 255 or < 0
  if (*r > 255)
  {
    *r = 255;
  }
  if (*r < 0)
  {
    *r = 0;
  }

  if (*g > 255)
  {
    *g = 255;
  }
  if (*g < 0)
  {
    *g = 0;
  }

  if (*b > 255)
  {
    *b = 255;
  }
  if (*b < 0)
  {
    *b = 0;
  }

  return (NO_ERROR);
}
