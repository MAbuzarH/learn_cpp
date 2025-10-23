// #include <stdio.h>
// #include <errors.h>
// #include <stdlib.h>
// #define BUFF_SIZ 256
// int main(int argc, char *argv[])
// {
//   FILE *infile, *outfile;
//   char rec[BUFF_SIZ];
//   size_t bytesIn, bytesOut;
//   if (argc != 3)
//   {
//     fprintf(stderr, "Usage:cp file1 file2 \n");
//     return 1;
//   }

//   // infile = fopen(argv[1], "rb");
//   infile = fopen("a.txt", "rb");
//   if (infile == NULL)
//   {
//     perror(argv[1]);
//     return 2;
//   }
//   // outfile = fopen(argv[2], "wb");
//   outfile = fopen("b.txt", "wb");
//   if (outfile == NULL)
//   {
//     perror(argv[2]);
//     fclose(infile);
//     return 3;
//   }

//   while ((bytesIn = fread(rec,1,BUFF_SIZ,infile))){
//     bytesOut = fwrite(rec,1,bytesIn,outfile);
//     if(bytesOut != bytesIn){
//        perror("flat write error");
//        fclose(infile);
//         fclose(outfile);
//       return 4;
//     }
//   }
//   fclose(infile);
//   fclose(outfile);
//   return 0;
// }

// run code: gcc -o copy copy.c
//./copy a.txt b.txt 
#include <stdio.h>
#include <stdlib.h> // Good practice for return codes and size_t type, though often covered by stdio.h
// The original code had: #include <errors.h>
// FIX: This is not a standard C header and must be removed.

#define BUFF_SIZ 256 // Define the buffer size for read/write operations

int main(int argc, char *argv[])
{
  // File pointers for the input and output files
  FILE *infile, *outfile;
  // Buffer to hold data read from the input file
  char rec[BUFF_SIZ];
  // Variables to store the number of bytes read (bytesIn) and written (bytesOut)
  size_t bytesIn, bytesOut;

  // Check if the correct number of arguments (program name + 2 filenames) was provided
  if (argc != 3)
  {
    // Print usage message to standard error
    fprintf(stderr, "Usage: %s file1 file2 \n", argv[0]);
    return 1;
  }

  // Open the input file specified by the first argument (argv[1]) in binary read mode ("rb")
  infile = fopen(argv[1], "rb");
  if (infile == NULL)
  {
    // Print an error message if the input file cannot be opened
    perror(argv[1]);
    return 2;
  }

  // Open the output file specified by the second argument (argv[2]) in binary write mode ("wb")
  outfile = fopen(argv[2], "wb");
  if (outfile == NULL)
  {
    // Print an error message if the output file cannot be opened
    perror(argv[2]);
    // Clean up: close the input file before exiting
    fclose(infile);
    return 3;
  }

  // Main copy loop: read data into the buffer until EOF or an error occurs
  while ((bytesIn = fread(rec, 1, BUFF_SIZ, infile)))
  {
    // Write the read data to the output file
    bytesOut = fwrite(rec, 1, bytesIn, outfile);

    // Check if the number of bytes written matches the number of bytes read
    if (bytesOut != bytesIn)
    {
      // Error occurred during writing
      perror("file write error");

      // Clean up: close both files before returning
      fclose(infile);
      fclose(outfile);
      return 4;
    }
  }

  // Check for read errors (failing to read the expected amount is handled above,
  // but this check catches other stream errors like reaching EOF)
  if (ferror(infile))
  {
    perror("file read error");
    fclose(infile);
    fclose(outfile);
    return 5;
  }

  // Close both files upon successful completion
  fclose(infile);
  fclose(outfile);

  // Success return code
  return 0;
}