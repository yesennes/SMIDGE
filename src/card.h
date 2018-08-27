#ifndef CARD_H
#define CARD_H
#include <string>
//Class that represents something that directly translates to a card
//in MCNP or Serpent. 
class Card{
    public:
        virtual std::string toSerpentCard() const = 0;
        virtual std::string toMCNPCard() const = 0;
};
#endif
