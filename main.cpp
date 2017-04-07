#include <G4VModularPhysicsList.hh>
#include <QBBC.hh>

#include <G4VisExecutive.hh>
#include <G4UImanager.hh>
#include <G4UIExecutive.hh>

#include "HWActionInitialization.h"
#include "HWDetectorConstruction.h"

#include "G4RunManager.hh"


int main(int argc, char** argv) {
    G4Random::setTheEngine(new CLHEP::RanecuEngine);

    G4RunManager* runManager = new G4RunManager;  // what is there a difference between G4RunManager() and G4RunManager?

    runManager->SetUserInitialization(new HWDetectorConstruction());

    // Physics list
    G4VModularPhysicsList* physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);

    runManager->SetUserInitialization(new HWActionInitialization());

    runManager->Initialize();

    // visualization
    G4UIExecutive* ui = new G4UIExecutive(argc, argv);

    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    G4UImanager* uiManager = G4UImanager::GetUIpointer();

    uiManager->ApplyCommand("/control/execute init.mac");

    ui->SessionStart();
    delete ui;

//    runManager->BeamOn(10);

    delete runManager;

    return 0;
}