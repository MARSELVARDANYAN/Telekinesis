
#include <iostream>


//----------------------------------------------------------------------//
//base
struct MTI
{
    std::string type_name = "MUSICANT";
    std::string bases{};
}mti;

//1
struct BTI
{
private:
    std::string type_name = "Bagpipes";
    std::string bases = "MUSICANT";
}bti;

//2
struct CTI
{
private:
    std::string type_name = "Clarinet";
    std::string bases = "MUSICANT";
}cti;

//3
struct STI
{
private:
    std::string type_name = "Saxophone";
    std::string bases = "MUSICANT";
}sti;

//4
struct FTI
{
private:
    std::string type_name = "Flute";
    std::string bases = "MUSICANT";
}fti;

//5
struct GTI
{
private:
    std::string type_name = "Grand_piano";
    std::string bases = "MUSICANT";
}gti;

//6
struct ATI
{
private:
    std::string type_name = "Accordion";
    std::string bases = "MUSICANT";
}ati;

//7
struct VTI
{
private:
    std::string type_name = "Violin";
    std::string bases = "MUSICANT";
}vti;

//8
struct GUTI
{
private:
    std::string type_name = "Guitar";
    std::string bases = "MUSICANT";
}guti;


//-------------------------------------------------------------------------//
//base 
struct MVtbl
{
    MTI* type_info = &mti;
    //void(*pl)() = &MUSICANT::play;
}mvtbl;

//1
struct BVtbl
{
    BTI* type_info = &bti;
    //void(*pl)() = &Bagpipes::play;
    
}bvtbl;

//2
struct CVtbl
{
    CTI* type_info = &cti;
    //void(*pl)() = &Clarinet::play;
}cvtbl;

//3
struct SVtbl
{
    STI* type_info = &sti;
    //void(*pl)() = &Saxophone::play;
}svtbl;

//4
struct FVtbl
{
    FTI* type_info = &fti;
    //void(*pl)() = &Flute::play;
}fvtbl;

//5
struct GVtbl
{
    GTI* type_info = &gti;
    //void(*pl)() = &Grand_piano::play;
}gvtbl;

//6
struct AVtbl
{
    ATI* type_info = &ati;
    //void(*pl)() = &Accordion::play;
}avtbl;

//7
struct VVtbl
{
    VTI* type_info = &vti;
    //void(*pl)() = &Violin::play;
}vvtbl;

//8
struct GUVtbl
{
    GUTI* type_info = &guti;
    //void(*pl)() = &Guitar::play;
}guvtbl;


//Base struct
struct MUSICANT
{   
    static void play()
    {
        std::cout << "Musicant" << std::endl;
    }
    MVtbl* vptr = &mvtbl;   
};

// 1
struct Bagpipes :MUSICANT
{
    static void play()
    {
        std::cout << "Bagpipes is playing" << std::endl;
    }
    BVtbl* vptr = &bvtbl;
};

//2
struct Clarinet :MUSICANT
{
    static void play()
    {
        std::cout << "Clarinet is playing" << std::endl;
    }
    CVtbl* vptr = &cvtbl;
};

//3
struct Saxophone :MUSICANT
{
    static void play()
    {
        std::cout << "Saxophone is playing" << std::endl;
    }
    SVtbl* vptr = &svtbl;
};

//4
struct Flute :MUSICANT
{
    static void play()
    {
        std::cout << "Flute is playing" << std::endl;
    }
    FVtbl* vptr = &fvtbl;
};

//5
struct Grand_piano :MUSICANT
{
    static void play()
    {
        std::cout << "Grand_piano is playing" << std::endl;
    }
    GVtbl* vptr = &gvtbl;
};

//6
struct Accordion :MUSICANT
{
    static void play()
    {
        std::cout << "Accordion is playing" << std::endl;
    }
    AVtbl* vptr = &avtbl;
};

//7
struct Violin :MUSICANT
{
    static void play()
    {
        std::cout << "Violin is playing" << std::endl;
    }
    VVtbl* vptr = &vvtbl;
};

//8
struct Guitar : MUSICANT
{
    static void play()
    {
        std::cout << "Guitar is playing" << std::endl;
    }
    GUVtbl* vptr = &guvtbl;
};



void leader(auto* ob)
{
    ob->play();
}




