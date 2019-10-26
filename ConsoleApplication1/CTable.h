#pragma once
#include <iostream>
#include <string>

using namespace std;

class CTable{

public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable& pcOther);
	CTable* pcClone();
	~CTable();

	void vShowName();
	void vShowSize();
	void vSetName(string sName);
	bool bSetNewSize(int iTableLen);
	void v_mod_tab(CTable* pcTab, int iNewSize);
	void v_mod_tab(CTable cTab, int iNewSize);

private:

	string s_name;
	int i_size;
	int* piTable;
	
	const int SIZE = 10;
	const string NAME = "Name";
};