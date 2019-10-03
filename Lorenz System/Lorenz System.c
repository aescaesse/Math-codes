#include <stdio.h>
 
struct Lorenz {
	float a, b, c;
	float x[100000], y[100000], z[100000];
};
 
void Run(struct Lorenz* p, int i)
{
	struct Lorenz l = *p;
	const float dt = 0.001;
	const float dx = l.a * (l.y[i] - l.x[i]) * dt;
	const float dy = (l.x[i] * (l.b - l.z[i]) - l.y[i]) * dt;
	const float dz = (l.x[i] * l.y[i] - l.c * l.z[i]) * dt;
	l.x[i + 1] = l.x[i] + dx;
	l.y[i + 1] = l.y[i] + dy;
	l.z[i + 1] = l.z[i] + dz;
	*p = l;
}
 
void Core()
{
	struct Lorenz attractor = { 10.0, 28.0, 8 / 3 };
	attractor.x[0] = 0.1;
	attractor.y[0] = 0.1;
	attractor.z[0] = 0.1;
	const int max = 100000 - 1;
	for (int i = 0; i < max; i++)
	{
		Run(&attractor, i);
		printf("%f, %f, %f\n", attractor.x[i], attractor.y[i], attractor.z[i]);
	}
	printf("max: %f, %f, %f ", attractor.x[max], attractor.y[max], attractor.z[max]);
 
}
int main()
{
	Core();
	return 0;
}