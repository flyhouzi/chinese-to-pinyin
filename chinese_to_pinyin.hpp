#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

std::string chinese_to_pinyin(const std::wstring& s) {
    std::string result;
    std::map<std::string, std::string> dic;
    std::ifstream f;
    f.open("unicode_to_pinyin.txt");
    std::string line;
    while(std::getline(f, line)) {
        std::stringstream ss(line);
        std::string first;
        std::string second;
        ss >> first;
        ss >> second;
        dic[first] = second;
    }
    f.close();
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::stringstream ss;
        std::string temp;
        ss << std::hex << *it;
        ss >> temp;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        auto iter = dic.find(temp);
        if (iter != dic.end()) {
            result += iter->second + " ";
        } else {
            result += (char)*it;
        }
    }

    return result;
}
