#ifndef PRACTICALWORK1_CAESARCIPHR_H
#define PRACTICALWORK1_CAESARCIPHR_H

#include <string>
#include <map>
#include <math.h>
#include "ChipherParent.h"
#include "GaloisFieldWork.h"

class CaesarCipher : Cipher {
private:
    galois_num al;
    std::map <char,float> frequency;

public:

    explicit CaesarCipher(galois_num _al) {
        al = normalize(_al);
    }

    std::string encode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
            res += get_char((get_num(sym)+al)%32);
        }

        return res;
    };

    std::string decode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
            res += get_char((get_num(sym)-al)%32);
        }

        return res;
    };

    std::string analysis(const std::string &s) override{
        std::string formatted_string = format_string(s);
        for(int i =0;i<ALPHABET.size();i++){
            frequency[ALPHABET[i]]=0;
            for (int j = 0; j < formatted_string.size(); j++) {
                if(ALPHABET[i]==formatted_string[j]){
                    frequency[ALPHABET[i]]+=1;
                }
            }
        }
        float max=0;
        char maxim;
        auto it =frequency.begin();
        for (int i = 0; it != frequency.end(); it++) {
            std::cout<<it->first<<"\t"<<it->second<<"\n";
            if(it->second>max){
                max=it->second;
                maxim=it->first;
            }
        }
        galois_num cur_pos=get_num(maxim);
        CaesarCipher ans((get_num(' ')-cur_pos)%32);
        return ans.encode(formatted_string);
    };
};

#endif
