#include <stdio.h>

int main()
{
    int points = 0;
    int number;
    char exitGame = 'Y';
    char name [20];
    char play;
    
    printf("--- Welcome to the quiz game ---\nTo win this game you need to make 3 points\n");
    printf("--------------------------------------------\nSo let's begin motherflower!\n");
    printf("You need to choose 1 , 2 or 3\n");
    printf("Do you wanna play? (y / n)\n");
    scanf("%s", &play);
    
    if(play == 'y'){
    
	    printf("Insert your name\n");
	    scanf("%s", &name);
	    
	    do {
		    points = 0;
		    
		    //First question
		    printf("\nCapital of Venezuela?\n1 - Caracas\n2 - Margarita\n3 - Maturin\n\n");
		    scanf("%d", &number);
			    if (number == 1){
				points++;
			    }
		    
		    //Second question
		    printf("\nCapital of Italy?\n1 - Bari\n2 - Roma\n3 - Palermo\n\n");
		    scanf("%d", &number);
			    if (number == 2){
				points++;
			    }
		    
		    //Third question
		    printf("\nCapital of Spain?\n1 - Valencia\n2 - Cadiz\n3 - Madrid\n\n");
		    scanf("%d", &number);
			    if (number == 3){
				points++;
			    }
		    
		    //Results
		    printf("\n%s your final score is %d/3 !! ", name, points);
		    printf("Do you want to play again?\n (y / n)\n\n");
		    scanf("%s", &exitGame);
	    
	    } while(exitGame == 'y');

     } else {
      printf("Alright c ya!");
     }
    return 0;
}
