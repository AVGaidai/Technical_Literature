/** \file */
#include <stdio.h>


/*
 * Size of input/output buffer
 */
#define BUF_SIZE 1024



/*
 * \brief Delete C comments function.
 *
 * The program deletes C comments.
 * Input data: C program text with comments.
 * Output data: C program text without comments.
 *
 * Argument a command line is filename C program text.
 *
 */
int main(int argc, char *argv[])
{
    FILE *fin, *fout;

    int LC = 0, MC = 0, CS = 0;
    int lch, pch = 0;
    
    if (argc < 2) {
        printf("%s INPUT_FNAME\n", argv[0]);
	return -1;
    }

    fin = fopen(argv[1], "r");
    fout = fopen("result.c", "w");

    pch = fgetc(fin);
    if (pch == EOF) return 0;
    
    while ((lch = fgetc(fin)) != EOF) {
        if (MC && pch == '*' && lch == '/') MC = 0;
                
        if (LC && lch == '\n') LC = 0;
                
        if (pch == '/' && lch == '*') MC = 1;
        else continue;

        if (pch == '/' && lch == '/') LC = 1;
        else continue;

        fputc(pch, fout);
        pch = lch;
    }
/*
    lch = 0;
    while (SIZE >= 1) {
	while (fread((void *) IBUF, sizeof(char), SIZE, fin) > 0) {
	    i = 0;
	    if (lch == '*' && IBUF[0] == '/' && MC && !LC) {
		MC = 0;
		++i;
	    } else if (lch == '/' && IBUF[0] == '*' && !MC && !LC) {
		MC = 1;
		++i;
	    } else if (lch == '/' && IBUF[0] == '/' && !MC && !LC) {
		LC = 1;
		++i;
	    } else if (lch != 0) {
		fwrite((const void *) &lch, sizeof(char), 1, fout);
	    }
	    for (j = 0; i < SIZE - 1; ++i) {
		if (IBUF[i] == '/' && !LC && !MC) {
		    if (IBUF[i + 1] == '/') {
			LC = 1;
		    } else if (IBUF[i + 1] == '*') {
			MC = 1;
			++i;
		    } else {
			OBUF[j++] = IBUF[i];
		    }
		} else if (LC && IBUF[i + 1] == '\n') {
		    LC = 0;
		} else if (MC && IBUF[i] == '*' && IBUF[i + 1] == '/') {
		    MC = 0;
		    ++i;
		} else if (!LC && !MC) {
		    OBUF[j++] = IBUF[i];
		}
	    }
	    fwrite((const void *) OBUF, sizeof(char), (size_t) j, fout);
	    lch = IBUF[i];
	}
	SIZE /= 2;
    }
*/
    printf("See \"result.c\" file.\n");
    fclose(fin), fclose(fout);

    return 0;
}
