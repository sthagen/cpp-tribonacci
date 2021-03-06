#pragma once
/* Implementations of the tribonacci sequence:
 *   0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513, 35890, 66012, ... (sequence A000073 in the OEIS)
 */
#include <vector>

// Naive recursive implementation - slowly and happily wrapping around for larger arguments
template <typename T> unsigned tribonacci(T n) {
  return n == 0 ? 0 : n == 1 ? 0 : n == 2 ? 1 : tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
}

// Iterative implementation - faster but still happily wrapping around for larger arguments
template <typename T> T tribonacci_iter(T i) {
    T triad[3] = {0, 0, 1};
    if (i < 3) return *(triad + i);
    while (--i > 1) {
        T accumulator = *(triad) + *(triad + 1) + *(triad + 2);
        *(triad) = *(triad + 1), *(triad + 1) = *(triad + 2), *(triad + 2) = accumulator;
    }
    return *(triad + 2);
}

// Dynamic programming implementation - needs some space ...
template <typename T> T tribonacci_dynamic(T i) {
    std::vector<T> f(std::max(T{3}, i + 1));
    f[0] = 0, f[1] = 0, f[2] = 1;
    if (i < 3) return f[i];
    for (T m = 3; m <= i; ++m) f[m] = f[m - 1] + f[m - 2] + f[m - 3];
    return f[i];
}
