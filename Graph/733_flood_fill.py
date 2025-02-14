class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image

        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        m, n = len(image), len(image[0])

        def dfs(i, j, c):
            image[i][j] = color

            for ni, nj in directions:
                I, J = i + ni, j + nj
                if 0 <= I < m and 0 <= J < n and image[I][J] == c:
                    dfs(I, J, c)

        dfs(sr, sc, image[sr][sc])

        return image