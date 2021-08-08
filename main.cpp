
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
              (key > 0) ? message[i] = (message[i] + key) - 26: message[i] = (message[i] + key) + 26;
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


      std::cout << "Input a key for encrypt\n";
      std::cin >> key;
      
      if ((key > 25) || (key < -25))
      {
         key -= key - (key%26);
      } 
    //  std::cout << "Key: " << key;
    
    std::cout << "Encrypted message: \n" << encrypt_caesar(message, key);
    std::cout << "\n\n\n";
    std::cout << "Decrypted message: \n" << decrypt_caeser(message, key);
}

