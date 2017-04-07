//
// Created by admin on 4/7/17.
//

#ifndef G4HELLOWORLD_HWRUNACTION_H
#define G4HELLOWORLD_HWRUNACTION_H


#include <G4UserRunAction.hh>
#include <G4ios.hh>

class HWRunAction : public G4UserRunAction{

public:
    HWRunAction(){};
    virtual ~HWRunAction(){};
    virtual void BeginOfRunAction(const G4Run* ){
        G4cout << "Run begins" << G4endl;
    };
    virtual void EndOfRunAction(const G4Run* ){
        G4cout << "Run ends" << G4endl;
    }

};


#endif //G4HELLOWORLD_HWRUNACTION_H
