#ifndef INDEX_H_
#define INDEX_H_

struct Index {
	Rectangle rect;
	Texture2D token;
	char type;
	bool marked;
};

#endif	/* INDEX_H_ */