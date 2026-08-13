from collections import defaultdict

class Solution:
    def longestValidSubstring(self, s: str) -> int:
        freq = defaultdict(int)
        ans = 0
        balance = 0
        left = 0

        for right in range(len(s)):
            ch = s[right]

            if ch == '(':
                balance += 1

            elif ch == ')':
                if balance == 0:
                    # Unmatched ')' -> reset window
                    freq.clear()
                    left = right + 1
                    continue
                balance -= 1

            else:
                freq[ch] += 1

                # Ensure each character appears at most twice
                while freq[ch] > 2:
                    lc = s[left]

                    if lc == '(':
                        balance -= 1
                    elif lc == ')':
                        balance += 1
                    else:
                        freq[lc] -= 1

                    left += 1

            if balance == 0:
                ans = max(ans, right - left + 1)

        return ans# longest valid bracket substring with limited repeats

# from collections import defaultdict

# class Solution:
#     def longestValidSubstring(self, s: str) -> int:
#         freq = defaultdict(int)
#         ans = 0
#         balance = 0
#         left = 0

#         for right in range(len(s)):
#             ch = s[right]

#             if ch == '(':
#                 balance += 1
#             elif ch == ')':
#                 if balance == 0:
#                     # Unmatched ')' — hard reset entire window
#                     freq.clear()
#                     left = right + 1
#                     continue
#                 balance -= 1
#             else:
#                 freq[ch] += 1
#                 # Shrink left until this letter is <= 2
#                 while freq[ch] > 2:
#                     lc = s[left]
#                     if lc == '(':
#                         balance -= 1
#                     elif lc == ')':
#                         balance += 1
#                     else:
#                         freq[lc] -= 1
#                     left += 1

#             if balance == 0:
#                 ans = max(ans, right - left + 1)

#         return ans


f


def main():
    s = input("Enter string: ")

    obj = Solution()
    result = obj.longestValidSubstring(s)

    print("Longest valid substring length:", result)


if __name__ == "__main__":
    main()   