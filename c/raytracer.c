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
static Vec3 v3sub (Vec3 v1, Vec3 v2) {
	return v3add(v1, v3neg(v2));
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
static void v3toColorStr (Vec3 vec, LogStr str) {
	sprintf(str, "%d %d %d",
		(int)(vec.v[0] * 255.999),
		(int)(vec.v[1] * 255.999),
		(int)(vec.v[2] * 255.999));
}
static Vec3 rayAt (Ray a, double t) {
	return v3add(a.pt, v3sclr(a.dir, t));
}
static Vec3 rayColor (Ray r) {
	double a = 0.5 * (r.dir.v[1] + 1);
	// expr spec: (1 - a) * (Vec3){{1, 1, 1}} + a * (Vec3){{0.5, 0.7, 1}}
	return v3add(v3sclr((Vec3){{1, 1, 1}}, (1 - a)),
				 v3sclr((Vec3){{0.5, 0.7, 1}}, a));
}

int main (void) {
	double ratio = 16.0 / 9.0;
	double focalLength = 1;
	int width = 400;
	int height = width / ratio;
	double viewHeight = 2;
	double viewWidth = viewHeight * ((double)width / height);
	height = height > 1 ? height : 1;
	Vec3 camCenter = {0};
	Vec3 viewPortU = {{viewWidth}};
	Vec3 viewPortV = {{[1] = -viewHeight}};
	Vec3 pixDeltaU = v3sclr(viewPortU, 1.0 / width);
	Vec3 pixDeltaV = v3sclr(viewPortV, 1.0 / height);
	// expr spec: camCenter - (Vec3){{[2] = focalLength}} - viewPortU / 2 - viewPortV / 2
	Vec3 viewUpperLeft = v3add(camCenter,
			v3neg(v3add((Vec3){{[2] = focalLength}},
			v3neg(v3add(v3sclr(viewPortU, 0.5),
			v3neg(v3sclr(viewPortV, 0.5)))))));
	// expr spec: viewUpperLeft + 0.5 * (pixDeltaU + pixDeltaV)
	Vec3 pix00Loc = v3add(viewUpperLeft,
			v3sclr(v3add(pixDeltaU, pixDeltaV), 0.5));
	puts("P3");
	printf("%d %d\n", width, height);
	puts("255");
	for (int j = 0; j < width; j++) {
		for (int i = 0; i < height; i++) {
			Vec3 pixelCenter = v3add(v3add(pix00Loc, v3sclr(pixDeltaU, i)),
							   v3sclr(pixDeltaV, j));
			Vec3 rayDir = v3sub(pixelCenter, camCenter);
			Ray r = {camCenter, rayDir};
			Vec3 color = rayColor(r);
			LogStr buf;
			v3toColorStr(color, buf);
			puts(buf);
		}
	}
}
