#pragma once


enum MonsterID;

struct InitMonsData
{
	int AI;
	MonsterID monID;
};

class StageSetup
{
public:
	StageSetup();
	~StageSetup();
	static void PVPSetup(std::vector<std::string> files,int monsterAI[6],MonsterID monids[6]);
	
private:

};