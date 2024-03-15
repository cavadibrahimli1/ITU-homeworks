def solution(grid):
    def invalid_rows(x):
        return sorted(grid[x]) != list(range(1,10))
    def invalid_cols(y):
        return sorted(grid[x][y] for x in range(9)) != list(range(1,10))
    def invalid_subgr(a,b):
        return sorted(grid[x][y] for x in range(a,a+3) for y in range(b,b+3)) != list(range(1,10))
    for i in range(0,9):
        if invalid_rows(i) or invalid_cols(i):
            return False
    for i in range(0,9,3):
        for j in range(0,9,3):
            if invalid_subgr(i,j):
                return False
    return True