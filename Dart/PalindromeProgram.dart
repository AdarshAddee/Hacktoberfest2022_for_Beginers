//UserName: ArpitSahu01

//Plaindrome means when a Number or a string when reversed
//looks same and pronounced same as it was before reversing
// Examaple:
//35653 when reversed gives same
//MADAM when reversed gives same
//Ana when reversed gives same(ignoring Lower and UPPER case)

import 'dart:io';

void main() {
  print('Enter the word or number you want to check');

  String? original = stdin.readLineSync();
  String lowerOriginal = original!.toLowerCase();
  String reverse = lowerOriginal.split('').reversed.join();

  if (lowerOriginal == reverse) {
    print('Its a Palindrome');
  } else {
    print('It is not a Palindrome');
  }
}
