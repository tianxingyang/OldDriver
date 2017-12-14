#pragma once

template <class type, int dim>
class Point
{
public:
    Point();
    Point(type coords[dim])
    {
        for (int index = 0; index < dim; ++index)
        {
            _coords[index] = coords[index];
        }
    }

    type& operator[] (int index)
    {
        assert(index < dim && index >= 0);
        return _coords[dim];
    }

    type operator[] (int index) const
    {
        assert(index < dim && index >= 0);
        return _coords[dim];
    }

private:
    type _coords[dim];
};

template<class type, int dim>
inline Point<type, dim>::Point()
{
}

template<class type, int dim>
inline ostream& operator<<(ostream &os, const Point<type, dim> &pt)
{
    os << "( ";
    for (int ix = 0; ix < dim - 1; ix++)
    {
        os << pt[ix] << ", ";
    }
    os << pt[dim - 1];
    os << " )";
}
