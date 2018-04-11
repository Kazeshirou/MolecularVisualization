#include "atom.h"

Atom::Atom(const QString &elem, const QVector3D &position) :
    Sphere(getRadii(elem),getColor(elem),position),
    m_elem(elem)
{

}

float Atom::getRadii(QString elem)
{
    static std::map<QString, double> elemToRadii;
    if (elemToRadii.size() == 0)
    {
          // http://www.imb-jena.de/ImgLibDoc/glossary/IMAGE_VDWR.html
          elemToRadii["F"]= 	1.47f;
          elemToRadii["CL"]= 	1.89f;
          // http://www.umass.edu/microbio/rasmol/rasbonds.htm
          elemToRadii["H"]=   1.100f;
          elemToRadii["C"]=   1.548f;
          elemToRadii["N"]=   1.400f;
          elemToRadii["O"]=   1.348f;
          elemToRadii["P"]=   1.880f;
          elemToRadii["S"]= 	1.808f;
          elemToRadii["CA"]= 	1.948f;
          elemToRadii["FE"]= 	1.948f;
          elemToRadii["ZN"]= 	1.148f;
          elemToRadii["I"]= 	1.748f;
    }
    double rad = elemToRadii[elem];
    int l = elem.length();
    while ((rad == 0) && (l > 0))
    {
        elem.remove(l--,1);
        rad = elemToRadii[elem];
    }
    if (rad == 0)
        rad = 1.5;
    return rad;
}

