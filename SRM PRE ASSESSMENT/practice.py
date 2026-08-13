# // multi level charachter compressor engine

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
#             freq.keys(),
#             key=lambda ch: (-freq[ch], priority(ch), ord(ch))
#         )

#         ans = []

#         for ch in chars:
#             ans.append(ch * freq[ch])

#         return "".join(ans)


from collections import Counter

class Solution:
    def compress(self, s: str) -> str:

        freq = Counter(s)

        def priority(ch):
            if ch.isdigit():
                return 1
            elif ch.isupper():
                return 2
            elif ch.islower():
                return 3
            return 4

        chars = sorted(
            freq.keys(),
            key=lambda ch: (-freq[ch], priority(ch), ord(ch))
        )

        ans = []

        for ch in chars:
            ans.append(ch * freq[ch])

        return "".join(ans)


def main():
    s = input("Enter string: ")

    obj = Solution()
    result = obj.compress(s)

    print("Compressed string:", result)


if __name__ == "__main__":
    main()