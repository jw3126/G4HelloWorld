//
// Created by admin on 4/6/17.
//

#ifndef G4HELLOWORLD_HWACTIONINITIALIZATION_H
#define G4HELLOWORLD_HWACTIONINITIALIZATION_H

#include <G4VUserActionInitialization.hh>
#include "HWPrimaryGeneratorAction.h"
#include "HWEventAction.h"
#include "HWSteppingAction.h"

class HWActionInitialization: public G4VUserActionInitialization {

public:
    HWActionInitialization() : G4VUserActionInitialization(){}
    ~HWActionInitialization() {}
    void Build() const {

        SetUserAction(new HWPrimaryGeneratorAction);
        SetUserAction(new HWEventAction);
        SetUserAction(new HWSteppingAction);
        SetUserAction(new HWRunAction);

    }
};


#endif //G4HELLOWORLD_HWACTIONINITIALIZATION_H
