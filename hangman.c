#include <stdio.h>

int main(void)
{
	char array[8];
	int i;

	array[0] = 'H';
	array[1] = 'a';
	array[2] = 'n';
	array[3] = 'g';
	array[4] = 'm';
	array[5] = 'a';
	array[6] = 'n';

	for(i = 0; i < 7; i++) {
		printf("%c", array[i]);
	}

	printf("\n");

	return 0;
}
