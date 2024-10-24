#include "BadIndex.h"

BadIndex::BadIndex(int i, const char* r) :_badindex(i), _reason(r) {}

const char* BadIndex::what() const noexcept
{
	cout << "BadIndex exeption catched: " << _reason << endl<< "Index: "<< _badindex<< endl;
	return _reason;
		
}

void BadIndex::SetReason(const char* r) { _reason = r; }

void BadIndex::SetBadIndex(int bi) { _badindex = bi; }



