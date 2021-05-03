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

int main() {

  srand(time(NULL));

  int trials = 100000000;
  int inCircle = 0;
  double base = 3.14159265;

  for (int i = 0; i < trials; i++) {
    double x = rand()/(double)RAND_MAX; /* Generate a random number between 0 and 1 */
    double y = rand()/(double)RAND_MAX; /* Generate a random number between 0 and 1 */
    if (x*x + y*y <= 1) inCircle++;
  }

  double difference = 4.0*((double)inCircle/trials) - base;
  if (difference < 0) difference *= -1;
  double accuracy = (1.0 - difference)*100;

  printf("\n");
  printf("Base: %lf\n",base);
  printf("Calculated: %lf\n",4*((double)inCircle/trials));
  printf("Difference: %lf\n",difference);
  printf("Accuracy: %f percent\n",accuracy);
  printf("\n");

  return 0;
}







//
