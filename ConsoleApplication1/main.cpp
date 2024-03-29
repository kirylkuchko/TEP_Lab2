#include <iostream>
#include <string>
#include "CTable.h"

int main(){

	CTable CTableBezp;
	CTable CTableParam("Parametyzowana tablica 1", 7);
	CTable CTableKop(CTableParam);
	cout << "_____________________________________Stworzone CTable____________________________________" << endl;
	CTableBezp.vShowName();
	CTableBezp.vShowSize();
	CTableParam.vShowName();
	CTableParam.vShowSize();
	CTableKop.vShowName();
	CTableKop.vShowSize();
	cout << "__________________________Modyfikacja CTable zwyklymi metodami___________________________" << endl;
	CTableParam.vSetName("Parametyzowana tablica 2");
	CTableParam.bSetNewSize(8);
	CTableParam.vShowName();
	CTableParam.vShowSize();
	CTableKop.vShowName();
	CTableKop.vShowSize();
	cout << "__________________________Klonowanie CTable za pomoca pcClone____________________________" << endl;
	CTable* CTableNew = CTableParam.pcClone();
	CTableParam.vShowName();
	CTableParam.vShowSize();
	CTableNew->vShowName();
	CTableNew->vShowSize();
	cout << "Sprawdzenie razacznosci ojektow CTable:" << endl;
	CTableParam.vSetName("Parametyzowana tablica 3");
	CTableParam.bSetNewSize(9);
	CTableNew->vSetName("Tablica pcClone");
	CTableParam.vShowName();
	CTableParam.vShowSize();
	CTableNew->vShowName();
	CTableNew->vShowSize();
	cout << "__________________________Modyfikacja CTable metodaj v_mod_tab___________________________" << endl;
	cout << "Pszed modyfikacjej:" << endl;
	CTableNew->vShowName();
	CTableNew->vShowSize();
	cout << "Zmeniamy dlugosc CTable na 10" << endl;
	cout << "Po modyfikacji metody v_mod_tab(CTable* pcTab, int iNewSize):"<<endl;
	CTableBezp.v_mod_tab(CTableNew, 10);
	CTableNew->vShowName();
	CTableNew->vShowSize();
	cout << "Zmeniamy dlugosc CTable na 13" << endl;
	cout << "Po modyfikacji metody v_mod_tab(CTable cTab, int iNewSize):"<<endl;
	CTableBezp.v_mod_tab(*CTableNew, 13);
	CTableNew->vShowName();
	CTableNew->vShowSize();
	cout << "___________________________________Destruktory____________________________________________" << endl;


	system("pause");
	return 0;
}

