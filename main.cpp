#include <G4VModularPhysicsList.hh>
#include <QBBC.hh>

#include "HWActionInitialization.h"
#include "HWDetectorConstruction.h"

#include "G4RunManager.hh"


int main() {
    G4Random::setTheEngine(new CLHEP::RanecuEngine);

    G4RunManager* runManager = new G4RunManager;  // what is there a difference between G4RunManager() and G4RunManager?

    runManager->SetUserInitialization(new HWDetectorConstruction());

    // Physics list
    G4VModularPhysicsList* physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);

    runManager->SetUserInitialization(new HWActionInitialization());


    runManager->Initialize();
    runManager->BeamOn(10);

    delete runManager;

    return 0;
}