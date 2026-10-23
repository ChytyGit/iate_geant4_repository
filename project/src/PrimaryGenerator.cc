#include <PrimaryGenerator.hh>

PrimaryGenerator::PrimaryGenerator() 
{
	particleGun = new G4ParticleGun(1); // принимает либо только кол-во ПЕРВИЧНЫХ частиц за ОДНО СОБЫТИЕ, либо с заданием частицы 
}

PrimaryGenerator::~PrimaryGenerator() { delete particleGun; }

void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent)
{
	// координаты источника
	G4double X = 0.;
	G4double Y = 0.;
	G4double Z = 0.;

	// создание вектора координат источника
	G4ThreeVector pos(X, Y, Z);

	particleGun->SetParticlePosition(pos);

	// вектор направления генерации
	G4double dX = 0.;
	G4double dY = 0.;
	G4double dZ = 1.;

	// создание вектора направления
	G4ThreeVector momentumDir(dX, dY, dZ);

	particleGun->SetParticleMomentumDirection(momentumDir);

	// один из способов задания вида частицы
	particleGun->SetParticleDefinition(G4Electron::ElectronDefinition());

	particleGun->GeneratePrimaryVertex(anEvent); // для генерации частиц необходимо вызвать метод, который СОЗДАЁТ наше событие (запуск частицы)
}