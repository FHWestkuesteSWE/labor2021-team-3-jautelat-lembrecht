// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#pragma once
#include <iostream>
#include "BasicClient.h"

std::string raumabfrage();

using namespace std;
int main(int argc, char* argv[])
{
    char server[] = "127.0.0.1";
    char port[] = "5000";
  //  BasicClient c(argv[1], argv[2]);
    BasicClient c(server, port);
    char req[1024] = "Generic Request!";
    char ans[1024];
    char wahl;
    do {
        std::cout << "Gebauedeleitsystem FHW 3000 - Jautelat/Lembrecht\n";
        cout << "Was wollen Sie tun: " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Aktuelle Raumtemperatur ueberpruefen \t(t)" << endl;
        cout << "Soll-Temperatur für einen Raum festlegen\t(s)" << endl;
        cout << "Zugang Zustand abfragen \t\t(z)" << endl;
        cout << "Aussentueren oeffnen   \t\t(u)" << endl;
        cout << "Aussentueren schliessen \t\t(l)" << endl;
        cout << "..." << endl;
        cout << "Beenden \t\t\t\t(e)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Ihre Wahl: ";
        cin >> wahl;
        
        string request = "";
        switch (wahl) {
        case 't':
        {
            request = "temp " + raumabfrage();
            strcpy_s(req, request.c_str());
             c.sendRequest(req, ans);
            cout << ans;
            break;
        }
        case 's':
        {
            uint16_t soll = 20;
            cout << "Geben Sie die gewünschte Raumtemperatur an: ";
            cin >> soll;
            request = "set " + raumabfrage() + " " + to_string(soll);
            strcpy_s(req, request.c_str());
            c.sendRequest(req, ans);
            cout << ans;
            break;
        }
        case 'z':
        {
            request = "state " + raumabfrage();
            strcpy_s(req, request.c_str());
            c.sendRequest(req, ans);
            cout << ans;
            break;
        }
        case 'u':
        {
            request = "unlock " + raumabfrage();
            strcpy_s(req, request.c_str());
            c.sendRequest(req, ans);
            cout << ans;
            break;
        }
        case 'l':
        {
            request = "lock " + raumabfrage();
            strcpy_s(req, request.c_str());
            c.sendRequest(req, ans);
            cout << ans;
            break;
        }
        default:;

        }
    } while (wahl != 'e');
}

std::string raumabfrage()
{
    std::string raum = "";
    cout << "Geben sie die Bezeichnung des Raumes ein: ";
    cin >> raum;
    return raum;
}