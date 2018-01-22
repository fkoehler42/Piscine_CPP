/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:26:46 by fkoehler          #+#    #+#             */
/*   Updated: 2018/01/18 19:21:40 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {

	public:

		Span(unsigned int n);
		Span(Span const &src);
		virtual ~Span(void);

		unsigned int			getMaxSize(void) const;
		std::vector<int>		getArray(void) const;

		void					addNumber(int const n);
		unsigned int			shortestSpan(void) const;
		unsigned int			longestSpan(void) const;

		Span		&operator=(Span const &rhs);

	private:

		Span(void);

		unsigned int const	_maxSize;
		std::vector<int>	_array;

};


#endif
