#include <iostream>
using namespace std;

struct info {
	int r;
	int g;
	int b;
} *ac;

char intencity(info* color);

int main() {
	int n, m;
	int r, g, b;
	cin >> n >> m;
	ac = new info[n * m + 1];
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> r >> g >> b;
			ac[i * m + j].r = r;
			ac[i * m + j].g = g;
			ac[i * m + j].b = b;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << intencity(&ac[i * m + j]);
		}
		cout << '\n';
	}

	return 0;
}

char intencity(info* color) {
	int result;
	result = 2126 * color->r + 7152 * color->g + 722 * color->b;
	if (result >= 0 && result < 510000) {
		return 35;
	}
	else if (result >= 510000 && result < 1020000) {
		return 111;
	}
	else if (result >= 1020000 && result < 1530000) {
		return 43;
	}
	else if (result >= 1530000 && result < 2040000) {
		return 45;
	}
	else if (result >= 2040000) {
		return 46;
	}
	else {
		return 0;
	}
}