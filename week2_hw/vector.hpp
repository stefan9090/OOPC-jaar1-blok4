#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ostream>

/// @file

/// \brief
/// vector ADT
/// \details
/// This is an ADT that implements vector values.
/// The x and y values are stored as integer values.
/// The +, += *, *=, == and << operators and constructor are provided

class vector
{
public:
    int x;
    int y;

    /// \brief
    /// default constructor
    /// \details
    /// This is the default constructors that initializes the x and y values to 0
    vector(){}
    
    /// \brief
    /// constructor from explicit values
    /// \details
    /// This constructors initializes the x and y to the given x and y values.
    vector(int x, int y);

    /// \brief
    /// Monadic operator+ 
    vector operator+();
    
    /// \brief
    /// Add 2 vectors
    /// \details
    /// This operator adds 2 vectors.
    vector operator+(const vector rhs)const;
    /// \brief
    /// Add a vector to another vector
    /// \details
    /// This operator adds a vector a vector.
    vector & operator+=(const vector & rhs);
    
    //vector operator*(const vector lhs, const vector rhs);
    
    /// \brief
    /// Multiply 2 vectors
    /// \details
    /// This operator multiplies 2 vectors.
    vector operator*(const vector rhs)const;
    
    /// \brief
    /// Multiply a vector by a integer
    /// \details
    /// This operator multiplies a vector by a integer.
    vector operator*(const int lhs)const;
    
    /// \brief
    /// Multiply a vector with another vector
    /// \details
    /// This operator multiplies a vector with a vector.
    vector & operator*=(const vector & rhs);
    
    /// \brief   
    /// compare two vectors
    /// \details
    /// This operator tests for equality. It returns true
    /// if and only if the x and y of both
    /// vectors are equal.
    bool operator==(const vector & rhs)const;
    
    /// \brief
    /// output operator for a vector
    /// \details
    /// This operator<< prints a constructor in the format
    /// [x,y] where both values are printed as
    /// decimal values.
    friend std::ostream & operator<<(std::ostream & os, const vector & rhs);
};

#endif // VECTOR_HPP
