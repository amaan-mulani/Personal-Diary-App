# Encrypted Diary App

A simple C++ console application that allows users to keep a private diary secured with a basic XOR encryption. Each user has their own diary file, and entries are timestamped to keep track of when they were made.

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
