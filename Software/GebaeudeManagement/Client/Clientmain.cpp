// main.cpp

#pragma once

//Includes
#include <iostream>
#include "BasicClient.h"

using namespace std;

//Functions
string raumabfrage();
string sendCommand(BasicClient Client1, string request);


int main(int argc, char* argv[])
{
    //Client Start
    char server[] = "127.0.0.1";
    char port[] = "5000";
    BasicClient Client1(server, port);  //BasicClient c(argv[1], argv[2]);

    //GUI
    char wahl;
    do {
        cout << "Gebauedeleitsystem FHW 3000 - Jautelat/Lembrecht\n";
        cout << "Was wollen Sie tun: " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Aktuelle Raumtemperatur ueberpruefen \t(t)" << endl;
        cout << "Soll-Temperatur für einen Raum festlegen\t(s)" << endl;
        cout << "Zugang Zustand abfragen \t\t(z)" << endl;
        cout << "Aussentueren oeffnen   \t\t(u)" << endl;
        cout << "Aussentueren schliessen \t\t(l)" << endl;
        cout << "..." << endl;
        cout << "Direkte Anfragen an Server (x)" << endl;
        cout << "Beenden \t\t\t\t(e)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Ihre Wahl: ";
        
        
        cin >> wahl;
        
        string request = "";
        string output = "";
        switch (wahl) {
        case 't':
        {
            request = "temp " + raumabfrage();
            output = sendCommand(Client1, request);
            cout << output;
            break;
        }
        case 's':
        {
            float soll = 20.0;
            cout << "Geben Sie die gewünschte Raumtemperatur an: ";
            cin >> soll;
            request = "set " + raumabfrage() + " " + to_string(soll);
            output = sendCommand(Client1, request);
            cout << output;
            break;
        }
        case 'z':
        {
            request = "state " + raumabfrage();
            output = sendCommand(Client1, request);
            cout << output;
            break;
        }
        case 'u':
        {
            request = "unlock " + raumabfrage();
            output = sendCommand(Client1, request);
            cout << output;
            break;
        }
        case 'l':
        {
            request = "lock " + raumabfrage();
            output = sendCommand(Client1, request);
            cout << output;
            break;
        }
        case 'x':
        {
            cout << "String an Server: ";
            //char in[1024] = "";
            cin.ignore();
            getline(cin, request);
            //request = in;
            output = sendCommand(Client1, request);
            cout << output;
            break;
        }
        default:;

        }
    } while (wahl != 'e');


}

string raumabfrage()
{
    string raum = "";
    cout << "Geben sie die Bezeichnung des Raumes ein: ";
    cin >> raum;
    return raum;
}

string sendCommand(BasicClient client, string request)
{
    //Add Pipe '|' as End Character
    request = request + " |";
    char req[1024] = "Empty Request";
    char ans[1024] = "Empty Response";
    strcpy_s(req, request.c_str());
    client.sendRequest(req, ans);
    return ans;
}