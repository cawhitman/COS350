#include <stdio.h>
#include <stdlib.h>

//Prototypes
long getFileSize(char *filename);
int compress();
int decompress();

//Globals
FILE *fp;

int main()
{
	long fileSize;

	fp = stdin;
	fileSize = getFileSize(fp);



	return 0;
}

//File size in bytes
long getFileSize (char *filename)
{
	long size;
	FILE *f;

	f = fopen(filename, "rb");
	if (f== NULL) return -1;
	fseek(f, 0, SEEK_END);
	size = ftellf(f);
	fclose(f);

	return size; 
}

//Compresses 8 bit ASCII characters into 7 bits 
int compress()
{

}

// 32 bit integer is written at the start of the output file
// Contains the length of the original input file
// **Ignore for now
int decompress()
{

}