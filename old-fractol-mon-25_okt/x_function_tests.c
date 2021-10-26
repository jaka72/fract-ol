#include <stdio.h>

/*

f(x) = x*x + C
  Starting point of x is always zero (the seed)
  C = Constant

  (Constant is a Real number, but to draw a fractal we need to use
     an Imaginary number as the Constant)
  

  For each Constant, iteration gives different behaviour:
     - goes to infinity
	 - doesn't go to infinity (tends to a fixed point, grows, cycles, chaotic behaviour...)

  For iterating real    numbers you can draw a single line in a grid (cycles, curved ...)
  For iterating Complex numbers you can draw a plane, surfaces in a grid
		(each point in a grid consists of 2 parts, real and imgn.  ie: x + 2i )


  To draw a color 2D image of the plane, you need to use a Complex number,
  	which consists of 2 points: 1 real and 1 imaginary  ( x,  i )
	  													( x + i  ) => Complex nr
														( x + 1i ) => Complex nr
														( x + 2i ) => Complex nr

   Iterating Real numbers outside radius -2 and 1: grows expon. to infinity
   Iterating Real numbers between radius -2 and 1: behave differently

   Iterating Complex numbers outside radius -2 and 2: grows expon. to infinity
   Iterating Complex numbers between radius -2 and 2: behave differently

		Mandelbrot set includes all the Complex C values, that don't escape to infinity
		  when C is iterated. These are colored black.

		We look at each point in the grid, ie: 1+1i, 1+2i,  3+5i,  -3+2i,  -2-3i,   3-2i ....   
		If the result of the function (using this point) is outside of Radius -2 and 2, 
		  then this point (1 + 1i)
		  is in the Mandebrot Set, and should be black.
									   r 	i
		For example:  input point is Complex 1 + 1i
					  f(1+1i) = (   1+1i * 1+1i + 1+1i    )
							  = 1 + 3i  ==>  this it is outside of radius -2, 2
					  The result of this point, when put into functiton,
					  escaped to infinity, so the starting input point (1+1i) is NOT black.

				We do a FIRST iteration for EACH Complex number within the radius.
				All Complex numbers whithin the radius, that their FIRST output escapes the radius,
				 have the same color.
				The same for the SECOND iteration, THIRD iteration ....

*/

float	mandl(float *x, float c)
{
	*x = *x * *x + c;
	return (*x);
}

int	main(void)
{
	float	constant;
	float	i, x, d;

	constant = -1.1;
	x = 0;
	i = 0;
	while (i++ < 35)
		printf("%.27f\n", mandl(&x, constant));

	printf(" res: %f\n", -1.1 * -1.1 + (-1.1));
	printf(" res: %f\n", -0.11 * -0.11 + (-1.1));

	return (0);
}

/*

----------------------------
 1.0	to inf
 0.9	to inf
 0.2	to inf
 0.1	to inf
 0.0   --- always 0 ---
-0.1	inf approaches input 
-0.2	inf approaches input
-0.9	inf approaches input
-1.0   ---result alternates 0 and -1 ---
-1.1	//random, then 0 and -1
-1.3	//random, then 0 and -1
-1.61	//random, then 0 and -1
-1.63	//to inf
-1.68	//to inf
-1.69	//to inf
-2.0   --- always 2 ---
-2.1	to inf
---------------------------------

0.1		to zero
0.2		to zero
0.9		to zero

-0.1	to zero
-0.9	to zero

-1.1	random, then 0 and -1
-1.2	random, then 0 and -1
-1.3	random, then 0 and -1
-1.5	random, then 0 and -1
-1.51	random, then 0 and -1
-1.52	random, then 0 and -1
-1.57	random, then 0 and -1
-1.58	random, then 0 and -1
-1.59	random, then 0 and -1
-1.6	random, then 0 and -1
-1.61	random, then 0 and -1


-1.63	to inf
-1.68	to inf
-1.69	to inf

-1.7	to inf
-1.8	to inf
-1.9	to inf


1.1		to inf
1.2		to inf
1.5		to inf
*/