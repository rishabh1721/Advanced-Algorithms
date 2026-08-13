class Solution:
    def solve(self,s):
        freq={}
        for ch in s:
            freq [ch]=freq.get(ch,0)+1
        length=0
        odd=False
        for count in freq.values():
            length+=(count//2)*2
            if count%2:
             odd=True
        if odd:
            length+=1
        return length
# def main():
#     s = input("Enter string: ")

#     obj = Solution()
#     result = obj.solve(s)

#     print("Longest palindrome length:", result)


# if __name__ == "__main__":
#     main()