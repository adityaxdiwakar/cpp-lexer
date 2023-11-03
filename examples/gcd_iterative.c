int gcd(int a, int b) {
  float x = 3.7;
  float x1 = 4.;
  while(a != b) {
    if (a > b) {
      a -= b;
    }
    else {
      b -= a;
    }
  }

  return a;
}
