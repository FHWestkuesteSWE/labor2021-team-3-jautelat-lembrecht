//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Zugang.h
//  @ Date : 17.05.2021
//  @ Author : 
//
//
#include <string>

#if !defined(_ZUGANG_H)
#define _ZUGANG_H


class Zugang {
public:
	bool zustand;
	std::string zugang_bez;
	bool lock(std::string zugang_bez);
	bool unlock(std::string zugang_bez);
	bool getZustand(std::string zugang_bez);
};

#endif  //_ZUGANG_H
