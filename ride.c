/*
ID: juanj031
PROG: ride
LANG: C
*/

#include <stdio.h>
#include <string.h>

int get_mod(char *str){
	int i = 0;
	int l = strlen(str);
	int number = 1;

	while( str[i] && isalpha(str[i]) ){
		number *= str[i] - 'A' + 1;
		i++;
	}	
	return number % 47;
}

int main(){

	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	const size_t line_size = 8;
	char comet[8];
	char group[8];

	while( fgets(comet, sizeof comet, fin) != NULL ){
		
		
		fgets(group, sizeof group, fin);
		if( get_mod(group) == get_mod(comet) ){
			fprintf(fout, "%s\n", "GO");
		}else {
			fprintf(fout, "%s\n", "STAY");
		}
	
	}	
	return 0;
}
