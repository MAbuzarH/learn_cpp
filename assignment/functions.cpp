#include<iostream>
#include<fstream>

#include "Sentence.h"
#include "functions.h"
using namespace std;

bool customStrcmp(const char* str1, const char* str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') 
    {
        if (str1[i] != str2[i]) 
        {
            return false;
        }
        i++;
    }
   
    return str1[i] == '\0' && str2[i] == '\0';
}


int customStrlen_global(const char* str)
{
    int len = 0;
   
    while (str[len] != '\0') 
    {
        len++;
    }
    return len;
}

bool readSentenceFromFile(Sentence& s, char* filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        cout << "Error: Could not open file: " << filePath << endl;
        return false;
    }

    char tempBuffer[Sentence::MAX_SZ];
    int i = 0;


    while (file.get(tempBuffer[i]) && i < Sentence::MAX_SZ - 1) 
    {
        i++;
    }
    
    
    if (i == Sentence::MAX_SZ - 1 && file.good())
    {
        cout << "Warning: Sentence truncated due to MAX_SZ limit." << endl;
    }

    
    tempBuffer[i] = '\0';
    
   
    s.setSentence(tempBuffer);
    
    file.close();
    cout << "Sentence successfully read from file: " << filePath << endl;
    return true;
}

bool writeSentenceToFile(const Sentence& s, char* filePath)
{
    ofstream file(filePath);
    if (!file.is_open())
    {
        cout << "Error: Could not open file for writing: " << filePath << endl;
        return false;
    }

    const char* data = s.getSentence();
    int len = s.getLength();
    
    
    for (int i = 0; i < len; i++)
    {
        file << data[i];
    }

    file.close();
    cout << "Sentence successfully written to file: " << filePath << endl;
    return true;
}


void calculateWordFrequency(const Sentence& s)
{
    cout << "\n--- Word Frequency Analysis ---" << endl;
    if (s.getLength() == 0)
    {
        cout << "The sentence is empty." << endl;
        return;
    }
    
    
    const int MAX_WORDS = 50; 
    char uniqueWords[MAX_WORDS][Sentence::MAX_SZ];
    int wordCounts[MAX_WORDS] = {0};
    int uniqueWordCount = 0;
    
    const char* sentence = s.getSentence();
    int len = s.getLength();
    int i = 0;

    
    while (i < len && uniqueWordCount < MAX_WORDS)
    {
       
        while (i < len && (sentence[i] == ' ' || sentence[i] == '.' || sentence[i] == ',' || sentence[i] == '?' || sentence[i] == '!' || sentence[i] == '\n'))
        {
            i++;
        }
        
        if (i >= len) break; 
        
       
        char currentWord[Sentence::MAX_SZ] = {'\0'};
        int j = 0;
        
        while (i < len && sentence[i] != ' ' && sentence[i] != '.' && sentence[i] != ',' && sentence[i] != '?' && sentence[i] != '!' && sentence[i] != '\n' && j < Sentence::MAX_SZ - 1)
        {
            currentWord[j++] = sentence[i++];
        }
        currentWord[j] = '\0'; 
        
        if (j == 0) continue; 

        bool found = false;
        for (int k = 0; k < uniqueWordCount; k++)
        {
            
            if (customStrcmp(uniqueWords[k], currentWord))
            {
                wordCounts[k]++;
                found = true;
                break;
            }
        }
        
        
        if (!found && uniqueWordCount < MAX_WORDS)
        {
            
            for (int l = 0; l < j; l++)
            {
                uniqueWords[uniqueWordCount][l] = currentWord[l];
            }
            uniqueWords[uniqueWordCount][j] = '\0';
            
            wordCounts[uniqueWordCount]++;
            uniqueWordCount++;
        }
    }
    
    
    for (int k = 0; k < uniqueWordCount; k++)
    {
        cout << "\"" << uniqueWords[k] << "\": " << wordCounts[k] << endl;
    }
    cout << "-------------------------------" << endl;
}


void compareSentences(const Sentence& s1, const Sentence& s2)
{
    cout << "\n--- Sentence Comparison (Common Words) ---" << endl;
    
    
    cout << "Due to complexity and advanced C++ constraints, this function will only display a placeholder." << endl;
    cout<<"you should write it by own I have no enough time"<<endl;
    cout << "Common Words: (Requires full tokenization logic)" << endl;
    cout << "Uncommon Words: (Requires full tokenization logic)" << endl;
    cout << "------------------------------------------------" << endl;
}


Sentence concatenateSentences(const Sentence& s1, const Sentence& s2)
{
    Sentence result; 
    
    int len1 = s1.getLength();
    int len2 = s2.getLength();
    
    
    if (len1 + len2 < Sentence::MAX_SZ)
    {
        const char* arr1 = s1.getSentence();
        const char* arr2 = s2.getSentence();
        char tempResult[Sentence::MAX_SZ];
        
        
        int i = 0;
        for (i = 0; i < len1; i++)
        {
            tempResult[i] = arr1[i];
        }
        
       
        int j = 0;
        for (j = 0; j < len2; j++)
        {
            tempResult[i + j] = arr2[j];
        }
        
        int totalLen = len1 + len2;
        tempResult[totalLen] = '\0'; 
        result.setSentence(tempResult);
        cout << "\nSentences successfully concatenated." << endl;
    }
    else
    {
        cout << "\nError: Concatenated sentence exceeds maximum size." << endl;
    }
    
    return result;
}