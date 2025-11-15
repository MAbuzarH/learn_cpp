#include <iostream>
#include <limits> // Required for clearing input buffer


#include "Sentence.h"
#include "functions.h"

using namespace std;

void getFilePath(char* path)
{
    cout << "Enter file path (e.g., input.txt): ";

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.getline(path, Sentence::MAX_SZ);
}

// Helper function to display the main menu
void displayMenu()
{
    cout << "\n=================================================" << endl;
    cout << "  UCP OOP C20 Assignment Two - Sentence Manager  " << endl;
    cout << "=================================================" << endl;
    cout << " R : Read a Sentence from a text file" << endl;
    cout << " D : Display the current Sentence" << endl;
    cout << " W : Write the current Sentence to a text file" << endl;
    cout << " U : Convert to UPPERCASE and display" << endl;
    cout << " L : Convert to lowercase and display" << endl;
    cout << " S : Search for a word in the Sentence" << endl;
    cout << " F : Calculate Frequencies of each word" << endl;
    cout << " C : Compare 2 Sentences from files" << endl;
    cout << " T : Concatenate 2 Sentences from files" << endl;
    cout << " E : Exit the program" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Select option: ";
}


int main()
{
    
    Sentence currentSentence; 
    char choice;
    
   
    char filePath[Sentence::MAX_SZ];
    char searchWord[Sentence::MAX_SZ];

    do
    {
        displayMenu();
       
        if (!(cin >> choice))
        {
           
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 'Z'; 
        }
        
        
        if (choice >= 'a' && choice <= 'z')
        {
            choice = choice - 32;
        }

        switch (choice)
        {
            // R: Read Sentence from File
            case 'R':
                getFilePath(filePath);
                readSentenceFromFile(currentSentence, filePath);
                break;

            // D: Display Sentence
            case 'D':
                currentSentence.display();
                break;

            // W: Write Sentence to File
            case 'W':
                getFilePath(filePath);
                writeSentenceToFile(currentSentence, filePath);
                break;

            // U: Uppercase
            case 'U':
                currentSentence.toUppercase();
                break;

            // L: Lowercase
            case 'L':
                currentSentence.toLowercase();
                break;

            // S: Search Word
            case 'S':
                // Clear the input buffer before reading the word
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Enter word to search: ";
                cin.getline(searchWord, Sentence::MAX_SZ);

                if (currentSentence.searchWord(searchWord))
                {
                    cout << "Result: The word \"" << searchWord << "\" was FOUND in the sentence." << endl;
                }
                else
                {
                    cout << "Result: The word \"" << searchWord << "\" was NOT FOUND in the sentence." << endl;
                }
                break;

            // F: Calculate Frequencies
            case 'F':
                calculateWordFrequency(currentSentence);
                break;

            // C: Compare 2 Sentences
            case 'C':
            {
              
                Sentence s1, s2;
                cout << "\n-- Reading Sentence 1 for Comparison --" << endl;
                getFilePath(filePath);
                if (readSentenceFromFile(s1, filePath))
                {
                    cout << "\n-- Reading Sentence 2 for Comparison --" << endl;
                    getFilePath(filePath);
                    if (readSentenceFromFile(s2, filePath))
                    {
                        compareSentences(s1, s2);
                    }
                }
                break;
            }

            // T: Concatenate 2 Sentences
            case 'T':
            {
                
                Sentence s1, s2;
                cout << "\n-- Reading Sentence 1 for Concatenation --" << endl;
                getFilePath(filePath);
                if (readSentenceFromFile(s1, filePath))
                {
                    cout << "\n-- Reading Sentence 2 for Concatenation --" << endl;
                    getFilePath(filePath);
                    if (readSentenceFromFile(s2, filePath))
                    {
                       
                        Sentence concatenated = concatenateSentences(s1, s2);
                        
                        
                        cout << "Concatenated Result: ";
                        concatenated.display();

                        
                        cout << "\n-- Writing Concatenated Sentence to File --" << endl;
                        getFilePath(filePath);
                        writeSentenceToFile(concatenated, filePath);
                    }
                }
                break;
            }

            // E: Exit
            case 'E':
                cout << "\nExiting Program. Goodbye!" << endl;
                break;

            // Other: Invalid Option
            default:
                cout << "Invalid option selected. Please choose from the menu." << endl;
                break;
        }

    } while (choice != 'E');

    return 0;
}