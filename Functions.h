
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <stdio.h>
#include <math.h>

extern float w, h; // values needed in the function later 

void resizeBmp(ALLEGRO_BITMAP *bmp);
void convertToAscii(ALLEGRO_BITMAP *bmp, FILE *fpText, char * AsciiDictionary);