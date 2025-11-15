

#include<iostream>
#include<fstream> 
 
#include "Sentence.h"
#include "functions.h"

using namespace std;

int customStrlen(const char* str)
{
    int len = 0;
    while (str[len] != '\0' && len < Sentence::MAX_SZ) 
    {
        len++;
    }
    return len;
}

Sentence::Sentence()
{
    
    length = 0;
   
    sentenceArray[0] = '\0';
}


Sentence::Sentence(char* newSentence)
{
    int i = 0;
    
    for (i = 0; newSentence[i] != '\0' && i < MAX_SIZE - 1; i++)
    {
        sentenceArray[i] = newSentence[i];
    }
    
    
    length = i;
    sentenceArray[length] = '\0';
}

Sentence::Sentence(const Sentence& other)
{
    // Copy length
    length = other.length;

    
    for (int i = 0; i < length; i++)
    {
        sentenceArray[i] = other.sentenceArray[i];
    }
    
   
    sentenceArray[length] = '\0';
}


Sentence::~Sentence()
{
    // No action needed for static array members
}


char* Sentence::getSentence() const
{
    return (char*)sentenceArray; 
}


int Sentence::getLength() const
{
    return length;
}


void Sentence::setSentence(char* newSentence)
{
    int newLen = customStrlen(newSentence);
    
    
    if (newLen < MAX_SIZE)
    {
        
        for (int i = 0; i < newLen; i++)
        {
            sentenceArray[i] = newSentence[i];
        }
        
       
        length = newLen;
        sentenceArray[length] = '\0';
    }
    else
    {
        cout << "Error: New sentence exceeds maximum capacity (" << MAX_SIZE << ")." << endl;
    }
}


void Sentence::display() const
{
    cout << "Stored Sentence: ";
   
    for (int i = 0; i < length; i++)
    {
        cout << sentenceArray[i];
    }
    cout << endl;
}

void Sentence::toUppercase()
{
   
    for (int i = 0; i < length; i++)
    {
        char c = sentenceArray[i];
        
       
        if (c >= 'a' && c <= 'z')
        {
            
            sentenceArray[i] = c - 32;
        }
    }
    cout << "Sentence converted to UPPERCASE." << endl;
    this->display(); 
  }

void Sentence::toLowercase()
{
    
    for (int i = 0; i < length; i++)
    {
        char c = sentenceArray[i];
        
       
        if (c >= 'A' && c <= 'Z')
        {
           
            sentenceArray[i] = c + 32;
        }
    }
    cout << "Sentence converted to lowercase." << endl;
    this->display(); 
}

bool Sentence::searchWord(char* wordToFind) const
{
    int wordLen = customStrlen(wordToFind);

    if (wordLen == 0 || wordLen > length)
    {
        return false;
    }

   
    for (int i = 0; i <= length - wordLen; i++)
    {
        bool match = true;
       
        for (int j = 0; j < wordLen; j++)
        {
            if (sentenceArray[i + j] != wordToFind[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return true;
        }
    }

    return false;
}