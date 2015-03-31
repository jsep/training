/*
ID: juanj031
PROG: gift1
LANG: C
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
		if(money > 0){
			currentGiver->final_money_value += money;
			// currentGiver->final_money_value +=  money%count;
			r = money/count;
			// currentGiver->final_money_value -=  r*count;
		}else
			r = 0;

			// printf("r:%d\n",r );
			// r = 0;
		print_g(*currentGiver);
		// printf("before for\n");

		for (i = 0; i < count; ++i)
		{
			giver_name = get_line(fin);
			Giver *giver = get_giver(giver_name, givers, givers_count);
			// printf("%s\n", giver_name);
			// printf("giver:%s\n",giver->name );
			print_g(*giver);
		
			giver->final_money_value += r;
			currentGiver->final_money_value -= r;
		

			print_g(*giver);
		
		}

		// printf("before get_line\n");b
		giver_name = get_line(fin);
	}
	money = 10;
	for (i = 0; i < givers_count; ++i)
	{
		fprintf(fout, "%s %d\n", givers[i].name , givers[i].final_money_value - givers[i].initial_money_value);
	}
	fclose(fin);
	fclose(fout);
	// while( fgets(comet, sizeof comet, fin) != NULL ){
		
	exit(0);
}
