/*
 * =====================================================================================
 *
 *       Filename:  Text.hpp
 *
 *    Description:
 *
 *        Created:  08/05/2016 18:34:36
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Graphics/Text.hpp>

#include <gk/core/IntTypes.hpp>

class Text : public sf::Text {
	public:
		Text(const char *fontName, unsigned int characterSize = 30);
		Text(const char *fontName, const std::string &text, unsigned int characterSize = 30);

		void setMaxWidth(u16 width);
};

#endif // TEXT_HPP_
