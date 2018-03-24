#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
using namespace std;

//unsigned gcd(unsigned, unsigned);

struct FloatArray {
protected:
	size_t size;
	float* data;
	static size_t number;
	void setSpaces() const;
public:
	explicit FloatArray(size_t const = 0);
	FloatArray(FloatArray const&);
	virtual ~FloatArray();
	void output() const;
	virtual void kek() const {
		cout << "FloatArray kek!\n";
	}
	FloatArray& operator=(FloatArray const&);
private:
	void swap(FloatArray&);
};

struct My : public FloatArray {
public:
	virtual void kek() const {
		cout << "My kek!\n";
	}
	
	explicit My(size_t const = 0);
	virtual ~My();
};

size_t FloatArray::number = 0;

int main() {
	FloatArray f(13);
	f.output();
	FloatArray ff;
	ff = f;
	ff.output();
	return 0;
}

FloatArray::FloatArray(size_t const size) : size(size), data(new float[size]) {
	number++;
	setSpaces();
	cout << "constructor " << size << endl;
	for (size_t i = 0; i < size; i++) data[i] = (float)i / 10.0f;
}

FloatArray::FloatArray(FloatArray const& f) : size(f.size), data(new float[size]) {
	number++;
	setSpaces();
	cout << "copy constructor " << size << endl;
	for (size_t i = 0; i < size; i++) data[i] = f.data[i];
}

FloatArray::~FloatArray() {
	setSpaces();
	cout << "destructor " << size << endl;
	delete[] data;
	size = 0;
	number--;
}

My::~My() {
	setSpaces();
	cout << "my destructor " << size << endl;
}

FloatArray& FloatArray::operator=(FloatArray const& f) {
	setSpaces();
	if (this != &f) {
		cout << "operator= " << size << endl;
		FloatArray(f).swap(*this);
	} else {
		cout << "equals!\n";
	}
	return *this;
}

void FloatArray::swap(FloatArray& f) {
	std::swap(size, f.size);
	std::swap(data, f.data);
}

void FloatArray::output() const {
	for (size_t i = 0; i < size; i++) {
		setSpaces();
		cout << data[i] << endl;
	}
}

void FloatArray::setSpaces() const {
//	cout << '[' << setfill('-') << setw(number + 1) << ']';
	for (size_t i = 0; i < number; i++) cout << "-";
	cout << ">\t";
}

My::My(size_t const size) : FloatArray(size) {
	setSpaces();
	cout << "My constructor " << size << endl;
}

//unsigned gcd(unsigned a, unsigned b) {
//	return b == 0 ? a : gcd(b, a % b);
//}