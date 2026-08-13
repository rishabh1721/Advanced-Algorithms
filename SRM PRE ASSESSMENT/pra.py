
# class Solution:
#     def solve(self, s):
#         freq = {}
        
#         for ch in s:
#             freq[ch] = freq.get(ch,0)+1
#         length = 0
#         odd = False
#         for cnt in freq.values():
#             length += (cnt//2)*2
#             if cnt%2 == 0:
#                 odd = True
#         if odd:
#             length+=1
#         return length
    

# def main():
#     s = input("Enter string: ")

#     obj = Solution()
#     result = obj.solve(s)

#     print("Longest palindrome length:", result)


# if __name__ == "__main__":
#     main()
            
            
# from collections import Counter
# class Solution:
#      def compress(self, s: str) -> str:
#           freq = Counter(s)
#           def priority(ch):
#                if ch.isdigit():
#                     return 1
#                elif ch.isupper():
#                     return 2
#                elif ch.islower():
#                     return 3
#                return 4
#           chars = sorted(
#                freq.keys(), key = lambda ch:(-freq[ch],priority(ch),ord(ch))
#           )
#           ans = []
#           for ch in chars:
#                ans.append(ch *freq[ch])
#           return "".join(ans)
# def main():
#     s = input("Enter string: ")

#     obj = Solution()
#     result = obj.compress(s)

#     print("Compressed string:", result)


# if __name__ == "__main__":
#     main()
# from collections import defaultdict
# class Solution:
#     def longestValidSubstring(self, s: str) -> int:
#         freq = defaultdict(int)
#         balance = 0
#         left = 0
#         ans = 0
        
#         for right in range(len(s)):
#             ch = s[right]
#             if ch =='(':
#                 balance +=1
#             elif ch==')':
#                 if balance == 0:
#                     freq.clear()
#                     left = right + 1
#                     continue
#                 balance -= 1
#             else:
#                 freq[ch] += 1
#                 while freq[ch] > 2:
#                     lc = s[left]
#                     if lc=='(':
#                         balance +=1
#                     elif lc == ')':
#                         balance -=1
#                     else:
#                         freq[lc] -= 1
#                     left +=1

#             if balance == 0:
#                 ans = max(ans,right-left+1)
#         return ans
    
# def main():
#     s = input("Enter string: ")

#     obj = Solution()
#     result = obj.longestValidSubstring(s)

#     print("Longest valid substring length:", result)


# if __name__ == "__main__":
#     main()




# class Solution:
#     def solve(self, s):
#         freq = {}
#         for ch in s:
#             freq[ch] = freq.get(ch,0)+1
#         odd = False
#         length = 0
#         for counter in freq.values():
#             length += (counter//2)*2
#             if counter%2==0:
#                 odd = True
#         if odd:
#             length +=1
#         return length

# from collections import Counter
# class Solution:
#     def compress(self, s: str) -> str:
#         freq = Counter(s)

#         def priority(ch):
#             if ch.isdigit():
#                 return 1
#             elif ch.isupper():
#                 return 2
#             elif ch.islower():
#                 return 3
#             return 4
        
#         chars = sorted(
#             freq.keys(), key=lambda ch:(-freq[ch],priority(ch),ord(ch))
#         )

#         ans = []
#         for ch in chars:
#             ans.append(ch * freq[ch])
#         return "".join(ans)


# from collections import defaultdict

#     def longestValidSubstring(self, s: str) -> int:
#         freq = defaultdict(int)
#         balance = 0
#         left = 0
#         ans = 0

#         for right in range(len(s)):
#             ch = s[right]
#             if ch == '(':
#                 balance -=1
#             elif ch==')':
#                 if balance == 0:
#                     freq.clear()
#                     left = right +1
#                     continue
#                 balance +=1
#             else:
#                 freq[ch] +=1
#                 while freq[ch] >2:
#                     lc = s[left]
#                     if lc == '(':
#                         balance -= 1
#                     elif lc == ')':
#                         balance += 1
#                     else:
#                         freq[lc] -= 1
#                     left +=1
#             if balance == 0:
#                 ans = max(ans,right-left+1)
#         return ans
    
from collections import defaultdict

class Solution:
    def longsubstr(self, s: str) -> int:
        freq = defaultdict(int)
        left = 0
        ans = 0
        balance = 0

        for right in range(len(s)):
            ch = s[right]

            if ch == '(':
                balance += 1

            elif ch == ')':
                if balance == 0:
                    freq.clear()
                    left = right + 1
                    continue
                balance -= 1

            else:
                freq[ch] += 1

                while freq[ch] > 2:
                    lc = s[left]

                    if lc == '(':
                        balance -= 1
                        if balance < 0:
                            balance = 0
                    elif lc == ')':
                        balance += 1
                    else:
                        freq[lc] -= 1

                    left += 1

            if balance == 0:
                ans = max(ans, right - left + 1)

        return ans



def main():
    s = input("Enter string: ")

    obj = Solution()
    result = obj.longsubstr(s)

    print("Longest valid substring length:", result)


if __name__ == "__main__":
    main()