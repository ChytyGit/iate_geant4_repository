#include <G4RunManager.hh>

int main(int argv, char** argc)
{
	auto runManager = new G4RunManager();

	runManager->Initialize();

	delete runManager;
	return 0;
}