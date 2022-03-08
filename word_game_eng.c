#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#define SIZE CHAR_MAX

int lengthString(char arrx[]);

int compareString(char arrx[], char arry[]);

int main() {
	
	char words[][SIZE] = {
	"theory",
	"satisfaction",
	"inspection",
	"advertising",
	"guidance",
	"charity",
	"distribution",
	"church",
	"outcome",
	"highway",
	"membership",
	"association",
	"gate",
	"childhood",
	"orange",
	"newspaper",
	"dinner",
	"dealer",
	"resolution",
	"ambition",
	"category",
	"winner",
	"ratio",
	"hair",
	"cookie",
	"instruction",
	"moment",
	"village",
	"truth",
	"initiative",
	"phone",
	"steak",
	"profession",
	"assumption",
	"championship",
	"agency",
	"recording",
	"writing",
	"king",
	"philosophy",
	"inspector",
	"politics",
	"sector",
	"youth",
	"operation",
	"loss",
	"singer",
	"tongue",
	"conversation",
	"switch",
	"ivory",
	"desert",
	"blast",
	"motorcycle",
	"hostile",
	"fuss",
	"voice",
	"relief",
	"plastic",
	"snake",
	"rent",
	"responsible",
	"helmet",
	"theme",
	"warrant",
	"sit",
	"chimney",
	"occupation",
	"budget",
	"ready",
	"horseshoe",
	"thoughtful",
	"constellation",
	"killer",
	"divide",
	"retain",
	"coast",
	"sticky",
	"deposit",
	"discourage",
	"infection",
	"popular",
	"march",
	"tempt",
	"nature",
	"qualify",
	"twin",
	"output",
	"winter",
	"chest",
	"bible",
	"percent",
	"handicap",
	"night",
	"button",
	"defend",
	"eyebrow",
	"remain",
	"crosswalk"
	"shallow",
	"immune",
	"decisive",
	"oven",
	"business",
	"rhythm",
	"era",
	"consideration",
	"club",
	"native",
	"full",
	"haircut",
	"deserve",
	"faith",
	"lot",
	"feature",
	"excitement",
	"lighter",
	"community",
	"slime",
	"wilderness",
	"publish",
	"length",
	"award",
	"knock",
	"unrest",
	"drive",
	"path",
	"bedroom",
	"moving",
	"biology",
	"coincidence",
	"explosion",
	"detector",
	"shower",
	"service",
	"censorship",
	"provoke",
	"strange",
	"fossil",
	"morning",
	"fool",
	"ditch",
	"econobox",
	"liberal",
	"bathtub",
	"shop",
	"boom",
	"franchise",
	"important"
	};
         
    srand(time(0));
    
    int high_score = 0;
    
    printf("Type \"help\" for instructions\n\n\n");
    
    
    int limit  = sizeof(words)/sizeof(words[0]);
    
    int rand_num = rand() % limit;
    
	int word_length = lengthString(words[rand_num]);
	
	printf("word_length: %d\n", word_length);
	
	int check[word_length];
	
	int i = 0;
	int k;
	int j;
	
	for (i = 0; i < word_length; i++) {
		check[i] = 0;
	}
	
	int num_correct = 0;
	int temp = num_correct;
	
	int lives_num = word_length * 2;
	printf("Lives: %d\n", lives_num);
	
	int WIN = 0;
	
	int delete_save = 0;
	
	char guess[word_length];
	
	while ( num_correct < word_length ) {
		
		if (lives_num == 0){
			break;
		}
		
		while (i < word_length) {
			if ( check[i] == 1 ) {
				printf("%c", words[rand_num][i]);
			}
			else {
				printf("_");
			}
			i++;
		}
		
		printf("\n\n");
		printf("User input: ");
		fgets(guess,20,stdin);
	
		for ( i = 0; i<word_length; i++ ) {
			guess[i] = tolower(guess[i]);
		}
		
		high_score++;
		
		int ln = lengthString(guess);
    	guess[ln-1] = '\0';
    	
    		
		if (compareString(guess, "deletesave") == 1){
			printf("Granted");
			delete_save = 1;
			goto omega;
		}
		
		
		if (compareString(words[rand_num], guess) == 1) {
			WIN = 1;
			break;
		}
		
		temp = num_correct;
		
		if ( compareString(guess, "hint") == 1 ){
			if ( lives_num == 1) {
				printf("You can't use a hint if lives_num is equal to 1\n");
				high_score--;
				continue;
			}
			for (i=0; i<word_length; i++){
				if (check[i] != 1){
					printf("Hint used!\n");
					num_correct++;
					lives_num = lives_num/2;
					printf("Lives: %d\n", lives_num);
					check[i] = 1;
					break;
				}
			}
		}
		
		if ( compareString(guess, "help") == 1 ){
			printf("\n\n--------------------------INSTRUCTIONS--------------------------\n");
			printf("\nInput letters to try to guess the random word\n");
    		printf("You can type 'hint' for a letter\n");
    		printf("Keep in mind this will divide your current lives by 2\n");
    		printf("Your goal is to find the random word using the least attempts\n");
    		printf("If you think you know the word you can type it out immediately\n");
    		printf("Your highscore will be saved and displayed in the end of the game\n");
    		printf("You can type 'deletesave' to delete your saved highscore\n\n");
			printf("---------------------------GOOD--LUCK---------------------------\n\n\n");
			high_score--;
			continue;
		}
		
		
		k = 0;
		j = 0;
		i = 0;
		
		while ( i < word_length ) {
			k = 0;
			while ( k < word_length ) {
				
				if (guess[0]== words[rand_num][i] && compareString(guess, "hint") == 0 && compareString(guess, "help") == 0 ){
					
					if (check[i] != 1) {
						
						while ( j < 1 ){
						printf("right guess\n", guess);	
						j++;
					}
						num_correct++;
						check[i] = 1;
					}
				}
				k++;
			}
			i++;
		}
		
		if ( num_correct == temp ) {
			lives_num--;
			printf("Lives: %d\n", lives_num);
		}
		
		i = 0;
		printf("\n");
	}
	
	if (num_correct == word_length || WIN == 1) {
		printf("You win, the word is: %s\n", words[rand_num]);
	}
	else{
		printf("Sorry, you lost. The word was: %s\n", words[rand_num]);
	}
	
	// saving algorithm
		
	char highScore[SIZE];
	
	char null[0];
		
	itoa(high_score, highScore, 10);
		
	FILE *fPointer;
	FILE *wPointer;
		
	fPointer = fopen("save.txt", "r");
		
	char singleLine[150];
	
	fgets(singleLine, 150, fPointer);
		
	int num = atoi(singleLine);
		
	int num2 = high_score;
	
	omega:
	
	if (delete_save == 1){
		wPointer = fopen("save.txt", "w");
		fprintf(wPointer, "%s", null);
		goto end;
	}
		
	if (num_correct == word_length || WIN == 1){
		
		if (num2 < num) {
			printf("\nYou set a new highscore!\n");
			printf("Your score: %d\n", high_score);
			wPointer = fopen("save.txt", "w");
			fprintf(wPointer, "%s", highScore);
			printf("Highscore: ");
			puts(highScore);
			
			fclose(wPointer);
		}
			
		else if (singleLine[0] == '\0'){
			printf("\nYou set the first highscore!\n");
			printf("Your score: %d\n", high_score);
			wPointer = fopen("save.txt", "w");
			fprintf(wPointer, "%s", highScore);
			printf("Highscore: ");
			puts(highScore);
			
			fclose(wPointer);
		}
			
		else {
			printf("\nYou didn't set a highscore.\n");
			printf("Your score: %d\n", high_score);
			printf("Highscore: ");
			puts(singleLine);
		}
			
	}
		
	else if (singleLine[0] == '\0'){
		printf("\nNo current highscores recorded.");
	}
		
	else{
		printf("\nHighscore: ");
		puts(singleLine);
	}
		
	end:
	
	getch();
	return 0;
}


//made my own strcmp() and strlen() functions because why not
//also strcmp() return values are stupid


int lengthString(char arrx[]){
	
	int i = 0;
	while (arrx[i] != '\0') {
		i++;
	}
	return i;
}


int compareString(char arrx[], char arry[]){
	
	int lengthx = lengthString(arrx);
	int lengthy = lengthString(arry);
	if (lengthx != lengthy){
		return 0;
	}
	char checkArray[lengthx];
	int i;
	int counter = 0;
	
	for (i = 0; i<lengthx; i++){
		checkArray[i] = 0;
	}
	for (i = 0; i<lengthx; i++){
		if (arrx[i] == arry[i]){
			checkArray[i] = 1;
		}
	}
	for (i = 0; i<lengthx; i++){
		if ( checkArray[i] == 1 ){
			counter++;
		}
	}
	if (counter == lengthx){
		return 1;
	}
	else{
		return 0;
	}
}
