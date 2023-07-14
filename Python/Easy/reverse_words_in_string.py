# Reverse words in a string 
# For one liner use:
# return ' '.join(reversed(s.split()))
s = "the sky is blue"

def reverseWords(s):
    ans = s.split()
    return " ".join(ans[::-1])

print(reverseWords(s))