# COS350
Systems Programming

Contents:

    z827.c
    short.txt
    shake.txt
    
Descriptions:

    z827.c
        z827.c is a program that compresses text files and adds an extension .z827. It also decompresses 
        its compressed .z827 files. 
        
    short.txt 
        A short text file to test with.
    
    shake.txt
        A long text file to test with.
        
Bugs:

    Upon compressing a text file we lose the last character byte. 
    
How to run: 

    > gcc z827.c -o z827
    > z827 <textFileName> OR z827 <textFileName.z827>
        
