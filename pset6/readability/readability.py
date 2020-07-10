from cs50 import get_string
import string
import math

text = get_string("Text: ")
countLetters = 0
countWords = 1
countSentences = 0

for i in text:

    if i == " ":
        countWords += 1

    elif i == "!" or i == "." or i == "?":
        countSentences += 1

    elif i.isalpha() == True:
        countLetters += 1

L = 100 * countLetters / countWords
S = 100 * countSentences / countWords
index = round(0.0588 * L - 0.296 * S - 15.8)

print(countLetters)
print(countWords)
print(countSentences)

if index > 16:
    print("Grade 16+")

elif index < 1:
    print("Before Grade 1")

else:
    print(f"Grade {index}")

