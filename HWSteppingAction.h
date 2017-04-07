//
// Created by admin on 4/7/17.
//

#ifndef G4HELLOWORLD_HWSTEPPINGACTION_H
#define G4HELLOWORLD_HWSTEPPINGACTION_H

#include <G4UserSteppingAction.hh>
#include <G4ios.hh>
#include <G4SIunits.hh>
#include "G4Step.hh"

class HWSteppingAction : public G4UserSteppingAction {

public:
    HWSteppingAction(){};
    ~HWSteppingAction(){};

    virtual void UserSteppingAction(const G4Step* aStep){
        G4double edepStep = aStep->GetTotalEnergyDeposit();
        G4Track* track = aStep -> GetTrack();
        const G4DynamicParticle* particle = track -> GetDynamicParticle();


        G4cout << "aStep" << G4endl;
        G4cout << "edep/MeV " << edepStep/MeV << G4endl;
        G4cout << aStep -> GetDeltaPosition()/mm << G4endl;

        //particle->DumpInfo(1);
    }

};


#endif //G4HELLOWORLD_HWSTEPPINGACTION_H
