#include "file.h" 
#include <stdio.h> 
#include <string.h> 

int main(void) {
	char *inp[5];
	char temp[100];
	static const char *Nameholder[] = {"Navn på fil:", "Id til bruker:", "Id til gruppe", "Id til katalog:", "Id til eier:", "Skal filen overvåkes, 0 for ja"};

	for(;;) {
		int i = 0;
		while (i) {
			printf("%s", Nameholder[i]);
			gets(temp);
			inp[i] = malloc(strlen(temp));
			inp[i] = temp;

			if (i > 5)
				break;
			i++;
		}
		add_file(inp[0], atoi(inp[1]), atoi(inp[2]), atoi(inp[3]), atoi(inp[4]), atoi(inp[5]));
	}
}
