# 489 Robot Room Cleaner.py
class Solution(object):
    def cleanRoom(self, robot):
        """
        :type robot: Robot
        :rtype: None
        """
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
 
        def goBack(robot):
            robot.turnLeft()
            robot.turnLeft()
            robot.move()
            robot.turnRight()
            robot.turnRight()
 
        def dfs(pos, robot, d, lookup):
            if pos in lookup:
                return
            lookup.add(pos)
 
            robot.clean()
            for _ in directions:
                if robot.move():
                    dfs((pos[0]+directions[d][0],
                         pos[1]+directions[d][1]),
                        robot, d, lookup)
                    goBack(robot)
                robot.turnRight()
                d = (d+1) % len(directions)
         
        dfs((0, 0), robot, 0, set())　


# 489 Robot Room Cleaner.py
# https://github.com/awangdev/LintCode/blob/master/Java/Robot%20Room%20Cleaner.java
class robot():
  def __init__(self, i, j, m):
    self.m = m
    self.i = i
    self.j = j
    self.d = 0
    self.di = [0,1,0,-1]
    self.dj = [1,0,-1,0]
  def turnL(self):
    self.d -=1
    if self.d < 0:
      self.d = 3
  def turnR(self):
    self.d +=1
    if self.d > 3:
      self.d = 0
  def move(self):
    self.i += self.di[self.d]
    self.j += self.dj[self.d]
    if self.i < 0 or self.i >= len(self.m) or self.j < 0 or self.j >= len(self.m[0]) or self.m[self.i][self.j] == 0:
        self.i -= self.di[self.d]
        self.j -= self.dj[self.d]
        return False
    else:
        return True
  def visited(self):
    return self.m[self.i][self.j] == 2
  def clean(self):
    self.m[self.i][self.j] = 2
  def reLoc(self):
    self.turnL()
    self.turnL()
    self.move()
    self.turnR()
    self.turnR()

class solution():
  def dfs(self):
    if self.robot.visited():
      return
    self.robot.clean()
    for _ in range(4):
      if self.robot.move():
        self.dfs()
        self.robot.reLoc()
      self.robot.turnL()
  def cleanRoom(self, room, row, col):
    self.robot = robot(row,col,room)
    self.dfs()
    
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
]
row = 1
col = 3
solution = solution()
solution.cleanRoom(room, row, col)
for i in range(len(room)):
    print(room[i])

class solution():
  def turnL(self):
    self.d -=1
    if self.d < 0:
      self.d = 3
  def turnR(self):
    self.d +=1
    if self.d > 3:
      self.d = 0
  def move(self):
    self.i += self.di[self.d]
    self.j += self.dj[self.d]
    if self.i < 0 or self.i >= len(self.m) or self.j < 0 or self.j >= len(self.m[0]) or self.m[self.i][self.j] == 0:
        self.i -= self.di[self.d]
        self.j -= self.dj[self.d]
        return False
    else:
        return True
  def visited(self):
    return self.m[self.i][self.j] == 2
  def clean(self):
    self.m[self.i][self.j] = 2
  def reLoc(self):
    self.turnL()
    self.turnL()
    self.move()
    self.turnR()
    self.turnR()
  def dfs(self):
    if self.visited():
      return
    self.clean()
    for _ in range(4):
      if self.move():
        self.dfs()
        self.reLoc()
      self.turnL()
  def cleanRoom(self, room, row, col):
    self.m = room
    self.i = row
    self.j = col
    self.d = 0
    self.di = [0,1,0,-1]
    self.dj = [1,0,-1,0]
    self.dfs()
    
room = [
  [1,1,1,1,1,0,1,1],
  [1,1,1,1,1,0,1,1],
  [1,0,1,1,1,1,1,1],
  [0,0,0,1,0,0,0,0],
  [1,1,1,1,1,1,1,1]
]
row = 1
col = 3
solution = solution()
solution.cleanRoom(room, row, col)
for i in range(len(room)):
    print(room[i])