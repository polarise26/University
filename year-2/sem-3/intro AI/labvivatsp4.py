from itertools import permutations


def dist(p1, p2):
    return (abs(((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)**0.5))


def alldist(points):
    return sum([dist(point, points[index+1]) for index, point in enumerate(points[:-1])])


def tsp(points, start=None):
    if start is None:
        start = points[0]
    return min([perm for perm in permutations(points) if perm[0] == start], key=alldist)


points = [[12, 12], [20, 16], [21, 19], [24, 6]]
print(alldist(points))
result = tsp(points)
print(result)
