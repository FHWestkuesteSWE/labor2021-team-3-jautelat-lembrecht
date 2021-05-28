//#include "pch.h"
#include "CppUnitTest.h"
#include "Client/BasicClient.h"
#include "Server/BasicServer.h"
#include <iostream>
#include <windows.h>
#include <shellapi.h>

/* CHANGE TO THE SERVER.exe PATH TO YOUR SYSTEM - USE Double Backslash: \\ */
	//Relative Path - NOT WORKING
//#define SERVER_PATH "..\\x64\\Debug\\Server.exe"
	//Harm
#define SERVER_PATH "D:\\VisualStudio\\MeineProjekte\\repo\\FHWestkuesteSWE\\Gruppe3\\Software\\GebaeudeManagement\\x64\\Debug\\Server.exe"
	//Yannik
//#define SERVER_PATH C:\ ???? \Software\GebaeudeManagement\x64\Debug\Server.exe
	//Schaedler
//#define SERVER_PATH $REPOSITORY$\Software\GebaeudeManagement\x64\Debug\Server.exe

//If error Message LNK1104 Cannot open file "Server.exe" - Close "Server.exe" in TaskManager>Details

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(T1_Clientstart)
		{
			bool fail = true;
			try
			{
				//Starte Client
				char server[] = "127.0.0.1";
				char port[] = "5000";
				BasicClient client1(server, port);
				fail = false;
			}
			catch (...)
			{
				fail = true;
			}
			Assert::IsFalse(fail);
		}
		
		TEST_METHOD(T2_Serverstart)
		{
			bool fail = true;
			try 
			{
				//Starte Server
				ShellExecuteA(NULL, "open", SERVER_PATH, NULL, NULL, SW_SHOWNORMAL);
				fail = false;
			} 
			catch (...)
			{
				fail = true;
			}
			Assert::IsFalse(fail);
		}

		TEST_METHOD(T3_ServerClientAbfrage)
		{
			//Starte Server
			char port[] = "5000";
			/*
			BasicServer server1;
			server1.start(port);
			*/
			//Starte Client
			char server[] = "127.0.0.1";
			BasicClient client1(server, port);

			//Anfrage von Client an Server
			char fail_phrase[1024] = "TEST FAILED";
			char ans[1024] = "TEST FAILED";
			char req[1024] = "unknownCommand";
			client1.sendRequest(req, ans);
			Assert::AreNotEqual(ans, fail_phrase);
		}
	};
}
