/** \file */
#include <stdio.h>
#include <stdlib.h>

/*
 * Size of <tab> in spaces
 */
#define N 8


/**
 * \brief The detab function.
 *
 * The program replaces <tab> on the N spaces.
 * Input data: any text with spaces and <tab>.
 * Output data: input text with spaces and without <tab>.
 */
int main(int argc, char *argv[])
{
    char *input, *output, ch;
   /* 
    * size -- size of input buffer
    * step -- increases buffer value
    * spaces -- counter for spaces
    * i -- pointer on current symbol for input
    * j -- pointer on current symbol for output
    */
    int i = 0, j = 0, step = 10, spaces = 0;
    int size;

   /* 
    * File descriptor for output result
    */
    FILE *fp;

    
   /*
    * Memory allocation for input stream
    */
    input = (char *) malloc(step * sizeof(char));
    size = step;
    do {
	scanf("%c", &ch);
	input[i] = ch;

       /*
	* Memory reallocation for input stream
	*/
	if (++i == size) {
	    input = (char *) realloc((void *) input,
				     (size + step) * sizeof(char));
	    size += step;
	}
    } while (ch != '\n');
    input[i - 1] = '\0';

    i = 0;
   /*
    * Memory allocation for output stream
    */
    output = (char *) malloc(size * sizeof(char));
    
    while (input[i] != '\0') {
	if (input[i] == '\t') {
	    spaces = N - (j % N);
	   /*
	    * Memory reallocation for output stream
	    */
	    output = (char *) realloc((void *) output,
				      (size + spaces) * sizeof(char));
	    size += spaces;
	    for ( ; spaces != 0; --spaces) {
		output[j++] = ' ';
	    }
	    --j;
	} else {
	    output[j] = input[i];
	}
	++i, ++j;
    }
    output[j] = input[i];

    printf("See \"result.txt\" file.\n");

    fp = fopen("result.txt", "w");

    fprintf(fp, "%s\n", input);
    fprintf(fp, "%s\n", output);    

    fclose(fp);
    
    free(input);
    free(output);
    
    return 0;
}
