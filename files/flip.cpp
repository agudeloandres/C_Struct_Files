#include <stdio.h>
#include <string.h>
#include <malloc.h>
 
const MAXLENGTH = 2048;
 
FILE *fin, *fout;
int  iConvertType;
char *sFromFileName;
char *sToFileName;   
char *sLine;
  
void printUsage();
void convert();
    
main(int argc, char *argv[])
{

	if (argc < 3) {
		printUsage();
		return 0;
	}
	
	if (!(strcmp(argv[1], "m")) && !(strcmp(argv[1], "u"))) {
		printUsage();
		return 0;
	}	
	if ((fin = fopen(argv[2], "rb")) == NULL) {
		printf("\nCan not open file %s.\n", argv[2]);
		return 0;
	}		          
	if ((fout = fopen(argv[3], "wb")) == NULL) {
		printf("\nCan not open file %s for output!\n", argv[3]);
		return 0;
	}	  
	sToFileName = strdup(argv[3]);
	
	if (!strcmp(argv[1], "m")) iConvertType = 1;  // To MSDOS style
	else iConvertType = 0;	// To UNIX type					
	
	convert();  // Now it's time to convert	
	fclose(fin);
	fclose(fout);    
	printf("DONE!\n");
}

void printUsage()
{         
	printf("flip -- convert text between MSDOS and UNIX format.\n");
	printf("USAGE: flip m|u FromFileName ToFileName\n");
	printf("            m: convert to MSDOS text format\n");
	printf("            u: convert to UNIX text format\n");
	printf(" FromFileName: name of the file being converted\n");
	printf("   ToFileName: new file name\n");
}										

void convert()
{       
	int iRet;
	int length;
	
	sLine = (char *)malloc(sizeof(char)*MAXLENGTH);
	while (fgets(sLine, MAXLENGTH, fin) != NULL) {
		length = strlen(sLine);  
		if ((length > 0) && sLine[length-1] == '\n') {  // End of the line 
			// To MSDOS, check if there is a LF. If not, add it.
			if ((iConvertType == 1) && (sLine[length-1] != '\r')) {
				sLine =(char *) realloc(sLine, MAXLENGTH+2);  // No LF, add it
				sLine[length-1] = '\r';
				sLine[length] = '\n';
				sLine[length+1] = '\0';
			}   
			// To UNIX, check it there is a LF. If there is, delete it
			if ((iConvertType == 0) && (sLine[length-2] == '\r')) { 
				sLine[length-2] = '\n';
				sLine[length-1] = '\0';
			}
		}
		// Can we output the string now?
		iRet = fputs(sLine, fout);
	}																			    
	free(sLine);	
}