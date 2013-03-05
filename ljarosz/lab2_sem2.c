#include <stdio.h>
#include <stdlib.h>

struct student {
	int id;
	char *name;
	char *surname;
};

typedef struct student student;

void display(student *s){
	printf("%d %s %s \n", s->id, s->name, s->surname);
}

void init(student *s){
	memset(s, 0, sizeof(student) );
	scanf("%d", &(s->id) );
	
	scanf("%s", s->name);
	scanf("%s", s->surname);
}

int main(){
	struct student mitp1;
	student mitp2;

	mitp1.id = 258743;
	mitp1.name = "Tomasz";
	mitp1.surname = "Chyrowicz";
	
	init(&mitp2);
	
	if (memcmp(&mitp1, &mitp2, sizeof(student) )){
		puts("Peeeelno krow :D");
	}
	
	memcpy(&mitp2, &mitp1, sizeof(student) );
	
	if (memcmp(&mitp1, &mitp2, sizeof(student) )){
		puts("Peeeelno krow Tomaszow :D");
	}
	
	return 0;
}