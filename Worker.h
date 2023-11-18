#pragma once
#include<iostream>
using namespace std;
class Worker {
	char* fio;
	char* post;
	size_t year;
	size_t zp;
public:
	Worker(const char* fio, const char* post, size_t year, size_t zp) :
		fio{ fio ? new char[strlen(fio) + 1] : nullptr },
		post{ post ? new char[strlen(post) + 1] : nullptr },
		year{ year },
		zp{ zp } {

		if (fio) {
			strcpy_s(this->fio, strlen(fio) + 1, fio);
		}
		if (post) {
			strcpy_s(this->post, strlen(post) + 1, post);
		}
	}

	explicit Worker() : Worker(nullptr, nullptr, year, 0) {};

	~Worker() {}

	const char* getFio() const { return fio; }

	const char* getPost() const { return post; }

	size_t getYear() const { return year; }

	size_t getZp() const { return zp; }

	void show(const Worker* slave, int count) const;
};

