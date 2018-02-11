#include <stdio.h>
#include <math.h>
#include "cs50.h"


int main(void)
{
  
  // get amount of change
  double chg_owed = get_float("Change owed: ");
  
  // subtract by floor of change owed to find coins owed
  double chg = chg_owed - floor(chg_owed);
  int coin_count = 0;  
  bool verbose = false;


  if(verbose) printf("They have %f change\n", chg);

  // while there is still some type of change to be given
  while(chg > 0)
  {
    // can we add a quarter?
    if(chg >= 0.25) {
      
      coin_count = coin_count + 1;
      chg = chg - 0.25;

      if(verbose) {
        printf("adding a quarter\n");
        printf("now we have %f change and %d coins\n", chg, coin_count);
      }
      
      continue;

    // can we add a dime?
    } else if(chg >= 0.1) {
      
      coin_count = coin_count + 1;
      chg = chg - 0.1;
 
      if(verbose) {
         printf("adding a dime\n");
         printf("now we have %f change and %d coins\n", chg, coin_count); 
      }
      
      continue;

    // can we add a nickel?
    } else if(chg >= 0.05) {
      
      coin_count = coin_count + 1;
      chg = chg - 0.05;
      
      if(verbose) { 
        printf("adding a nickel\n");
        printf("now we have %f change and %d coins\n", chg, coin_count);
      }
     
      continue;
    
    // can we add a penny? - .001 is for imprecision errors...
    } else if(chg > 0.001) {
      
      coin_count = coin_count + 1;
      chg = chg - 0.01;
      
      if(verbose) {
        printf("adding a penny\n");
        printf("now we have %f change and %d coins\n", chg, coin_count);
      }
      
      continue;
    } else {
      
      printf("there is %f change left\n", chg);
      printf("this amount is >= 0.01? %d\n", chg >= 0.01);
      
      break;
    }

  }

  printf("coins required: %d\n", coin_count);

}
