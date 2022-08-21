class UnsealTheSafe:
    memo = [
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
        {},
    ]

    adjacents = {
        1: [2, 4],
        2: [1, 5, 3],
        3: [2, 6],
        4: [1, 5, 7],
        5: [2, 6, 4, 8],
        6: [3, 5, 9],
        7: [4, 8, 0],
        8: [5, 9, 7],
        9: [6, 8],
        0: [7],
    }

    def dp(self, start, N):
        if N == 1:
            return 1
        if N in self.memo[start]:
            return self.memo[start][N]
        cnt = sum([self.dp(s, N - 1) for s in self.adjacents[start]])
        self.memo[start][N] = cnt
        return cnt

    def countPasswords(self, N):
        return sum([self.dp(s, N) for s in range(0, 10)])


if __name__ == "__main__":
    u = UnsealTheSafe()
    print(u.countPasswords(20))
