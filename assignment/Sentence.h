

class Sentence
{
private:
   
    static const int MAX_SIZE = 256; 
    
 
    char sentenceArray[MAX_SIZE];
    
    int length; 
    
public: 
    
    static const int MAX_SZ = 256; 
    Sentence();

   
    Sentence(char* newSentence);

    Sentence(const Sentence& other);

   
    ~Sentence();


   
    char* getSentence() const;

    
    int getLength() const;


    
    void setSentence(char* newSentence);


   
    void display() const;

    void toUppercase();

   
    void toLowercase();

    
    bool searchWord(char* wordToFind) const;
};