QColor Atom::getColor(QString elem)
{
    static std::map<QString, QRgb> elemToColor;
    if(elemToColor.size()==0)
    {
        elemToColor["H"] = /*[255,255,255]*/ 0xFFFFFF  	/* 0xFFFFFF			*/  	;
        elemToColor["HE"]= /*[217,255,255]*/ 0xFFC0CB  	/* 0xD9FFFF			*/  	;
        elemToColor["LI"]= /*[204,128,255]*/ 0xB22222  	/* 0xCC80FF			*/  	;
        elemToColor["BE"]= /*[194,255,  0]*/ 0xFF1493  	/* 0xC2FF00			*/  	;
        elemToColor["B"] = /*[255,181,181]*/ 0x00FF00  	/* 0xFFB5B5			*/  	;
        elemToColor["C"] = /*[144,144,144]*/ 0x808080  	/* 0x909090			*/  	;
        elemToColor["N"] = /*[ 48, 80,248]*/ 0x8F8FFF  	/* 0x3050F8			*/  	;
        elemToColor["O"] = /*[255, 13, 13]*/ 0xF00000  	/* 0xFF0D0D			*/  	;
        elemToColor["F"] = /*[144,224, 80]*/ 0xDAA520  	/* 0x90E050			*/  	;
        elemToColor["NE"]= /*[179,227,245]*/ 0xFF1493  	/* 0xB3E3F5			*/  	;
        elemToColor["NA"]= /*[171, 92,242]*/ 0x0000FF  	/* 0xAB5CF2			*/  	;
        elemToColor["MG"]= /*[138,255,  0]*/ 0x228B22  	/* 0x8AFF00			*/  	;
        elemToColor["AL"]= /*[191,166,166]*/ 0x808090  	/* 0xBFA6A6			*/  	;
        elemToColor["SI"]= /*[240,200,160]*/ 0xDAA520  	/* 0xF0C8A0			*/  	;
        elemToColor["P"] = /*[255,128,  0]*/ 0xFFA500  	/* 0xFF8000			*/  	;
        elemToColor["S"] = /*[255,255, 48]*/ 0xFFC832  	/* 0xFFFF30			*/  	;
        elemToColor["CL"]= /*[ 31,240, 31]*/ 0x00FF00  	/* 0x1FF01F			*/  	;
        elemToColor["AR"]= /*[128,209,227]*/ 0xFF1493  	/* 0x80D1E3			*/  	;
        elemToColor["K"] = /*[143, 64,212]*/ 0xFF1493  	/* 0x8F40D4			*/  	;
        elemToColor["CA"]= /*[ 61,255,  0]*/ 0x808090  	/* 0x3DFF00			*/  	;
        elemToColor["SC"]= /*[230,230,230]*/ 0xFF1493  	/* 0xE6E6E6			*/  	;
        elemToColor["TI"]= /*[191,194,199]*/ 0x808090  	/* 0xBFC2C7			*/  	;
        elemToColor["V"] = /*[166,166,171]*/ 0xFF1493  	/* 0xA6A6AB			*/  	;
        elemToColor["CR"]= /*[138,153,199]*/ 0x808090  	/* 0x8A99C7			*/  	;
        elemToColor["MN"]= /*[156,122,199]*/ 0x808090  	/* 0x9C7AC7			*/  	;
        elemToColor["FE"]= /*[224,102, 51]*/ 0xFFA500  	/* 0xE06633			*/  	;
        elemToColor["CO"]= /*[240,144,160]*/ 0xFF1493  	/* 0xF090A0			*/  	;
        elemToColor["NI"]= /*[ 80,208, 80]*/ 0xA52A2A  	/* 0x50D050			*/  	;
        elemToColor["CU"]= /*[200,128, 51]*/ 0xA52A2A  	/* 0xC88033			*/  	;
        elemToColor["ZN"]= /*[125,128,176]*/ 0xA52A2A  	/* 0x7D80B0			*/  	;
        elemToColor["GA"]= /*[194,143,143]*/ 0xFF1493  	/* 0xC28F8F			*/  	;
        elemToColor["GE"]= /*[102,143,143]*/ 0xFF1493  	/* 0x668F8F			*/  	;
        elemToColor["AS"]= /*[189,128,227]*/ 0xFF1493  	/* 0xBD80E3			*/  	;
        elemToColor["SE"]= /*[255,161,  0]*/ 0xFF1493  	/* 0xFFA100			*/  	;
        elemToColor["BR"]= /*[166, 41, 41]*/ 0xA52A2A  	/* 0xA62929			*/  	;
        elemToColor["KR"]= /*[ 92,184,209]*/ 0xFF1493  	/* 0x5CB8D1			*/  	;
        elemToColor["RB"]= /*[112, 46,176]*/ 0xFF1493  	/* 0x702EB0			*/  	;
        elemToColor["SR"]= /*[  0,255,  0]*/ 0xFF1493  	/* 0x00FF00			*/  	;
        elemToColor["Y"] = /*[148,255,255]*/ 0xFF1493  	/* 0x94FFFF			*/  	;
        elemToColor["ZR"]= /*[148,224,224]*/ 0xFF1493  	/* 0x94E0E0			*/  	;
        elemToColor["NB"]= /*[115,194,201]*/ 0xFF1493  	/* 0x73C2C9			*/  	;
        elemToColor["MO"]= /*[ 84,181,181]*/ 0xFF1493  	/* 0x54B5B5			*/  	;
        elemToColor["TC"]= /*[ 59,158,158]*/ 0xFF1493  	/* 0x3B9E9E			*/  	;
        elemToColor["RU"]= /*[ 36,143,143]*/ 0xFF1493  	/* 0x248F8F			*/  	;
        elemToColor["RH"]= /*[ 10,125,140]*/ 0xFF1493  	/* 0x0A7D8C			*/  	;
        elemToColor["PD"]= /*[  0,105,133]*/ 0xFF1493  	/* 0x006985			*/  	;
        elemToColor["AG"]= /*[192,192,192]*/ 0x808090  	/* 0xC0C0C0			*/  	;
        elemToColor["CD"]= /*[255,217,143]*/ 0xFF1493  	/* 0xFFD98F			*/  	;
        elemToColor["IN"]= /*[166,117,115]*/ 0xFF1493  	/* 0xA67573			*/  	;
        elemToColor["SN"]= /*[102,128,128]*/ 0xFF1493  	/* 0x668080			*/  	;
        elemToColor["SB"]= /*[158, 99,181]*/ 0xFF1493  	/* 0x9E63B5			*/  	;
        elemToColor["TE"]= /*[212,122,  0]*/ 0xFF1493  	/* 0xD47A00			*/  	;
        elemToColor["I"] = /*[148,  0,148]*/ 0xA020F0  	/* 0x940094			*/  	;
        elemToColor["XE"]= /*[ 66,158,176]*/ 0xFF1493  	/* 0x429EB0			*/  	;
        elemToColor["CS"]= /*[ 87, 23,143]*/ 0xFF1493  	/* 0x57178F			*/  	;
        elemToColor["BA"]= /*[  0,201,  0]*/ 0xFFA500  	/* 0x00C900			*/  	;
        elemToColor["LA"]= /*[112,212,255]*/ 0xFF1493  	/* 0x70D4FF			*/  	;
        elemToColor["CE"]= /*[255,255,199]*/ 0xFF1493  	/* 0xFFFFC7			*/  	;
        elemToColor["PR"]= /*[217,255,199]*/ 0xFF1493  	/* 0xD9FFC7			*/  	;
        elemToColor["ND"]= /*[199,255,199]*/ 0xFF1493  	/* 0xC7FFC7			*/  	;
        elemToColor["PM"]= /*[163,255,199]*/ 0xFF1493  	/* 0xA3FFC7			*/  	;
        elemToColor["SM"]= /*[143,255,199]*/ 0xFF1493  	/* 0x8FFFC7			*/  	;
        elemToColor["EU"]= /*[ 97,255,199]*/ 0xFF1493  	/* 0x61FFC7			*/  	;
        elemToColor["GD"]= /*[ 69,255,199]*/ 0xFF1493  	/* 0x45FFC7			*/  	;
        elemToColor["TB"]= /*[ 48,255,199]*/ 0xFF1493  	/* 0x30FFC7			*/  	;
        elemToColor["DY"]= /*[ 31,255,199]*/ 0xFF1493  	/* 0x1FFFC7			*/  	;
        elemToColor["HO"]= /*[  0,255,156]*/ 0xFF1493  	/* 0x00FF9C			*/  	;
        elemToColor["ER"]= /*[  0,230,117]*/ 0xFF1493  	/* 0x00E675			*/  	;
        elemToColor["TM"]= /*[  0,212, 82]*/ 0xFF1493  	/* 0x00D452			*/  	;
        elemToColor["YB"]= /*[  0,191, 56]*/ 0xFF1493  	/* 0x00BF38			*/  	;
        elemToColor["LU"]= /*[  0,171, 36]*/ 0xFF1493  	/* 0x00AB24			*/  	;
        elemToColor["HF"]= /*[ 77,194,255]*/ 0xFF1493  	/* 0x4DC2FF			*/  	;
        elemToColor["TA"]= /*[ 77,166,255]*/ 0xFF1493  	/* 0x4DA6FF			*/  	;
        elemToColor["W"] = /*[ 33,148,214]*/ 0xFF1493  	/* 0x2194D6			*/  	;
        elemToColor["RE"]= /*[ 38,125,171]*/ 0xFF1493  	/* 0x267DAB			*/  	;
        elemToColor["OS"]= /*[ 38,102,150]*/ 0xFF1493  	/* 0x266696			*/  	;
        elemToColor["IR"]= /*[ 23, 84,135]*/ 0xFF1493  	/* 0x175487			*/  	;
        elemToColor["PT"]= /*[208,208,224]*/ 0xFF1493  	/* 0xD0D0E0			*/  	;
        elemToColor["AU"]= /*[255,209, 35]*/ 0xDAA520  	/* 0xFFD123			*/  	;
        elemToColor["HG"]= /*[184,184,208]*/ 0xFF1493  	/* 0xB8B8D0			*/  	;
        elemToColor["TL"]= /*[166, 84, 77]*/ 0xFF1493  	/* 0xA6544D			*/  	;
        elemToColor["PB"]= /*[ 87, 89, 97]*/ 0xFF1493  	/* 0x575961			*/  	;
        elemToColor["BI"]= /*[158, 79,181]*/ 0xFF1493  	/* 0x9E4FB5			*/  	;
        elemToColor["PO"]= /*[171, 92,  0]*/ 0xFF1493  	/* 0xAB5C00			*/  	;
        elemToColor["AT"]= /*[117, 79, 69]*/ 0xFF1493  	/* 0x754F45			*/  	;
        elemToColor["RN"]= /*[ 66,130,150]*/ 0xFF1493  	/* 0x428296			*/  	;
        elemToColor["FR"]= /*[ 66,  0,102]*/ 0xFF1493  	/* 0x420066			*/  	;
        elemToColor["RA"]= /*[  0,125,  0]*/ 0xFF1493  	/* 0x007D00			*/  	;
        elemToColor["AC"]= /*[112,171,250]*/ 0xFF1493  	/* 0x70ABFA			*/  	;
        elemToColor["TH"]= /*[  0,186,255]*/ 0xFF1493  	/* 0x00BAFF			*/  	;
        elemToColor["PA"]= /*[  0,161,255]*/ 0xFF1493  	/* 0x00A1FF			*/  	;
        elemToColor["U"] = /*[  0,143,255]*/ 0xFF1493  	/* 0x008FFF			*/  	;
        elemToColor["NP"]= /*[  0,128,255]*/ 0xFF1493  	/* 0x0080FF			*/  	;
        elemToColor["PU"]= /*[  0,107,255]*/ 0xFF1493  	/* 0x006BFF			*/  	;
        elemToColor["AM"]= /*[ 84, 92,242]*/ 0xFF1493  	/* 0x545CF2			*/  	;
        elemToColor["CM"]= /*[120, 92,227]*/ 0xFF1493  	/* 0x785CE3			*/  	;
        elemToColor["BK"]= /*[138, 79,227]*/ 0xFF1493  	/* 0x8A4FE3			*/  	;
        elemToColor["CF"]= /*[161, 54,212]*/ 0xFF1493  	/* 0xA136D4			*/  	;
        elemToColor["ES"]= /*[179, 31,212]*/ 0xFF1493  	/* 0xB31FD4			*/  	;
        elemToColor["FM"]= /*[179, 31,186]*/ 0xFF1493  	/* 0xB31FBA			*/  	;
        elemToColor["MD"]= /*[179, 13,166]*/ 0xFF1493  	/* 0xB30DA6			*/  	;
        elemToColor["NO"]= /*[189, 13,135]*/ 0xFF1493  	/* 0xBD0D87			*/  	;
        elemToColor["LR"]= /*[199,  0,102]*/ 0xFF1493  	/* 0xC70066			*/  	;
        elemToColor["RF"]= /*[204,  0, 89]*/ 0xFF1493  	/* 0xCC0059			*/  	;
        elemToColor["DB"]= /*[209,  0, 79]*/ 0xFF1493  	/* 0xD1004F			*/  	;
        elemToColor["SG"]= /*[217,  0, 69]*/ 0xFF1493  	/* 0xD90045			*/  	;
        elemToColor["BH"]= /*[224,  0, 56]*/ 0xFF1493  	/* 0xE00038			*/  	;
        elemToColor["HS"]= /*[230,  0, 46]*/ 0xFF1493  	/* 0xE6002E			*/  	;
        elemToColor["MT"]= /*[235,  0, 38]*/ 0xFF1493  	/* 0xEB0026			*/  	;
    }

    QRgb color = elemToColor[elem];
    int l = elem.length();
    while ((color == 0) && (l > 0))
    {
        //  printf("color 0 for %s\n",ss0.c_str());
        elem.remove(l--,1);
        color = elemToColor[elem];
    }

    return QColor(color+0xff000000);
}
