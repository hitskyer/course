dict = {}
dict["height"]="180"
dict["name"]="michael"
dict["age"]="18"
for k, v in dict.items():
    print(k," 对应的值 ",v)

from random import randint

class Game():
    def __init__(self, sides = 6):
        self.sides = sides
        self.nums = {}
        for face in range(1, self.sides+1):
            self.nums[face] = face
    def roll(self):
        print(self.nums[randint(1, self.sides+1)])


rollgame = Game(10)
i = 0
while i < 10:
    rollgame.roll()
    i = i + 1