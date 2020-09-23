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
  double grayScale;

  if (mode == 0)
  {
    grayScale = round ((*r + *g + *b) / 3.0);
    *r = grayScale;
    *g = grayScale;
    *b = grayScale;
  }
  else if (mode == 1)
  {
    grayScale = round ((max (*r, *g, *b) + min (*r, *g, *b)) / 2.0);
    *r = grayScale;
    *g = grayScale;
    *b = grayScale;
  }
  else if (mode == 2)
  {
    grayScale = round ((0.21 * *r) + (0.72 * *g) + (0.07 * *b));
    *r = grayScale;
    *g = grayScale;
    *b = grayScale;
  }

  return (NO_ERROR);
}

int toSepia(int *r, int *g, int *b)
{
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
  double sepRed, sepGreen, sepBlue;

  sepRed = round((0.393 * *r) + (0.769 * *g) + (0.189 * *b));

  sepGreen = round((0.349 * *r) + (0.686 * *g) + (0.168 * *b));

  sepBlue = round((0.272 * *r) + (0.534 * *g) + (0.131 * *b));

  //Check for Sepia Color vals > 255 or < 0
  if (sepRed > 255)
  {
    sepRed = 255;
  }
  if (sepRed < 0)
  {
    sepRed = 0;
  }

  if (sepGreen > 255)
  {
    sepGreen = 255;
  }
  if (sepGreen < 0)
  {
    sepGreen = 0;
  }

  if (sepBlue > 255)
  {
    sepBlue = 255;
  }
  if (sepBlue < 0)
  {
    sepBlue = 0;
  }

  //set pointers to sep colors
  *r = sepRed;
  *g = sepGreen;
  *b = sepBlue;

  return (NO_ERROR);
}
