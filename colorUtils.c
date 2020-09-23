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

  *r = &red;
  *g = &green;
  *b = &blue;

  //Error Tests
  if (red == NULL || green == NULL || blue == NULL)
  {
    return (NULL_ERROR);
  }

  if (red > 255 || green > 255 || blue > 255)
  {
    return (ESCEEDS_VAL_ERROR);
  }

  if (red < 0 || green < 0 || blue < 0)
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
    *g = red;
    *b = red;

    return (NO_ERROR);
  }
  else if (mode == 1)
  {
    *r = (min (red, green, blue) + max (red, green, blue)) / 2;
    *g = red;
    *b = red;

    return (NO_ERROR);
  }
  else if (mode == 2)
  {
    *r = (0.21 * red) + (0.72 * green) + (0.07 * blue);
    *b = red;
    *g = red;

    return (NO_ERROR);
  }

}

int toSepia(int *r, int *g, int *b)
{
  //TODO: test

  //Vars
  int sepRed;
  int sepGreen;
  int sepBlue;

  *r = &sepRed;
  *g = &sepGreen;
  *b = &sepBlue;

  //Error Tests
  if (sepRed == NULL || sepGreen == NULL || sepBlue == NULL)
  {
    return (NULL_ERROR);
  }

  if (sepRed > 255 || sepGreen > 255 || sepBlue > 255)
  {
    return (ESCEEDS_VAL_ERROR);
  }

  if (sepRed < 0 || sepGreen < 0 || sepBlue < 0)
  {
    return (NEGATIVE_VAL_ERROR);
  }

  //Non-Error Code
  *r = (0.393 * sepRed) + (0.769 * sepGreen) + (0.189 * sepBlue);

  *g = (0.349 * sepRed) + (0.686 * sepGreen) + (0.168 * sepBlue);

  *b = (0.272 * sepRed) + (0.534 * sepGreen) + (0.131 * sepBlue);

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

  //Set RGB vals
  *r = sepRed;
  *g = sepGreen;
  *b = sepBlue;

  return (NO_ERROR);
}
