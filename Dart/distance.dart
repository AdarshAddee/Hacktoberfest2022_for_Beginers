// Github username: agisrh
// Date: 12 Oct 2022

import 'dart:math';

void main() {
  double _distance = distnace(-6.183448, 106.828705, -6.177731, 106.842180);
  print(_distance);
}

distnace(double lat1, double lon1, double lat2, double lon2) {
  var p = 0.017453292519943295;
  var c = cos;
  var a = 0.5 -
      c((lat2 - lat1) * p) / 2 +
      c(lat1 * p) * c(lat2 * p) * (1 - c((lon2 - lon1) * p)) / 2;
  double totalDistance = 12742 * asin(sqrt(a));
  double roundDistance =
      double.parse((totalDistance * 1000).toStringAsFixed(2));

  // return in meters
  return roundDistance;
}
