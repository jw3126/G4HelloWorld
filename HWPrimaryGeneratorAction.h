//
// Created by admin on 4/6/17.
//

#ifndef G4HELLOWORLD_HWPRIMARYGENERATORACTION_H
#define G4HELLOWORLD_HWPRIMARYGENERATORACTION_H

// don't use the SI Units header file!

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"

#include "globals.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

class HWPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction {

public:
    HWPrimaryGeneratorAction(): G4VUserPrimaryGeneratorAction(){
        G4int n_particle = 1;
        fParticleGun = new G4ParticleGun(n_particle);

        G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
        G4ParticleDefinition* gamma = particleTable -> FindParticle("gamma");

        G4ParticleMomentum momentumDirection = G4ParticleMomentum(1,0,0);
        G4ThreeVector position = G4ThreeVector(-1*m, 0, 0);

        fParticleGun->SetParticleDefinition(gamma);
        fParticleGun->SetParticleEnergy(7*MeV);
        fParticleGun->SetParticleMomentumDirection(momentumDirection);
        fParticleGun->SetParticlePosition(position);
    }

    ~HWPrimaryGeneratorAction() {delete fParticleGun;}

    void GeneratePrimaries(G4Event* anEvent) {
        fParticleGun->GeneratePrimaryVertex(anEvent);
    }

private:
    G4ParticleGun* fParticleGun;

};


#endif //G4HELLOWORLD_HWPRIMARYGENERATORACTION_H
