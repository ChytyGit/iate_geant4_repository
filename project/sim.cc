#include <G4RunManager.hh>
#include <G4UImanager.hh>
#include <G4VisExecutive.hh>
#include <G4UIExecutive.hh>
#include <DetectorConstruction.hh>
#include <G4VisManager.hh>
#include <PrimaryGenerator.hh>
#include <QBBC.hh>


int main(int argc, char** argv)
{
	G4UIExecutive* ui = 0;
	if (argc == 1) // если запуск по умлочанию (интерактивный режим с 0 аргументов)
	{
		ui = new G4UIExecutive(argc, argv);
	}

	auto runManager = new G4RunManager();

	runManager->SetUserInitialization(new DetectorConstruction()); // подключаем нашу геометрию
	runManager->SetUserInitialization(new QBBC()); // создаём референсный физический лист
	runManager->SetUserAction(new PrimaryGenerator());

	auto visManager = new G4VisExecutive();
	visManager->Initialize();

	G4UImanager* UImanager = G4UImanager::GetUIpointer();
	//runManager->Initialize(); // запускаем саму симуляцию (правильнее: ядро, которое за всё отвечает [отнесено в макрос])

	if(!ui)
	{
		G4String command = "/control/execute ";
		G4String fileName = argv[1]; // читает название .mac файла
		UImanager->ApplyCommand(command + fileName);
	}
	else
	{
		UImanager->ApplyCommand("/control/execute vis.mac"); // сразу запускает vis.mac
		ui->SessionStart();
		delete ui;
	}

	delete runManager; // завершаем работу
	return 0;
}