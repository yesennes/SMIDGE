#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>
#include "material.h"
#include <iostream>

using namespace std;

namespace SMIDGE{
    BOOST_AUTO_TEST_CASE(materialTest) {
        pair<Nuclide, double> forMat1(Nuclide(Element::URANIUM, 235, "03c"), 1);
        Material mat1("Mat1", forMat1);
        string card = mat1.toSerpentCard();
        const char test[] =  "mat Mat1 sum\n92235.03c 1";
        BOOST_CHECK_EQUAL(card,test);

        vector<pair<Nuclide, double>> mat2Nucl;
        mat2Nucl.push_back(pair<Nuclide, double>(Nuclide(Element::PLUTONIUM, 55, "03c"), .73));
        mat2Nucl.push_back(pair<Nuclide, double>(Nuclide(Element::HYDROGEN, 2, "06c"), .27));
        Material mat2("Mat2", mat2Nucl);
        mat2.setDensity(56.9);
        mat2.setTemperature(500.4);
        mat2.setColor(0x123456);
        mat2.setBurn(true);
        string card2 = mat2.toSerpentCard();
        const char test2[] = "mat Mat2 56.9 temp 500.4\n              rgb 18 52 86\n              burn 1\n94055.03c 0.73\n 1002.06c 0.27";
        BOOST_CHECK_EQUAL(card2, test2);

        Material mat3("Mats3", pair<Nuclide, double>(Nuclide(Element::MENDELEVIUM, 235, "09c"), 1));
        mat3.getNuclides().push_back(pair<Nuclide, double>(Nuclide(Element::LITHIUM, 50, "bad"), 2));
        mat3.setDensity(70);
        mat3.setAtomicDensity(false);
        mat3.setTftTemps(30.5, 40);
        mat3.setVolume(99.9);
        BOOST_CHECK_EQUAL(mat3.toSerpentCard(), "mat Mats3 -70\n              tft 30.5 40\n              vol 99.9\n101235.09c 1\n 3050.bad 2");
    }
}
