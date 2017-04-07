//
// Created by admin on 4/6/17.
//

#ifndef G4HELLOWORLD_HWPRIMARYGENERATORACTION_H
#define G4HELLOWORLD_HWPRIMARYGENERATORACTION_H


#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <G4SIunits.hh>

class HWPrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction {

public:
    HWPrimaryGeneratorAction() {
        G4int n_particle = 3;
        fParticleGun = new G4ParticleGun(n_particle);

        G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
        G4ParticleDefinition* gamma = particleTable -> FindParticle("gamma");

        G4ParticleMomentum momentumDirection = G4ParticleMomentum(0,0,1);
        G4ThreeVector position = G4ThreeVector(1*cm, 2*cm, 3*cm);

        fParticleGun->SetParticleEnergy(60*MeV);
        fParticleGun->SetParticleDefinition(gamma);
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
