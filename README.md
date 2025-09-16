# Encrypted Diary App

A simple C++ encrypted diary app using XOR cipher. Users can write timestamped diary entries saved to a file and read them back decrypted using a secret key. Features a menu-driven interface for secure note keeping.

---

## Features

- **Write Entries:** Append new diary entries with the current timestamp.
- **Read Entries:** View all previous entries, decrypted on-the-fly with your secret key.
- **Simple Encryption:** Uses XOR cipher with a user-provided secret key to encrypt and decrypt diary contents.
- **User-Specific Files:** Each username corresponds to a separate diary file (`username.txt`).
- **Menu-Driven Interface:** Easy-to-use menu for writing, reading, or exiting.

---

## How It Works

- When writing entries, the app encrypts each line using XOR with the provided secret key and saves it to the user's diary file along with a timestamp.
- When reading, the app decrypts each line on the fly using the same key to display readable diary entries.
- If the secret key is incorrect, the decrypted text will be unintelligible, providing a basic level of privacy.

---
