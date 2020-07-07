#include <stdint.h>

typedef uint8_t BYTE;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint16_t WORD;

typedef struct
{
	BYTE blue;
	BYTE green;
	BYTE red;
} __attribute__((__packed__)) pixel;

typedef struct
{
	BYTE type[2];
	DWORD size;
	WORD reserve[2];
	DWORD offset;
} __attribute__((__packed__)) bmpinfo;

typedef struct 
{
	DWORD header_size;
	LONG width;
	LONG height;
	WORD plane;
	WORD bits;
	DWORD compression;
	DWORD size;
	LONG ppm_x;
	LONG ppm_y;
	DWORD colors;
	DWORD colors_imp;

} __attribute__((__packed__)) bmpheader;