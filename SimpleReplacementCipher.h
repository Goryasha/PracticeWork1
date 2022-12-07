#ifndef PRACTICALWORK1_SIMPLEREPLACEMENTCIPHER_H
#define PRACTICALWORK1_SIMPLEREPLACEMENTCIPHER_H


#include <string>
#include <map>
#include <math.h>
#include "ChipherParent.h"
#include "GaloisFieldWork.h"

class SimpleReplacement : Cipher{
private:
    std::string key;
public:
    SimpleReplacement(const std::string key_string){
        key= format_string(key_string);
    };

    std::string encode(const std::string &s) override{
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (int i = 0; i < formatted_string.size(); ++i) {
            for (int j = 0; j < key.size(); ++j) {
                if (formatted_string[i]==key[j]){
                    std::cout<<key[j]<<'\t'<<get_num(key[j])<<'\t'<<'\t'<<get_num(ALPHABET[j])<<'\t'<<get_char(get_num(ALPHABET[j]))<<'\n';
                    res+=get_char(get_num(ALPHABET[j]));
                }
            }
        }
        return res;
    };

    std::string decode(const std::string &s) override{
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (int i = 0; i < formatted_string.size(); ++i) {
            for (int j = 0; j < key.size(); ++j) {
                if (formatted_string[i]==ALPHABET[j]){
                    res+=get_char(get_num(key[j]));
                }
            }
        }
        return res;
    };

    std::string analysis(const std::string &s) override{
        return "Unavailable to analysis, because Alphabet has spaces!";
    };
};

#endif
