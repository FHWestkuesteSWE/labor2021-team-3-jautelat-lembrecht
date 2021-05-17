// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#pragma once
#include <iostream>
#include "BasicClient.h"

using namespace std;
int main(int argc, char* argv[])
{
    char server[] = "127.0.0.1";
      char port[] = "5000";
  //  BasicClient c(argv[1], argv[2]);
    BasicClient c(server, port);
    char req[1024] = "state Raum1";
    char ans[1024];
    char wahl;
    do {
        std::cout << "Gebauedeleitsystem FHW 3000 - Jautelat/Lembrecht\n";
        cout << "Was wollen Sie tun: " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Aktuelle Raumtemperatur ueberpruefen \t(t)" << endl;
        cout << "Zugang Zustand abfragen \t(z)" << endl;
        cout << "Aussentueren oeffnen / schliessen \t(a)" << endl;
        cout << "..." << endl;
        cout << "Beenden \t\t\t\t(e)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Ihre Wahl: ";
        cin >> wahl;
        switch (wahl) {
        case 't': // req zusammenbauen
            c.sendRequest(req, ans);
            cout << ans;
            break;
        case 'z': // req zusammenbauen
            c.sendRequest(req, ans);
            cout << ans;
            break;
        default:;

        }
    } while (wahl != 'e');
}

