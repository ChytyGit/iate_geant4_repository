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

	// ========Равномерное распределение по телесному углу=========
	//G4double thetaMax = 20. * CLHEP::deg;
	//G4double cosThetaMax = std::cos(thetaMax);

	//G4double cosTheta = cosThetaMax + (1. - cosThetaMax) * G4UniformRand();
	//G4double sinTheta = std::sqrt(1. - cosTheta * cosTheta);
	//G4double phi = CLHEP::twopi * G4UniformRand();

	//G4double dX = sinTheta * std::cos(phi);
	//G4double dY = sinTheta * std::sin(phi);
	//G4double dZ = cosTheta;
	// =============================================================
	
	// вектор направления генерации
	G4double dX = 0.;
	G4double dY = 0.;
	G4double dZ = 1.;

	// создание вектора направления
	// если норма вектора не 1, то Geant4 автоматически его нормализует (направление останется неизменным)
	G4ThreeVector momentumDir(dX, dY, dZ);

	particleGun->SetParticleMomentumDirection(momentumDir);

	// один из способов задания вида частицы
	particleGun->SetParticleDefinition(G4Electron::ElectronDefinition());

	particleGun->GeneratePrimaryVertex(anEvent); // для генерации частиц необходимо вызвать метод, который СОЗДАЁТ наше событие (запуск частицы)
}