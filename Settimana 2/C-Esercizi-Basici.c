#include <stdio.h>

int main()
{
    //First Exercise
    
    //Variables int
    int y ;
    int x;
    
    //User Input
    printf("------ Welcome ------\n");
    printf("Insert two numbers: \n");
    
    //Assign the user input to my variables using '&'' address of operator
    scanf("%d %d", &y , &x);
    
    printf("---------------------\n");
    printf("You insert this two numbers: %d and %d\n", y , x);
    printf("The multiplication of the two numbers is ");
    
    //Mathematical operation and print of the result
    printf("%d * %d = %d\n",y , x, y*x);
    
    //-----------------------------------------------
    
    //Second Exercise
    printf("Media aritmetica dei numeri inseriti sopra: %.2f", (float)(y+x)/2);
    return 0;
}
