//////////////////
// to run:
// cmsenv in any CMSSW 7X or +
// make call_HTT
// ./call_HTT
/////////////////
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "HadTopKinFit.h" // HadTopKinFit
#include <TLorentzVector.h>
#include <TTree.h>
#include <TFile.h>
#include <map>

// forward declarations
class HadTopKinFit;
HadTopKinFit * kinFit_;

int main(int argc, char* argv[]) {
    srand( time(NULL) );
    Double_t  jet1_px = 267.332;
    Double_t  jet1_py = -528.941;
    Double_t  jet1_pz = -854.402;
    Double_t  jet1_E = 1047.32;
    Double_t  jet2_px = -8.45553;
    Double_t  jet2_py = 19.6435;
    Double_t  jet2_pz = -28.823;
    Double_t  jet2_E = 130.05;
    Double_t  jet3_px = 303.292;
    Double_t  jet3_py = -140.964;
    Double_t  jet3_pz = -331.144;
    Double_t  jet3_E = 486.969;
    kinFit_ = new HadTopKinFit(1, "TF_jets.root");
    TLorentzVector recBJet, recWJet1, recWJet2;
    recBJet.SetPxPyPzE(jet1_px, jet1_py, jet1_pz, jet1_E);
    recWJet1.SetPxPyPzE(jet2_px, jet2_py, jet2_pz, jet2_E);
    recWJet2.SetPxPyPzE(jet3_px, jet3_py, jet3_pz, jet3_E);
    std::cout << recBJet.Pt()<< " " << recWJet1.Pt() << " " << recWJet2.Pt() << std::endl;
    kinFit_->fit(recBJet, recWJet1, recWJet2);
    std::cout << "nll_kinfit             "<< kinFit_->nll() << std::endl;
    std::cout << "b-jets pt after kinfit "<< kinFit_->fittedBJet().Pt() << std::endl;
    delete kinFit_;
    return 0;
}
