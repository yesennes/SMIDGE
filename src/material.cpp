#include <regex>
#include <stdexcept>
#include "material.h"

using namespace std;
namespace SMIDGE{
    std::ostream& operator<<(std::ostream& os, const Nuclide& nuclide){
        streamsize originalWidth = os.width();
        char originalFill = os.fill();
        os.width(2);
        os << (int)(nuclide.element) + 1;
        os.width(3);
        os.fill('0');
        os << nuclide.massNumber << '.' << nuclide.libId;
        os.width(originalWidth);
        os.fill(originalFill);
        return os;
    }

    Nuclide::Nuclide(Element e, int massNumber, const std::string& libId): element(e), massNumber(massNumber), libId(libId){
    }

    Nuclide::Nuclide(const std::string& from){
        static regex pat("\\s*(\\d{1,3})(\\d{3})\\.(\\w*)");
        smatch res;
        if(!regex_match(from, res, pat)){
            throw invalid_argument(from + " is not a valid Nuclide");
        }
        element = (Element)stoi(res[1]);
        massNumber = stoi(res[2]);
        libId = res[3];
    }

    Material::Material(const std::string& name, const std::pair<Nuclide, double>& nuclide):
        name(name), density(-1), atomicDensity(true), temperature(-1), tftMin(-1), tftMax(-1), color(-1), volume(-1), burn(false){
        nuclides.push_back(nuclide);
    }

    Material::Material(const std::string& name, const std::vector<std::pair<Nuclide, double>>& nuclides)
        : name(name), density(-1), atomicDensity(true), temperature(-1), tftMin(-1),
        tftMax(-1), color(-1), volume(-1), burn(false), nuclides(nuclides){
    }

    void Material::setName(const std::string& name){
        this->name = name;
    }

    std::string const& Material::getName() const{
        return name;
    }

    void Material::setDensity(double density){
        this->density = density;
    }

    double Material::getDensity() const{
        return density;
    }

    void Material::setAtomicDensity(bool atomicDensity){
        this->atomicDensity = atomicDensity;
    }

    bool Material::getAtomicDensity() const{
        return atomicDensity;
    }

    void Material::setTemperature(double temp){
        this->temperature = temp;
    }

    double Material::getTempeture() const{
        return temperature;
    }

    void Material::setTftTemps(double min, double max){
        tftMin = min;
        tftMax = max;
    }

    double Material::getTftMin() const{
        return tftMin;
    }

    double Material::getTftMax() const{
        return tftMax;
    }

    void Material::setColor(int color){
        this->color = color;
    }

    void Material::setColor(int r, int b, int g){
        this->color = r << 16 | b << 8 | g;
    }

    int Material::getColor() const{
        return color;
    }

    void Material::setVolume(double volume){
        this->volume = volume;
    }

    std::string Material::toSerpentCard() const{
        stringstream ret;
        ret << "mat " << name << " ";
        if(density != -1){
            if(!atomicDensity)
                ret << "-";
            ret << density;
        } else
            ret << "sum";
        int indentLen = ret.str().length() + 1;
        stringstream spaces;
        for(int i = 0; i < indentLen; i++)
            spaces << " ";
        string indent = spaces.str();
        if(temperature != -1)
            ret << " temp " << temperature;
        if(tftMax != -1 && tftMin != -1)
            ret << endl << indent << "tft " << tftMin << " " << tftMax;
        if(color != -1)
            ret << endl << indent << "rgb " << (color >> 16)
                << " " << ((color >> 8) & 0xff) << " " << (color & 0xff);
        if(volume != -1)
            ret << endl << indent << "vol "  << volume;
        if(burn)
            ret << endl << indent << "burn " << 1;
        for(const pair<Nuclide, double>& nuclide : nuclides){
            ret << endl << nuclide.first << " " << nuclide.second;
        }
        return ret.str();
    }

    std::string Material::toMCNPCard() const{
        //TODO write function
        return "";
    }

    void Material::setBurn(bool burn){
        this->burn = burn;
    }

    bool Material::getBurn() const{
        return burn;
    }

    double Material::getVolume() const{
        return volume;
    }

    std::vector<std::pair<Nuclide, double>>& Material::getNuclides(){
        return nuclides;
    }

    std::vector<std::pair<Nuclide, double>> const& Material::getNuclides() const{
        return nuclides;
    }

    template<typename IteratorT> void Material::setNuclides(IteratorT begin, IteratorT end){
        nuclides = vector<pair<Nuclide, double>>(begin, end);
    }

    std::string const& getName(Element e){
        static string elements[] = {
            "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen",
            "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon",
            "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium",
            "Titanium", "Vanadium", "Chromium", "Manganese", "Iron", "Cobalt", "Nickel",
            "Copper", "Zinc", "Gallium", "Germanium", "Arsenic", "Selenium", "Bromine",
            "Krypton", "Rubidium", "Strontium", "Yttrium", "Zirconium", "Niobium", "Molybdenum",
            "Technetium", "Ruthenium", "Rhodium", "Palladium", "Silver", "Cadmium", "Indium",
            "Tin", "Antimony", "Tellurium", "Iodine", "Xenon", "Cesium", "Barium", "Lanthanum",
            "Cerium", "Praseodymium", "Neodymium", "Promethium", "Samarium", "Europium", "Gadolinium",
            "Terbium", "Dysprosium", "Holmium", "Erbium", "Thulium", "Ytterbium", "Lutetium",
            "Hafnium", "Tantalum", "Tungsten", "Rhenium", "Osmium", "Iridium", "Platinum",
            "Gold", "Mercury", "Thallium", "Lead", "Bismuth", "Polonium", "Astatine",
            "Radon", "Francium", "Radium", "Actinium", "Thorium", "Protactinium", "Uranium",
            "Neptunium", "Plutonium", "Americium", "Curium", "Berkelium", "Californium", "Einsteinium",
            "Fermium", "Mendelevium", "Nobelium", "Lawrencium", "Rutherfordium", "Dubnium",
            "Seaborgium", "Bohrium", "Hassium", "Meitnerium", "Darmstadtium", "Roentgenium",
            "Copernicium", "Nihonium", "Flerovium", "Moscovium", "Livermorium", "Tennessine",
            "Oganesson"
        };
        return elements[(int)e];
    }
}
