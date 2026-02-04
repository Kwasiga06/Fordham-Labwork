
###############################
# MY FUNCTIONS
###############################

def IsSubsequence(str1, str2):
    # Check if str1 is a subsequence of str2
    i, j = 0, 0
    while i < len(str1) and j < len(str2):
        if str1[i] == str2[j]:
            i += 1
        j += 1
    return i == len(str1)

def isSubtring(str1, str2):
    # Check if str1 is a substring of str2
    n, m = len(str2), len(str1)
    if m == 0:
        return True
    if m > n:
        return False
    for i in range(n - m + 1):
        match = True
        for j in range(m):
            if str2[i + j] != str1[j]:
                match = False
                break
        if match:
            return True
    return False


###############################
# TESTS FOR EACH FUNCTION
###############################

def main():
    print("-------------- TEST 1 -------------------")
    print("Words:")
    ts1_1 = "low"
    ts1_2 = "helloworld"

    print(ts1)
    print(ts1_2)
    test1 = IsSubsequence(ts1_1, ts1_2)
    test2 = isSubtring(ts1_1, ts1_2)

    print("Is it subsequent: " + str(test1))
    print("Is it a substring: " + str(test2))

    print("-------------- TEST 2 -------------------")

    print("-------------- TEST 3 -------------------")

    print("-------------- TEST 4 -------------------")

if __name__ == "__main__":
    main()
