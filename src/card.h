#include <string>
//Class that represents something that directly translates to a card
//in MCNP or Serpent. 
class Card{
    public:
        virtual std::string toSerpentCard() = 0;
        virtual std::string toMCNPCard() = 0;
};
