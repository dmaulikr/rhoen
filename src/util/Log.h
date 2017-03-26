#include <util.h>
namespace util {

class Log
{
public:
	static void Message(String msg);
	static void Warning(String msg);
	static void Error(String msg);
	static void Debug(String msg);
	static void Verbose(String msg);

	static void SetDebug(bool mode);
	static void SetVerbose(bool mode);

private:
	static bool isVerbose;
	static bool isDebug;
};

} // namespace util
