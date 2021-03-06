#include <stdexcept>
#include "SortableIntVector.h"

using namespace std;

SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : IntVector(aArrayOfIntegers, aNumberOfElements) {}

void SortableIntVector::sort(Comparable aOrderFunction)
{
	for (int i = 0; i < IntVector::size() - 1; i++)
	{
		for (int j = IntVector::size() - 1; j >= i + 1; j--)
		{
			if (!aOrderFunction(IntVector::get(j), IntVector::get(j - 1)))
			{
				IntVector::swap(j, j - 1);
			}
		}
	}
}



