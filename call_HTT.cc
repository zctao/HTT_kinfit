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
//#include <LorentzVector.h>
#include <TTree.h>
#include <TFile.h>
#include <map>

#include <Math/LorentzVector.h>
#include <Math/PtEtaPhiM4D.h>
typedef ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<double> > LorentzVector;

// forward declarations
class HadTopKinFit;
HadTopKinFit * kinFit_;

int main(int argc, char* argv[]) {
    srand( time(NULL) );
    /*
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
    */

    Double_t  jet1_pT =  39.856;
    Double_t  jet1_eta = 1.55933;
    Double_t  jet1_phi = 1.84473;
    //Double_t  jet1_e = 99.1138;
    Double_t  jet1_M = 5.51458;
    Double_t  jet2_pT = 37.9869;
    Double_t  jet2_eta = -1.74536;
    Double_t  jet2_phi = -0.858032;
    //Double_t  jet2_e = 112.371;
    Double_t  jet2_M = 7.65134;
    Double_t  jet3_pT = 31.7428;
    Double_t  jet3_eta = 2.21387;
    Double_t  jet3_phi = -0.426758;
    //Double_t  jet3_e = 147.133;
    Double_t  jet3_M = 6.84044;

    kinFit_ = new HadTopKinFit(1, "TF_jets.root");
    LorentzVector recBJet , recWJet1, recWJet2;
    recBJet.SetPt(jet1_pT);
    recBJet.SetEta(jet1_eta);
    recBJet.SetPhi(jet1_phi);
    recBJet.SetM(jet1_M);
    //
    recWJet1.SetPt(jet2_pT);
    recWJet1.SetEta(jet2_eta);
    recWJet1.SetPhi(jet2_phi);
    recWJet1.SetM(jet2_M);
    //
    recWJet2.SetPt(jet3_pT);
    recWJet2.SetEta(jet3_eta);
    recWJet2.SetPhi(jet3_phi);
    recWJet2.SetM(jet3_M);
    //
    std::cout << recBJet.pt() << " " << recWJet1.Pt() << " " << recWJet2.Pt() << std::endl;
    kinFit_->fit(recBJet, recWJet1, recWJet2);
    std::cout << "nll_kinfit             "<< kinFit_->nll() << std::endl;
    std::cout << "b-jets pt after kinfit "<< kinFit_->fittedBJet().Pt() << std::endl;
    delete kinFit_;
    return 0;
}
