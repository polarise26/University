def getInvCount(arr):
    inv_count = 0
    empty_value = -1
    for i in range(0, 9):
        for j in range(i + 1, 9):
            if arr[j] != empty_value and arr[i] != empty_value and arr[i] > arr[j]:
                inv_count += 1
    return inv_count

# This function returns true
# if given 8 puzzle is solvable.


def isSolvable(puzzle):
    # Count inversions in given 8 puzzle
    inv_count = getInvCount([j for sub in puzzle for j in sub])
    # return true if inversion count is even.
    return (inv_count % 2 == 0)
    # Driver code


puzzle = [[1, 4, -1], [3, 2, 6], [7, 5, 8]]
if(isSolvable(puzzle)):
    print("Solvable")
else:
    print("Not Solvable")
