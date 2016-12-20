#ifndef IO_HELPER_H
#define IO_HELPER_H

#include <iostream>
#include <fstream>


struct FileInfo {
	char* content;
	long size;
};


static FileInfo read_bytes(const char * filename)
{
		// Open file
    ifstream opened(filename, ios::binary|ios::ate);
    ifstream::pos_type pos = opened.tellg();

    // Truncate to 32 bits in case file is very big
    int length = pos;

		// Read file bytes
    char *p_read_chars = new char[length];
    opened.seekg(0, ios::beg); // Search for file beggining
    opened.read(p_read_chars, length); // Read all bytes

    // Close file, but no need to do it
    opened.close();

		// Set return value
	FileInfo result = FileInfo();
	result.content = p_read_chars;
	result.size = length;
    return result;
}

#endif // IO_HELPER_H
