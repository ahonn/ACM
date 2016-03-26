// CodeForces 581B

// Description
// The capital of Berland has n multifloor buildings. The architect who built up the capital was very creative, so all the houses were built in one row.

// Let's enumerate all the houses from left to right, starting with one. A house is considered to be luxurious if the number of floors in it is strictly greater than in all the houses with larger numbers. In other words, a house is luxurious if the number of floors in it is strictly greater than in all the houses, which are located to the right from it. In this task it is assumed that the heights of floors in the houses are the same.

// The new architect is interested in n questions, i-th of them is about the following: "how many floors should be added to the i-th house to make it luxurious?" (for all i from 1 to n, inclusive). You need to help him cope with this task.

// Note that all these questions are independent from each other — the answer to the question for house i does not affect other answers (i.e., the floors to the houses are not actually added).

// Input
// The first line of the input contains a single number n (1 ≤ n ≤ 105) — the number of houses in the capital of Berland.
// The second line contains n space-separated positive integers hi (1 ≤ hi ≤ 109), where hi equals the number of floors in the i-th house.

// Output
// Print n integers a1, a2, ..., an, where number ai is the number of floors that need to be added to the house number i to make it luxurious. If the house is already luxurious and nothing needs to be added to it, then ai should be equal to zero.
// All houses are numbered from left to right, starting from one.

// Sample Input
// Input
// 5
// 1 2 3 1 2
// Output
// 3 2 0 2 0

// Input
// 4
// 3 2 1 4
// Output
// 2 3 4 0

#include <cstdio>
#include <cstring>
using namespace std;

long long h[100005];

int main() {
  // freopen("../input.txt", "rt", stdin);
  int n, i;
  long long maxn, ans;
  while(scanf("%d", &n) != EOF) {
    memset(h, 0, sizeof(h));
    for(i = 1; i <= n; i++) {
      scanf("%lld", &h[i]);
    }
    maxn = h[n];
    h[n] = 0;
    for(i = n-1; i > 0; i--) {
      ans = maxn + 1 - h[i];
      maxn = (maxn < h[i]) ? h[i] : maxn;
      h[i] = (ans < 0) ? 0 : ans;
    }
    for(i = 1; i <= n; i++) {
      printf("%lld ", h[i]);
    }
    printf("\n");
  }
  return 0;
}
