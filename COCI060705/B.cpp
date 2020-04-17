#include <stdio.h>

int main(void) {
	int h1, m1, s1, h2, m2, s2;
	scanf("%2d:%2d:%2d", &h1, &m1, &s1);
	scanf("%2d:%2d:%2d", &h2, &m2, &s2);
	if (s1 > s2) s2 += 60, m2--;
	s2 -= s1;
	if (m1 > m2) m2 += 60, h2--;
	m2 -= m1;
	if (h1 > h2) h2 += 24;
	h2 -= h1;
	if (h2 == 0 && m2 == 0 && s2 == 0) h2 = 24;
	printf("%02d:%02d:%02d\n", h2, m2, s2);
	return false;
}