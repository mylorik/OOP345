// Name:  Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 08.11.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

namespace w7
{
	template <typename T = double>
	class DataTable
	{
		std::vector<T> x_val_{};
		std::vector<T> y_val_{};
		int field_width_{};
		int precision_for_numbers_{};

		T accumulate(std::vector<T> data) const
		{
			return std::accumulate(data.begin(), data.end(), T(0));
		}

		template <typename Func>
		T accumulate(std::vector<T> data, Func func) const
		{
			return std::accumulate(data.begin(), data.end(), T(0), func);
		}

	public:
		DataTable(std::ifstream& ifs, const int& width, const int& precision) : field_width_(width), precision_for_numbers_(precision)
		{
			T X, Y;
			while (ifs.good())
			{
				ifs >> X >> Y;
				x_val_.push_back(X);
				y_val_.push_back(Y);
			}
			ifs.close();

			/*
			 * I know if I will have 2 same values at the end of the file, and there will be no empty line at the end, my code will just delete one CORRECT record
			 * but I do like it for some strange reason...
			 * 
			 * I could count lines and run "for" loop, it would work perfectly, but I am trying to figure out, how do I fix that problem, 
			 * when I have empty line at the end of the file, I am getting the last record second time.
			 * 
			 * 
			 */
			if (x_val_.size() > 2 && x_val_[x_val_.size() - 1] == x_val_[x_val_.size() - 2])
			{
				x_val_.pop_back();
			}
			if (y_val_.size() > 2 && y_val_[y_val_.size() - 1] == y_val_[y_val_.size() - 2])
			{
				y_val_.pop_back();
			}
		}

		T mean() const
		{
			return accumulate(y_val_) / getSize();
		}

		T sigma() const
		{
			return sqrt(
				accumulate(y_val_, [&](const T& a, const T& b) -> T
				{
					return a + (b - mean()) * (b - mean());
				}) / (getSize() - 1));
		}

		T median() const
		{
			std::vector<T> temp = y_val_;
			std::sort(temp.begin(), temp.end());

			return temp[temp.size() / 2];
		}

		void regression(T& slope, T& y_intercept) const
		{
			auto accum_x = accumulate(x_val_);
			auto accum_y = accumulate(y_val_);

			auto inner_product_of_xy = std::inner_product(x_val_.begin(), x_val_.end(), y_val_.begin(), T(0));
			auto accum_x_sqr = accumulate(x_val_, [](const T& a, const T& b) -> T { return a + b * b; });

			slope = ((getSize() * inner_product_of_xy) - (accum_x * accum_y)) / ((getSize() * accum_x_sqr) - (accum_x * accum_x));
			y_intercept = (accum_y - slope * accum_x) / getSize();
		}

		void display(std::ostream& os) const
		{
			os << std::setw(field_width_) << "x" << std::setw(field_width_) << "y" << std::endl << std::fixed << std::setprecision(
				precision_for_numbers_);

			for (size_t i = 0; i < getSize(); i++)
			{
				os << std::setw(field_width_) << x_val_[i] << std::setw(field_width_) << y_val_[i] << std::endl;
			}
		}

		size_t getSize() const
		{
			return x_val_.size();
		}

		friend std::ostream& operator<<(std::ostream& os, const DataTable& dt)
		{
			dt.display(os);
			return os;
		}
	};
}

#endif //W7_DATATABLE_H
