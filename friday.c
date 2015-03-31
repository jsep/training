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

int main(int argc, char const *argv[])
{
	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");
	// FILE *fout = stdout;
	int i, j, N;
	char n[6];
	int year = 0;
	int day = 0;
	int weekDay = 0;
	int month = 0;
	int days[7] = {0, 0, 0, 0, 0, 0, 0};
	int leap_day = 0;
	fscanf(fin, "%d", &N);
	// printf("yeah!\n");

	for (year = 1900; year < 1900+N; ++year){


		
		
		for (month = 0; month < 12; ++month)
		{
			if(month == 1)
				leap_day = (year%100 == 0 )? year%400 == 0: year%4 == 0;
			else 
				leap_day = 0;
			// printf("year:%d %d\n", year, leap_day);		
			
			for (day = 0; day < months_days[month] + leap_day; ++day){
		

				// printf("day: %d weekDay: %d %s, month: %d %s \n", day, weekDay, Days[weekDay], month, Months[month]);
				if(day == 12){
					// printf("13 day %s %s\n ", Days[weekDay], Months[month]);
					days[weekDay]++;
				}
				weekDay++;
				if( weekDay == 7)
					weekDay = 0;
			
			}
		}
	// printf("--------------------------\n");

		
	}

	fprintf(fout, "%d %d ", days[5], days[6]);
	for (i = 0; i < 5; ++i)
	{
		fprintf(fout, "%d", days[i]);
		if(i!=4)
			fprintf(fout, " ");
	}
	fprintf(fout, "\n");
	return 0;
}