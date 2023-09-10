def encrypt(a, b):
    enc = [[" " for i in range(len(a))] for j in range(b)]
    flag = 0
    row = 0

    for i in range(len(a)):
        enc[row][i] = a[i]
        if row == 0:
            flag = 0
        elif row == b - 1:
            flag = 1
        if flag == 0:
            row += 1
        else:
            row -= 1

    ct = []
    for i in range(b):
        for j in range(len(a)):
            if enc[i][j] != ' ':
                ct.append(enc[i][j])

    cipher = "".join(ct)
    return cipher


def decrypt(cipher, b):
    rail = [['\n' for _ in range(len(cipher))] for _ in range(b)]
    dir_down = None
    row, col = 0, 0

    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == b - 1:
            dir_down = False

        rail[row][col] = '*'
        col += 1
        if dir_down:
            row += 1
        else:
            row -= 1

    index = 0
    for i in range(b):
        for j in range(len(cipher)):
            if rail[i][j] == '*' and index < len(cipher):
                rail[i][j] = cipher[index]
                index += 1

    result = []
    row, col = 0, 0
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == b - 1:
            dir_down = False

        if rail[row][col] != '*':
            result.append(rail[row][col])
            col += 1

        if dir_down:
            row += 1
        else:
            row -= 1

    return "".join(result)


while True:
    print("Choose an option:")
    print("1. Encrypt")
    print("2. Decrypt")
    print("3. Quit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        a = input("Enter the plain text: ")
        b = int(input("Enter the b: "))
        encrypted_text = encrypt(a, b)
        print("Encrypted text:", encrypted_text)
    elif choice == 2:
        cipher = input("Enter the cipher text: ")
        b = int(input("Enter the b: "))
        decrypted_text = decrypt(cipher, b)
        print("Decrypted text:", decrypted_text)
    elif choice == 3:
        break
    else:
        print("Invalid choice")
