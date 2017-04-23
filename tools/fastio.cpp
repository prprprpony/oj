// integers only
template<typename T>
bool RD(T & a) 
{
	int c;
	while (!((c = getchar()) == '-' || isdigit(c) || c == EOF));
	if (c == EOF)
		return 0;
	a = 0;
	if (c == '-') {
		while (isdigit(c = getchar()))
			a = 10 * a - (c & 15);
	} else {
		do {
			a = 10 * a + (c & 15);
		} while (isdigit(c = getchar()));
	}
	return 1;
}

template<typename T>
void PT(const T a)
{
	static const int maxd = 25;
	static char d[maxd];
	int i = maxd - 1;
	T t = a;
	if (t < 0) {
		do {
			d[--i] = -(t % 10) | 48;
		} while (t /= 10);
		d[--i] = '-';
	} else {
		do {
			d[--i] = (t % 10) | 48;
		} while (t /= 10);
	}
	PT(d + i);
}
