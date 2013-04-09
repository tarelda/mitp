#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char* text;
	
	text = (char*) malloc(sizeof(char) * 20);
	strcpy(text, "Text");
	
	if (fork() == 0) {
		puts("Im child :)");
		printf("Adres: %d \n", (int) text);
		puts("I change the text to new value.");
		printf("Wartosc textu: %s \n", text);
		strcpy(text, "Nowy tekst");
		printf("Wartosc textu: %s \n", text);
		printf("Adres: %d \n", (int) text);
		sleep(10);
	}
	else {
		sleep(5);
		puts("Jestem rodzicem :)");
		printf("Adres: %d \n", (int) text);
		printf("Wartosc textu: %s \n", text);
		strcpy(text, "Nowy tekst 2");
		printf("Wartosc textu: %s \n", text);
	}
	return 0;
}