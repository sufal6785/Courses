def count_sort(l, n):
    maxi = float("-inf")

    for i in range(n):
        maxi = max(l[i], maxi)

    count = [0] * (maxi + 1)

    for i in l:
        count[i] += 1

    for i in range(1, maxi + 1):
        count[i] += count[i - 1]

    output = [0] * n
    for i in range(n - 1, -1, -1):
        count[l[i]] -= 1
        output[count[l[i]]] = l[i]

    return output


def main():
    lst = [4, 4, 1, 0, 2, 2, 8, 9, 10]

    result = count_sort(lst, len(lst))

    for i in result:
        print(i)


if __name__ == "__main__":
    main()
