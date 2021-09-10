#pragma once
#include "ClassFlowImage.h"
#include "ClassFlowAlignment.h"

enum t_CNNType {
    AutoDetect,
    Analogue,
    Digital,
    DigitalHyprid,
    None
 };

struct roi {
    int posx, posy, deltax, deltay;
    float result;
    int resultklasse;
    string name;
    CImageBasis *image, *image_org;
};

struct general {
    string name;
    std::vector<roi*> ROI;
};


class ClassFlowCNNGeneral :
    public ClassFlowImage
{
protected:
    t_CNNType CNNType;
    std::vector<general*> GENERAL;

    string cnnmodelfile;
    int modelxsize, modelysize;
    bool isLogImageSelect;
    string LogImageSelect;
    ClassFlowAlignment* flowpostalignment;
    bool SaveAllFiles;   
    bool extendedResolution;

    int ZeigerEval(float zahl, int ziffer_vorgaenger);

    bool doNeuralNetwork(string time); 
    bool doAlignAndCut(string time);

public:
    ClassFlowCNNGeneral(ClassFlowAlignment *_flowalign, t_CNNType _cnntype = AutoDetect);

    bool ReadParameter(FILE* pfile, string& aktparamgraph);
    bool doFlow(string time);

    string getHTMLSingleStep(string host);
    string getReadout(int _analog);   

    void DrawROI(CImageBasis *_zw); 

   	std::vector<HTMLInfo*> GetHTMLInfo();   

    int AnzahlROIs(int _analog);
    int getAnzahlGENERAL();
    general* GetGENERAL(int _analog);
    general* GetGENERAL(string _name, bool _create);
    general* FindGENERAL(string _name_number);    
    string getNameGENERAL(int _analog);    

    bool isExtendedResolution(int _number); 

    void UpdateNameNumbers(std::vector<std::string> *_name_numbers);

    t_CNNType getCNNType(){return CNNType;};

    string name(){return "ClassFlowCNNGeneral";}; 
};
