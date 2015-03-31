/*
ID: juanj031
PROG: gift1
LANG: C 
*/

#define MAX_PEOPLE 10
#define MAX_NAME 32

#include <stdio.h>
#include <string.h>
#include <assert.h>


typedef struct Person Person;

struct Person
{
	char name[MAX_NAME];
	int total;
};

Person people[MAX_PEOPLE];
int npeople = 0;

void add_person(char *name){
	assert(npeople < MAX_PEOPLE);
	strcpy(people[npeople].name, name);
	npeople++;
}

Person *lookup(char *name){
	int i;

	for (i = 0; i < npeople; ++i)
	{
		if(strcmp(name, people[i].name) == 0){
			return &people[i];
		}
	}

	assert(0);
}


int main(){

	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	char name[MAX_NAME];
	int i, j, np, ng, amt;
	Person *giver, *receiver;

	fscanf(fin, "%d", &np);
	for (i = 0; i < np; ++i)
	{
		fscanf(fin, "%s", name);
		add_person(name);
	}

	/*process gift lines*/
	for (i = 0; i < np; ++i)
	{
		fscanf(fin, "%s %d %d", name, &amt, &ng);
		giver = lookup(name); 
		for (j = 0; j < ng; ++j)
		{
			fscanf(fin, "%s", name);
			receiver = lookup(name);
			giver->total -= amt/ng;
			receiver->total += amt/ng;
		}
	}

	/*print the format*/

	for (i = 0; i < np; ++i)
	{
		fprintf(fout, "%s %d\n", people[i].name, people[i].total );
	}

}