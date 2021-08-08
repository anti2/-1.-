
#include <iostream>

std::string encrypt_caesar(std::string message, int key)
{
    for (int i = 0; i < message.length(); i++)
    {
        if (isalpha(message[i]))
        {
            if (isalpha(message[i] + key))
            {
               message[i] += key;
            }
            else
            {
              message[i] = (message[i] + key) - 26;
            }
        }
        
    }
    return message;
}

std::string decrypt_caeser(std::string message, int key)
{
    encrypt_caesar(message, -key);
    return message;
}

int main() {
    int key;
    std::string message;
    std::cout << "Input a message\n";
    std::getline(std::cin, message);

    do
    {
        std::cout << "Input a key for encrypt (min - 1: max - 25)\n";
        std::cin >> key;
    } while (key < 1 || key > 25);

    std::cout << "Encrypted message: \n" << encrypt_caesar(message, key);
    std::cout << "\n\n\n";
    std::cout << "Decrypted message: \n" << decrypt_caeser(message, key);
}
