import random
import string
import os

def generate_password(length, use_numbers, use_symbols):
    characters = string.ascii_letters
    if use_numbers:
        characters += string.digits
    if use_symbols:
        characters += string.punctuation

    password = ''.join(random.choice(characters) for _ in range(length))
    return password

def save_password_to_file(password, filename='passwords.txt'):
    with open(filename, 'a') as file:
        file.write(password + '\n')

def calculate_entropy(password):
    unique_characters = len(set(password))
    entropy = len(password) * (unique_characters ** 0.5)
    return entropy

def main():
    length = int(input("Enter desired password length: "))
    use_numbers = input("Include numbers? (y/n): ").lower() == 'y'
    use_symbols = input("Include symbols? (y/n): ").lower() == 'y'

    password = generate_password(length, use_numbers, use_symbols)
    print(f"Generated Password: {password}")

    entropy = calculate_entropy(password)
    print(f"Password Entropy: {entropy:.2f}")

    save_option = input("Do you want to save this password? (y/n): ").lower()
    if save_option == 'y':
        save_password_to_file(password)
        print("Password saved to file.")

if __name__ == "__main__":
    main()
