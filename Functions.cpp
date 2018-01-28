#include "Functions.h"

float w, h;

void resizeBmp(ALLEGRO_BITMAP *bmp)
{
	float imageWidth = al_get_bitmap_width(bmp);
	float imageHeight = al_get_bitmap_height(bmp);

	// for scaling issues
	if (imageWidth > imageHeight) 
	{
		w = (imageWidth / imageHeight) * 200;
		h = (imageHeight / imageWidth) * 200;
	}
	else {
		w = (imageWidth / imageHeight) * 300;
		h = (imageHeight / imageWidth) * 150;
	}

	printf("Rescaling...\n");
	al_set_target_bitmap(bmp);
	al_draw_scaled_bitmap(bmp, 0, 0, imageWidth, imageHeight, 0, 0, w, h, 0);
}
void convertToAscii(ALLEGRO_BITMAP *bmp, FILE *fpText, char * AsciiDictionary)
{
	ALLEGRO_COLOR color;
	float Gray;

	al_set_target_bitmap(bmp);
	al_lock_bitmap(bmp, al_get_bitmap_format(bmp), ALLEGRO_LOCK_READWRITE);


	char str;
	printf("Grayscaling...\n");
	printf("Converting grayscaled bitmap to ascii...\n");
	for (int i = 0; i < h; i++)
	{

		for (int j = 0; j < w; j++)
		{
			color = al_get_pixel(bmp, j, i);
			Gray = (color.r + color.g + color.b) / 3;
			color.r = Gray;
			color.g = Gray;
			color.b = Gray;
			al_put_pixel(j, i, color);

			// zaokraglij liczbe Gray do 2 miejsc po przecinku do (dziesiêtnych lub do 5tek)
			float newGray = Gray * 10;
			Gray = round(newGray);

			// porownuj liczbe 'szarosci' z kolejnymi wartosciami
			if (Gray >= 9.5) {
				str = AsciiDictionary[18];
			}
			else if (Gray == 9.0) {
				str = AsciiDictionary[17];
			}
			else if (Gray == 8.5) {
				str = AsciiDictionary[16];
			}
			else if (Gray == 7.5) {
				str = AsciiDictionary[15];
			}
			else if (Gray == 7.0) {
				str = AsciiDictionary[14];
			}
			else if (Gray == 6.5) {
				str = AsciiDictionary[13];
			}
			else if (Gray == 6.0) {
				str = AsciiDictionary[12];
			}
			else if (Gray == 5.5) {
				str = AsciiDictionary[11];
			}
			else if (Gray == 5.0) {
				str = AsciiDictionary[10];
			}
			else if (Gray == 4.5) {
				str = AsciiDictionary[9];
			}
			else if (Gray == 4.0) {
				str = AsciiDictionary[8];
			}
			else if (Gray == 3.5) {
				str = AsciiDictionary[7];
			}
			else if (Gray == 3.0) {
				str = AsciiDictionary[6];
			}
			else if (Gray == 2.5) {
				str = AsciiDictionary[5];
			}
			else if (Gray == 2.0) {
				str = AsciiDictionary[4];
			}
			else if (Gray == 1.5) {
				str = AsciiDictionary[3];
			}
			else if (Gray == 1.0) {
				str = AsciiDictionary[2];
			}
			else if (Gray == 0.5) {
				str = AsciiDictionary[1];
			}
			else if (Gray == 0) {
				str = AsciiDictionary[0];
			}

			fprintf(fpText, "%c", str);
		}
		fprintf(fpText, "\n");

	}
}