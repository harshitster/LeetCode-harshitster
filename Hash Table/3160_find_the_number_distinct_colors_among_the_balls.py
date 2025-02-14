class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        out = []
        balls, colors = {}, {}

        for ball, color in queries:
            if ball in balls:
                prev_color = balls[ball]
                colors[prev_color] -= 1 
                if colors[prev_color] == 0:
                    del colors[prev_color]

            balls[ball] = color
            colors[color] = colors.get(color, 0) + 1
            out.append(len(colors))

        return out