#include "stdafx.h"
//#include <thread>
#include "PythonBridge.h"
#include "../Monster/MonsterAction.h"
#include "../Monster/MonsterActionManeger.h"

//#include "../GameData.h"
//#include "../Monster/Monster.h"
Monster* ME = nullptr;

//使用しているMonsterのポジションを返します
static PyObject* GetMyPosition(PyObject* self,PyObject* args)
{
	Monster* mon = nullptr;
	for (Monster* obj : g_mons)
	{
		if (obj->Getnum() == g_meNum)
		{
			mon = obj;
			break;
		}
	}
	PyObject *x, *y, *z;
	x = PyFloat_FromDouble(mon->Getpos().x);
	y = PyFloat_FromDouble(mon->Getpos().y);
	z = PyFloat_FromDouble(mon->Getpos().z);


	PyObject* pos = PyList_New(3);
	PyList_SetItem(pos, 0, x);

	//pos = PyList_New(1);
	PyList_SetItem(pos, 1, y);

	//pos = PyList_New(2);
	PyList_SetItem(pos, 2, z);

	/*Py_DECREF(x);
	Py_DECREF(y);
	Py_DECREF(z);*/

	return pos;
}

static PyObject* GetMyHP(PyObject* self, PyObject* args)
{
	Monster* mon = nullptr;
	for (Monster* obj : g_mons)
	{
		if (obj->Getnum() == g_meNum)
		{
			mon = obj;
			break;
		}
	}
	PyObject* pHP = PyLong_FromLong(mon->GetHP());
	return pHP;
}

static PyObject* GetMyMP(PyObject* self, PyObject* args)
{
	Monster* mon = nullptr;
	for (Monster* obj : g_mons)
	{
		if (obj->Getnum() == g_meNum)
		{
			mon = obj;
			break;
		}
	}
	PyObject* pMP = PyLong_FromLong(mon->GetMP());
	return pMP;
}

static PyObject* GetMyTeam(PyObject* self, PyObject* args)
{
	PyObject* pTeam = PyLong_FromLong(g_meTeam);
	return pTeam;
}

static PyObject* GetMyNum(PyObject* self, PyObject* args)
{
	PyObject* pNum = PyLong_FromLong(g_meNum);
	return pNum;
}

static PyObject* GetAllBuddyPosition(PyObject* self, PyObject* args)
{
	PyObject* poss = PyList_New(g_buddyCount-1);
	int count = 0;
	for (Monster* mon : g_mons)
	{
		if (mon == NULL)
			break;
		if (mon->Getnum() == g_meNum || mon->Getteam() != g_meTeam)
			continue;
		PyObject *x, *y, *z;
		x = PyLong_FromDouble(mon->Getpos().x);
		y = PyLong_FromDouble(mon->Getpos().y);
		z = PyLong_FromDouble(mon->Getpos().z);

		PyObject* pos = PyList_New(3);
		PyList_SetItem(pos, 0, x);

		PyList_SetItem(pos, 1, y);

		PyList_SetItem(pos, 2, z);

		PyList_SetItem(poss, count, pos);
		count++;
	}
	
	return poss;
}

static PyObject* GetAllBuddyNum(PyObject* self, PyObject* args)
{
	PyObject* nums = PyList_New(g_buddyCount-1);
	int count = 0;
	for (Monster* mon : g_mons)
	{
		if (mon == NULL)
			break;
		if (mon->Getnum() == g_meNum || mon->Getteam() != g_meTeam)
			continue;
		PyObject* num = PyLong_FromLong(mon->Getnum());

		PyList_SetItem(nums, count, num);
		count++;
	}

	return nums;
}

static PyObject* GetAllEnemyPosition(PyObject* self, PyObject* args)
{
	PyObject* poss = PyList_New(g_enemyCount);

	int count = 0;
	for (Monster* mon : g_mons)
	{
		if (mon == NULL)
			break;
		if (mon->Getnum() == g_meNum || mon->Getteam() == g_meTeam)
			continue;
		PyObject *x, *y, *z;
		x = PyLong_FromDouble(mon->Getpos().x);
		y = PyLong_FromDouble(mon->Getpos().y);
		z = PyLong_FromDouble(mon->Getpos().z);

		PyObject* pos = PyList_New(3);
		PyList_SetItem(pos, 0, x);

		PyList_SetItem(pos, 1, y);

		PyList_SetItem(pos, 2, z);

		PyList_SetItem(poss, count, pos);
		count++;
	}

	return poss;
}


static PyObject* GetAllEnemyNum(PyObject* self, PyObject* args)
{
	PyObject* nums = PyList_New(g_enemyCount);
	int count = 0;
	for (Monster* mon : g_mons)
	{
		if (mon == NULL)
			break;
		if (mon->Getnum() == g_meNum || mon->Getteam() == g_meTeam)
			continue;
		PyObject* num = PyLong_FromLong(mon->Getnum());

		PyList_SetItem(nums, count, num);
		count++;
	}

	return nums;
}

