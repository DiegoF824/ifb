#include <math.h>
#include <stdio.h>

double m(double a, double b) { return ((a + b) / 2); }

double f1(double x) {
  return (pow(x, 3) - x - 2);
}

double f2(double x) {
  return (cos(x) - x);
}

double f3(double x) {
  return (exp((x * -1)) - x);
}

double f4(double x) {
  return (pow(x, 2) - 4);
}

double f5(double x) {
  return (log(x) + x - 2);
}

int main() {
  double a;
  double b;
  double M;
  int rep = 1;
  /* f1 */;
  a = 1;
  b = 2;
  while (rep) {
    M = m(a, b);
    double fa = f1(a);
    double fm = f1(M);
    if (fm == 0) {
      printf("%lf\n", M);
      rep = 0;
    } else if ((fa > 0 && fm < 0) || (fa < 0 && fm > 0)) {
      b = M;
    } else {
      a = M;
    }
  }
  /* f2 */
  a = 0;
  b = 1;
  rep = 1;
  while (rep) {
    M = m(a, b);
    double fa = f2(a);
    double fm = f2(M);
    if (fm == 0) {
      printf("%lf\n", M);
      rep = 0;
    } else if ((fa > 0 && fm < 0) || (fa < 0 && fm > 0)) {
      b = M;
    } else {
      a = M;
    }
  }
  /* f3 */
  a = 0;
  b = 1;
  rep = 1;
  while (rep) {
    M = m(a, b);
    double fa = f3(a);
    double fm = f3(M);
    if (fm == 0) {
      printf("%lf\n", M);
      rep = 0;
    } else if ((fa > 0 && fm < 0) || (fa < 0 && fm > 0)) {
      b = M;
    } else {
      a = M;
    }
  }
  /* f4 */
  a = 0;
  b = 3;
  rep = 1;
  while (rep) {
    M = m(a, b);
    double fa = f4(a);
    double fm = f4(M);
    if (fm == 0) {
      printf("%lf\n", M);
      rep = 0;
    } else if ((fa > 0 && fm < 0) || (fa < 0 && fm > 0)) {
      b = M;
    } else {
      a = M;
    }
  }
  /* f5 */
  a = 1;
  b = 2;
  rep = 1;
  while (rep) {
    M = m(a, b);
    double fa = f5(a);
    double fm = f5(M);
    if (fm == 0) {
      printf("%lf\n", M);
      rep = 0;
    } else if ((fa > 0 && fm < 0) || (fa < 0 && fm > 0)) {
      b = M;
    } else {
      a = M;
    }
  }
  return 0;
}
