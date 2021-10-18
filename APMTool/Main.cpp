#include "stdafx.h"
#include "AtaSmart.h"
#include <iostream>

#pragma comment(lib, "comsupp.lib")

using namespace std;

int main(int argc, char** argv) {
		CAtaSmart s;
		s.Init(true, false, false, false, false, false);
		if (argc == 1 || argc > 3) {	//Default: print usage and list drives
			cout << "Usage: " << endl;
			cout << argv[0] << " idx : shows APM config for drive at index idx" << endl;
			cout << argv[0] << " idx 0 : disables APM for drive at index idx" << endl;
			cout << argv[0] << " idx 1-254 : enables APM for drive at index idx" << endl << endl;
			cout << "Disk drives:" << endl << "--------------------" << endl;
			for (int i = 0; i < s.vars.GetSize(); i++) {
				wcout << "(" << i << ") " << (const wchar_t*)s.vars.GetAt(i).Model << " (Temp: " << s.vars.GetAt(i).Temperature << " deg)" << endl;
			}
			return 0;
		}
		int idx = atoi(argv[1]);
		if (idx<0 || idx>s.vars.GetUpperBound()) {
			cout << "No drive at idx" << endl;
			return 0;
		}
		if (!s.vars.GetAt(idx).IsApmSupported) {
			cout << "APM not supported" << endl;
			return 0;
		}
		
		if (argc == 2) {	//Show current APM
			if (!s.vars.GetAt(idx).IsApmEnabled) {
				cout << "APM not enabled" << endl;
			} else {
				cout << "APM: " << (int)s.GetApmValue(idx) << endl;
			}
			return 0;
		}
		int apmv= atoi(argv[2]);
		if (apmv < 0 || apmv>254) {
			cout << "Wrong APM value" << endl;
			return 0;
		}
		if (apmv) {
			s.EnableApm(idx, apmv);
		} else {
			s.DisableApm(idx);
		}
		cout << "Done!" << endl;
}