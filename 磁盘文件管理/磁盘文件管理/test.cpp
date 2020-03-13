#include "fileManager.hpp"
#include "fileutil.hpp"
#include "md5.h"
#include "FileManagerTool.h"

void menu() {
	cout << "***************************************" << endl;
	cout << "          1. scanner" << endl;
	cout << "          2. show all" << endl;
	cout << "          3. show copy" << endl;
	cout << "          4. delete name" << endl;
	cout << "          5. delete md5" << endl;
	cout << "          6. delete all" << endl;
	cout << "          7. delete matched" << endl;
	cout << "          0. exist" << endl;
	cout << "***************************************" << endl;
}
void testFileManagerTool() {
	FileManagerTool fmt;
	int input;
	do {
		menu();
		std::string garbage;
		cout << "ÇëÊäÈëÑ¡Ïî£º" << endl;
		cin >> input;
		getline(cin, garbage);
		switch (input) {
		case 1:
			fmt.scanner();
			break;
		case 2:
			fmt.showAllFile();
			break;
		case 3:
			fmt.showCopy();
			break;
		case 4:
			fmt.deletebyName();
			break;
		case 5:
			fmt.deletebyMd5();
			break;
		case 6:
			fmt.deleteAllCopy();
			break;
		case 7:
			fmt.deleteFussyMatchCopy();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (input != 0);
}
int main() {
	testFileManagerTool();
	return 0;
}

