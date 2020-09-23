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

  //Vars
  int red;
  int green;
  int blue;

  int r = &red;
  int g = &green;
  int b = &blue;

  //Error Tests
  if (*r == NULL || *g == NULL || *b == NULL)
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
    *r = (red + green + blue) / 3;
    *g = *r;
    *b = *r;

    return (NO_ERROR);
  }
  else if (mode == 1)
  {
    *r = (min (red, green, blue) + max (red, green, blue)) / 2;
    *g = *r;
    *b = *r;

    return (NO_ERROR);
  }
  else if (mode == 2)
  {
    *r = (0.21 * red) + (0.72 * green) + (0.07 * blue);
    *b = *r;
    *g = *r;

    return (NO_ERROR);
  }

}

int toSepia(int *r, int *g, int *b)
{
  //TODO: implement

  //Vars
  int sepRed;
  int sepGreen;
  int sepBlue;

  *r = &sepRed;
  *g = &sepGreen;
  *b = &sepBlue;

  //Error Tests
  if (*r == NULL || *g == NULL || *b == NULL)
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
  sepRed = (0.393 * *r) + (0.769 * *g) + (0.189 * *b);

  sepGreen = (0.349 * *r) + (0.686 * *g) + (0.168 * *b);

  sepBlue = (0.272 * *r) + (0.534 * *g) + (0.131 * *b);

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

  return (NO_ERROR);
}
