#include <stdio.h>

int binsearch(int key, int (*keyforindex)(int index), int left, int right)
{
	while (left < right) {
		int m = (left + right) / 2;

		if (key > keyforindex(m))
			left = m + 1;
		else
			right = m;
	}

	return (keyforindex(left) == key) ? left : -1;
}


int k4idx(int idx)
{
	return idx * 2;
}

int main(char argc, char **argv)
{
	int k, l, r;

	k = atoi(argv[1]);
	l = atoi(argv[2]);
	r = atoi(argv[3]);
	printf("%d\n", binsearch(k, k4idx, l, r));

	return 0;
}
