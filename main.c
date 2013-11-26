#include "fil.h" 
#include <stdio.h> 
#include <string.h> 

int main(void) { 
	
	char *inp[]; 
	char temp[100]; 
	int i = 0; 
	static const char *Nameholder[] = {"Navn på fil:", "Id til bruker:", "Id til gruppe", "Id til katalog:", "Id til eier:", "Skal filen overvåkes, 0 for nei og 1 for ja"); 
	while (i)
		{
		printf("%s", Nameholder[i]); 
		gets(temp); 
		inp[i] = malloc(strlen(temp)); 
		inp[i] = temp; 
		
	if (i > 5)
		break; 
	i ++; 
	}
	
	add_file(inp[0], inp[1], inp[2], inp[3], inp[4], inp[5]); 
	
}	