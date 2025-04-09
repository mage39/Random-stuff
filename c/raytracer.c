#include <stdio.h>

typedef struct { double v[3]; } Vec3;
typedef struct { Vec3 pt, dir; } Ray;
typedef char LogStr[1024];

static Vec3 v3neg (Vec3 vec) {
	for (int i = 0; i < 3; i++) vec.v[i] = -vec.v[i];
	return vec;
}
static Vec3 v3add (Vec3 v1, Vec3 v2) {
	for (int i = 0; i < 3; i++) v1.v[i] += v2.v[i];
	return v1;
}
static Vec3 v3mul (Vec3 v1, Vec3 v2) {
	for (int i = 0; i < 3; i++) v1.v[i] *= v2.v[i];
	return v1;
}
static Vec3 v3div (Vec3 v1, Vec3 v2) {
	for (int i = 0; i < 3; i++) v1.v[i] /= v2.v[i];
	return v1;
}
static Vec3 v3sclr (Vec3 vec, double scalar) {
	for (int i = 0; i < 3; i++) vec.v[i] *= scalar;
	return vec;
}
static Vec3 v3sqr (Vec3 v1) {
	for (int i = 0; i < 3; i++) v1.v[i] *= v1.v[i];
	return v1;
}
static double v3dot (Vec3 v1, Vec3 v2) {
	double ret;
	for (int i = 0; i < 3; i++) ret += v1.v[0] * v2.v[0];
	return ret;
}
static Vec3 v3crs (Vec3 v1, Vec3 v2) {
	return (Vec3){{
		v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
		v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],
		v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]}};
}
static void v3logStr (Vec3 vec, LogStr str) {
	sprintf(str, "%g %g %g", vec.v[0], vec.v[1], vec.v[2]);
}
static void v3toColorLogStr (Vec3 vec, LogStr str) {
	sprintf(str, "%d %d %d",
		(int)(vec.v[0] * 255.999),
		(int)(vec.v[1] * 255.999),
		(int)(vec.v[2] * 255.999));
}
static Vec3 rayAt (Ray a, double t) {
	return v3add(a.pt, v3sclr(a.dir, t));
}

int main (void) {
	double ratio = 16.0 / 9.0;
	int width = 400, height = width / ratio;
	height > 1 ? height : 1;
	puts("P3");
	printf("%d %d\n", width, height);
	puts("255");
	for (int j = 0; j < width; j++) {
		for (int i = 0; i < height; i++) {
			Vec3 color = {{(double)i / (height - 1), (double)j / (width - 1)}};
			LogStr buf;
			v3toColorLogStr(color, buf);
			puts(buf);
		}
	}
}
