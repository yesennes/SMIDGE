#include "card.h"
#include <vector>
#include <iostream>

namespace SMIDGE{

    enum class Element{
        HYDROGEN, HELIUM, LITHIUM, BERYLLIUM, BORON, CARBON, NITROGEN, OXYGEN,
        FLUORINE, NEON, SODIUM, MAGNESIUM, ALUMINUM, SILICON, PHOSPHORUS, SULFUR,
        CHLORINE, ARGON, POTASSIUM, CALCIUM, SCANDIUM, TITANIUM, VANADIUM, CHROMIUM,
        MANGANESE, IRON, COBALT, NICKEL, COPPER, ZINC, GALLIUM, GERMANIUM, ARSENIC,
        SELENIUM, BROMINE, KRYPTON, RUBIDIUM, STRONTIUM, YTTRIUM, ZIRCONIUM, NIOBIUM,
        MOLYBDENUM, TECHNETIUM, RUTHENIUM, RHODIUM, PALLADIUM, SILVER, CADMIUM,
        INDIUM, TIN, ANTIMONY, TELLURIUM, IODINE, XENON, CESIUM, BARIUM, LANTHANUM,
        CERIUM, PRASEODYMIUM, NEODYMIUM, PROMETHIUM, SAMARIUM, EUROPIUM, GADOLINIUM,
        TERBIUM, DYSPROSIUM, HOLMIUM, ERBIUM, THULIUM, YTTERBIUM, LUTETIUM, HAFNIUM,
        TANTALUM, TUNGSTEN, RHENIUM, OSMIUM, IRIDIUM, PLATINUM, GOLD, MERCURY, THALLIUM,
        LEAD, BISMUTH, POLONIUM, ASTATINE, RADON, FRANCIUM, RADIUM, ACTINIUM, THORIUM,
        PROTACTINIUM, URANIUM, NEPTUNIUM, PLUTONIUM, AMERICIUM, CURIUM, BERKELIUM, CALIFORNIUM,
        EINSTEINIUM, FERMIUM, MENDELEVIUM, NOBELIUM, LAWRENCIUM, RUTHERFORDIUM, DUBNIUM,
        SEABORGIUM, BOHRIUM, HASSIUM, MEITNERIUM, DARMSTADTIUM, ROENTGENIUM, COPERNICIUM,
        NIHONIUM, FLEROVIUM, MOSCOVIUM, LIVERMORIUM, TENNESSINE, OGANESSON,
    };

    struct Nuclide{
        Element element;
        int massNumber;
        std::string libId;

        friend std::ostream& operator<<(std::ostream& os, const Nuclide& nuclide);
        //Converts from MCNP and Serpent format
        Nuclide(Element e, int massNumber, const std::string& libId);
        explicit Nuclide(const std::string& from);
    };

    class Material : public Card{
        std::string name;
        //Where not specified, defaults to -1
        //Use -1 to denote sum from nuclide fractions.
        double density;
        //atomic density (10^24/cm^3), otherwise mass density (g/cm^3). Defaults to atomic
        bool atomicDensity;
        //In K, -1 denotes no temperature specified.
        double temperature;
        //In K, -1 specifies none given. If either is -1, other is ignored
        double tftMin, tftMax;
        //0xRRGGBB. -1 for none
        int color;
        //In cm^3 for 3D, cm^2 for 2D. -1 for none given
        double volume;
        //Indicates material should be depleted. Defaults to false
        bool burn;
        std::vector<std::pair<Nuclide, double>> nuclides;

        public:
        //Simplest constructor, assumes summing density
        Material(const std::string& name, const std::pair<Nuclide, double>& nuclide);
        Material(const std::string& name, const std::vector<std::pair<Nuclide, double>>& nuclide);
        
        void setName(const std::string& name);
        std::string const& getName() const;

        void setDensity(double density);
        double getDensity() const;

        void setAtomicDensity(bool atomicDensity);
        bool getAtomicDensity() const;
        
        void setTemperature(double temp);
        double getTempeture() const;

        void setTftTemps(double min, double max);

        double getTftMin() const;
        double getTftMax() const;

        void setColor(int color);
        void setColor(int r, int b, int g);

        int getColor() const;

        void setVolume(double volume);
        double getVolume() const;

        void setBurn(bool burn);
        bool getBurn() const;

        std::vector<std::pair<Nuclide, double>>& getNuclides();
        const std::vector<std::pair<Nuclide, double>>& getNuclides() const;
        template<typename IteratorT> void setNuclides(IteratorT begin, IteratorT end);

        virtual std::string toSerpentCard() const;
        virtual std::string toMCNPCard() const;
    };

    std::string const& getName(Element e);
}
