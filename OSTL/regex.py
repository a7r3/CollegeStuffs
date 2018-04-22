import re

# Ask for a word from the User
word = input("Enter a word > ")
# The Regex pattern which has to be matched with the word
pattern = '[aeiou]'

# If a match of pattern takes place (Vowel at Start)
if re.match(pattern, word):
	# Print the word + 'zay'
	print(word+'zay')
else:
	# Search for the occurence of pattern in word
	# And get the index of first occurence of it
	start = re.search(pattern, word).start()
	# Print the sequence
	# word (from 'start' to end)
	# word (word from '0' to 'start')
	# the word 'ay'
	print(word[start:]+word[0:start]+'ay')
