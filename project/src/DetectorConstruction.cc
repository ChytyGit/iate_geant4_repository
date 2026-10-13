#include <DetectorConstruction.hh> // здесь мы подключаем наш интерфейс

DetectorConstruction::DetectorConstruction() {}
DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume*  DetectorConstruction::Construct()
{
	G4NistManager* nistManager = G4NistManager::Instance(); // про материпы позже
	G4Material* worldMat = nistManager->FindOrBuildMaterial("G4_Galactic");

	G4double worldLength = 0.5 * m; // для каждой геометрии лучше отдельно указывать все размеры
									// такой способ позволяет держать структуру и быстро изменять в случае надобности
	G4double worldWidth = worldLength;
	G4double worldHigh = worldLength;

	G4Box* worldSolid = new G4Box("worldSolid", worldLength, worldWidth, worldHigh); // Создаём SolidVolume. Названия должны согласоваться с объектом, т. е.
																					 // для мирового объёма всё начинаем на world и добавляем тип объёма
	G4LogicalVolume* worldLogical = new G4LogicalVolume(worldSolid, worldMat, "worldLogical"); //Создаём LogicalVolume
	G4VPhysicalVolume* worldPhysical = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), "worldPhysical", worldLogical, 0, false, 0); // Создаём PhysicalVolume

	G4VisAttributes* worldAtt = new G4VisAttributes();
	worldAtt->SetVisibility(false); // Делаем мировой куб невидимым, если нужна видимость, то меняем на true
	worldLogical->SetVisAttributes(worldAtt);


	// =======Объединение объёмов=======
	//G4Box* box = new G4Box("Box", 4 * cm, 4 * cm, 4 * cm);
	//G4LogicalVolume* boxLogical = new G4LogicalVolume(box, worldMat, "boxLogical");
	//G4Tubs* cylinder = new G4Tubs("Cylinder", 0. * cm, 5. * cm, 5. * cm, 0., 2 * CLHEP::pi);
	//G4UnionSolid* unionSolid = new G4UnionSolid("unionSolid", box, cylinder, 0, G4ThreeVector(0., 0., 2. * cm)); // здесь "box" - главный объём, cylinder - вторичный.
	//																											  // это значит, что cylinder ставится в координатах относительно box	
	//G4LogicalVolume* unionLogical = new G4LogicalVolume(unionSolid, worldMat, "unionLogical");
	//G4VPhysicalVolume* unionPhysical = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), unionLogical, "unionPhysical", worldLogical, false, 0, false);
	// =================================
	
	// =======Вычитание объёмов=======
	//G4Box* box = new G4Box("Box", 4 * cm, 4 * cm, 4 * cm);
	//G4LogicalVolume* boxLogical = new G4LogicalVolume(box, worldMat, "boxLogical");
	//G4Tubs* cylinder = new G4Tubs("Cylinder", 0. * cm, 5. * cm, 5. * cm, 0., 2 * CLHEP::pi);
	//G4SubtractionSolid* substractionSolid = new G4SubtractionSolid("unionSolid", box, cylinder, 0, G4ThreeVector(0., 0., 2. * cm)); // как и в случае сложение box - главыный, cylinder - вторичный
	//																																// соответственно, вычитаем из box
	//G4LogicalVolume* substractionLogical = new G4LogicalVolume(substractionSolid, worldMat, "unionLogical");
	//G4VPhysicalVolume* substractionPhysical = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), substractionLogical, "unionPhysical", worldLogical, false, 0, false);
	// ===============================

	// =======Пересечение объёмов=======
	G4Box* box = new G4Box("Box", 4 * cm, 4 * cm, 4 * cm);
	G4LogicalVolume* boxLogical = new G4LogicalVolume(box, worldMat, "boxLogical");
	G4Tubs* cylinder = new G4Tubs("Cylinder", 0. * cm, 5. * cm, 5. * cm, 0., 2 * CLHEP::pi);
	G4IntersectionSolid* intersectionSolid = new G4IntersectionSolid("unionSolid", box, cylinder, 0, G4ThreeVector(0., 0., 2. * cm)); // объединяем два объёма
	G4LogicalVolume* intersectionLogical = new G4LogicalVolume(intersectionSolid, worldMat, "unionLogical");
	G4VPhysicalVolume* intersectionPhysical = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), intersectionLogical, "unionPhysical", worldLogical, false, 0, false);
	// =================================
	return worldPhysical;
}