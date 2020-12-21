#include <stdio.h> 

int main() {
	unsigned long long t = 40755, p = 40755, h = 40755;
	unsigned long long dt = 286, dp = 496, dh = 573;
	t += dt; dt++;
	while (1) {
		if (t < p)
		{
			t += dt; dt++;
		}
		else if (p < t)
		{
			p += dp; dp += 3;
		}
		else if (h < p)
		{
			h += dh; dh += 4;
		}
		else if (t < h)
		{
			t += dt; dt++;
		}
		else break;
	}
	printf("ans = %lld\n", t);
}