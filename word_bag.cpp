#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

map<string, int> *wordsCounting(string text) {
  map<string, int> *wordCount = new map<string,int>;
  stringstream wordStream(text);
  string word;

  while(getline(wordStream,word,' ')){
    (*wordCount)[word]+=1;
  }

  return wordCount;
}

string text = "In Western musical theory, a cadence (Latin cadentia, 'a falling') is the end of a phrase in which the melody or harmony creates a sense of resolution. A harmonic cadence is a progression of two or more chords that concludes a phrase, section, or piece of music. A rhythmic cadence is a characteristic rhythmic pattern that indicates the end of a phrase. A cadence is labeled like or less 'weak' or 'strong' depending on the impression of finality it gives. While cadences are usually classified by specific chord or melodic progressions, the use of such progressions does not necessarily constitute a cadence—there must be a sense of closure, as at the end of a phrase. Harmonic rhythm plays an important part in determining where a cadence occurs.";

int main()
{
    string strBuf;
    //getline(std::cin, strBuf);
    cout << strBuf << '\n';
    map<string,int> *wordCount = wordsCounting(text);
    std::cout << key        // string (key)
              << ':'
              << val        // string's value
              << std::endl;

    return 0;
}
