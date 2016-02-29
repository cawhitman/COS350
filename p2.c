#include <stdio.h>
#include <stdlib.h>

//Prototypes
long getFileSize(char *filename);
char *compress(char *filename, long fileSize);
int decompress();

//Globals
FILE *fp;
long fileSize;

int main()
{

	fp = stdin;
	
	//get filesize of standard in 
	fileSize = getFileSize(fp);

	//create output buffer
	char *compressionbuffer = malloc(fileSize + 1);

	//compress 8 bits to 7 bits
	compressionbuffer = compress(fp, fileSize);
	

	free(compressionbuffer);
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
char *compress(char *filename, long fileSize)
{
	//create output buffer
	char *outbuffer = malloc(fileSize + 1);

	int charBuf; 
	float bytes = filesize / 8; 
	f = fopen(filename, "rb");
	int count = 0;
	while((charBuff = fgetc(filename)!= EOF) && count <= bytes)
	{
		outbuffer |= (charBuf << (7 * count));
		count++; 
	}

	return outbuffer; 
}

// 32 bit integer is written at the start of the output file
// Contains the length of the original input file
// **Ignore for now
int decompress()
{

}