class Material{
        string name;
        //Use -1 to denote sum from nuclide fractions.
        double density;
        //atomicDensity (10^24/cm^3), otherwise mass density (g/cm^3).
        bool atomicDensity;
        //In K, -1 denotes no temperature specified.
        double temp;
        //In K, -1 specifies none given. If either is -1, other is ignored
        double tftMin, tftMax;
        //0xRRGGBB
        int color;
        //In cm^3 for 3D, cm^2 for 2D
        double volume;
        //Indicates material should be depleted
        bool burn;
    public:
        void setName(string name);
        string getName();
        void setDensity(double density);
        double getDensity();
        void setAtomicDensity(double atomicDensity);
        double getAtomicDensity();

}
