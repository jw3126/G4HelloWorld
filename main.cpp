#include <G4VModularPhysicsList.hh>
#include <QBBC.hh>

#include "HWActionInitialization.h"
#include "HWDetectorConstruction.h"

#include "G4RunManager.hh"


int main() {

    G4RunManager* runManager = new G4RunManager;  // what is there a difference between G4RunManager() and G4RunManager?

    runManager->SetUserInitialization(new QBBC); // physics list must be set before PrimaryActionGenerator
    runManager->SetUserInitialization(new HWDetectorConstruction());
    runManager->SetUserInitialization(new HWActionInitialization());

    runManager->Initialize();
    runManager->BeamOn(1000);

    delete runManager;

    return 0;
}