static PyObject* GetAllEnemyHP(PyObject* self, PyObject* args)
{
	PyObject* pHPs = PyList_New(g_enemyCount);
	int count = 0;
	for (Monster* mon : g_mons)
	{
		if (mon == NULL)
			break;
		if (mon->Getnum() == g_meNum || mon->Getteam() == g_meTeam)
			continue;
		PyObject* num = PyLong_FromLong(mon->GetHP());

		PyList_SetItem(pHPs, count, num);
		count++;
	}
	return pHPs;
}


//仲間の数を返す
static PyObject* GetBuddyCount(PyObject* self, PyObject* args)
{
	PyObject* bc = PyLong_FromLong(g_buddyCount);
	return bc;
}

//エネミーの数を返す
static PyObject* GetEnemyCount(PyObject* self, PyObject* args)
{
	PyObject* ec = PyLong_FromLong(g_enemyCount);
	return ec;
}

PyObject* SetAction(PyObject* self, PyObject* args)
{
	int count = PyTuple_Size(args);
	for (int i = 0; i < count; i++)
	{
		PyObject* tup = PyTuple_GetItem(args,i);
		int tar = PyLong_AsLong(PyTuple_GetItem(tup, 0));
		int act = PyLong_AsLong(PyTuple_GetItem(tup, 0));
		MonsterActionManeger* mam = FindGO<MonsterActionManeger>("MAM");
		ME->AddAction(mam->LoadAction(tar, act));
	}
	return NULL;
}

//module内の関数たち
static PyMethodDef methods[] =
{
	{"GetMyPosition",GetMyPosition,METH_NOARGS,"Jibun no position wo tuple de kaeshi masu."},
	{"GetMyHP",GetMyHP,METH_NOARGS,"Jibun no HP wo kaeshi masu."},
	{"GetMyMP",GetMyMP,METH_NOARGS,"Jibun no MP wo kaeshi masu."},
	{"GetMyTeam",GetMyTeam,METH_NOARGS,"Jibun no Team wo kaeshi masu."},
	{"GetMyNum",GetMyNum,METH_NOARGS,"Jibun no num wo kaeshi masu."},

	{"GetAllBuddyPosition",GetAllBuddyPosition,METH_NOARGS,"Nakama zenin no position wo kaeshi masu."},
	{"GetAllBuddyNum",GetAllBuddyNum,METH_NOARGS,"Nakama zenin no num wo kaeshi masu."},

	{"GetAllEnemyPosition",GetAllEnemyPosition,METH_NOARGS,"Teki zenin no position wo kaeshi masu."},
	{"GetAllEnemyNum",GetAllEnemyNum,METH_NOARGS,"Teki zenin no num wo kaeshi masu."},
	{"GetAllEnemyHP",GetAllEnemyHP,METH_NOARGS,"Teki zenin no HP wo kaeshi masu."},

	{"GetBuddyCount",GetBuddyCount,METH_NOARGS,"mikata no kazu wo kaeshi masu."},
	{"GetEnemyCount",GetEnemyCount,METH_NOARGS,"teki no kazu wo kaeshi masu."},
	{"SetAction",SetAction,METH_VARARGS,"action wo settei simasu"},
	{NULL,NULL,0,NULL}
};

//module 本体
static PyModuleDef pModule =
{
	PyModuleDef_HEAD_INIT,
	"SendGame",
	NULL,
	-1,
	methods,
	NULL,
	NULL,
	NULL,
	NULL
};

//moduleの初期化
static PyObject* initModule(void)
{
	return PyModule_Create(&pModule);
}


PythonBridge::PythonBridge()
{
	mam = FindGO<MonsterActionManeger>("MAM");
}

void PythonBridge::Update()
{/*
	for (int i = 0;i < threads.size();i++)
	{
		if (comp[i])
		{
			threads[i]->detach();
			auto ite = std::find(threads.begin(), threads.end(), threads[i]);
			threads.erase(ite);
		}
	}*/
	if (pTS != nullptr && end)
	{
		PyEval_RestoreThread(pTS);
		////PyEval_ReleaseThread(pTS);
		//Py_Finalize();
		end = false;
	}
}

void PythonBridge::pbInit()
{
	
	int count = 0;
	QueryGOs<Monster>("monster", [&](Monster* obj)->bool
	{
		g_mons[count] = obj;
		count++;
		return true;
	});
	for (int i = 1; i < count; i++)
	{
		for (int j = 1; j < count; j++)
		{
			if (g_mons[j]->Getteam() > g_mons[i]->Getteam())
			{
				Monster* mon = g_mons[j];
				g_mons[j] = g_mons[i];
				g_mons[i] = mon;
			}
		}
	}
}

