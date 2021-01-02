#pragma once

template <typename T> unsigned tribonacci(T n) {
  return n == 0 ? 0 : n == 1 ? 1 : n == 2 ? tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

template <typename T> T tribonacci_iter(T i) {
  if (i == 0) return 0;
  if (i == 1) return 1;
  T triad[3] = {1, 1, 2};
  while (i-- > 2)
    triad[i & 1] = triad[0] + triad[1] + triad[2];
  return triad[0];
}
