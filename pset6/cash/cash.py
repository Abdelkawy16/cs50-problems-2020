from cs50 import get_float


def main():
    while 1:
        amount = get_float("Change owed: ")
        if amount > 0:
            break
    amount = int(amount * 100)

    count = 0
    while amount != 0:
        if amount >= 25:
            amount = amount - 25
            count += 1

        elif amount >= 10:
            amount = amount - 10
            count += 1

        elif amount >= 5:
            amount = amount - 5
            count += 1

        elif amount >= 1:
            count += amount
            amount = 0


    print(count)



if __name__ == "__main__":
    main()