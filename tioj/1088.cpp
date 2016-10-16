#include "lib1088.h"
int main()
{
	int S[4];
	Initialize(S + 1, S + 2, S + 3);
	while (1) {
		int x = 0;
		for (int i = 1; i <= 3; ++i)
			x ^= S[i];
		for (int i = 1; i <= 3; ++i) {
			int j = x ^ S[i];
			if (S[i] > j) {
				int k, n;
				Take_Stone(i, S[i] - j, &k, &n);
				S[i] = j;
				S[k] -= n;
				break;
			}
		}
	}
}
