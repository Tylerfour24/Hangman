#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void setup(int index, char *answer, char *display);
void result(int correct, int wrongcount);
void statistics(int correct, int wrongcount, int wins, int losses);

int main(int argc, char *argv[]) //(int argc, char *argv[]) once this is ready to accept command line input, if ever
{
	srand(time(NULL));
	char answer[35]={'\0'};
	char pseudoanswer[35]={'\0'};
	char display[35]={'\0'};
	char checker[35]={'\0'};
	char guess[2];
	int index;
	int wrongcount;
	int compare;
	int correct;
	char *combine;
	//char *fuse;
	int die;
	int linecount = 0;
	int wordchoice = 0;

	if(argc != 2) {
		combine = strncat(getenv("HOME"), "/.words", 35);
	}
	else {
		combine = strncat(getenv("HOME"), argv[1], 35);
	}
	FILE *userfile = fopen(combine, "r");
	if(userfile == NULL) {
		printf("File missing, exiting program.\n");
		exit(0);
	}

	 
	while(fgets(pseudoanswer, 35, userfile) != NULL) { //read next line into answer
		linecount++;
	}
	fseek(userfile, 0, SEEK_SET);
	die = (rand() % linecount) ;
	while(fgets(pseudoanswer, 35, userfile) != NULL) {
		wordchoice++;
		if (wordchoice == die) {
			strncpy(answer, pseudoanswer, 35);
		}
	}


	

	for(index = 0; index < 35; index++) {
		if(answer[index] == '\n') {
			answer[index] = '\0';
			break;
		}
		else {
			display[index] = '_';
		}
	}

	setup(index, answer, display);

	wrongcount = 0;
	correct = strcmp(display, answer);
	while( (wrongcount != 6) && (correct != 0) ) {

		printf("Enter a letter: ");
		fgets(guess, sizeof(guess)+1, stdin);
		strncpy(checker, display, sizeof(display)+1);

		for(index = 0; index < 35; index++) {
			if(answer[index] == '\n') {
				answer[index] = '\0';
				break;
			}
			else {
				if(answer[index] == guess[0]) {
					display[index] = guess[0];
				}
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

		printf("\n");

		for(index = 0; index < 35; index++) {
			if(answer[index] == '\n') {
				answer[index] = '\0';
				break;
			}
			else {
				printf("%c", display[index]);
			}
		}
		printf("\n\n");
	}

	if(correct != 0) {
		printf("Correct answer: ");
		for(index = 0; index < 35; index++) {
			if(answer[index] == '\n') {
				answer[index] = '\0';
				break;
			}
			else {
				printf("%c", answer[index]);
			}
		}
		printf("\n\n");
	}





	/*fuse = strncat(getenv("HOME"), "/.gamestats", 35);

	

void statistics(int correct, int wrongcount, int wins, int losses, char fuse) {

	FILE *histfile = fopen(fuse, "w+");
	int wins;
	int losses;
	int average;

*/


	return 0;
}

void setup(int index, char *answer, char *display) { //Starts the game

	for(index = 0; index < 35; index++) {
		if(answer[index] == '\n') {
			answer[index] = '\0';
			break;
		}
		else {
			printf("%c", display[index]);
		}
	}
	printf("\n\n");
}

void result(int correct, int wrongcount) { //Handles guess and win/loss images
	if(correct == 0) {
		printf("\n\nYOU WIN!!\n\n");
		printf("   ___\n  |   |\n      |\n      |     \\0/\n      |      |   \n  ____|____ / \\ \n"); //Prints winning screen
		switch(wrongcount) {
			case(0) :
				printf("You missed no guesses!");
				break;
			case(1) :
				printf("You missed one guess!");
				break;
			case(2) :
				printf("You missed two guesses!");
				break;
			case(3) :
				printf("You missed three guesses!");
				break;
			case(4) :
				printf("You missed four guesses!");
				break;
			case(5) :
				printf("You missed five guesses!");
				break;
		}
	}
	else {
		switch(wrongcount) { //Prints necessary screen based on number of guesses remaining.
			case(0) :
				printf("   ___\n  |   |\n      |\n      |\n      |\n  ____|____\n");
				break;
			case(1) :
				printf("   ___\n  |   |\n  0   |\n      |\n      |\n  ____|____\n");
				break;
			case(2) :
				printf("   ___\n  |   |\n  0   |\n  |   |\n      |\n  ____|____\n");
				break;
			case(3) :
				printf("   ___\n  |   |\n  0   |\n /|   |\n      |\n  ____|____\n");
				break;
			case(4) :
				printf("   ___\n  |   |\n  0   |\n /|\\  |\n      |\n  ____|____\n");
				break;
			case(5) :
				printf("   ___\n  |   |\n  0   |\n /|\\  |\n /    |\n  ____|____\n");
				break;
			case(6) :
				printf("\n\nYOU LOSE!\n\n");
				printf("   ___\n  |   |\n  O   |\n /|\\  |\n / \\  |\n  ____|____\n");
				break;
		}
	}
}

/*void statistics() {
	if(correct == 0) {
		wins++;
		printf("%d\n", wins);
	}
	else if (wrongcount == 6) {
		losses++;
		printf("%d\n", losses);
	}
}*/

