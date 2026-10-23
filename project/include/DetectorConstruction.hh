#pragma once // всегда пишем эту строчкку в наших hh-файлах

#include <G4VUserDetectorConstruction.hh> // базовый класс всей геометрии
#include <G4LogicalVolume.hh>
#include <G4VPhysicalVolume.hh>
#include <G4PVPlacement.hh>
#include <G4NistManager.hh> // этот manager отвечает за построение предустановленных материалов.
#include <G4Box.hh> // примитивный параллелепипед
#include <G4Tubs.hh>
#include <G4UnionSolid.hh>
#include <G4SubtractionSolid.hh>
#include <G4IntersectionSolid.hh>
#include <G4VisAttributes.hh>
#include <G4Material.hh>
#include <G4SystemOfUnits.hh> // для работы с СИ (метр, МэВ и др.) и не только.


class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
	DetectorConstruction();
	~DetectorConstruction();

	G4VPhysicalVolume* Construct() override; // главный метод создания геометрии, именно его вызывает runManager

private:
};