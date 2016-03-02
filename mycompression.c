
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//Prototypes
long int getFileSize(char *input);
void compress(char *filename, long int fileSize);
void decompress(char *filename, long int fileSize);

//Globals
unsigned int fileSize;

int main(int argc, char *argv[])
{	
	if(argc != 2)
	{
		printf("Please add a txt file as an argument. \n");
		return 0; 
	}

         
	//get filesize of standard in 
	fileSize = getFileSize(argv[1]);

	//create output buffer
	unsigned char *compressionbuffer = malloc(fileSize + 1);

	//compress 8 bits to 7 bits
	compress(argv[1], fileSize);
	
	free(compressionbuffer);
	return 0;
}

//File size in bytes
long int getFileSize (char *input)
{
	long int size;
	FILE *file_fp;

      	file_fp = fopen(input, "rb");
	
	fseek(file_fp, 0L, SEEK_END);
	size = ftell(file_fp );
	
	rewind(file_fp );
	fclose(file_fp );

	return size; 
}

//Compresses 8 bit ASCII characters into 7 bits 
void compress(char *filename, long int fileSize)
{
	FILE *in_fp;
	int out_fp;
	
	//Create compressed output file
	out_fp = open("compressedOut.txt", O_WRONLY);
	in_fp = fopen(filename, "rb");

	unsigned int nextChar; 
	unsigned int temp;
	//write (out_fp, &fileSize ,4);

	//Initialize values
	temp = fgetc(in_fp);
	int leftShiftCount = 7;
	int rightShiftCount = 0;
	int inFile;

	
	//Print original file size in header
	write (out_fp, &fileSize, 4);

	while(temp!= EOF)
	{
		nextChar = fgetc(in_fp);
		
		unsigned char compressedChar = (temp | (nextChar << leftShiftCount));
		write (out_fp, &compressedChar, 1);

		if(rightShiftCount<6)
		{
			rightShiftCount++;
			temp = nextChar >> rightShiftCount;
		}else
		{
			temp = fgetc(in_fp);
			rightShiftCount = 0;
		}
		
		
		if(leftShiftCount > 1)
		{
			leftShiftCount--;
		} else {
			leftShiftCount = 7;
		}


	}
	
	
}

// 32 bit integer is written at the start of the output file
// Contains the length of the original input file
// **Ignore for now
void decompress(char *filename, long int fileSize)
{
	FILE *in_fp;
	int out_fp;
	
	//Create compressed output file
	out_fp = open("decompressed.txt", O_WRONLY);
	in_fp = fopen("compressedOut.txt", "rb");

	unsigned int nextChar; 
	unsigned int temp;
	//write (out_fp, &fileSize ,4);

	//Initialize values
	temp = fgetc(in_fp);
	int leftShiftCount = 7;
	int rightShiftCount = 0;
	int inFile;

	
	//Print original file size in header
	write (out_fp, &fileSize, 4);

	while(temp!= EOF)
	{
		nextChar = fgetc(in_fp);
		
		unsigned char compressedChar = (temp | (nextChar << leftShiftCount));
		write (out_fp, &compressedChar, 1);

		if(rightShiftCount<6)
		{
			rightShiftCount++;
			temp = nextChar >> rightShiftCount;
		}else
		{
			temp = fgetc(in_fp);
			rightShiftCount = 0;
		}
		
		
		if(leftShiftCount > 1)
		{
			leftShiftCount--;
		} else {
			leftShiftCount = 7;
		}


	}

}
