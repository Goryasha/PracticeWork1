#ifndef PRACTICALWORK1_AFFINERECURRENTCIPHER_H
#define PRACTICALWORK1_AFFINERECURRENTCIPHER_H

#include <string>

#include "ChipherParent.h"
#include "GaloisFieldWork.h"

class RecurrentCipher : Cipher {
private:
    galois_num al1;
    galois_num be1;
    galois_num al2;
    galois_num be2;
    std::map <char,float> frequency;

public:

    RecurrentCipher(galois_num _al1, galois_num _be1, galois_num _al2, galois_num _be2) {
        al1 = _al1;
        al2 = _al2;
        be1 = _be1;
        be2 = _be2;
    }

    std::string encode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res = "";

        if (formatted_string.size() >= 1) {
//            std::cout<<formatted_string[0]<<'\t'<<get_num(formatted_string[0])<<'\t'<<'\t'<<get_char(sum(prod(get_num(formatted_string[0]), al1), be1))<<'\t'<<sum(prod(get_num(formatted_string[0]), al1), be1)<<'\n';
            res += get_char(sum(prod(get_num(formatted_string[0]), al1), be1));
        }
        if (formatted_string.size() >= 2) {
//            std::cout<<formatted_string[1]<<'\t'<<get_num(formatted_string[1])<<'\t'<<'\t'<<get_char(sum(prod(get_num(formatted_string[1]), al2), be2))<<'\t'<<sum(prod(get_num(formatted_string[1]), al2), be2)<<'\n';
            res += get_char(sum(prod(get_num(formatted_string[1]), al2), be2));
        }

        galois_num coefs[4] = {al1, be1, al2, be2};

        for (int i = 2; i < formatted_string.size(); i++) {
            char sym = formatted_string[i];
            galois_num tmp_al = prod(coefs[0], coefs[2]);
            galois_num tmp_be = sum(coefs[1], coefs[3]);
            coefs[0] = coefs[2];
            coefs[1] = coefs[3];
            coefs[2] = tmp_al;
            coefs[3] = tmp_be;
//            std::cout<<tmp_al<<'\t'<<tmp_be<<'\t'<<sym<<'\t'<<get_num(sym)<<'\t'<<'\t'<<get_char(sum(prod(get_num(sym), tmp_al), tmp_be))<<'\t'<<sum(prod(get_num(sym), tmp_al), tmp_be)<<'\n';
            res += get_char(sum(prod(get_num(sym), tmp_al), tmp_be));
        }

        return res;
    };

    std::string decode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res = "";

        if (s.size() >= 1) {
            res += get_char(divide(sum(get_num(formatted_string[0]), be1), al1));
//            std::cout<<formatted_string[0]<<'\t'<<get_num(formatted_string[0])<<'\t'<<'\t'<<get_char(divide(sum(get_num(formatted_string[0]), be1), al1))<<'\t'<<divide(sum(get_num(formatted_string[0]), be1), al1)<<'\n';

        }
        if (s.size() >= 2) {
//            std::cout<<formatted_string[1]<<'\t'<<get_num(formatted_string[1])<<'\t'<<'\t'<<get_char(divide(sum(get_num(formatted_string[1]), be2), al2))<<'\t'<<divide(sum(get_num(formatted_string[1]), be2), al2)<<'\n';

            res += get_char(divide(sum(get_num(formatted_string[1]), be2), al2));
        }

        galois_num coefs[4] = {al1, be1, al2, be2};

        for (int i = 2; i < formatted_string.size(); i++) {
            char sym = formatted_string[i];
            galois_num tmp_al = prod(coefs[0], coefs[2]);
            galois_num tmp_be = sum(coefs[1], coefs[3]);
            coefs[0] = coefs[2];
            coefs[1] = coefs[3];
            coefs[2] = tmp_al;
            coefs[3] = tmp_be;
//            std::cout<<tmp_al<<'\t'<<tmp_be<<'\t'<<sym<<'\t'<<get_num(sym)<<'\t'<<'\t'<<get_char(divide(sum(get_num(sym), tmp_be), tmp_al))<<'\t'<<divide(sum(get_num(sym), tmp_be), tmp_al)<<'\n';

            res += get_char(divide(sum(get_num(sym), tmp_be), tmp_al));
        }

        return res;
    };

    std::string analysis(const std::string &s) override{
        std::string formatted_string = format_string(s);
        char maxim1;
        char maxim2;
        char maxim3;
        int counter=1;
        while(maxim1!=' ' or maxim2!='e' or maxim3!='o') {
            formatted_string=format_string(this->encode(formatted_string));
            std::cout<<"Iteration "<<counter++<<" : "<<formatted_string<<"\n";
            for (int i = 0; i < ALPHABET.size(); i++) {
                frequency[ALPHABET[i]] = 0;
                for (int j = 0; j < formatted_string.size(); j++) {
                    if (ALPHABET[i] == formatted_string[j]) {
                        frequency[ALPHABET[i]] += 1;
                    }
                }
            }
            float max1 = 0;
            float max2 = 0;
            float max3 = 0;
            auto it = frequency.begin();
            for (int i = 0; it != frequency.end(); it++) {
//                std::cout << it->first << "\t" << it->second << "\n";
                if (it->second > max1) {
                    maxim3 = maxim2;
                    max3=max2;
                    maxim2 = maxim1;
                    max2=max1;
                    max1 = it->second;
                    maxim1 = it->first;
                }else if(it->second>max2){
                    maxim3 = maxim2;
                    max3=max2;
                    max2 = it->second;
                    maxim2 = it->first;
                }
                else if(it->second>max3){
                    max3 = it->second;
                    maxim3 = it->first;
                }
            }
            std::cout<<"position1 "<<maxim1<<"\n";
            std::cout<<"position2 "<<maxim2<<"\n";
            std::cout<<"position3 "<<maxim3<<"\n";
        }
        return formatted_string;
    };
};


#endif
