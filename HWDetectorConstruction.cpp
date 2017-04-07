//
// Created by admin on 4/6/17.
//
#include "G4Box.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "HWDetectorConstruction.h"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

#include "G4RunManager.hh"

G4VPhysicalVolume* HWDetectorConstruction::Construct() {

    // materials
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* mediumWorld = nist -> FindOrBuildMaterial("G4_WATER");

    // geometry
    G4double x = 1.;
    G4double y = 2.;
    G4double z = 3.;
    G4Box* solidWorld = new G4Box("solidWorld", x,y,z);
    G4LogicalVolume* logicalWorld = new G4LogicalVolume(solidWorld, mediumWorld, "logicalWorld");

    G4RotationMatrix* pRot = NULL;
    const G4ThreeVector& tlate = G4ThreeVector();
    G4LogicalVolume* pCurrentLogical = logicalWorld;
    const G4String& pName = "physicalWorld";
    G4LogicalVolume* pMotherLogical = NULL;
    G4bool pMany = false; // boolean solid?
    G4int pCopyNo = 0;  // multiple copies of volume in physical world?
    const G4bool pSurfChk = true;  // check overlaps?

    G4VPhysicalVolume* physicalWorld =
            new G4PVPlacement(pRot,
                              tlate,
                              pCurrentLogical,
                              pName,
                              pMotherLogical,
                              pMany,
                              pCopyNo,
                              pSurfChk);

    return physicalWorld;
}