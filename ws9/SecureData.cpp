// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 23.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


// Workshop 9 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO: rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.

		int how_many_parts = nbytes / 2;

		auto convert_1 = std::bind(converter, text + how_many_parts * 2, key, nbytes - (how_many_parts * 2), Cryptor());
		auto convert_2 = std::bind(converter, text + how_many_parts, key, how_many_parts , Cryptor());

		std::thread thread_1(convert_1);
        std::thread thread_2(convert_2);	

		converter(text, key, how_many_parts, Cryptor());

        thread_1.join();
		thread_2.join();

		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
            // TODO: open a binary file for writing
            std::ofstream ofstr(file, std::ios::binary);

            if (!ofstr.good())
            {
                std::string errMess = "opening fails";
                throw std::string(errMess);
            }

            // TODO: write data into the binary file
            //         and close the file
            ofstr.write(text, nbytes);
            ofstr.close();
        }
	}

    void SecureData::restore(const char *file, char key) {
        // TODO: open binary file for reading
        std::ifstream ifstr(file, std::ios::binary);

        if (!ifstr.good())
        {
            std::string errMess = "opening fails";
            throw std::string(errMess);
        }

        ifstr.seekg(0, ifstr.end);
        nbytes = (int)ifstr.tellg();
        ifstr.seekg(0, ifstr.beg);

        // TODO: - allocate memory here for the file content
        text = new char[nbytes];

        // TODO: - read the content of the binary file
        ifstr.read(text, nbytes);
        ifstr.close();

        *ofs << "\n"
             << nbytes << " bytes copied from binary file "
             << file << " into memory.\n";

        encoded = true;

        // decode using key
        code(key);

        *ofs << "Data decrypted in memory\n\n";
    }

    std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}