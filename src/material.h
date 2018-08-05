#include "card.h"
#include <vector>
#include <iostream>

namespace SMIDGE{

    enum class Element{
        HYDROGEN,
        HELIUM,
        LITHIUM,
        BERYLLIUM,
        BORON,
        CARBON,
        NITROGEN,
        OXYGEN,
        FLUORINE,
        NEON,
        SODIUM,
        MAGNESIUM,
        ALUMINUM,
        SILICON,
        PHOSPHORUS,
        SULFUR,
        CHLORINE,
        ARGON,
        POTASSIUM,
        CALCIUM,
        SCANDIUM,
        TITANIUM,
        VANADIUM,
        CHROMIUM,
        MANGANESE,
        IRON,
        COBALT,
        NICKEL,
        COPPER,
        ZINC,
        GALLIUM,
        GERMANIUM,
        ARSENIC,
        SELENIUM,
        BROMINE,
        KRYPTON,
        RUBIDIUM,
        STRONTIUM,
        YTTRIUM,
        ZIRCONIUM,
        NIOBIUM,
        MOLYBDENUM,
        TECHNETIUM,
        RUTHENIUM,
        RHODIUM,
        PALLADIUM,
        SILVER,
        CADMIUM,
        INDIUM,
        TIN,
        ANTIMONY,
        TELLURIUM,
        IODINE,
        XENON,
        CESIUM,
        BARIUM,
        LANTHANUM,
        CERIUM,
        PRASEODYMIUM,
        NEODYMIUM,
        PROMETHIUM,
        SAMARIUM,
        EUROPIUM,
        GADOLINIUM,
        TERBIUM,
        DYSPROSIUM,
        HOLMIUM,
        ERBIUM,
        THULIUM,
        YTTERBIUM,
        LUTETIUM,
        HAFNIUM,
        TANTALUM,
        TUNGSTEN,
        RHENIUM,
        OSMIUM,
        IRIDIUM,
        PLATINUM,
        GOLD,
        MERCURY,
        THALLIUM,
        LEAD,
        BISMUTH,
        POLONIUM,
        ASTATINE,
        RADON,
        FRANCIUM,
        RADIUM,
        ACTINIUM,
        THORIUM,
        PROTACTINIUM,
        URANIUM,
        NEPTUNIUM,
        PLUTONIUM,
        AMERICIUM,
        CURIUM,
        BERKELIUM,
        CALIFORNIUM,
        EINSTEINIUM,
        FERMIUM,
        MENDELEVIUM,
        NOBELIUM,
        LAWRENCIUM,
        RUTHERFORDIUM,
        DUBNIUM,
        SEABORGIUM,
        BOHRIUM,
        HASSIUM,
        MEITNERIUM,
        DARMSTADTIUM,
        ROENTGENIUM,
        COPERNICIUM,
        NIHONIUM,
        FLEROVIUM,
        MOSCOVIUM,
        LIVERMORIUM,
        TENNESSINE,
        OGANESSON,
    };

    struct Nuclide{
        Element e;
        int massNumber;
        std::string libId;

        friend std::ostream& operator<<(std::ostream& os, const Nuclide&);
        //Converts from MCNP and Serpent format
        Nuclide(Element e, int massNumber, std::string libId);
        Nuclide(const std::string& from);
    };

    class Material : public Card{
        std::string name;
        //Use -1 to denote sum from nuclide fractions.
        double density;
        //atomicDensity (10^24/cm^3), otherwise mass density (g/cm^3).
        bool atomicDensity;
        //In K, -1 denotes no temperature specified.
        double tempeture;
        //In K, -1 specifies none given. If either is -1, other is ignored
        double tftMin, tftMax;
        //0xRRGGBB
        int color;
        //In cm^3 for 3D, cm^2 for 2D
        double volume;
        //Indicates material should be depleted
        bool burn;
        std::vector<std::pair<Nuclide, double>> nuclides;

        public:
        //Simplest constructor, assumes summing density
        Material(std::string name, std::pair<Nuclide, double> nuclide);
        Material(std::string name, std::vector<std::pair<Nuclide, double>>& nuclide);
        
        void setName(std::string name);
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

        std::vector<std::pair<Nuclide, double>>& getNuclides();
        std::vector<std::pair<Nuclide, double>> const& getNuclides() const;
        template<typename IteratorT>
            void setNuclides(IteratorT begin, IteratorT end);

    };



    std::string const& getName(Element e);

}
