#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

// Function to encrypt/decrypt using XOR
string xorEncrypt(string text, int key) 
{
    string result = "";
    for (char c : text)
	{
        result += c ^ key;
    }
    return result;
}

int main() 
{
    string username;
    int key;

    // Get login details
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter secret key: ";
    cin >> key;

    string filename = username + ".txt";

    int choice;

    do 
	{
        cout << "\n--- Diary Menu ---\n";
        cout << "1. Write entry\n";
        cout << "2. Read entries\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Flush 

        if (choice == 1) 
		{
            // Write mode
            ofstream file(filename, ios::app);
            time_t now = time(0);
            char* dt = ctime(&now);
            file << "\n[Entry on: " << dt << "]\n";

            cout << "Start writing (type QUIT to finish):\n";
            string line;
            while (true) {
                getline(cin, line);
                if (line == "QUIT") break;

                file << xorEncrypt(line, key) << "\n";
            }

            file.close();
            cout << "Entry saved.\n";

        } else if (choice == 2) 
		{
            // Read mode
            ifstream file(filename);

            if (!file) 
			{
                cout << "No diary found for this user.\n";
                continue;
            }

            string line;
            while (getline(file, line)) 
			{
                if (line.find("[Entry on:") == 0) 
				{
                    cout << line << "\n"; // print timestamp
                } else 
				{
                    cout << xorEncrypt(line, key) << "\n"; // decrypt and print
                }
            }

            file.close();

        } else if (choice == 3) 
		{
            cout << "Goodbye!\n";
        } else 
		{
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}
