#include "hash.h"
int main() {
	printf("%s\n",hash("/bin/sh"));
	printf("Was: %s\n",prevHashFor("/bin/sh"));
	printf("Changed: %d\n",fileChanged("/bin/sh"));
}
