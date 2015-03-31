/*
ID: juanj032
PROG: friday
LANG: C
*/

#define MAX_YEAR 400

#include <stdio.h>
#include <stdlib.h>

char *Months[] ={ "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DIC"};

char *Days [] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int months_days [] = {
				31, // JAN 
				28, // FEB
				31, // MAR
				30, // APR
				31, // MAY
				30, // JUN
				31, // JUL
				31, // AUG
				30, // SEP
				31, // OCT
				30, // NOV
				31 // DEC 
			};

int isleap(int y){
	return (y%4 == 0 && (y%100 != 0 || y%400 == 0));
}

int month_length(int y, int m){

	if( m == 1 ){ /* Febrary */
		return months_days[m]+isleap(y);
	}else
		return months_days[m];
}

int main(int argc, char const *argv[])
{
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	// FILE *fout = stdout;
	int i, year, month, dayOfWeak, N;
	int days[7] = {0, 0, 0, 0, 0, 0, 0};

	fscanf(fin, "%d", &N);
	dayOfWeak = 0; /* January 13h 1900 is Saturday = 0*/
	
	for (year = 1900; year < 1900+N; ++year){
	
		for (month = 0; month < 12; ++month){
			days[dayOfWeak]++;
			dayOfWeak = (dayOfWeak+ month_length(year, month)) % 7;
		}		
	}

	for (i = 0; i < 7; ++i){
		if(i)
			fprintf(fout, " ");
		fprintf(fout, "%d", days[i]);		
	}
	fprintf(fout, "\n");
	return 0;
}