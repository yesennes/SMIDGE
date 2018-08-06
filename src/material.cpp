#include <regex>
#include <stdexcept>
#include "material.h"

using namespace std;
namespace SMIDGE{
    std::ostream& operator<<(std::ostream& os, const Nuclide& nuclide){
        os.width(2);
        os << (int)(nuclide.element);
        os.width(3);
        os << nuclide.massNumber << '.' << nuclide.libId;
        return os;
    }

    Nuclide::Nuclide(Element e, int massNumber, std::string libId): element(e), massNumber(massNumber), libId(libId){
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

    Material::Material(std::string name, std::pair<Nuclide, double> nuclide){
    }

    Material::Material(std::string name, std::vector<std::pair<Nuclide, double>>& nuclide){
    }

    void Material::setName(std::string name){
    }

    std::string const& Material::getName() const{
    }

    void Material::setDensity(double density){
    }

    double Material::getDensity(){
    }

    void Material::setAtomicDensity(bool atomicDensity){
    }

    bool Material::getAtomicDensity(){
    }

    void Material::setTemperature(double temp){
    }

    double Material::getTempeture(){
    }

    void Material::setTftTemps(double min, double max){
    }

    double Material::getTftMin(){
    }

    double Material::getTftMax(){
    }

    void Material::setColor(int color){
    }

    void Material::setColor(int r, int b, int g){
    }

    int Material::getColor(){
    }

    void Material::setVolume(double volume){
    }

    double Material::getVolume(){
    }

    std::vector<std::pair<Nuclide, double>>& Material::getNuclides(){
    }

    std::vector<std::pair<Nuclide, double>> const& Material::getNuclides(){
    }

    void Material::setNuclides(IteratorT begin, IteratorT end){
    }

    std::string const& getName(Element e){
    }
