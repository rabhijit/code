x = [3, 7, 1, 99, 4, 33, 32, 65, 8, 100]
def insertion_sort(lst):
    sorted = []
    while len(x) > 0:
        place = x.pop(0)
        if len(sorted) == 0:
            sorted.append(place)
        else:
            index = 0
            while index < len(sorted):
                if place < sorted[index]:
                    break
                index += 1
            sorted.insert(index, place)



    return sorted
print(insertion_sort(x))
