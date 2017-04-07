//
// Created by admin on 4/6/17.
//

#ifndef G4HELLOWORLD_HWDETECTORCONSTRUCTION_H
#define G4HELLOWORLD_HWDETECTORCONSTRUCTION_H


#include <G4VUserDetectorConstruction.hh>

class HWDetectorConstruction: public G4VUserDetectorConstruction {

public:
    HWDetectorConstruction(){};
    ~HWDetectorConstruction(){};

    virtual G4VPhysicalVolume* Construct();
//    virtual void ConstructSDandField() {};

};


#endif //G4HELLOWORLD_HWDETECTORCONSTRUCTION_H
