#include "ShakerSortableIntVector.h"

using namespace std;

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector(aArrayOfIntegers, aNumberOfElements) {}

void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
	int lBeginIndex = 0;
	int lEndIndex = size() - 1;

	while (lBeginIndex < lEndIndex)
	{
		for (int i = lBeginIndex; i <= lEndIndex - 1; i++)
		{
			if (aOrderFunction(IntVector::get(i), IntVector::get(i + 1)))
			{
				swap(i, i + 1);
			}
		}

		lEndIndex -= 1;

		for (int i = lEndIndex; i >= lBeginIndex + 1; i--)
		{
			if (!aOrderFunction(IntVector::get(i), IntVector::get(i - 1)))
			{
				swap(i, i - 1);
			}
		}
		lBeginIndex += 1;
	}

}