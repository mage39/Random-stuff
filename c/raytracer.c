#include <cglm/cglm.h>

static void pixColor (vec3 origin, vec3 dir, vec3 dst) {
	vec3 unitDir;
	glm_vec3_divs(dir, 3, unitDir);
	float a = .5 * (unitDir[1] + 1);
	vec3 from = {1, 1, 1}, to = {.5, .7, 1};
	glm_vec3_lerp(from, to, a, dst);
}

int main (void) {
	constexpr int width = 400;
	constexpr int height = 225;
	constexpr float focalLength = 1;
	constexpr float viewHeight = 2;
	constexpr float viewWidth = viewHeight / ((float)width / height);
	vec3 center = {0};
	vec3 viewportU = {viewWidth};
	vec3 viewportV = {[1] = -viewHeight};
	vec3 pixDeltaU, pixDeltaV;
	glm_vec3_divs(viewportU, width, pixDeltaU);
	glm_vec3_divs(viewportV, height, pixDeltaV);
	vec3 viewUpperLeft = {[2] = focalLength};
	{ // viewUpperLeft init
		glm_vec3_sub(center, viewUpperLeft, viewUpperLeft);
		vec3 t;
		glm_vec3_divs(viewportU, 2, t);
		glm_vec3_sub(viewUpperLeft, t, viewUpperLeft);
		glm_vec3_divs(viewportV, 2, t);
		glm_vec3_sub(viewUpperLeft, t, viewUpperLeft);
	}
	vec3 pix00loc;
	{ // pix00loc init
		glm_vec3_adds(viewUpperLeft, .5, pix00loc);
		vec3 t;
		glm_vec3_add(pixDeltaU, pixDeltaV, t);
		glm_vec3_mul(pix00loc, t, pix00loc);
	}
	FILE* out = fopen("out.ppm", "w");
	fprintf(out, "P6\n%d %d\n255\n", width, height);
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			vec3 pixCenter;
			{ // pixCenter init
				vec3 t;
				glm_vec3_scale(pixDeltaU, i, t);
				glm_vec3_add(pix00loc, t, pixCenter);
				glm_vec3_scale(pixDeltaV, j, t);
				glm_vec3_add(pixCenter, t, pixCenter);
			}
			vec3 rayDir;
			glm_vec3_sub(pixCenter, center, rayDir);
			vec3 t;
			pixColor(center, rayDir, t);
			unsigned char pixel[] = {t[0], t[1], t[2]};
			fwrite(pixel, 1, 3, out);
		}
	}
	fclose(out);
}
