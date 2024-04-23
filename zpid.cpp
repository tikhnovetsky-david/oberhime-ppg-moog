#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include <Windows.h>

#include "h.h"

#define BUFFER 1024

bool system_debugger_attached(void)
{
    return IsDebuggerPresent();
}

std::vector<std::string> hashes;

void fill(std::vector<std::string>& h) 
{
    h.push_back("1ea5fa123f6d21e34fdda88b60c9b653");
    h.push_back("19cc2bfe5b1fd0a136182763c24b0e1d");
    h.push_back("b789552059b239b877821f0c029f9492");
    h.push_back("ca482746bab2d46ff62f01401bc41b3e");
    h.push_back("85b16351a3183cf9c888d34ab718b8d2");
    h.push_back("8276af4f7e8a892058951f3d2277c27c");
    h.push_back("19e50ee46091ccbe2394a408871e6ffc");
    h.push_back("70d3eeb40cf11d4c2ee2f29bc7cc520e");
    h.push_back("b895cfd5f4c3d57a5c6477f655f7d183");
    h.push_back("ccbee27618795b6169124cecea74b6e2");
    h.push_back("701b64f72f26c4a827afa95f1e9e8ef3");
    h.push_back("276d3bc11a11ea456d33e390d89f6820");
}


std::vector<char> func_iterate(char * s)
{
    char* t;
    std::vector<char> sym;
    std::size_t size = 0;
    for (t = s; *t != '\0'; t++) 
    {
        size++;
        sym.push_back(t[0]);
    }

    return sym;
}

void func_kg(char * s)
{
    std::string r;
    std::stringstream ss;
    for (int i = 0; i < func_iterate(s).size(); i++)
    {
        ss << std::hex << (int)func_iterate(s)[i];
    }
    std::string hexstr = ss.str();

    md5 m;
    m.update(hexstr.begin(), hexstr.end());
    m.hex_digest(r);

    if (std::find(hashes.begin(), hashes.end(), r) != hashes.end())
        std::cout << "This is correct!\n";
    else
        exit(-101);
}

void func_read()
{
    char* data = new char[BUFFER];
    std::cin >> std::setw(BUFFER) >> data;
    func_kg(data);
    delete[] data;
}

int main()
{
    if (system_debugger_attached()) exit(-100);
    fill(hashes);
    std::cout << "Username : ";
    func_read();
    std::cout << "Password : ";
    func_read();

    return 0;
}