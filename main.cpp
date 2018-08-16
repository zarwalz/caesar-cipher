// Zineb Zarwal
// 12 July 2018
// Project 1

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    int count = 0; //counter to iterate from 0 to 25 (the length of the alphabet)
    int shift = 0; //counter to iterate how many shifts are required for decryption
    int greatest = 0; //counter to track with shift has the greatest num of common words
    string encPhrase;
    string decPhrase = encPhrase;
    ifstream fileOne, fileTwo;
    fileOne.open("code.txt");
    getline(fileOne, encPhrase);
    int size = (int)encPhrase.length();
    int sizeOfVector = 0;
    
    fileTwo.open("englishwords.txt");
    vector<string> commonWords; //using a vector to import words from file (unknown size)
    string word;
    
    while (!fileTwo.eof()) //importing common words into a string vector
        {
        getline(fileTwo, word);
        commonWords.push_back(word);
        }
    sizeOfVector = (int)commonWords.size();
    
    do   //this do-while shifts the encrypted phrase by one each time and compares each iterationit with common words
    {
        for (int i = 0; i < size; i++)
            {
                if(isalpha(encPhrase[i]))
                    {
                        for (int j = 0; j < 1; j++)
                            {
                                if (encPhrase[i] == 'z' || encPhrase[i] == 'Z')
                                    encPhrase[i] = 'a';
                                else
                                    encPhrase[i]++;
                    }
                }
            }
        int foundWords = 0;
        for (int v = 0; v < sizeOfVector; v++)
            {
            int found = (int)encPhrase.find(commonWords[v]);
                if(found != string::npos)
                {
                    foundWords++;
                }
            }
        
        if (foundWords > greatest)
            {
            greatest = foundWords;
            decPhrase = encPhrase;
            shift = count + 1;
            }
        
       count++;
    
    
        
      }while (count < 25);
    
    fileOne.close();
    fileTwo.close();
    
    cout << "Decrypted Phrase: " << decPhrase << endl;
    cout << "Shift num: " << shift << endl;
    cout << "# of common words: " << greatest << endl;

    return 0;
}


