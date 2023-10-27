# Get a word from the user
word = input("Enter a word: ")

# Define the set of English vowels
vowels = set('aeiouy')

# Initialize a variable to count the vowels
vowel_count = 0

# Iterate through the characters in the word and count the vowels
for char in word:
    if char.lower() in vowels:
        vowel_count += 1

# Print the result
print(f"The number of vowels in '{word}' is: {vowel_count}")
