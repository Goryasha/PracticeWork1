
#include <iostream>
#include "SimpleReplacementCipher.h"
#include "AffineCipher.h"
#include "AffineRecurrentCipher.h"
#include "CaesarCiphr.h"

int main() {
//    AthenianCipher c(15,20);
//    CaesarCipher c(7);
    RecurrentCipher c(4,10,5,7);
//    SimpleReplacement c("hijklmnopqrstuvwxyz -',:.abcdefg");
    std::cout <<"encode\n";
    std::cout << c.encode("Let's imagine ...You're watching TV. It's a hot evening: You feel thirsty. You see an advert for a refreshing drink. You see people looking cool and relaxed. You notice the name of the refreshing drink because you think it could be useful for you to satisfy your thirst.")<< "\n";
    std::cout <<"decode\n";
    std::cout << c.decode(c.encode("Let's imagine ...You're watching TV. It's a hot evening: You feel thirsty. You see an advert for a refreshing drink. You see people looking cool and relaxed. You notice the name of the refreshing drink because you think it could be useful for you to satisfy your thirst.")) << "\n";
    std::cout <<"analysis\n";
    std::cout << c.analysis(c.encode("Let's imagine ...You're watching TV. It's a hot evening: You feel thirsty. You see an advert for a refreshing drink. You see people looking cool and relaxed. You notice the name of the refreshing drink because you think it could be useful for you to satisfy your thirst.")) << "\n";

}

//c.encode("Let's imagine ...You're watching TV. It's a hot evening: You feel thirsty. You see an advert for a refreshing drink. You see people looking cool and relaxed. You notice the name of the refreshing drink because you think it could be useful for you to satisfy your thirst.")
//c.encode("Children start school at the age of five, but there is some free nursery-school education before that age. The state nursery schools are not for all. They are for some families, for example for families with only one parent. In most areas there are private nursery schools. Parents who want their children to go to nursery school pay for their children under years old to go to these private nursery schools.")