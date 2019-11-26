def caesar_cipher(shift,string):
    ### FILL YOUR CODE HERE ###
    lower = ['a','b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    upper = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y','Z']
    shift %= 26
    new_string = ""
    for i in range(len(string)):
        if string[i] == ' ':
            new_string += string[i]
        elif string[i] in lower:
            for j in range(len(lower)):
                if string[i] == lower[j]:
                    if j + shift <= len(lower) - 1:
                        new_string += lower[j+shift]
                    else:
                        new_string += lower[shift - (len(lower) - j)]
        elif string[i] in upper:
            for j in range(len(upper)):
                if string[i] == upper[j]:
                    if j + shift <= len(upper) - 1:
                        new_string += upper[j+shift]
                    else:
                        new_string += upper[shift - (len(upper) - j)]

    return new_string

print(caesar_cipher(25, "made by Abhijit Ravichandran"))
