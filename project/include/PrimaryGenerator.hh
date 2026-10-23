#pragma once

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <G4Electron.hh> // частица-электрон
#include <G4RandomTools.hh>

class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
	PrimaryGenerator();
	~PrimaryGenerator();

	void GeneratePrimaries(G4Event*) override; // главный метод, в котором должна быть определена логика генерации частиц. Его вызывает runManager
private:
	G4ParticleGun* particleGun;
};