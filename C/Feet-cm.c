#include <stdio.h>
// Github username: VertexAssassins
// Aim: Convert Feet to cm
// Date: 11/10/2022
/*
Program to Convert a length given in feet to the
equivalent
length in centimetres
Input: length_in_feet: A length measured in feet Output: length_in_cm : The length measured in cm
*/

double const CENTIMETRES_IN_INCH = 2.5;
double const INCHES_IN_FOOT = 12.0;

int main(void)
{
  double length_in_feet;
  double length_in_cm;

  printf("Enter the length in feet :");
  scanf("%ld", &length_in_feet);

  length_in_cm = length_in_feet * INCHES_IN_FOOT * CENTIMETRES_IN_INCH;

  printf("Length is %.dcm\n", length_in_cm);
  return 0;
}