bool py_exe(int num, int team, const char* file)
{
	std::unique_ptr<std::thread> th = nullptr;
	th.reset(new std::thread([&]
	{
		MonsterActionManeger* mam = FindGO<MonsterActionManeger>("MAM");
		if (file == NULL)
			return;
		g_meNum = num;
		g_meTeam = team;
		g_buddyCount = 0;
		g_enemyCount = 0;
		Monster* me;
		QueryGOs<Monster>("monster", [&](Monster* obj)->bool
		{
			if (obj->Getnum() == num)
				me = obj;

			if (obj->Getteam() == team)
			{
				g_buddyCount++;
			}
			else
			{
				g_enemyCount++;
			}
			return true;
		});

		SetCurrentDirectory("Python36");

		PyImport_AppendInittab("SendGame", initModule);

		PyObject *pName, *pModule, *pFunction, *pArgs, *pValue;

		Py_Initialize();
		pName = PyUnicode_DecodeFSDefault(file);
		pModule = PyImport_Import(pName);
		Py_DECREF(pName);
		pFunction = PyObject_GetAttrString(pModule, "Brain");
		pArgs = PyTuple_New(0);
		pValue = PyObject_CallObject(pFunction, pArgs);
		Py_DECREF(pModule);
		Py_DECREF(pFunction);

		int vl = PyList_Size(pValue);
		if (vl == 0)
		{
			Py_DECREF(pValue);
			SetCurrentDirectory("../");
			Py_Finalize();
			return;
		}
		//std::vector<int[2]> actions;
		for (int i = 0; i < vl; i++)
		{
			int action[2];
			action[0] = PyLong_AsLong(PyList_GetItem(PyList_GetItem(pValue, i), 0));
			action[1] = PyLong_AsLong(PyList_GetItem(PyList_GetItem(pValue, i), 1));
			me->AddAction(mam->LoadAction(action[0], action[1]));
		}

		Py_DECREF(pValue);

		SetCurrentDirectory("../");
		Py_Finalize();
	}));
	return true;
}

//pythonを実行するゾ。
void PythonBridge::py_exe(int num,int team,const char* file)
{
	g_meNum = num;
	g_meTeam = team;
	g_buddyCount = 0;
	g_enemyCount = 0;
	Monster* me;
	QueryGOs<Monster>("monster", [&](Monster* obj)->bool
	{
		if (obj->Getnum() == num)
			me = obj;

		if (obj->Getteam() == team)
		{
			g_buddyCount++;
		}
		else
		{
			g_enemyCount++;
		}
		return true;
	});

	SetCurrentDirectory("Python36");

	/*PyImport_AppendInittab("SendGame", initModule);
	Py_InitializeEx(1);*/

	PyEval_InitThreads();

	th.reset(new std::thread([=]
	{
		PyGILState_STATE GILState;
		GILState = PyGILState_Ensure();
	

	PyObject *pName, *pModule, *pFunction, *pArgs, *pValue;
	
	//pName = PyUnicode_DecodeFSDefault(file);
	pName = PyUnicode_DecodeFSDefault("PythonAIs.Threader");
	pModule = PyImport_Import(pName);
	Py_DECREF(pName);

	pFunction = PyObject_GetAttrString(pModule, "execute");
	//pFunction = PyObject_GetAttrString(pModule, "Brain");

	pArgs = PyTuple_New(3);
	PyObject* pMenum = PyLong_FromLong(num);
	PyObject* pMeteam = PyLong_FromLong(team);
	PyObject* pFile = PyUnicode_FromString(file);
	PyTuple_SetItem(pArgs, 0, pMenum);
	PyTuple_SetItem(pArgs, 1, pMeteam);
	PyTuple_SetItem(pArgs, 2, pFile);

	pValue = PyObject_CallObject(pFunction, pArgs);

	//char* c = PyUnicode_AsUTF8(pValue);

	Py_DECREF(pArgs);
	Py_DECREF(pModule);
	Py_DECREF(pFunction);

	

	if (pValue == NULL)
	{
		SetCurrentDirectory("../");
		//Py_Finalize();
		
		end = true;
		return;
	}
	else
	{
		
		Py_DECREF(pValue);
		PyGILState_Release(GILState);
		SetCurrentDirectory("../");
		
		end = true;
		return;
	}
	int vl = PyList_Size(pValue);
	if (vl == 0)
	{
		Py_DECREF(pValue);
		SetCurrentDirectory("../");
		//Py_Finalize();
		end = true;
		return;
	}

	for (int i = 0; i < vl; i++)
	{
		int action[2];
		action[0] = PyLong_AsLong(PyList_GetItem(PyList_GetItem(pValue, i), 0));
		action[1] = PyLong_AsLong(PyList_GetItem(PyList_GetItem(pValue, i), 1));
		me->AddAction(mam->LoadAction(action[0], action[1]));
	}

	Py_DECREF(pValue);

	SetCurrentDirectory("../");

	//Py_Finalize();
	end = true;
	}));

	pTS = PyEval_SaveThread();
	//Py_Finalize();
}

void PythonBridge::AddExe(int num, int team, const char * file)
{
	ExeData ed = { num,team,file };
	m_exeDatalist.push_back(ed);
}

void PythonBridge::py_exe()
{
}

Pyinit::Pyinit()
{
	PyImport_AppendInittab("SendGame", initModule);
	Py_InitializeEx(1);
}

Pyinit::~Pyinit()
{
	Py_Finalize();
}
