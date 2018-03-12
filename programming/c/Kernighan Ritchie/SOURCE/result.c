
#include <stdio.h>
#include <stdlib.h>


#define N 80


#define n 8


int main(int argc, char *argv[])
{
    char *input, *output, ch;
   
    int i = 0, j = 0, step = 10, pos = 0;
    int size, ldil;

   
    FILE *fp;

    
   
    input = (char *) malloc(step * sizeof(char));
    size = step;
    do {
	scanf("%c", &ch);
	input[i] = ch;

       n
	if (++i == size) {
	    input = (char *) realloc((void *) input,
				     (size + step) * sizeof(char));
	    size += step;
	}
    } while (ch != '\n');
    input[i - 1] = '\0';

    i = 0;
   
    output = (char *) malloc((size + size / N) * sizeof(char));
    ldil = -1;
    while (input[i] != '\0' && size > N) {
	if (input[i] == '\t') {
	    pos += n - (pos % n) - 1;
	    ldil = i;
	} else if (input[i] == ' ') {
	    ldil = i;
	}
	output[j] = input[i];
	++i, ++j, ++pos;
	if (pos == N) {
	    if (ldil == -1) {
		while (input[i] != '\0') {
		    output[j] = input[i];
		    ++i, ++j;
		    if (input[i - 1] == '\t' || input[i - 1] == ' ') {
			output[j++] = '\n';
			pos = 0;
			break;
		    }
		}
	    } else { 
		j -= i - ldil - 1;
		i = ldil + 1;
		pos = 0;
		ldil = -1;
		output[j++] = '\n';
	    }
	}
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

ar));
	    size += step;
	}
    } while (ch != '\n');
    input[i - 1] = '\0';

    i = 0;
   
    output = (char *) malloc((size + size / N) * sizeof(char));
    ldil = -1;
    while (input[i] != '\0' && size > N) {
	if (input[i] == '\t') {
	    pos += n - (pos % n) - 1;
	    ldil = i;
	} else if (input[i] == ' ') {
	    ldil = i;
	}
	output[j] = input[i];
	++i, ++j, ++pos;
	if (pos == N) {
	    if (ldil == -1) {
		while (input[i] != '\0') {
		    output[j] = input[i];
		    ++i, ++j;
		    if (input[i - 1] == '\t' || input[i - 1] == ' ') {
			output[j++] = '\n';
			pos = 0;
			break;
		    }
		}
	    } else { 
		j -= i - ldil - 1;
		i = ldil + 1;
		pos = 0;
		ldil = -1;
		output[j++] = '\n';
	    }
	}
    }
    output[j] = input[i];

    printf("See \"result.txt\" file.\n");

    fp = fopen("result.txt", "w");

    fprintf(fp, "%s\n", i