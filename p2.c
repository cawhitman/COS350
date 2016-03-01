
#include <stdio.h>
#include <stdlib.h>

//Prototypes
long int getFileSize(char *input);
void compress(char *filename, long int fileSize);
int decompress();

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
	FILE *out_fp;
	
	//Create compressed output file
	out_fp = fopen("compressedOut.txt", "w+");
	in_fp = fopen(filename, "rb");

	unsigned int nextChar; 
	unsigned int temp;
	
	//Initialize values
	temp = fgetc(in_fp);
	int count = 0;

	while(temp!= EOF)
	{
		nextChar = fgetc(in_fp);
		unsigned char compressedChar = temp | (nextChar << (8 - count));
		
	
		temp = nextChar;
		count++;
		if(count <=7)
		{
			fwrite (&compressedChar, 1, 1, out_fp);
		} else
		{
	 		//chop off bits
			count = 0; 
		}
	}
	
	
}

// 32 bit integer is written at the start of the output file
// Contains the length of the original input file
// **Ignore for now
int decompress()
{

}