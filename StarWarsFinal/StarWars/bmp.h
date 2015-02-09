#ifndef __bmp_
#define __bmp_

#include <stdio.h>
#include <stdlib.h>

typedef struct Image Image;

struct Image {
  unsigned long sizeX;
  unsigned long sizeY;
  char *data;
};

/*Le loader de bmp*/
int ImageLoad(char *, Image *);

#endif

