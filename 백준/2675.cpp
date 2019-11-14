#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int count, repeat;
	char input[21], output[168];

	cin >> count;
	for (int i = 0; i < count; i++) {
		memset(output, '\0', sizeof(output));
		cin >> repeat >> input;
		for (int j = 0; j < 20; j++) {
			if (input[j] == '\0') {
				output[j*repeat] = '\0';
				break;
			}
			for (int re = 0; re < repeat; re++) {
				output[j*repeat + re] = input[j];
			}
		}
		cout << output << "\n";
	}

	return 0;
}