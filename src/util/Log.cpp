#include <util.h>
namespace util {

bool Log::isVerbose = false;
bool Log::isDebug = false;

void Log::Message(String msg)
{
	(void) msg; // TODO
}

void Log::Warning(String msg)
{
	(void) msg; // TODO
}
    
void Log::Error(String msg)
{
	(void) msg; // TODO
}

void Log::Debug(String msg)
{
	if (!isDebug) return;
	(void) msg; // TODO
}

void Log::Verbose(String msg)
{
	if (!isVerbose) return;
	(void) msg; // TODO
}

void Log::SetDebug(bool mode)
{
	isDebug = mode;
}

void Log::SetVerbose(bool mode)
{
	isVerbose = mode;
}

// TODO: use terminal color escape sequences
// const String R("\033[1;31m"); // red
// const String G("\033[1;32m"); // green
// const String Y("\033[1;33m"); // yellow
// const String M("\033[1;35m"); // magenta
// const String C("\033[1;36m"); // cyan
// const String N("\033[0m");    // reset

} // namespace util
