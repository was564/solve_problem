#include <stdio.h>
#include <string.h>

int solve(long long* dp, int X) {
	if (X == 1) {
		return 1;
	}
	else if (X % 3 == 0) {
		if (dp[X / 3] == -1) { solve(dp, X / 3); }
		if (dp[X - 1] == -1) { solve(dp, X - 1); }
		if (dp[X / 3] < dp[X - 1]) { return dp[X] = dp[X / 3] + 1; }
		else { return dp[X] = dp[X - 1] + 1; }
	}
	else if (X % 2 == 0) {
		if (dp[X / 2] == -1) { solve(dp, X / 2); }
		if (dp[X - 1] == -1) { solve(dp, X - 1); }
		if (dp[X / 2] < dp[X - 1]) { return dp[X] = dp[X / 2] + 1; }
		else { return dp[X] = dp[X - 1] + 1; }
	}
	else {
		if (dp[X - 1] == -1) { solve(dp, X - 1); }
		return dp[X] = dp[X - 1] + 1;
	}
}

int main() {
	long long dp[1000001];
	int X;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &X);
	if (X == 1) { printf("0"); }
	else {
		printf("%d", solve(dp, X) + 1);
	}
	return 0;
}