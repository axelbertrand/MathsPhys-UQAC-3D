#pragma once

#include <valarray>
#include <initializer_list>
#include "math/quaternion.hpp"

namespace physicslib
{
	class Matrix34
	{
	public:
		/**
		 * Default constructor
		 * Create the identity matrix 4x4
		 */
		Matrix34();

		/**
		 * Create a matrix 4x4 filled with the number `fillNumber` except for last line
		 */
		explicit Matrix34(double fillNumber);

		/*
		 * Create a matrix 4x4 with an initializer list
		 * `Matrix34 mat { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 }`
		 */
		Matrix34(const std::initializer_list<double>& initializerList);

		/**
		 * Create a matrix 4x4 from a quaternion
		 */
		Matrix34(const Quaternion& quaternion);

		/**
		 * Default copy constructor
		 */
		Matrix34(const Matrix34& anotherMatrix) = default;

		/**
		 * Virtual destructor
		 */
		virtual ~Matrix34() = default;

		/**
		 * Default assignment operator
		 */
		Matrix34& operator=(const Matrix34& anotherMatrix) = default;

		/**
		 * Get the determinent of the matrix
		 */
		double getDeterminant() const;

		/**
		 * Reverse the matrix
		 */
		void reverse();

		/**
		 * return reversed matrix in a new matrix object
		 */
		Matrix34 getReverseMatrix() const;

		// Matrix mathematical operations
		Matrix34& operator+=(const Matrix34& anotherMatrix);
		Matrix34 operator+(const Matrix34& anotherMatrix);
		Matrix34& operator-=(const Matrix34& anotherMatrix);
		Matrix34 operator-(const Matrix34& anotherMatrix);
		Matrix34& operator*=(const Matrix34& anotherMatrix);
		Matrix34 operator*(const Matrix34& anotherMatrix);

		// Matrix/scalar operations
		Matrix34& operator+=(const double scalar);
		Matrix34& operator-=(const double scalar);
		Matrix34& operator*=(const double scalar);
		Matrix34& operator/=(const double scalar);

		/**
		 * Setter
		 * `mat(i, j) = 3;`
		 */
		double& operator()(const std::size_t row, const std::size_t column);

		/**
		 * Getter
		 * `double n = mat(i, j);`
		 */
		const double& operator()(const std::size_t row, const std::size_t column) const;

	private :
		std::valarray<double> m_data;
	};

	// Matrix/scalar operations
	Matrix34 operator+(const Matrix34& matrix, const double scalar);
	Matrix34 operator+(const double scalar, const Matrix34& matrix);
	Matrix34 operator-(const Matrix34& matrix, const double scalar);
	Matrix34 operator-(const double scalar, const Matrix34& matrix);
	Matrix34 operator*(const Matrix34& matrix, const double scalar);
	Matrix34 operator*(const double scalar, const Matrix34& matrix);
	Matrix34 operator/(const Matrix34& matrix, const double scalar);
	Matrix34 operator/(const double scalar, const Matrix34& matrix);
}