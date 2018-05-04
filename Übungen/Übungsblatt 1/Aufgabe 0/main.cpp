#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <set>


using namespace std;

struct WordCount {
    string word;
    int count = 0;
};

/*Global Variables*/
const vector <char> PUNCTUATION {',', '.', '!', '?', ':'};

/*Global Functions*/
string normalizeLine(string line);
vector<WordCount> findDistinctWords(const string &line);
vector<WordCount> countWords(vector<WordCount> distinctWords, string normalizedText);
void printResult(vector<WordCount> result, int wordCount);
ifstream getFile();
string readFile(ifstream infile);
int countTotalWords(string text);

int main()
{
    string normalizedText;
    vector<WordCount> distinctWords;
    int wordCount;

    normalizedText = readFile(getFile());
    wordCount = countTotalWords(normalizedText);
    distinctWords = findDistinctWords(normalizedText);
    distinctWords = countWords(distinctWords, normalizedText);
    printResult(distinctWords, wordCount);

    return 0;
}

string readFile(ifstream infile)
{
    string line, result;
    while(getline(infile, line))
    {
        result.append(normalizeLine(line));
    }
    return result;
}

int countTotalWords(string text)
{
    istringstream iss(text);
    vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
    return tokens.size();
}

ifstream getFile()
{
    string filePath;
    cout << "This program counts words." << endl;
    cout << "Pass in a file:" << endl;
    cin >> filePath;

    ifstream infile(filePath);

    while(!infile.good())
    {
        cout << "File not found. Try again:" << endl;
        cin >> filePath;
        infile = ifstream(filePath);
    }
    return infile;
}

void printResult(vector<WordCount> result, int wordCount)
{
    cout << "The text has " << wordCount << " words" << endl;
    cout << result.size() << " distinct words" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].word << ": " << result[i].count << endl;
    }
}

vector<WordCount> countWords(vector<WordCount> distinctWords, string normalizedText)
{
    istringstream iss(normalizedText);
    vector<string> normalizedTextSplitted{istream_iterator<string>{iss}, istream_iterator<string>{}};
    for(int i = 0; i < distinctWords.size(); ++i)
    {
        string word = distinctWords[i].word;
        for(int j = 0; j < normalizedTextSplitted.size(); ++j)
        {
            if (distinctWords[i].word == normalizedTextSplitted[j])
            {
                distinctWords[i].count++;
            }
        }
    }
    return distinctWords;
}

string normalizeLine(string line)
{
    for (char i : PUNCTUATION)
    {
        line.erase(std::remove(line.begin(), line.end(), i), line.end());
    }
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    return line;
}

vector<WordCount> findDistinctWords(const string &line)
{
    set<string> distinct;
    vector<WordCount> result;
    istringstream iss(line);
    vector<string> splitted{istream_iterator<string>{iss}, istream_iterator<string>{}};

    for(int i = 0; i < splitted.size(); ++i)
    {
        distinct.insert(splitted[i]);
    }
    for(string d : distinct)
    {
        WordCount c;
        c.word = d;
        result.push_back(c);
    }

    return result;
}