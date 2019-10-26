#include <iostream>
#include <string>
#include "CTable.h"

using namespace std;

CTable::CTable() {

	s_name = NAME;
	cout << "bezp: " << s_name << endl;
	piTable = new int[SIZE];
	i_size = SIZE;

}

CTable::CTable(string sName, int iTableLen) {

	this->vSetName(sName);
	cout << "parametr: " << sName << endl;
	this->bSetNewSize(iTableLen);

}

CTable::CTable(const CTable& pcOther) {

	s_name = pcOther.s_name + "_copy";
	i_size = pcOther.i_size;
	piTable = new int[i_size];
	for (int i = 0; i < pcOther.i_size; i++) {
		piTable[i] = pcOther.piTable[i];
	}
	cout << "kopiujacy: " << s_name << endl;

}

CTable::~CTable() {

	cout << "usuwam " << s_name << endl;
	delete piTable;

}

void CTable::vSetName(string sName) {

	s_name = sName;

}

bool CTable::bSetNewSize(int iTableLen) {

	if (iTableLen <= 0 && this->piTable != nullptr) {
		cout << "Nie mozliwe stworzyc CTable z dlugoscia mniej lub rownym 0" << endl;
		return false;
	}

	int* pi_newTable = new int[iTableLen];
	if (this->i_size <= iTableLen) {
		for (int i = 0; i < this->i_size; i++) {
			pi_newTable[i] = this->piTable[i];
		}
	}
	else {
		for (int i = 0; i < iTableLen; i++) {
			pi_newTable[i] = this->piTable[i];
		}
	}
	delete piTable;
	this->i_size = iTableLen;
	this->piTable = pi_newTable;
	return true;

}

CTable* CTable::pcClone() {

	CTable* ct = new CTable(s_name, i_size);
	for (int i = 0; i < ct->i_size; i++) {
		ct->piTable[i] = this->piTable[i];
	}
	return ct;

}

void CTable::vShowName() {

	cout << "Name: " << s_name << endl;

}

void CTable::vShowSize() {

	cout << "Size: " << i_size << endl;

}

void CTable::v_mod_tab(CTable* pcTab, int iNewSize) {

	pcTab->bSetNewSize(iNewSize);

}

void CTable::v_mod_tab(CTable cTab, int iNewSize) {

	cTab.bSetNewSize(iNewSize);

}
