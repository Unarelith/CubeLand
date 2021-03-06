/*
 * =====================================================================================
 *
 *       Filename:  Button.cpp
 *
 *    Description:
 *
 *        Created:  25/08/2015 18:42:18
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/Mouse.hpp>
#include <gk/gl/RenderTarget.hpp>
#include <gk/graphics/Font.hpp>

#include "Button.hpp"

Button::Button(const char *text, u8 fontSize) {
	m_text.setCharacterSize(fontSize);
	m_text.setFont("font-default");
	m_text.setString(text);

	m_rect.setFillColor(gk::Color::Black);
	m_rect.setOutlineColor(gk::Color::White);
	m_rect.setOutlineThickness(2);
	m_rect.setPosition(2, 2); // Outline
	m_rect.setSize(m_text.getLocalBounds().width + 64, m_text.getLocalBounds().height + 16);

	gk::FloatRect textRect = gk::FloatRect(m_text.getLocalBounds());
	m_text.setOrigin(textRect.x + textRect.width  / 2,
	                 textRect.y  + textRect.height / 2);

	m_text.setPosition(width() / 2, height() / 2);
}

void Button::onEvent(const SDL_Event &event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if(m_isActivated && event.button.button == SDL_BUTTON_LEFT) {
			m_action();
		}
	}
}

void Button::update() {
	gk::IntRect hitbox(getPosition().x, getPosition().y, width(), height());

	if(gk::Mouse::isInRect(hitbox)) {
		m_rect.setFillColor(gk::Color(100, 100, 100, 75));
	} else {
		m_rect.setFillColor(gk::Color::Black);
	}
}

void Button::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(m_rect, states);

	target.draw(m_text, states);
}

