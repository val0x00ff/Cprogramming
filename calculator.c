// A simple calculator using giving the result as float

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char letter;
  float num1,num2;
    printf("What operation would you like to perform?\n\tA) Addition\n\tB) Subtraction\n\tC) Multiplication\n\tD) Division\n\n");
    scanf("%c", &letter);

 if ((toupper(letter) != 'A') && (toupper(letter) != 'B') && (toupper(letter) != 'C') && (toupper(letter) != 'D'))
   {
      printf("Not a valid operation\n");
      return 1;
   }
    printf("Please enter first number: ");
     scanf("%f", &num1);
     printf("Please enter second number: ");
     scanf("%f", &num2);

 if (toupper(letter) == 'A')
    printf("The sum of %.2f and %.2f, is %.2f\n", num1, num2, num1 + num2);

  else if (toupper(letter) == 'B')
     printf("The difference of %.2f and %.2f, is %.2f\n", num1, num2, num1 - num2);

  else if (toupper(letter) == 'C')
     printf("The product of %.2f and %.2f, is %.2f\n", num1, num2, num1 * num2);

  else if (toupper(letter) == 'D')
     printf("The quoation of %.2f and %.2f, is %.2f\n", num1, num2, num1 / num2);
 else
     printf("The operation was not valid");
 return 0;
}
