// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  double v = value;
  if (n == 1) {
    return value;
  }
  if (n == 0) {
    return 1;
  }
  for (uint32_t i = 2;; i++) {
    value *= v;
    if (n == i) {
      return value;
    }
  }
}

uint64_t fact(uint16_t n) {
  uint64_t result = 1;
  if (n == 0) {
    return 1;
  }
  for (uint32_t i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double sum = 0;
  for (uint32_t i = 0; i <= count; i++) {
    sum += calcItem(x, i);
  }
  return sum;
}

double sinn(double x, uint16_t count) {
  double sum = 0;
  for (uint32_t i = 1; i <= count; i++) {
    double sign = 1;
    if ((i - 1) % 2 != 0) {
      sign = -1;
    }
    sum += sign * calcItem(x, 2 * i - 1);
  }
  return sum;
}

double cosn(double x, uint16_t count) {
  double sum = 0;
  for (uint32_t i = 1; i <= count; i++) {
    double sign = 1;
    if ((i - 1) % 2 != 0) {
      sign = -1;
    }
    sum += sign * calcItem(x, 2 * i - 2);
  }
  return sum;
}
