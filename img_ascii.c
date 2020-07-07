#include <stdio.h>
#include <stdlib.h>

#include "img_ascii.h"

char get_char(double val);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("usage: img_ascii image.bmp\n");
		//return 1;
	}

	FILE *img; // = fopen("Bendy.bmp", "r");
	fopen_s(&img, "Bendy.bmp", "r");

	bmpinfo info;
	fread(&info, sizeof(bmpinfo), 1, img);
	bmpheader header;
	fread(&header, sizeof(bmpheader), 1, img);

	LONG height = abs(header.height), width = header.width;

	int padding = (4 - (width * sizeof(pixel)) % 4) % 4;
	for (int i = 0; i < height; i++)
	{
		fseek(img, -136 + header.size - (sizeof(pixel) * i * (width + padding)), SEEK_SET);
		for (int j = 0; j < width; j++)
		{
			pixel p;
			fread(&p, sizeof(pixel), 1, img);
			int avg = (p.blue + p.green + p.red) / 3;
			char c = get_char(avg);
			printf("%c%c", c, c);
		}
		printf("%c", '\n');
	}
	

	//scanf_s("");

	fclose(img);
}

char get_char(double val)
{
	if(val < 30)
		return 'E';
	else if(val < 70)
		return 'A';
	else if(val > 250)
		return '0';
	else
		return ';';
}