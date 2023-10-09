import re

def create_matrix(key):
    # Create a 5x5 key table
    key_matrix = [[None] * 5 for _ in range(5)]

    if 'j' in key:
        alphabet = "ABCDEFGHKLMNOPQRSTUVWXYZ"
    else:
        alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    
    # Initialize key table with characters from the key
    used_characters = set()
    row, col = 0, 0
    
    for char in key.upper():
        if char not in used_characters:
            key_matrix[row][col] = char
            used_characters.add(char)
            col += 1
            if col == 5:
                col = 0
                row += 1

    # Fill the rest of the key table with remaining characters
    for char in alphabet:
        if char not in used_characters:
            key_matrix[row][col] = char
            col += 1
            if col == 5:
                col = 0
                row += 1

    return key_matrix

def char_pos(char, key_matrix):
    # Find the row and column of a character in the key table
    position = [(i, j) for i in range(5) for j in range(5) if key_matrix[i][j] == char]
    return position[0] if position else None


def playfair_encrypt(plaintext, key):
    plaintext = plaintext.upper().replace(" ", "")    
    # plaintext += 'X' if len(plaintext) % 2 == 1 else ''
    key_matrix = create_matrix(key)
    ciphertext = ""
    i = 0

    while i < len(plaintext):

        if i == len(plaintext) - 1:
            plaintext += 'X'

        char1, char2 = plaintext[i], plaintext[i + 1]
                
        if char1 == char2:
            char2 = 'X'
            i += 1
        else:
            i += 2

        row1, col1 = char_pos(char1, key_matrix)
        row2, col2 = char_pos(char2, key_matrix)

        if row1 == row2:
            # same row then shift right
            ciphertext += key_matrix[row1][(col1 + 1) % 5] + key_matrix[row2][(col2 + 1) % 5]
        elif col1 == col2: # same column then shift down
            ciphertext += key_matrix[(row1 + 1) % 5][col1] + key_matrix[(row2 + 1) % 5][col2]
        else:
            ciphertext += key_matrix[row1][col2] + key_matrix[row2][col1]

    return ciphertext

def playfair_decrypt(ciphertext, key):
    key_matrix = create_matrix(key)
    plaintext = ""
    i = 0

    while i < len(ciphertext):
        char1, char2 = ciphertext[i], ciphertext[i + 1]
        i += 2
        
        row1, col1 = char_pos(char1, key_matrix)
        row2, col2 = char_pos(char2, key_matrix)

        if row1 == row2:
            plaintext += key_matrix[row1][(col1 - 1) % 5] + key_matrix[row2][(col2 - 1) % 5]
        elif col1 == col2:
            plaintext += key_matrix[(row1 - 1) % 5][col1] + key_matrix[(row2 - 1) % 5][col2]
        else:
            plaintext += key_matrix[row1][col2] + key_matrix[row2][col1]

    return plaintext

def main():    
    while(True):
        choice = input("\n1. Encrypt\n2. Decrypt\n3. Quit\n(E/D/Q): ")

        if choice == 'E':
            text = input("Enter Plain Text: \n")
            text = re.sub(r'[^a-zA-Z]', '', text)
            key = input("\nEnter key: ")
            encrypted_text = playfair_encrypt(text, key)
            print(f"\nEncrypted Text: {encrypted_text}")

        elif choice == 'D':
            encrypted_text = input("Enter Encypted Text: \n")
            key = input("\nEnter key: ")
            decrypted_text = playfair_decrypt(encrypted_text, key)
            digraphs = [decrypted_text[i:i+2] for i in range(0, len(decrypted_text), 2)]
            print(f"\nDecrypted Text: {' '.join(digraphs)}")

        else:
            break
    
if __name__ == "__main__":
    main()
