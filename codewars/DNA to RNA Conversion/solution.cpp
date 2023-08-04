#include <string>
std::string DNAtoRNA(std::string dna)
{
    for (char &c : dna)
    {
        if (c == 'T')
            c = 'U';
    }
    return dna;
}

// ......................................................................

#include <string>
#include <algorithm>
std::string DNAtoRNA(std::string dna)
{
    std::replace(dna.begin(), dna.end(), 'T', 'U');
    return dna;
}

// ......................................................................

#include <string>
#include <regex>
std::string DNAtoRNA(std::string dna)
{
    return std::regex_replace(dna, std::regex("T"), "U");
}