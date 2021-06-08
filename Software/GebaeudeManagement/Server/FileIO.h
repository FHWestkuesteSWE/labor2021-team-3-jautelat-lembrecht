//FileIO.h

#ifndef FILEIO_H
#define FILEIO_H



class FileIO {
public:
	
	FileIO();
	std::string readFile(std::string path);
	bool saveToFile(std::string path);

private:

};

#endif
