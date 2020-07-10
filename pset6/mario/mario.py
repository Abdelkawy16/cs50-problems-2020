from cs50 import get_int


def main():
    while 1:
        n = get_int("Height: ")
        if n >= 1 and n <= 8:
            break

    x = n - 1
    y = 1
    for i in range(n):
        for j in range(x):
            print(" ", end = "")
        for i in range(y):
            print("#", end = "")
        x -= 1
        y += 1
        print()



if __name__ == "__main__":
    main()