#pragma once
//すべての船のデータはここで保存して置きます
class ShipData
{
public:
	ShipData();
	~ShipData();

private:
	int CrashPartsCount;
	int CrashPartX;
	int CrashPartZ;
};

