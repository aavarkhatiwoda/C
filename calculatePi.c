#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
Generate pi:

  * tally how many randomly generated points on an XY grid lie inside the unit
    circle of radius 1 using the distance formula with restriction
    x^2 + y^2 < r^2. Since r is simply 1, r^2 = 1, so x^2 + y^2 must < 1.

  * divide points inside the unit circle by total points, "trials" below, to get
    the fraction of the area that a circle of radius 1 will fill inside a 2x2
    square (circle fits perfectly inside square).

  * pi*r*r / 2*r*2*r = inCircle/total -> pi/4 = inCircle/total
    -> pi = 4*inCircle/total
*/

/*
The generated value becomes more accurate as the number of trials increases.
*/



double generateRand_0_1() {       /* Generate a random number between 0 and 1 */
  return rand()/(double)RAND_MAX;
}

int main() {

  srand(time(NULL));


  int trials = 1000000;
  int inCircle = 0;
  double x;
  double y;

  for (int i = 0; i < trials; i++) {
    x = generateRand_0_1();
    y = generateRand_0_1();

    if (x*x + y*y <= 1) {
      inCircle++;
    }
  }

  double difference = 4*((double)inCircle/trials) - 3.141592;
  if (difference < 0) {
    difference *= -1;
  }

  printf("%lf\n",4*((double)inCircle/trials));

  printf("Difference: %lf\n",difference);


  return 0;
}









//
