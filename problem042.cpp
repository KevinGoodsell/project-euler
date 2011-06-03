/* Project Euler #42
 *
 * The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1);
 * so the first ten triangle numbers are:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * By converting each letter in a word to a number corresponding to its
 * alphabetical position and adding these values we form a word value. For
 * example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value
 * is a triangle number then we shall call the word a triangle word.
 *
 * Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
 * containing nearly two-thousand common English words, how many are triangle
 * words?
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<string> get_words()
{
    std::ifstream fin("words.txt");
    string word;
    vector<string> result;
    while (getline(fin, word, ',')) {
        result.push_back(word.substr(1, word.size()-2));
    }

    return result;
}

long word_value(const string &word)
{
    long result = 0;
    for (size_t i=0; i<word.size(); i++) {
        result += word[i] - 'A' + 1;
    }

    return result;
}

bool is_triangle(const string &word)
{
    long val = word_value(word);

    for (long i=1;; i++) {
        long term = (i + 1) * i / 2;
        if (term == val) return true;
        if (term > val) break;
    }

    return false;
}

int main()
{
    vector<string> words(get_words());
    int count = 0;

    for (size_t i=0; i<words.size(); i++) {
        if (is_triangle(words[i])) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
