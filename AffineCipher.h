#ifndef PRACTICALWORK1_AFFINECIPHER_H
#define PRACTICALWORK1_AFFINECIPHER_H

#include <string>

#include "ChipherParent.h"
#include "GaloisFieldWork.h"

class AthenianCipher : Cipher {
private:
    galois_num al;
    galois_num be;
    std::map <char,float> frequency;

public:

    AthenianCipher(galois_num _al, galois_num _be) {
        al = _al;
        be = _be;
    }

    std::string encode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
//            std::cout<<sym<<'\t'<<get_num(sym)<<'\t'<<'\t'<<get_char(sum(prod(get_num(sym), al), be))<<'\t'<<sum(prod(get_num(sym), al), be)<<'\n';
            res += get_char(sum(prod(get_num(sym), al), be));
        }

        return res;
    };

    std::string decode(const std::string &s) override {
        std::string formatted_string = format_string(s);
        std::string res = "";

        for (char sym : formatted_string) {
//            std::cout<<sym<<'\t'<<get_num(sym)<<'\t'<<'\t'<<get_char(divide(sum(get_num(sym), be), al))<<'\t'<<divide(sum(get_num(sym), be), al)<<'\n';

            res += get_char(divide(sum(get_num(sym), be), al));
        }

        return res;
    }

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
        float max1=0;
        float max2=0;
        char maxim1;
        char maxim2;
        auto it =frequency.begin();
        for (int i = 0; it != frequency.end(); it++) {
//            std::cout<<it->first<<"\t"<<it->second<<"\n";
            if(it->second>max1){
                maxim2=maxim1;
                max2=max1;
                max1=it->second;
                maxim1=it->first;
            }else if(it->second>max2){
                max2 = it->second;
                maxim2 = it->first;
            }
        }
        galois_num cur_pos=get_num(maxim1);
        galois_num cur_pos2=get_num(maxim2);
        std::cout<<"position1 "<<get_num(maxim1)<<"\n";
        std::cout<<"position2 "<<get_num(maxim2)<<"\n";
        galois_num alpha=divide(sum(cur_pos,cur_pos2),sum(4,26));
        galois_num betta=sum(cur_pos,prod(alpha,26));
        std::cout<<"alpha "<<alpha<<"\n";
        std::cout<<"betta "<<betta<<"\n";
        AthenianCipher ans(alpha,betta);
        return ans.decode(formatted_string);
    };
};


#endif
