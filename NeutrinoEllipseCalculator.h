// C++ implementation of arXiv:1305.1872
// Analytic solutions for neutrino momenta in decay of top quarks
// Gala Nicolas Kaufman (gnn4@cornell.edu)

#include <memory>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

#include <TMatrix.h>
#include <TMatrixD.h>
#include <TMatrixDEigen.h>
#include <TArrayD.h>
#include <TMath.h>
#include "Math/VectorUtil.h"
#include "Math/GenVector/LorentzVector.h"
#include "TLorentzVector.h"
#include "DataFormats/Math/interface/LorentzVector.h"

#include "Math/RootFinderAlgorithms.h"
#include "Math/Polynomial.h"

using namespace std;
using namespace ROOT::Math;

class NeutrinoEllipseCalculator{

 private:
  //inputs: lepton and b-jet momenta
  //TLorentzVector bJet_;
  //TLorentzVector lepton_;
  math::XYZTLorentzVector *bJet_;
  math::XYZTLorentzVector *lepton_;

  double   bJetBeta_,   bJetBeta2_,   bJetGamma_,   bJetGamma2_;
  double leptonBeta_, leptonBeta2_, leptonGamma_, leptonGamma2_;

  //particle masses
  double mW_, mt_, mnu_;
  double mW2_, mt2_, mnu2_;

  //parameters
  double x0_, x0p_;
  double Sx_, Sy_;
  double epsilon2_;

  double c_, s_; //cosine and sine of theta_{b,mu}

  double omega_;
  double Omega_;
  double x1_, y1_;
  double Z2_;

  //matrices
  TMatrixD *Ab_;
  TMatrixD *Al_;

  TMatrixD *Htilde_;
  TMatrixD *H_;
  TMatrixD *Hperp_;

  TMatrixD *Nperp_;

  double bJetSF_;

  void setBJetRelativisticFactors();
  void setLeptonRelativisticFactors();

  void setAngles();

  void initializeMatrices();

  TMatrixD rotationMatrix(int, double);

  void Wsurface();
  void bJetEllipsoid();
  void leptonEllipsoid();
  void neutrinoSolution();
  void labSystemTransform();

  void calcNeutrinoEllipse();

 public:
  NeutrinoEllipseCalculator();
  //NeutrinoEllipseCalculator(TLorentzVector& , TLorentzVector& , double& , double& , double& );
  //NeutrinoEllipseCalculator(math::XYZTLorentzVector& , math::XYZTLorentzVector& , double& , double& , double& );
  NeutrinoEllipseCalculator(double , double , double , double , double , double , double , double , double& , double& , double& );
  ~NeutrinoEllipseCalculator();

  //void setbJet(const TLorentzVector& );
  //void setLepton(const TLorentzVector& );
  //void setbJet(const math::XYZTLorentzVector& );
  //void setLepton(const math::XYZTLorentzVector& );
  void setBJet(const double , const double, const double , const double );
  void setLepton(const double , const double, const double , const double );

  void setTopMass(double& mTop){ mt_=mTop; };
  void setWBosonMass(double& mW){ mW_=mW; };
  void setNeutrinoMass(double& mNu){ mnu_=mNu; };
  void setMasses(double& , double& , double& );
  
  TMatrixD getNeutrinoEllipse();
  TMatrixD getHomogeneousNeutrinoEllipse();
  
  void calcBJetCorrection();

  void print3By3Matrix(const TMatrixD& m);
  void print4By4Matrix(const TMatrixD& m);

};
