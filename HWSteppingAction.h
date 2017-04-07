//
// Created by admin on 4/7/17.
//

#ifndef G4HELLOWORLD_HWSTEPPINGACTION_H
#define G4HELLOWORLD_HWSTEPPINGACTION_H

#include <G4UserSteppingAction.hh>
#include <G4ios.hh>
#include "G4Step.hh"
#include "G4StepPoint.hh"

#define show(arg) {G4cout << #arg << " = " << (arg) << G4endl;}

class HWSteppingAction : public G4UserSteppingAction {

public:
    HWSteppingAction():G4UserSteppingAction(){};
    virtual ~HWSteppingAction(){};
    virtual void UserSteppingAction(const G4Step* step){
        step->GetTrack()->GetDynamicParticle()->DumpInfo(1);
    }

};


#endif //G4HELLOWORLD_HWSTEPPINGACTION_H
