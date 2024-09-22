class SnakeGame:

    def __init__(self, width: int, height: int, food: List[List[int]]):
        self.width = width
        self.height = height
        self.food = food
        self.snake_coords = [(0, 0)]
        self.length = 0
        self.directions = {
            "R": (0, 1),
            "L": (0, -1),
            "U": (-1, 0),
            "D": (1, 0)
        }

    def validPosition(self, position):
        x, y = position
        return x >= 0 and x < self.height and y >= 0 and y < self.width

    def move(self, direction: str) -> int:        
        dx, dy = self.directions[direction]
        head_position = self.snake_coords[0]
        hx, hy = head_position[0] + dx, head_position[1] + dy

        if not self.validPosition((hx, hy)):
            return -1
        
        if len(self.food) > 0 and hx == self.food[0][0] and hy == self.food[0][1]:
            self.length += 1
            self.food.pop(0)
        else:
            if (hx, hy) in self.snake_coords[:-1]:
                return -1
            else:
                self.snake_coords.pop()

        self.snake_coords.insert(0, (hx, hy))
        print(self.snake_coords)
        return self.length


# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)s