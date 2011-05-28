/* Project Euler #22
 *
 * Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
 * containing over five-thousand first names, begin by sorting it into
 * alphabetical order. Then working out the alphabetical value for each name,
 * multiply this value by its alphabetical position in the list to obtain a name
 * score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN, which is
 * worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN
 * would obtain a score of 938 * 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::getline;
using std::remove;
using std::vector;

int name_value(const string &name)
{
    int sum = 0;
    string::const_iterator it;
    for (it=name.begin(); it!=name.end(); ++it) {
        sum += *it - 'A' + 1;
    }

    return sum;
}

int main()
{
    string line;
    std::ifstream fin("names.txt");
    getline(fin, line);
    fin.close();

    string::iterator rm = remove(line.begin(), line.end(), '"');
    line.erase(rm, line.end());

    std::vector<string> names;
    size_t start = 0;
    size_t end = line.find(',');
    for (; end != string::npos; end = line.find(',', end+1)) {
        names.push_back(string(line, start, end-start));
        start = end+1;
    }
    names.push_back(string(line, start));

    std::sort(names.begin(), names.end());

    long sum = 0;
    for (size_t i=0; i<names.size(); i++) {
        long val = name_value(names[i]) * (i+1);
        sum += val;
    }

    std::cout << sum << std::endl;

    return 0;
}
