main() {

  var list = new List(3);
  list[0] = 'a';
  list[1] = 'b';
  list[2] = 'c';
  print(list);

  var growable = new List();
  growable.addAll(['grow', 'able']);
  print(growable);

  var list2 = ['also', 'growable'];
  list2.add(42);
  print(list2);

  var list3 = [47, 3, 25];
  try {
    for (var item in list3) {
      if (item < 10) {
        list3.remove(item);
      }
    }
  } catch(e) {
    print('error');
  }
}
