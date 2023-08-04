#include <iostream>
#include <vector>
#include <algorithm>

class WhichAreIn {
public:
    static std::vector<std::string> inArray(std::vector<std::string>& array1, std::vector<std::string>& array2) {
        std::vector<std::string> r;

        for (const std::string& str1 : array1) {
            for (const std::string& str2 : array2) {
                if (str2.find(str1) != std::string::npos) {
                    r.push_back(str1);
                    break;
                }
            }
        }

        std::sort(r.begin(), r.end());

        return r;
    }
};
