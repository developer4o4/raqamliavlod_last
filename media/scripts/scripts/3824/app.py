def remove_tashkent_letters(word):
    toshkent_letters = ['T', 'O', 'S', 'H', 'K', 'E', 'N']
    result = ''.join(char for char in word if char.upper() not in toshkent_letters)
    return result

input_word = "MATEMATIKA"
result = remove_tashkent_letters(input_word)

print(result)
