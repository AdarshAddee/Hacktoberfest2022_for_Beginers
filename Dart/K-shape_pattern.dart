// Github username: Night-101
// Aim: K-shape Alphabet Pattern

import 'dart:io';
void main() {
  
  for (int i = 8; i >= 0; i--) {
    int alphabet = 65;
    for(int j = 0;j<=i;j++)
    {
       stdout.write('${String.fromCharCode(alphabet+j)} ');
    }
    stdout.writeln();
  }
  for (int i = 0; i <= 8; i++) {
    int alphabet = 65;
    for(int j = 0;j<=i;j++)
    {
       stdout.write('${String.fromCharCode(alphabet+j)} ');
    }
    stdout.writeln();
  }
}
