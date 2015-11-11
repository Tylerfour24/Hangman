#include <stdio.h>
#include <string.h>

void setup(int index, char *answer, char *display);
void result(int correct, int wrongcount);

int main(void)
{
	char answer[8];
	char display[8];
	char checker[8];
	char guess[2]; //space for one character, the newline, and the null byte
	int index;
	int wrongcount;
	int compare;
	int correct;

	answer[0] = 'h'; //Still need to grab a word from a file
	answer[1] = 'a';
	answer[2] = 'n';
	answer[3] = 'g';
	answer[4] = 'm';
	answer[5] = 'a';
	answer[6] = 'n';

	for(index = 0; index < 7; index++) {
		display[index] = '_';
	}

	setup(index, answer, display);

	wrongcount = 0;
	correct = strcmp(display, answer);
	while( (wrongcount != 6) && (correct != 0) ) {

		printf("Enter a letter: ");
		fgets(guess, sizeof(guess)+1, stdin);
		strncpy(checker, display, sizeof(display)+1); //this is supposed to create a copy of the empty display

		for(index = 0; index < 7; index++) {

			if(answer[index] == guess[0]) {
				display[index] = guess[0]; //alter display if the guessed letter is present
			}
		}
		
		correct = strcmp(display, answer);
		compare = strcmp(display, checker);

		if(compare == 0) {
			wrongcount += 1;
		}

		else {
			; //Do nothing
		}

		result(correct, wrongcount);

		for(index = 0; index < 7; index++) {
			printf("%c", display[index]);
		}
		printf("\n");
	}
	return 0;
}

void setup(int index, char *answer, char *display) {

	for(index = 0; index < 7; index++) {
		printf("%c", answer[index]);
	}

	printf("\n");

	for(index = 0; index < 7; index++) {
		printf("%c", display[index]);
	}

	printf("\n\n");
}

void result(int correct, int wrongcount) {
	if(correct == 0) {
		printf("\n\nYOU WIN!\n\n");
		printf("   ___\n  |   |\n      |\n      |      O\n      |     /|\\ \n  ____|____ / \\ \n"); //Prints winning screen
	}
	else {
		switch(wrongcount){ //Prints necessary screen based on number of guesses remaining.
			case(0) :
				printf("   ___\n  |   |\n      |\n      |\n      |\n  ____|____\n");
				break;
			case(1) :
				printf("   ___\n  |   |\n  O   |\n      |\n      |\n  ____|____\n");
				break;
			case(2) :
				printf("   ___\n  |   |\n \\O   |\n      |\n      |\n  ____|____\n");
				break;
			case(3) :
				printf("   ___\n  |   |\n \\O/  |\n      |\n      |\n  ____|____\n");
				break;
			case(4) :
				printf("   ___\n  |   |\n \\O/  |\n  |   |\n      |\n  ____|____\n");
				break;
			case(5) :
				printf("   ___\n  |   |\n \\O/  |\n  |   |\n /    |\n  ____|____\n");
				break;
			case(6) :
				printf("\n\nYOU LOSE!\n\n");
				printf("   ___\n  |   |\n \\O/  |\n  |   |\n / \\  |\n  ____|____\n");
				break;
		}
	}
}
