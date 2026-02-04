###############################
# MY FUNCTIONS
###############################

def IsSubstring(str1, str2):
    """
    Checks if str2 is a substring of str1.
    @param str1: The main string to search within.
    @param str2: The pattern string to search for.
    """
    n, m = len(str1), len(str2)
    if m > n:
        return False

    # Iterate through str1 to check for substring match
    # Outer loop: Try every possible starting index in str1 where str2 could fit
    for i in range(n - m + 1):
        match = True
        # Inner loop: Compare each character of str2 with the corresponding character in str1
        for j in range(m):
            if str1[i + j] != str2[j]:
                match = False
                break
        if match:
            return True  # Found a matching substring
    return False  # No matching substring found

def IsSubsequence(str1, str2):
    """
    Checks if str2 is a subsequence of str1.

    @param str1: The main string to search within.
    @param str2: The pattern string to search for as a subsequence.
    """
    n, m = len(str1), len(str2)
    if m > n:
        return False
    i, j = 0, 0
    # Loop through str1, moving on when a matching character for j is found
    while i < n and j < m:
        if str1[i] == str2[j]:
            j += 1 
        i += 1 
    return j == m  # True if all characters in str2 were matched

###############################
# TESTS FOR EACH FUNCTION
###############################

def main():
    print("-------------- TEST 1 -------------------")
    print("Words:")
    ts1_main = "helloworld"
    ts1_pattern = "low"

    print(ts1_main)
    print(ts1_pattern)
    test1 = IsSubsequence(ts1_main, ts1_pattern)
    test2 = IsSubstring(ts1_main, ts1_pattern)

    print("Is it subsequent: " + str(test1))
    print("Is it a substring: " + str(test2))

    print("-------------- TEST 2 -------------------")
    print("Words:")
    ts2_main = "abracadabra"
    ts2_pattern = "abc"
    print(ts2_main)
    print(ts2_pattern)
    test1_2 = IsSubsequence(ts2_main, ts2_pattern)
    test2_2 = IsSubstring(ts2_main, ts2_pattern)
    print("Is it subsequent: " + str(test1_2))
    print("Is it a substring: " + str(test2_2))

    print("-------------- TEST 3 -------------------")
    print("Words:")
    ts3_main = "abcde"
    ts3_pattern = "ace"
    print(ts3_main)
    print(ts3_pattern)
    test1_3 = IsSubsequence(ts3_main, ts3_pattern)
    test2_3 = IsSubstring(ts3_main, ts3_pattern)
    print("Is it subsequent: " + str(test1_3))
    print("Is it a substring: " + str(test2_3))

    print("-------------- TEST 4 -------------------")
    print("Words:")
    ts4_main = "abcdefg"
    ts4_pattern = "xyz"
    print(ts4_main)
    print(ts4_pattern)
    test1_4 = IsSubsequence(ts4_main, ts4_pattern)
    test2_4 = IsSubstring(ts4_main, ts4_pattern)
    print("Is it subsequent: " + str(test1_4))
    print("Is it a substring: " + str(test2_4))

if __name__ == "__main__":
    main()
