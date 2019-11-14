#include <stdio.h>

int main() {
	int x1, y1, x2, y2, r1, r2, rmax, rmin, count, T;

	scanf("%d", &T);
	count = 0;
	while (count < T) {

		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		if (r1 > r2) {
			rmax = r1;
			rmin = r2;
		}
		else {
			rmax = r2;
			rmin = r1;
		}

		if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) > rmax*rmax) {
			if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == (r1 + r2)*(r1 + r2)) {
				printf("1\n");
			}

			else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (r1 + r2)*(r1 + r2)) {
				printf("2\n");
			}

			else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) > (r1 + r2)*(r1 + r2)) {
				printf("0\n");
			}
		}

		else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < rmax*rmax) {
			if (x1 == x2 && y1 == y2 && r1 == r2) {
				printf("-1\n");
			}
			else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == (rmax - rmin)*(rmax - rmin)) {
				printf("1\n");
			}

			else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (rmax - rmin)*(rmax - rmin)) {
				printf("0\n");
			}

			else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) > (rmax - rmin)*(rmax - rmin)) {
				printf("2\n");
			}
		}

		else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == rmax * rmax) {
			if (rmax == 0) {
				printf("1\n");
			}
			else {
				printf("2\n");
			}
		}
		count += 1;
	}
}