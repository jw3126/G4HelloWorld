//
// Created by admin on 4/7/17.
//

#ifndef G4HELLOWORLD_HWEVENTACTION_H
#define G4HELLOWORLD_HWEVENTACTION_H


#include <G4UserEventAction.hh>
#include "HWRunAction.h"

class HWEventAction : public G4UserEventAction{

public:
    HWEventAction() {}
    ~HWEventAction() {}

    virtual void BeginOfEventAction(const G4Event* ){
        G4cout << "begin of event" << G4endl;
    };

    virtual void EndOfEventAction(const G4Event* ) {
        G4cout << "end of event" << G4endl;
    };


};


#endif //G4HELLOWORLD_HWEVENTACTION_H
