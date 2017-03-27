namespace util {

float InvSqrt(float x)
{
	float xhalf;
	int i;

	xhalf = 0.5f * x;
	i = *(int*)&x;              // store floating-point bits in integer
	i = 0x5f3759df - (i >> 1);  // initial guess for Newton's method
	x = *(float*)&i;            // convert new bits into float
	x = x*(1.5f - xhalf*x*x);   // one round of Newton's method
	return x;
}

float Sqrt(float x)
{
	return x * InvSqrt(x);
}

} // namespace util
