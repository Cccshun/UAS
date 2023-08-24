import itertools

# 棋盘的大小
board_width = 20
board_height = 9

# 圆的半径
circle_radius = 4

# 圆的个数
num_circles = 5

# 计算圆内格子的坐标
def covered_cells(x, y):
    cells = set()  
    for i in range(max(0, x - circle_radius), min(board_width, x + circle_radius + 1)):
        for j in range(max(0, y - circle_radius), min(board_height, y + circle_radius + 1)):
            if (x - i)**2 + (y - j)**2 < circle_radius**2:
                cells.add((i, j))
    return cells

# 计算总共覆盖的格子数量
def total_covered(cells):
    return len(set(itertools.chain.from_iterable(cells)))

# # 枚举所有可能的圆心位置，计算覆盖的格子数目
# max_covered = 0
# s = 0
# t = 0
# for positions in itertools.product(range(board_width), repeat=num_circles):
#     circles_cells = [covered_cells(x, y) for x, y in zip(positions, positions[1:])]
#     curr_covered = total_covered(circles_cells)
#     max_covered = max(max_covered, curr_covered)
#     s += curr_covered
#     t += 1

# print("最大覆盖格子数目:", max_covered)
# print(s)
# print(t)
# print(s/t)

tmp = [(16,2),  (2,2),  (9,3),  (4,6),  (16,7)]
c = [covered_cells(x, y) for x, y in tmp]
print(total_covered(c))
