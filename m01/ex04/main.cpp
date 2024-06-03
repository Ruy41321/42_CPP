#include <iostream>
#include <fstream>
#include <string>

std::string replace_string(std::string str, const std::string& s1, const std::string& s2) {
    size_t pos = 0;
    while ((pos = str.find(s1, pos)) != std::string::npos) {
        str.erase(pos, s1.length());
        str.insert(pos, s2);
        pos += s2.length();
    }
    return str;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "You must insert as parameter: <filename> <s1> <s2>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty() || s2.empty()) {
        std::cerr << "Error: s1 and s2 must not be empty\n";
        return 1;
    }

    std::ifstream starting_file(filename.c_str());
    if (!starting_file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return 1;
    }

    std::ofstream replacing_file((filename + ".replace").c_str());
    if (!replacing_file.is_open()) {
        std::cerr << "Error: Could not open file " << filename + ".replace" << "\n";
        return 1;
    }

    std::string line;
    while (std::getline(starting_file, line)) {
        replacing_file << replace_string(line, s1, s2) << "\n";
    }

    starting_file.close();
    replacing_file.close();

    return 0;
}