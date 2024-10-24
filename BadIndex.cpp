#include "BadIndex.h"

const char* BadIndex::what() const noexcept
{
	cout << "Bad Index exeption:" << _reason << endl;

}

void BadIndex::SetReason(const char* r) { _reason = r; }


