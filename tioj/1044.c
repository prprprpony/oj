#include "lib1044.h"
int main()
{
	int low = 1, high = Initialize(), mid;
	while (low <= high) {
		mid = low + ((high - low) >> 1);
		if (Guess(mid))
			high = mid - 1;
		else
			low = mid + 1;
	}
	Report(low);
}
