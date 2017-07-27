#ifndef BINARY_SEARCH_H_
#define BINARY_SEARCH_H_

#include <algorithm>

binary_search

template<class _FwdIt, class _Ty, class _Pr>
bool my_binary_search(_FwdIt _First, _FwdIt _Last, const _Ty& _Val, _Pr _Pred)
{
    _Iter_diff_t<_FwdIt> _Count = _STD distance(_First, _Last);
    while ( _Count > 0)
    {
        _Iter_diff_t<_FwdIt> _Count2 = _Count / 2;
        _FwdIt _Mid = _First;
        _STD advance(_Mid, _Count2);

        if(_Pred(*_Mid, _Val))
        {
            _First = ++_Mid;
            _Count -= _Count2 + 1;
        }
        else
        {
            _Count = _Count2;
        }
    }
    return (_First);
}

template <class FwdIt, class T>
FwdIt MyBinarySearch(FwdIt first, FwdIt last, const T& key)
{
	
}

#endif //BINARY_SEARCH_H_


template<class _FwdIt,
	class _Ty,
	class _Pr> inline
	_FwdIt _Lower_bound_unchecked(_FwdIt _First, _FwdIt _Last,
		const _Ty& _Val, _Pr& _Pred)
	{	// find first element not before _Val, using _Pred
	_Iter_diff_t<_FwdIt> _Count = _STD distance(_First, _Last);

	while (0 < _Count)
		{	// divide and conquer, find half that contains answer
		_Iter_diff_t<_FwdIt> _Count2 = _Count / 2;
		_FwdIt _Mid = _First;
		_STD advance(_Mid, _Count2);

		if (_Pred(*_Mid, _Val))
			{	// try top half
			_First = ++_Mid;
			_Count -= _Count2 + 1;
			}
		else
			_Count = _Count2;
		}

	return (_First);
	}

	void * __fileDECL bsearch (
    const void *key,
    const void *base,
    size_t num,
    size_t width,
    int (__fileDECL *compare)(const void *, const void *)
    )
#endif  /* __USE_CONTEXT */
{
    char *lo = (char *)base;
    char *hi = (char *)base + (num - 1) * width;
    char *mid;
    size_t half;
    int result;

    /* validation section */
    _VALIDATE_RETURN(base != NULL || num == 0, EINVAL, NULL);
    _VALIDATE_RETURN(width > 0, EINVAL, NULL);
    _VALIDATE_RETURN(compare != NULL, EINVAL, NULL);

        /*
        We allow a NULL key here because it breaks some older code and because we do not dereference
        this ourselves so we can't be sure that it's a problem for the comparison function
        */

    while (lo <= hi)
    {
        if ((half = num / 2) != 0)
        {
            mid = lo + (num & 1 ? half : (half - 1)) * width;
            if (!(result = __COMPARE(context, key, mid)))
                return(mid);
            else if (result < 0)
            {
                hi = mid - width;
                num = num & 1 ? half : half-1;
            }
            else
            {
                lo = mid + width;
                num = half;
            }
        }
        else if (num)
            return (__COMPARE(context, key, lo) ? NULL : lo);
        else
            break;
    }

    return NULL;
}


int MyBSearch (const void *key, const void *base, size_t nmemb, size_t size, int *piEqual, int (*compar) (const void *, const void *))
{
	size_t l, u, idx;
	const void *p, *p2;
	int comparison, comparison2;
	
	*piEqual = 0;
	if (!nmemb) return 0;
	l = 0;
	u = nmemb;
	
	while (l < u)
	{
		idx = (l + u) / 2;
		p = (void *) (((const char *) base) + (idx * size));
		comparison = (*compar) (key, p);
		
		if (comparison == 0)
		{
			*piEqual = 1;
			return idx;
		}		
		else if (comparison < 0)
		{
			if (idx == 0) return idx;
			
			p2 = (void *) (((const char *) base) + ((idx - 1) * size));
			comparison2 = (*compar) (key, p2);
			
			if (comparison2 > 0) return idx;
			
			u = idx;
		}
		else /*if (comparison > 0)*/ 
		{
			l = idx + 1;
		}		
	}
	
	return u;
}