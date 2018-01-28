#include "Functions.h"


int main()
{
	al_init();
	al_init_image_addon();

	char BitmapName[100];
	int notFound;
		
	printf("Please enter the name of the bitmap: (format: <nameOfTheFile> - with .bmp): \n");
	scanf("%s", BitmapName);

	ALLEGRO_BITMAP *bmp = NULL;
	bmp = al_load_bitmap(BitmapName);
	
	if (bmp)
	{
		printf("Bitmap was found !");
		notFound = 0;
	}
	else {
		printf("Bitmap was not found !\n");
		notFound = 1;
	}

	if (!notFound)
	{
		resizeBmp(bmp);

		char AsciiDictionary[19] = "@#%xo+<>/;:,.";
		FILE *fpText = fopen("graphic.txt", "w+");

		// conversion from bitmap to ascii
		convertToAscii(bmp, fpText, AsciiDictionary);

		al_unlock_bitmap(bmp);

		printf("Ascii picture created...\n");
		fclose(fpText);

	}

	printf("Press enter to exit the program...\n");
	al_destroy_bitmap(bmp);

	getchar();
	getchar();
	return 0;
}