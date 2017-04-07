//
// Created by admin on 4/6/17.
//

#ifndef G4HELLOWORLD_HWACTIONINITIALIZATION_H
#define G4HELLOWORLD_HWACTIONINITIALIZATION_H

#include <G4VUserActionInitialization.hh>
#include "HWPrimaryGeneratorAction.h"

class HWActionInitialization: public G4VUserActionInitialization {

public:
    HWActionInitialization() : G4VUserActionInitialization(){}
    ~HWActionInitialization() {}
    void Build() const {
        SetUserAction(new HWPrimaryGeneratorAction());
    }
};


#endif //G4HELLOWORLD_HWACTIONINITIALIZATION_H
