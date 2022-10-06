// Getting started with the basics of Dart Language
import 'dart:io';

void howToPrint() {
  // _Print Something in Dart
  print("Hy, Learner !");

  // Variables in dart
  var fName = "Rohit"; // Inference type
  String lName = "Shaw\n"; // static type
  print(fName + " " + lName);
}

void userInput() {
  // Taking User-Input
  stdout.writeln("What's your name: ?"); // You can use print function too.
  String? name = stdin.readLineSync();
  print('My name is $name');
}

void variabLes() {
  var a1 = 4656; // Inference type
  int a2 = 35876; // Integer type
  print('Amount1: $a1 & Amount2: $a2');

  double tr = 99.14; // double type
  var tw = 119.05;
  print('Ro has: $tw & Yash has: $tr \n');

  String n1 = "Rohit"; // String type
  var n2 = "Crepuscular";
  print('$n1 is in-born $n2 xD!!\n');

  bool nashe = true; // Boolean type
  var cZone = false;
  print('Grind karna is: $nashe, But staying in Comfort Zone is: $cZone \n');

  dynamic pullShot = 45; // Dynamic type
  print('Hitman\'s, Jersey no. is: $pullShot \n');

  pullShot = 'We, love watching Ro\'s pullShoT !';
  print(pullShot);
}

void main() {
  // You can use the above defined functions accordingly !
  // howToPrint();
  // userInput();
  variabLes();
}
