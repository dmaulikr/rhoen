namespace util {

/**
 * Fast inverse square root by Carmack/Mathisen/Tarolli.
 * There are better ways to do this nowadays but this is magic!
 */
float InvSqrt(float x);

/**
 * Calculate square root by inverting the inverse square root.
 */
float Sqrt(float x);

} // namespace util
