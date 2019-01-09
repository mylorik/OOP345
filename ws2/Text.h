// Name: Artem Kulihina
// Seneca Student ID: 128516168
// Seneca email: akulihin@myseneca.ca
// Date of completion: 21.09.2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef TEXT_H
#define TEXT_H


namespace w2
{
	class Text
	{
		int m_size_{};
		std::string* m_string_{};
	public:
		Text();
		explicit Text(const std::string&);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&) noexcept;
		Text& operator=(Text&&) noexcept;
		~Text();
		size_t size() const;
	};
}
#endif
