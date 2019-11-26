a = [4, 2, 56, 23, 12, 1, 32, 5, 7]

def quicksort(lst):
    if len(lst) == 0 or len(lst) == 1:
        return lst
    else:
        pivot = -1
        index = 0
        while index != pivot + len(lst):
            if lst[index] >= lst[pivot]:
                lst.append(lst.pop(index))
                pivot -= 1
            else:
                index += 1

        return quicksort(lst[:pivot]) + quicksort(lst[pivot:])

print(quicksort(a))
