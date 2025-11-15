
class Sentence;

bool readSentenceFromFile(Sentence& s, char* filePath);


bool writeSentenceToFile(const Sentence& s, char* filePath);


void calculateWordFrequency(const Sentence& s);


void compareSentences(const Sentence& s1, const Sentence& s2);


Sentence concatenateSentences(const Sentence& s1, const Sentence& s2);