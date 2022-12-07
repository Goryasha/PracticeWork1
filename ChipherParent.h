#ifndef PRACTICALWORK1_CHIPHERPARENT_H
#define PRACTICALWORK1_CHIPHERPARENT_H

#include <string>
#include <iostream>

const std::string ALPHABET = "abcdefghijklmnopqrstuvwxyz -',:.";

class Cipher {
protected:

    unsigned long long get_num(char c) {
        int tmp = ALPHABET.find(c);
        if (tmp != std::string::npos) {
            return tmp;
        } else {
            std::cout<<"Error on "<<c<<"\n";
            throw std::invalid_argument("There is no such symbol  in APHABET");
        }
    }

    char get_char(unsigned long long n) {
        if (n >= ALPHABET.size()) {
            std::cout<<"Error on "<<n<<"\n";
            throw std::invalid_argument("N is larger than the size of the alphabet");
        }
        return ALPHABET[n];
    }

    std::string format_string(const std::string &s) {
        std::string res = "";

        for (int i = 0; i < s.size(); i++) {
            char tmp = tolower(s[i]);
            if (ALPHABET.find(tmp) != std::string::npos) {
                res += tmp;
            } else {
                std::cout << "Symbol-" << s[i] << " not included in the coding alphabet\n";
            }
        }

        return res;
    }

public:
    virtual std::string decode(const std::string &s);
    virtual std::string encode(const std::string &s);
    virtual std::string analysis(const std::string &s);
};

std::string Cipher::decode(const std::string &s) {
    return {};
}

std::string Cipher::encode(const std::string &s) {
    return {};
}

std::string Cipher::analysis(const std::string &s) {
    return {};
}

#endif
