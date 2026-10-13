#include <G4RunManager.hh>
#include <G4UImanager.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <DetectorConstruction.hh>
#include <G4VisManager.hh>
#include <QBBC.hh>


int main(int argc, char** argv)
{
	G4UIExecutive* ui = new G4UIExecutive(argc, argv);

	auto runManager = new G4RunManager();
	auto visManager = new G4VisExecutive();

	runManager->SetUserInitialization(new DetectorConstruction()); // подключаем нашу геометрию
	runManager->SetUserInitialization(new QBBC());

	visManager->Initialize();
	runManager->Initialize(); // запускаем саму симуляцию (правильнее: ядро, которое за всё отвечает)

	G4UImanager* UImanager = G4UImanager::GetUIpointer();
	UImanager->ApplyCommand("/vis/open OGL 600x600");
	UImanager->ApplyCommand("/vis/drawVolume");

	ui->SessionStart();

	delete runManager; // завершаем работу
	return 0;
}