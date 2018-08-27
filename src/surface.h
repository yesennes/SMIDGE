#include <vector>
#include "card.h"

namespace SMIDGE{
    class Surface : public Card{
        std::string name;

        public:
        Surface(const std::string& name);

        void setName(const std::string& name);
        std::string const& getName() const;

        virtual std::string toSerpentCard() const;
        virtual std::string toMCNPCard() const;

        virtual std::string getSurfaceType() const = 0;
        virtual std::vector<double>& getParams(std::vector<double>& toFill) const = 0;
    };
}
