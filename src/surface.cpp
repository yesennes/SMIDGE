#include "surface.h"
#include <sstream>
using namespace std;

namespace SMIDGE{
    Surface::Surface(const std::string& name) : name(name){
    }

    std::string const& Surface::getName() const{
        return name;
    }

    void Surface::setName(const std::string& name){
        this->name = name;
    }

    std::string Surface::toSerpentCard() const{
        stringstream s;
        s << "surf " << getName() << " " << getSurfaceType();
        vector<double> params;
        for(double d : getParams(params))
            s << " " << d;
        return s.str();
    }

    std::string Surface::toMCNPCard() const{
        //TODO
        return "";
    }
}
