def remove_tashkent_letters(word):
    # TOSHKENT so'zidagi harflarni aniqlaymiz
    tashkent_letters = set("TOSHKENT")
    # Berilgan so'zdan TOSHKENT harflarini olib tashlaymiz
    result = "".join([char for char in word if char.upper() not in tashkent_letters])
    return result

# Kirish ma'lumotlari
input_data = ["YANGITOSHKENT", "TATU"]

# Chiqish ma'lumotlari
output_data = [remove_tashkent_letters(word) for word in input_data]

# Natijani chop etamiz
for output in output_data:
    print(output)
